cmake_minimum_required(VERSION 3.16)
project(pong VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  set(CMAKE_BUILD_TYPE Release CACHE STRING "" FORCE)
endif()

option(USE_SYSTEM_RAYLIB "Prefer system-installed raylib" ON)

if(USE_SYSTEM_RAYLIB)
  find_package(raylib QUIET)
endif()

if(NOT raylib_FOUND)
  message(STATUS "raylib not found on system, fetching from source")
  include(FetchContent)
  set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
  set(BUILD_GAMES OFF CACHE BOOL "" FORCE)
  FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 5.5
    GIT_SHALLOW TRUE
  )
  FetchContent_MakeAvailable(raylib)
endif()

add_executable(pong
  src/main.cpp
  src/Ball.cpp
  src/Player.cpp
)

target_include_directories(pong PRIVATE include)
target_link_libraries(pong PRIVATE raylib)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
  target_compile_options(pong PRIVATE -Wall -Wextra -Wpedantic)
elseif(MSVC)
  target_compile_options(pong PRIVATE /W4)
endif()

install(TARGETS pong RUNTIME DESTINATION bin)
