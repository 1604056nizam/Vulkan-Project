#version 450
layout(location = 0) in vec3 inPos;
layout(location = 1) in vec3 inColor;
layout(location = 2) in vec2 inUV;

layout(set = 0, binding = 0) uniform UBO {
    mat4 model;
    mat4 view;
    mat4 proj;
} ubo;

layout(location = 0) out vec3 vColor;
layout(location = 1) out vec2 vUV;

void main() {
	vColor = inColor;
	vUV = inUV;
    gl_Position = ubo.proj * ubo.view * ubo.model * vec4(inPos, 1.0);
}
