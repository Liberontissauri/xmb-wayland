add_executable(xmb-wayland src/main.cpp)

target_include_directories(xmb-wayland PRIVATE include)
target_link_libraries(xmb-wayland PRIVATE model_lib)
target_link_libraries(xmb-wayland PRIVATE lager)
target_link_libraries(xmb-wayland PRIVATE absl::log absl::status)
