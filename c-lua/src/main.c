#include <stdio.h>
#include <stdlib.h>

// LUA API Header Files
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

int example_func(lua_State *L) {
    // Check if the first argument is integer and return the value
    int a = luaL_checkinteger(L, 1);

    // Check if the second argument is integer and return the value
    int b = luaL_checkinteger(L, 2);

    // multiply and store the result inside a type lua_Integer
    lua_Integer c = a * b;

    // push the result to Lua
    lua_pushinteger(L, c);

    // exit code, successful = 1, otherwise error.
    return 1; // Successful
}

int main(int argc, char* argv[]) {
    /* Declare the Lua State */
    lua_State *L = luaL_newstate();

    /* Makes available Lua Standard Library */
    luaL_openlibs(L);

    /* Individual libraries can also be opened instead */
    // luaopen_math(L);
    // luaopen_string(L);

    /* *********************************** */
    /* 1. Running Lua code from a C string */
    printf("\n---- 1. Running Lua Code from String \n");

    // Option A
    const char *code = "print('Hello World from C-String')";
    if (luaL_loadstring(L, code) == LUA_OK) {
        if (lua_pcall(L, 0, 0, 0) == LUA_OK) {
            // If it was executed successfuly we
            // remove the code from the stack
            lua_pop(L, lua_gettop(L));
        }
    }

    // Option B
    // can replace lua_pcall + luaL_loadstring
    if (luaL_dostring(L, code) == LUA_OK) {
        lua_pop(L, lua_gettop(L));
    }

    /* *********************************** */
    /* 2. Running Lua code from a file */
    printf("\n---- 2. Running Lua Code from a file \n");
    // Option A
    const char *lua_file = "lua/example-file-read.lua";
    if (luaL_loadfile(L, lua_file) == LUA_OK) {
        if (lua_pcall(L, 0, 0, 0) == LUA_OK) {
            // If it was executed successfuly we
            // remove the code from the stack
            lua_pop(L, lua_gettop(L));
        }
    }

    // Option B
    if (luaL_dofile(L, lua_file) == LUA_OK) {
        lua_pop(L, lua_gettop(L));
    }

    /* *********************************** */
    /* 3. Exposing Variables */
    printf("\n---- 3. Exposing variables \n");
    lua_pushinteger(L, 32);
    lua_setglobal(L, "answer");
    const char *global_code = "print('Answer: ' .. answer)";

    if (luaL_dostring(L, global_code) == LUA_OK) {
        lua_pop(L, lua_gettop(L));
    }

    /* *********************************** */
    /* 4. Exposing Functions */
    printf("\n---- 4. Exposing functions \n");
    // Push the pointer to function
    lua_pushcfunction(L, example_func);

    // Get the value on top of the stack
    // and set as a global, in this case is the function
    lua_setglobal(L, "mul");

    // we can use the function `mul` inside the Lua code
    const char *mul = "print(mul(7, 8))";

    if (luaL_dostring(L, mul) == LUA_OK) {
        lua_pop(L, lua_gettop(L));
    }

    /* *********************************** */
    /* 5. Exposing Functions with Namespace */
    printf("\n---- 5. Exposing functions with Namespace \n");
    // First, we need to define an array with
    // all functions that will be available inside our namespace
    const struct luaL_Reg MyMathLib[] = {
        { "mul", example_func }
    };

    // We create a new table
    lua_newtable(L);

    // Here we set all functions from MyMathLib array into
    // the table on the top of the stack
    luaL_setfuncs(L, &MyMathLib, 0);

    // We get the table and set as global variable
    lua_setglobal(L, "MyMath");

    // Now we can call from Lua using the namespace MyMath
    const char * namespace_code = "print(MyMath.mul(7, 8))";

    if (luaL_dostring(L, namespace_code) == LUA_OK) {
        lua_pop(L, lua_gettop(L));
    }

    /* *********************************** */
    /* 6. Getting global variable from Lua */
    printf("\n---- 6. Getting global variable from Lua \n");
    const char * lua_file_global = "lua/example-global.lua";
    if (luaL_dofile(L, lua_file_global) == LUA_OK) {
        lua_pop(L, lua_gettop(L));
    }

    lua_getglobal(L, "message");
    if (lua_isstring(L, -1)) {
        const char * message = lua_tostring(L, -1);
        lua_pop(L, 1);
        printf("Message from lua: %s\n", message);
    }

    /* *********************************** */
    /* 7. Calling Lua function from C */
    printf("\n---- 7. Calling Lua function from C \n");
    const char * lua_file_function = "lua/example-function.lua";
    if (luaL_dofile(L, lua_file_function) == LUA_OK) {
        lua_pop(L, lua_gettop(L));
    }

    lua_getglobal(L, "my_function");
    if (lua_isfunction(L, -1)) {
        if (lua_pcall(L, 0, 1, 0) == LUA_OK) {
            lua_pop(L, lua_gettop(L));
        }
    }

    /* *********************************** */
    /* 8. Calling Lua function from C with args */
    printf("\n---- 8. Calling Lua function from C with args \n");
    const char * lua_file_function_args = "lua/example-function-args.lua";
    if (luaL_dofile(L, lua_file_function_args) == LUA_OK) {
        lua_pop(L, lua_gettop(L));
    }

    // Put the function to be called onto the stack
    lua_getglobal(L, "my_function");
    lua_pushinteger(L, 3);  // first argument
    lua_pushinteger(L, 4);  // second argument

    // Execute my_function with 2 arguments and 1 return value
    if (lua_pcall(L, 2, 1, 0) == LUA_OK) {

        // Check if the return is an integer
        if (lua_isinteger(L, -1)) {

            // Convert the return value to integer
            int result = lua_tointeger(L, -1);

            // Pop the return value
            lua_pop(L, 1);
            printf("Result: %d\n", result);
        }
        // Remove the function from the stack
        lua_pop(L, lua_gettop(L));
    }

    /* *********************************** */
    /* 9. Error Handling */
    printf("\n---- 9. Error Handling \n");
    const char * error_code = "print(return)"; // intentional error

    if (luaL_dostring(L, error_code) != LUA_OK) {
        puts(lua_tostring(L, lua_gettop(L)));
        lua_pop(L, lua_gettop(L));
    }

    /* After using the lua state, when nothing needs to be executed, close the state */
    lua_close(L);
    return 0;
}
