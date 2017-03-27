#include <iostream>
#include "display.h"
#include "mesh.h"
#include "Shader.h"
#include "texture.h"
#include "transform.h"
#include "camera.h"
#include "customtime.h"

int main(int argc, char** argv) {
	Display display(800, 600, "OpenGl Project Testdisplay");

	Vertex triangle[] = { Vertex(glm::vec3(-1.0f,-1.0f,0),glm::vec2(0,0)),
							Vertex(glm::vec3(0,1.0f,0),glm::vec2(0.5,1.0)),
							Vertex(glm::vec3(1.0f,-1.0f,0),glm::vec2(1.0,0)),

							Vertex(glm::vec3(-1.0f,-1.0f,0.5f),glm::vec2(0,0)),
							Vertex(glm::vec3(0,1.0f,0.5f),glm::vec2(0.5,1.0)),
							Vertex(glm::vec3(1.0f,-1.0f,0.5f),glm::vec2(1.0,0)),

							Vertex(glm::vec3(-1.0f,-1.0f,1),glm::vec2(0,0)),
							Vertex(glm::vec3(0,1.0f,1),glm::vec2(0.5,1.0)),
							Vertex(glm::vec3(1.0f,-1.0f,1),glm::vec2(1.0,0))
	};

	unsigned int indices[] = { 0,1,2,3,4,5,6 };
	float aspect = float(display.getWidth()) / float(display.getHeigth());
	std::cout << "Display dimensions are " << display.getWidth() << " x " << display.getHeigth() << ", thus resultung aspect: " << aspect << "." << std::endl;

	Camera cam(glm::vec3(0, 0, -20), aspect, 70.0f, 0.1f, 100.0f);
	//Mesh mesh(triangle, sizeof(triangle) / sizeof(triangle[0]), indices, sizeof(indices) / sizeof(indices[0]));
	Mesh mesh("./../data/obj/securitycam.obj");
	Shader shader("./../data/shaders/basicShader");
	Texture texture("./../data/textures/metal.jpg");

	float time = 0.0f;
	CustomTime customTime;

	while (!display.getIsClosed()) {
		customTime.incrementTime();
		std::cout << customTime.getTime() << std::endl;
		display.Clear(0.0f, 0.15f, 0.2f, 1.0f);
		display.Update();
		time += 0.001f;
	}
	return 0;
}