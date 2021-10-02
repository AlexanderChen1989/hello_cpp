

# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_binary
cc_binary(
	name = "constructor",
	srcs = ["main.cc"],
	copts = [],
	deps = ["hello_lib"],
)

# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_library
cc_library(
	name = "hello_lib",
	srcs = ["lib.cc"],
	hdrs = ["lib.h"],
	deps = [],
)