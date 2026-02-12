cmake_minimum_required(VERSION 3.20)
project(CPP_Mastery LANGUAGES CXX)

include(FetchContent)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

FetchContent_Declare(
  catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.12.0
)

FetchContent_MakeAvailable(catch2)

add_executable(calculator
  src/calculator.cpp
  src/parser.cpp
)

add_executable(parser_tests
  tests/parser_tests.cpp
  src/parser.cpp
)

enable_testing()

add_test(NAME parser_tests COMMAND parser_tests)

target_link_libraries(parser_tests PRIVATE Catch2::Catch2WithMain)

target_include_directories(calculator PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_include_directories(parser_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

target_compile_options(calculator PRIVATE
  $<$<CXX_COMPILER_ID:GNU,Clang>:-Wall -Wextra -Wpedantic>
  $<$<CXX_COMPILER_ID:MSVC>:/W4 /permissive->
)

target_compile_options(parser_tests PRIVATE
  $<$<CXX_COMPILER_ID:GNU,Clang>:-Wall -Wextra -Wpedantic>
  $<$<CXX_COMPILER_ID:MSVC>:/W4 /permissive->
)
