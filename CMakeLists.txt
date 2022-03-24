cmake_minimum_required(VERSION 3.14)
project(Cpp-libs)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 11)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  hello_test
  ./src/test/hello_test.cpp
)

add_executable(
  bit_vector_test
  ./src/test/bit_vector_test.cpp
)
target_link_libraries(
  hello_test
  bit_vector_test
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(hello_test)
gtest_discover_tests(bit_vector_test)

