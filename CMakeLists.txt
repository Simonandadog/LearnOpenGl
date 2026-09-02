cmake_minimum_required(VERSION 3.16)
project(LearnOpenGL)

set(CMAKE_CXX_STANDARD 17)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GLFW3 REQUIRED glfw3)

add_executable(${PROJECT_NAME}
        src/main.cpp
        src/glad.c
)

target_include_directories(${PROJECT_NAME} PRIVATE
        include
        ${GLFW3_INCLUDE_DIRS}
)

target_link_libraries(${PROJECT_NAME} PRIVATE
        ${GLFW3_LIBRARIES}
        GL
        dl
        pthread
)