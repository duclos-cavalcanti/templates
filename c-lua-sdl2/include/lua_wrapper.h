#ifndef LUA_WRAPPER_H
#define LUA_WRAPPER_H

#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

#include <SDL2/SDL.h>

typedef lua_State luaState;

luaState *luaCreateState();
void luaDestroyState(luaState *L);

char luaGetString(luaState *L, const char *name, char **str);
char luaGetInteger(luaState *L, const char *name, int *v);
char luaGetTableIntegerField(lua_State *L, const char *table, const char *field, int* v);

char luaRunScript(luaState *L, const char *script);
char luaRunVoidMethod(luaState *L, const char *method, int args_nr, ...);

void luaExposeFunction(luaState *L, lua_CFunction function, const char *name);

int luaCheckInteger(luaState *L, int depth);
#endif
