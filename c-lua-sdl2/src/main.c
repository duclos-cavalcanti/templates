#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <SDL.h>

#include "lua_wrapper.h"
#include "utils.h"

// Structures
typedef struct AppSettings {
    char *Title;
    int ScreenWidth;
    int ScreenHeight;
    SDL_Color BackgroundColor;
    SDL_Color ForegroundColor;
} AppSettings_t;

// Constants
const char *DrawFile = "lua/draw.lua";
const char *SettingsFile = "lua/settings.lua";

// Global Variables
AppSettings_t * gSettings = NULL;
SDL_Window * gWindow = NULL;
SDL_Renderer * gRenderer = NULL;

// API between Lua and SDL
int API_DrawPoint(lua_State *L) {

    int x1 = luaCheckInteger(L, 1);
    int y1 = luaCheckInteger(L, 2);

    SDL_SetRenderDrawColor(gRenderer, 
                           gSettings->ForegroundColor.r, 
                           gSettings->ForegroundColor.g, 
                           gSettings->ForegroundColor.b, 
                           SDL_ALPHA_OPAQUE);

    SDL_RenderDrawPoint(gRenderer, x1, y1);

    return 0;
}

void update() {
    // Update routines
}

void draw() {
    // Draw routines
}

void clear() {
    SDL_SetRenderDrawColor(gRenderer, 
                           gSettings->BackgroundColor.r, 
                           gSettings->BackgroundColor.g, 
                           gSettings->BackgroundColor.b, 
                           0xFF);
    SDL_RenderClear(gRenderer);
}

void refresh() {
    SDL_RenderPresent(gRenderer);
}

// Opens configuration file and reads it in
AppSettings_t *loadConfig(void) {
    int fg_red, fg_green, fg_blue;
    int bg_red, bg_green, bg_blue;
    
    luaState *L = luaCreateState();
    if (!luaRunScript(L, SettingsFile)) { return NULL; }

    AppSettings_t *settings = (AppSettings_t*) malloc(sizeof(AppSettings_t));

    if (!luaGetString(L, "title", &settings->Title)) { return NULL; }
    if (!luaGetInteger(L, "screen_width", &settings->ScreenWidth)) { return NULL; }
    if (!luaGetInteger(L, "screen_height", &settings->ScreenHeight)) { return NULL; }

    if (!luaGetTableIntegerField(L, "background_color", "r", &bg_red)) { return NULL; }
    if (!luaGetTableIntegerField(L, "background_color", "g", &bg_green)) { return NULL; }
    if (!luaGetTableIntegerField(L, "background_color", "b", &bg_blue)) { return NULL; }

    if (!luaGetTableIntegerField(L, "foreground_color", "r", &fg_red)) { return NULL; }
    if (!luaGetTableIntegerField(L, "foreground_color", "g", &fg_green)) { return NULL; }
    if (!luaGetTableIntegerField(L, "foreground_color", "b", &fg_blue)) { return NULL; }

    settings->BackgroundColor.r = bg_red;
    settings->BackgroundColor.g = bg_green;
    settings->BackgroundColor.b = bg_blue;

    settings->ForegroundColor.r = fg_red;
    settings->ForegroundColor.g = fg_green;
    settings->ForegroundColor.b = fg_blue;

    luaDestroyState(L);
    return settings;
}

int main(int argc, char ** argv) {

    // Loading settings.lua
    if (( gSettings = loadConfig() ) == NULL ) {
        logError("Failed settings initialization\n");
        return -1;
    }

    lua_State *draw_state = luaCreateState();
    luaExposeFunction(draw_state, API_DrawPoint, "drawpoint");
    luaRunScript(draw_state, DrawFile);

    if (SDL_Init( SDL_INIT_VIDEO) < 0) {
        logError("Failed SDL_Init: %s\n", SDL_GetError());
        return -1;
    }
        
    gWindow = SDL_CreateWindow(
            gSettings->Title,
            SDL_WINDOWPOS_UNDEFINED, 
            SDL_WINDOWPOS_UNDEFINED, 
            gSettings->ScreenWidth, 
            gSettings->ScreenHeight, 
            SDL_WINDOW_SHOWN
            );
    if (gWindow == NULL) {
        logError("Failed Window initialization: %s\n", SDL_GetError());
        return -1;
    }

    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
    if (gRenderer == NULL) {
        logError("Failed Renderer initialization: %s\n", SDL_GetError());
        return -1;
    }

    int quit = 0;
    int time_diff;
    int x = gSettings->ScreenWidth/2, y = 0;
    SDL_Event e;
    uint start = SDL_GetTicks();

    while (quit != 1) {
        // Events
        while(SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = 1;
            }
        }

        // Update inputs
        update();

        // Clear screen
        clear();

        // Render objects
        draw();

        time_diff = (SDL_GetTicks() - start);
        luaRunVoidMethod(/*luaState     */ draw_state, 
                         /*method       */ "draw", 
                         /*num of args  */ 3, 
                         /*args         */ time_diff,
                         /*args         */ x,
                         /*args         */ (++y) % gSettings->ScreenHeight);

        // Update/Refresh screen
        refresh();
    }

    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    free(gSettings);

    gWindow = NULL;
    gRenderer = NULL;

    SDL_Quit();

    luaDestroyState(draw_state);

    return 0;
}

