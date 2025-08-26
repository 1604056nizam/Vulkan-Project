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
	external/stb
)

# Source files
set(SOURCES
    main.cpp
    src/TexturedCubeApp.cpp
)

# Create executable
add_executable(TexturedCubeApp ${SOURCES})

# --- Copy the shaders folder next to the built .exe after every build ---
set(SHADERS_DIR "${CMAKE_SOURCE_DIR}/shaders")

add_custom_command(TARGET TexturedCubeApp POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory "$<TARGET_FILE_DIR:TexturedCubeApp>/shaders"
    COMMAND ${CMAKE_COMMAND} -E copy_directory "${SHADERS_DIR}" "$<TARGET_FILE_DIR:TexturedCubeApp>/shaders"
    COMMAND ${CMAKE_COMMAND} -E make_directory $<TARGET_FILE_DIR:TexturedCubeApp>/assets
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/assets $<TARGET_FILE_DIR:TexturedCubeApp>/assets
	COMMENT "Copying shaders/ to output folder"
)


# Link against Vulkan and GLFW
target_link_libraries(TexturedCubeApp
    PRIVATE
    Vulkan::Vulkan
    glfw
)

