#define GLFW_INCLUDE_VULKAN

#include "TexturedCubeApp.hpp"
#include <iostream>
#include <GLFW/glfw3.h>

const uint32_t WIDTH = 800;
const uint32_t HEIHGT = 600;


void TexturedCubeApp::run() {
	initWindow();
	initVulkan();
	mainLoop();
	cleanUp();
}

void TexturedCubeApp::initWindow() {
	glfwInit();

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	this->window = glfwCreateWindow(WIDTH, HEIHGT, "VULKAN WINDOW", nullptr, nullptr);

	std::cout << "Window initialized (placeholder)" << std::endl;
}

void TexturedCubeApp::initVulkan() {
	VkApplicationInfo appInfo{};
	appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	appInfo.pApplicationName = "Textured Cube";
	appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
	appInfo.pEngineName = "No Engine";
	appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
	appInfo.apiVersion = VK_API_VERSION_1_0;


	uint32_t glfwExtensionCount = 0;
	const char** glfwEntensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

	VkInstanceCreateInfo createInfo{};
	createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	createInfo.pApplicationInfo = &appInfo;
	createInfo.enabledExtensionCount = glfwExtensionCount;
	createInfo.ppEnabledExtensionNames = glfwEntensions;


	createInfo.enabledLayerCount = 0;


	// Creating the instance
	if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS) {
		throw std::runtime_error("Failed to create vulkan instance");
	}

	std::cout << "Vulkan instance created successfully" << std::endl;


	//creating the surface
	if (glfwCreateWindowSurface(instance, window, nullptr, &surface) != VK_SUCCESS) {
		throw std::runtime_error("Failed to create window surface");
	}

	std::cout << "Vulkan Surface created Successfully" << std::endl;


	//creating the physical Device
	uint32_t deviceCount = 0;
	vkEnumeratePhysicalDevices(instance, &deviceCount, nullptr);

	if (deviceCount == 0) {
		throw std::runtime_error("Failed to find GPUs with vulkan support");
	}

	std::vector<VkPhysicalDevice> devices(deviceCount);
	vkEnumeratePhysicalDevices(instance, &deviceCount, devices.data());

	for (const auto& device : devices) {
		//check for graphics queue and presentation support

		if (isDeviceSuitable(device, surface)) {
			physicalDevice = device;
			break;
		}
	}

	if (physicalDevice == VK_NULL_HANDLE) {
		throw std::runtime_error("Failed to find a suitable GPU");
	}

	VkPhysicalDeviceProperties deviceProperties;
	vkGetPhysicalDeviceProperties(physicalDevice, &deviceProperties);

	std::cout << "Found GPU: " << deviceProperties.deviceName << std::endl;
}

void TexturedCubeApp::mainLoop() {
	std::cout << "Running main loop (placeholder)" << std::endl;

	while (!glfwWindowShouldClose(this->window)) {
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();

}

void TexturedCubeApp::cleanUp() {
	std::cout << "Cleaning up (placeholder)" << std::endl;
	vkDestroySurfaceKHR(instance, surface, nullptr);
	vkDestroyInstance(instance, nullptr);
	glfwDestroyWindow(window);
	glfwTerminate();
}



bool TexturedCubeApp::isDeviceSuitable(VkPhysicalDevice device, VkSurfaceKHR surface) {
	uint32_t queueFamilyCount = 0;
	vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, nullptr);
	std::vector<VkQueueFamilyProperties> queueFamilies(queueFamilyCount);
	vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, queueFamilies.data());


	bool grpahicsFound = false;
	bool presentFound = false;

	for (uint32_t i = 0; i < queueFamilyCount; i++) {
		if (queueFamilies[i].queueFlags & VK_QUEUE_GRAPHICS_BIT) {
			grpahicsFound = true;
		}

		VkBool32 presentSupport = false;

		vkGetPhysicalDeviceSurfaceSupportKHR(device, i, surface, &presentSupport);

		if (presentSupport) {
			presentFound = true;
		}

		if (grpahicsFound && presentFound) {
			break;
		}
	}
	
	return grpahicsFound && presentFound;
}
