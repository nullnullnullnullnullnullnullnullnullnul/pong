cmake_minimum_required(VERSION 3.10)
project(pong LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(SOURCES
    src/main.cpp
    src/Ball.cpp
    src/Player.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME}
    PRIVATE
    ${CMAKE_SOURCE_DIR}/lib/libraylib.a
    GL m dl pthread rt X11
)
