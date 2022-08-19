#include <stdarg.h>
#include <string.h>

#include "lua_wrapper.h"

luaState *luaCreateState() {
    luaState *L = luaL_newstate();
    luaL_openlibs(L);

    return L;
}

void luaDestroyState(luaState *L) {
    lua_close(L);
}

char luaGetString(luaState *L, const char *name, char **str) {
    lua_getglobal(L, name);
    if (lua_isstring(L, -1)) {
        const char * gl = lua_tostring(L, -1);
        char* s = (char *)malloc(strlen(gl));
        strcpy(s, gl);
        *str = s;
        lua_pop(L, 1);

        return 1;
    }

    return 0;
}

char luaGetInteger(luaState *L, const char *name, int *v) {
    lua_getglobal(L, name);
    if (lua_isinteger(L, -1)) {
        int value = lua_tointeger(L, -1);
        *v = value;
        lua_pop(L, 1);

        return 1;
    }

    return 0;
}

char luaGetTableIntegerField(lua_State *L, const char *table, const char *field, int* v) {
    lua_getglobal(L, table);
    if (lua_istable(L, -1)) {
        lua_getfield(L, -1, field);
        int value = lua_tointeger(L, -1);
        *v = value;
        lua_pop(L, 1);
        lua_pop(L, 1);
        return 1;
    }
    lua_pop(L, 1);
    return 0;
}


void luaExposeFunction(luaState *L, lua_CFunction function, const char *name) {
    lua_pushcfunction(L, function);
    lua_setglobal(L, name);
}

char luaRunScript(luaState *L, const char *script) {
    if (luaL_dofile(L, script) == LUA_OK) {
        lua_pop(L, lua_gettop(L));

        return 1;
    }
    return 0;
}

char luaRunVoidMethod(luaState *L, const char *method, int args_nr, ...) {
    lua_getglobal(L, method);
    if (lua_isfunction(L, -1)) {
        va_list list;
        va_start(list, args_nr);
        for (int i = 0; i < args_nr; i++) {
            int arg = va_arg(list, int);
            lua_pushinteger(L, arg);
        }
        va_end(list);

        if (lua_pcall(L, args_nr, 0, 0) == LUA_OK) {
            lua_pop(L, lua_gettop(L));
            return 1;
        }

        return 0;
    }
    return 0;
}

int luaCheckInteger(luaState *L, int depth) {
    return luaL_checkinteger(L, depth);
}
