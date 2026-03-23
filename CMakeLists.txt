cmake_minimum_required(VERSION 3.28)
project(XMBWayland)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Lager REQUIRED)

include(FetchContent)

FetchContent_Declare(
		absl
		GIT_REPOSITORY https://github.com/abseil/abseil-cpp.git
		GIT_TAG        master # Or a specific commit/tag
		
)
FetchContent_MakeAvailable(absl)

FetchContent_Declare(
		googletest
		URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_subdirectory(compositor)
add_subdirectory(model)
