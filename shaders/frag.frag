#version 450
layout(location=0) in vec3 vColor;
layout(location=1) in vec2 vUV;
layout(location=0) out vec4 outColor;

layout(set = 0, binding = 1) uniform sampler2D texSampler;

void main(){ 
	vec4 tex = texture(texSampler, vUV);
	outColor = tex * vec4(vColor, 1.0);
} 
