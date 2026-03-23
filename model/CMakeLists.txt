add_library(model_lib src/model.cpp)

target_include_directories(model_lib PUBLIC include)

target_link_libraries(model_lib PUBLIC lager absl::log absl::status)

add_executable(model_tests tests/model_tests.cpp)

target_link_libraries(model_tests PRIVATE  model_lib lager absl::log absl::status GTest::gtest_main)


include(GoogleTest)
gtest_discover_tests(model_tests)
