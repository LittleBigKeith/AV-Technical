cmake_minimum_required(VERSION 3.8)
project(nmp)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()
#GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 11)
#Fetch googletest at compile time
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
#this should only build by default if this is the current project
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    include(CTest)
endif()
#To build the code, add the following to the end of your CMakeLists.txt file:
enable_testing()

add_executable(
  main
  main.cpp
  TesterFunction.cpp
)
target_link_libraries(
  main
  gtest_main
)

add_executable(
  TesterFunction
  Test.cpp
)
target_link_libraries(
  TesterFunction
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(main)