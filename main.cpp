#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <cstdlib>
#include <optional>
#include <set>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <array>
#include "TexturedCubeApp.hpp"


const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;

VkInstance instance;
VkSurfaceKHR surface;
VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
VkDevice device;
VkQueue graphicsQueue;
VkQueue presentQueue;


struct Vertex {
	glm::vec3 pos;
	glm::vec2 texCoord;

	static VkVertexInputBindingDescription getBindingDescription() {
		VkVertexInputBindingDescription binding{};

		binding.binding = 0;
		binding.stride = sizeof(Vertex);
		binding.inputRate = VK_VERTEX_INPUT_RATE_VERTEX;

		return binding;
	}

	static std::array<VkVertexInputAttributeDescription, 2> getAttributeDescriptions() {
		std::array<VkVertexInputAttributeDescription, 2> attr{};
		
		attr[0].binding = 0;
		attr[0].location = 0;
		attr[0].format = VK_FORMAT_R32G32B32_SFLOAT;
		attr[0].offset = offsetof(Vertex, pos);


		attr[1].binding = 0;
		attr[1].location = 1;
		attr[1].format = VK_FORMAT_R32G32_SFLOAT;
		attr[1].offset = offsetof(Vertex, texCoord);

		return attr;
	}
};

//defining the cube 

const std::vector<Vertex> vertices = {
	// Front face
	{{-0.5f, -0.5f,  0.5f}, {0.0f, 0.0f}},
	{{ 0.5f, -0.5f,  0.5f}, {1.0f, 0.0f}},
	{{ 0.5f,  0.5f,  0.5f}, {1.0f, 1.0f}},
	{{-0.5f,  0.5f,  0.5f}, {0.0f, 1.0f}},
	// Back face
	{{-0.5f, -0.5f, -0.5f}, {1.0f, 0.0f}},
	{{ 0.5f, -0.5f, -0.5f}, {0.0f, 0.0f}},
	{{ 0.5f,  0.5f, -0.5f}, {0.0f, 1.0f}},
	{{-0.5f,  0.5f, -0.5f}, {1.0f, 1.0f}},
};

//end defining the cube


//adding index data 
const std::vector<uint16_t> indices = {
	// Front
	0, 1, 2, 2, 3, 0,
	// Right
	1, 5, 6, 6, 2, 1,
	// Back
	5, 4, 7, 7, 6, 5,
	// Left
	4, 0, 3, 3, 7, 4,
	// Top
	3, 2, 6, 6, 7, 3,
	// Bottom
	4, 5, 1, 1, 0, 4
};
//end adding index data
int main() {
	/*try {
		initWindow();
		createInstance();
		createSurface();
		pickPhysicalDevice();
		createLogicalDevice();
		mainLoop();
		cleanup();
	}
	catch (const std::exception& e) {
		std::cerr << "ERROR: " << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;*/
	TexturedCubeApp app;

	
	try {
		TexturedCubeApp app;
		app.run();
	}
	catch (const std::exception& e) {
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	system("pause"); 
	return 0;
	


}
