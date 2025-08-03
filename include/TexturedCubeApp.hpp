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
	struct QueueFamilyIndices {
		int graphicsFamily = -1;
		int presentFamily = -1;

		bool isComplete() {
			return graphicsFamily >= 0 && presentFamily >= 0;
		}
	};

	struct SwapChainSupportDetails {
		VkSurfaceCapabilitiesKHR capabilities;
		std::vector<VkSurfaceFormatKHR> formats;
		std::vector<VkPresentModeKHR> presentModes;
	};

	void initWindow();
	void initVulkan();
	void mainLoop();
	void cleanUp();
	void createCommandPool();
	void createCommandBuffers();
	void recordCommandBuffers(VkRenderPass renderPass);
	void createVertexBuffer();
	void createIndexBuffer();
	bool isDeviceSuitable(VkPhysicalDevice device, VkSurfaceKHR surface);
	uint32_t findMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties);
	void createSyncObject();
	void drawFrame();


	QueueFamilyIndices findQueueFamilies(VkPhysicalDevice decvice, VkSurfaceKHR surface);
	SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device, VkSurfaceKHR surface);

	GLFWwindow* window;

	VkInstance instance;
	VkSurfaceKHR surface;
	VkDevice device;
	VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
	VkQueue graphicsQueue;
	VkQueue presentQueue;
	VkSwapchainKHR swapChain;
	std::vector<VkImage> swapChainImages;
	VkFormat swapChainImageFormat;
	VkExtent2D swapChainExtent;
	VkPipelineLayout pipelineLayout;
	VkPipeline graphicsPipeline;

	VkBuffer vertexBuffer;
	VkDeviceMemory vertexBufferMemory;

	VkBuffer indexBuffer;
	VkDeviceMemory indexBufferMemory;
	std::vector<VkImageView> swapChainImageViews;
	VkRenderPass renderPass;
	std::vector<VkFramebuffer> swapChainFramebuffers;

	VkCommandPool commandPool;
	std::vector<VkCommandBuffer> commandBuffers;

	VkSemaphore imageAvailableSemaphore;
	VkSemaphore renderFinishedSemaphore;
	VkFence inFlightFence;
};