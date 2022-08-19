load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_library(
    name = "hello-world-lib",
    srcs = glob(["lib/*.c"]),
    hdrs = glob(["lib/include/*.h"]),
    includes = [ "lib/include" ],
    visibility = ["//visibility:public"]
)

cc_library(
    name = "hello-world",
    srcs = glob(
                ["src/*.c"],
                exclude = ["src/main.c"],
                ),
    hdrs = glob(["include/*.h"]),
    includes = [ "include" ],
    visibility = ["//visibility:public"]
)

cc_binary(
    name = "hello-world-binary",
    srcs = ["src/main.c"],
    # srcs = glob(["src/*.c"]),
    visibility = ["//visibility:public"],
    deps = [
        ":hello-world",
        ":hello-world-lib",
    ],
)
