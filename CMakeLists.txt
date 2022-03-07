cmake_minimum_required(VERSION 3.10)

project(Tuple
  LANGUAGES CXX
)

find_package(Threads)

# Compile googltest as static lib
add_library(googletest1 STATIC
  googletest/googletest/src/gtest-all.cc
)

target_compile_features(googletest1
  PUBLIC
    cxx_std_17
)

target_compile_options(googletest1
  PRIVATE
    "-g" "-O2"
)

target_include_directories(googletest1
  PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/googletest/googletest/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/googletest/googletest"
)

add_executable(testTuple
  testTuple.cc
)

target_include_directories(testTuple
  PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/googletest/googletest/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/googletest/googletest"
)

target_compile_options(testTuple
  PRIVATE
  "-Wall" "-Wextra" "-g" "-fsanitize=address,undefined"
)

target_compile_features(testTuple
  PUBLIC
    cxx_std_17
)

set_target_properties(testTuple
  PROPERTIES
    CXX_EXTENSIONS OFF
    LINK_FLAGS "-fsanitize=address,undefined"
)

target_link_libraries(testTuple
  PRIVATE
    googletest1
    Threads::Threads
)
