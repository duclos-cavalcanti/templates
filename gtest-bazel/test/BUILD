load("@rules_cc//cc:defs.bzl", "cc_test")

cc_test(
  name = "example_test",
  size = "small",
  srcs = [ 
          "src/hello-test.cc",
          "src/main.cc",
          "mock/mock.c",
          ],

  includes=
  [
	"../main/include",
	"../main/lib/include",
	"include",
	"mock/include",
  ],
  deps =
  [
	"//main:hello-world",
	"//main:hello-world-lib",
	"@com_google_googletest//:gtest_main",
  ],
)
