#include <gl/glew.h>
#include <gl/freeglut.h>
#include <iostream>
using namespace std;

typedef struct {
	GLenum       type;
	const char*  filename;
	GLuint       shader;
} ShaderInfo;

GLuint LoadShaders(ShaderInfo*);
