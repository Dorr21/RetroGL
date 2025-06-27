cmake_minimum_required(VERSION 3.10)
project(RetroGL)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

find_package(OpenGL REQUIRED)



set(triangleBESRC
    src/triangleBE.c
    static/glew.c
)

add_executable(triangleBE ${triangleBESRC})

target_include_directories(triangleBE PRIVATE ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(triangleBE 
    PRIVATE 
        OpenGL::GL
        ${PROJECT_SOURCE_DIR}/static/libglfw3.a
)