#pragma once

#include <vulkan/vulkan.h>
#include <vector>
#include <set>

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
	void createInstance(uint32_t& glfwExtensionCount, const char** glfwExtensions);
	void createPhysicalDevice(uint32_t& deviceCount, std::vector<VkPhysicalDevice>& devices);
	void createLogicalDevice(std::set<int>& uniqueQueueFamilies, float& queuePriority, const std::vector<const char*>& deviceExtension);
	void createSwapChain(QueueFamilyIndices& indices);
	void createCommandPool();
	void createCommandBuffers();
	void recordCommandBuffers(VkRenderPass renderPass);
	void createVertexBuffer();
	void createIndexBuffer();
	bool isDeviceSuitable(VkPhysicalDevice device, VkSurfaceKHR surface);
	uint32_t findMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties);
	void createSyncObject();
	void drawFrame();
	void createDescriptorSetLayout();
	void createUniformBuffers();
	void createDescriptorPoolAndSets();
	
	
	void createTextureImage();
	void createTextureImageView();
	void createTextureSampler();

	VkCommandBuffer beginSingleTimeCommands();
	void endSingleTimeCommands(VkCommandBuffer cmd);
	void transitionImageLayout(VkImage img, VkFormat fmt, VkImageLayout oldL, VkImageLayout newL);
	void copyBufferToImage(VkBuffer src, VkImage dst, uint32_t width, uint32_t height);


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

	VkImage depthImage{};
	VkDeviceMemory depthImageMemory{};
	VkImageView depthImageView{};
	VkFormat depthFormat{};


	std::vector<VkBuffer> uboBuffers;
	std::vector<VkDeviceMemory> uboMemories;
	std::vector<void*> uboMapped;

	VkDescriptorSetLayout descriptorSetLayout{};
	VkDescriptorPool descriptorPool{};
	std::vector<VkDescriptorSet> descriptorSets;


	VkImage textureImage{};
	VkDeviceMemory textureImageMemory{};
	VkImageView textureImageView{};
	VkSampler textureSampler{};

	// helpers (declare)
	


};