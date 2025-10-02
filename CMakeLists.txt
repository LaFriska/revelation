cmake_minimum_required(VERSION 3.16)
project(revelation LANGUAGES CXX)

# Compiler options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(-Wall -fsanitize=address -Iinclude)

add_link_options(-fsanitize=address)

# Collect all .cpp files from src/
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp)

# Build target
add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE include)
target_include_directories(${PROJECT_NAME} PRIVATE assets)

if (LINUX)
    # Linux libs
    target_link_libraries(${PROJECT_NAME} PRIVATE
            raylib
            GL
            m
            pthread
            dl
            rt
            X11
    )
endif ()

if (APPLE)
    # Linux libs
    target_link_libraries(${PROJECT_NAME} PRIVATE
            "-framework CoreVideo",
            "-framework IOKit",
            "-framework Cocoa",
            "-framework GLUT",
            "-framework OpenGL"
    )
endif ()

# Add a custom run target (like "make run")
add_custom_target(run
        COMMAND Revelation
        DEPENDS Revelation
        WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)
