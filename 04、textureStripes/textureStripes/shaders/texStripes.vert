#version 150

layout (std140) uniform Matrices {
	mat4 m_pvm;
	mat4 m_viewModel;
	mat3 m_normal;
};

in vec4 position;
in vec2 texCoord;

out vec2 texCoordV;

void main () {
	
	texCoordV = texCoord;
	gl_Position = m_pvm * position;	
}