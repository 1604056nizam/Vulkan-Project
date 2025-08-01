#pragma once

#include <vulkan/vulkan.h>
#include <vector>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>


class TexturedCubeApp
{
public:
	void run();

private:
	void initWindow();
	void initVulkan();
	void mainLoop();
	void cleanUp();

	void createVertexBuffer();
	void createIndexBuffer();
	bool isDeviceSuitable(VkPhysicalDevice device, VkSurfaceKHR surface);

	GLFWwindow* window;

	VkInstance instance;
	VkSurfaceKHR surface;
	VkDevice device;

	VkBuffer vertexBuffer;
	VkDeviceMemory vertexBufferMemory;

	VkBuffer indexBuffer;
	VkDeviceMemory indexBufferMemory;

	

	VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
};