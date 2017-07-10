#version 330

uniform vec4 color1 = vec4(0.0, 0.0, 1.0, 1.0);
uniform vec4 color2 = vec4(0.3, 0.7, 0.5, 1.0);

uniform int multiplicationFactor = 8;

in vec2 texCoordV;

out vec4 outputF;

void main() {


	float f = fract(texCoordV.s * 8.0);
	float s = smoothstep(0.45, 0.5, f) - smoothstep(0.95, 1.0, f);
	outputF = mix(color2, color1, s);
}