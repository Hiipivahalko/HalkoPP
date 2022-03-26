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

#file(GLOB files_for_tests CONFIGURE_DEPENDS "./src/*.cpp""./src/**/*.cpp" "./test/*.cpp")
#message(STATUS " >> ALL CPP FILES: ${files_for_tests}")

add_executable(
  hello_test
  ./src/hello.cpp
  ./src/bitArray/bitArray.cpp
  ./test/hello_test.cpp
  ./test/bitVector_test.cpp
  #${files_for_tests}
)

target_link_libraries(
  hello_test
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(hello_test)

