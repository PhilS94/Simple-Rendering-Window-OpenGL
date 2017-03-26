#include <iostream>
#include "display.h"
#include "mesh.h"
#include "Shader.h"
#include "texture.h"
#include "transform.h"
#include "camera.h"
#include <glm/glm.hpp>

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

	Camera cam(glm::vec3(0, 0, -4), aspect, 70.0f, 0.1f, 100.0f);
	//Mesh mesh(triangle, sizeof(triangle) / sizeof(triangle[0]), indices, sizeof(indices) / sizeof(indices[0]));
	Mesh mesh("./../data/obj/securitycam.obj");
	Shader shader("./../data/shaders/basicShader");
	Texture texture("./../data/textures/metal.jpg");
	Transform transform(glm::vec3(0, 0, 0), glm::vec4(0, 1, 1, 0), glm::vec3(1, 1, 1));;

	float time = 0.0f;

	while (!display.getIsClosed()) {
		display.Clear(0.0f, 0.15f, 0.2f, 1.0f);

		float amplitude = 2;
		float velocity = 0.5f;
		float sinTime = amplitude*sinf(velocity*time);
		float cosTime = amplitude*cosf(velocity*time);

		GLfloat radius = 10.0f;
		cam.setPosition(glm::vec3(sinTime * radius, 0, cosTime * radius));
		cam.setForward(-cam.getPosition());
		//transform.getPosition().x = sinTime;
		//ransform.getPosition().y = sinTime;
		//transform.getPosition().z = sinTime;
		//transform.getRotation().z = 0.5f*time;
		//transform.getRotation().y = 0.2f*time;

		shader.Bind();
		texture.Bind(0);
		shader.Update(transform, cam);
		mesh.Draw();

		display.Update();
		time += 0.001f;
	}
	return 0;
}