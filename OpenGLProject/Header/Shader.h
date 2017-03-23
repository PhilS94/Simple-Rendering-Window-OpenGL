#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <GL\glew.h>

class Shader {
public:
	Shader(const std::string& fileName);
	void Bind();
	std::string LoadShader(const std::string& fileName);
	GLuint CreateShader(const std::string& text, unsigned int type);
	void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
	virtual ~Shader();

private:
	static const unsigned int NUM_SHADERS =2; // Vertex and Shader Fragment Shader only
	GLuint program; //Shader program (Keep track of where program is)
	GLuint shaders[NUM_SHADERS};
};
#endif
