#include "LoadShaders.h"
#pragma comment (lib, "glew32.lib")

enum VAO_IDs { Triangles, NumVAOs };
enum Buffer_IDs { ArrayBuffer, NumBuffers };

enum Attrib_IDs { vPosition = 0 };

GLuint VAOs[NumVAOs];
GLuint Buffers[NumBuffers];

const GLuint NumVertices = 6;

void init()
{
	glGenVertexArrays(NumVAOs, VAOs);
	glBindVertexArray(VAOs[Triangles]);

	GLfloat vertices[NumVertices][2] = {
		{ -0.90, -0.90 },
		{ 0.85, -0.90 },
		{ -0.90, 0.85 },
		{ 0.90, -0.85 },
		{ 0.90, 0.90 },
		{ -0.85, 0.90 },
	};

	glGenBuffers(NumBuffers, Buffers);
	glBindBuffer(GL_ARRAY_BUFFER, Buffers[ArrayBuffer]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	ShaderInfo shaders[] = {
		{ GL_VERTEX_SHADER, "triangles.vert" },
		{ GL_FRAGMENT_SHADER, "triangles.frag" },
		{ GL_NONE, NULL }
	};

	GLuint program = LoadShaders(shaders);
	glUseProgram(program);

#define  BUFFER_OFFSET(offset) ((void *)(offset))

	glVertexAttribPointer(vPosition, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
	glEnableVertexAttribArray(vPosition);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glBindVertexArray(VAOs[Triangles]);
	glDrawArrays(GL_TRIANGLES, 0, NumVertices);

	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutInitWindowSize(512, 512);

	glutInitContextVersion(4, 3);
	glutInitContextProfile(GLUT_CORE_PROFILE);
	glutCreateWindow(argv[0]);

	cout << glGetString(GL_VERSION) << endl;
	cout << glGetString(GL_RENDERER) << endl;

	glewExperimental = GL_TRUE;
	if (glewInit())
	{
		cerr << "Unable to initialize GLEW ... exiting" << endl;
		exit(1);
	}

	GLenum error = glGetError();

	init();
	glutDisplayFunc(display);
	glutMainLoop();
}


