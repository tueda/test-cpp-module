cmake_minimum_required(VERSION 3.28)
include(cmake/init-vcpkg.cmake)

# Detect if the project is the root or being bundled.
if(NOT DEFINED PROJECT_NAME)
  set(IS_ROOT_PROJECT ON)
endif()

# Project information.
project(
  test-cpp-module
  VERSION 0.0.1
  LANGUAGES CXX)

# Root project settings.
if(IS_ROOT_PROJECT)
  include(CTest)
endif()

# Source code.
add_subdirectory(src)
if(IS_ROOT_PROJECT AND BUILD_TESTING)
  add_subdirectory(tests EXCLUDE_FROM_ALL)
endif()
