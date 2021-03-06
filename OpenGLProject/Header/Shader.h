#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <GL\glew.h>
#include "transform.h"
#include "camera.h"

class Shader {
public:
	Shader() { Shader("./../data/shaders/basicShader"); };
	Shader(const std::string& fileName);
	void Bind();
	void Update(Transform& transform, Camera& cam);
	std::string LoadShader(const std::string& fileName);
	GLuint CreateShader(const std::string& text, GLenum shaderType);
	void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
	virtual ~Shader();

private:
	static const unsigned int NUM_SHADERS = 2; // Vertex and Shader Fragment Shader only

	enum {
		TRANSFORM_U,
		NUM_UNIFORMS
	};
	GLuint program; //Shader program (Keep track of where program is)
	GLuint shaders[NUM_SHADERS];
	GLuint uniforms[NUM_UNIFORMS];
};
#endif
