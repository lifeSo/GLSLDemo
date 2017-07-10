#version 330

layout (std140) uniform Material {
	vec4 diffuse;
	vec4 ambient;
	vec4 specular;
	vec4 emissive;
	float shininess;
	int texCount;
};

layout (std140) uniform Lights {
	vec3 l_dir;	   // camera space
};

in Data {
	vec3 normal;
	vec4 eye;
	vec2 texCoord;
} DataIn;

uniform sampler2D texUnit;

out vec4 colorOut;

void main() {

	// set the specular term to black
	vec4 spec = vec4(0.0);

	// normalize both input vectors
	vec3 n = normalize(DataIn.normal);
	vec3 e = normalize(vec3(DataIn.eye));

	float intensity = max(dot(n,l_dir), 0.0);

	vec4 difColor = intensity *  diffuse * texture(texUnit, DataIn.texCoord);
	vec4 ambColor = ambient * texture(texUnit, DataIn.texCoord);
	colorOut = max(difColor , ambColor);

}