cmake_minimum_required(VERSION 3.10)
project(VulkanHello)

set(CMAKE_CXX_STANDARD 17)

# Vulkan SDK (you already have it installed)
find_package(Vulkan REQUIRED)

# Add GLFW from local source
add_subdirectory(external/glfw-3.4)

# Your executable
add_executable(VulkanHello main.cpp)

# Link to Vulkan and GLFW
target_link_libraries(VulkanHello PRIVATE Vulkan::Vulkan glfw)
