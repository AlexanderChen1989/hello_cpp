

# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_library
cc_library(
	name = "nice_lib",
	srcs = ["nice.cc"],
	hdrs = ["nice.h"],
)

# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_binary
cc_binary(
	name = "nice",
	srcs = ["main.cc"],
	deps = ["nice_lib"],
)