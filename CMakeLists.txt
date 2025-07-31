cmake_minimum_required(VERSION 3.10)
project(TexturedCubeApp)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Vulkan SDK (automatically detected from environment)
find_package(Vulkan REQUIRED)

# Add GLFW from local source
add_subdirectory(external/glfw-3.4)

# Include directories
include_directories(
    include
    external/glfw-3.4/include
    external/glm
)

# Source files
set(SOURCES
    main.cpp
    src/TexturedCubeApp.cpp
)

# Create executable
add_executable(TexturedCubeApp ${SOURCES})

# Link against Vulkan and GLFW
target_link_libraries(TexturedCubeApp
    PRIVATE
    Vulkan::Vulkan
    glfw
)
