#include <iostream>
#include "display.h"
#include "mesh.h"
#include "Shader.h"
#include "texture.h"
#include "transform.h"
#include "camera.h"
#include <glm/glm.hpp>

int main(int argc, char** argv) {
	Display display(800, 600, "Nice Display");

	Vertex vertices[] = {	Vertex(glm::vec3(-1.0f,-1.0f,0),glm::vec2(0,0)),
							Vertex(glm::vec3(0,1.0f,0),glm::vec2(0.5,1.0)),
							Vertex(glm::vec3(1.0f,-1.0f,0),glm::vec2(1.0,0))
	};

	float aspect = float(display.getWidth()) / float(display.getHeigth());
	std::cout << display.getWidth() << " x " << display.getHeigth() << " and Aspect: " << aspect << std::endl;
	Camera cam(glm::vec3(0, 0, -2), aspect, 70.0f, 0.1f, 100.0f);
	Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));
	Shader shader("./../data/shaders/basicShader");
	Texture texture("./../data/textures/metal.jpg");
	Transform transform;

	float time = 0.0f;

	while (!display.getIsClosed()) {

		display.Clear(0.0f, 0.15f, 0.3f, 1.0f);


		float amplitude = 1;
		float velocity = 0.5f;
		float sinTime = amplitude*sinf(velocity*time);
		float cosTime = amplitude*cosf(velocity*time);

		GLfloat radius = 3.0f;
		GLfloat camX = sinTime * radius;
		GLfloat camZ = cosTime * radius;
		cam.setForward(-cam.getPosition());
		cam.setPosition(glm::vec3(camX, 0, camZ));
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