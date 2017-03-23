#include <iostream>
#include "display.h"
#include "mesh.h"
#include "Shader.h"
#include "texture.h"
#include "transform.h"
#include <glm/glm.hpp>

int main(int argc, char** argv) {
	Display display(800, 600, "Nice Display");
	//X geht von ´links nach rechts -1 bis 1
	// Y geht von unten nach oben -1 bis 1

	Vertex vertices[] = { Vertex(glm::vec3(-0.5,-0.5,0),glm::vec2(0,0)),
							Vertex(glm::vec3(0,0.5,0),glm::vec2(0.5,1.0)),
							Vertex(glm::vec3(0.5,-0.5,0),glm::vec2(1.0,0))
		//Vertex(glm::vec3(-1,1,0),glm::vec2(0,0)),
		//Vertex(glm::vec3(-1,0,0),glm::vec2(0.5,1.0)),
		//Vertex(glm::vec3(0,1,0),glm::vec2(1.0,0)) 
	};

	Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));
	Shader shader("./../data/shaders/basicShader");
	Texture texture("./../data/textures/metal.jpg");
	Transform transform;

	float time = 0.0f;

	while (!display.getIsClosed()) {

		display.Clear(0.0f, 0.15f, 0.3f, 1.0f);

		float amplitude = 0.5f;
		float velocity = 0.5f;
		float sinTime = amplitude*sinf(velocity*time);
		float cosTime = amplitude*cosf(velocity*time);

		transform.getPosition().x = sinTime;
		transform.getPosition().y = sinTime;
		transform.getRotation().z = 0.5f*time;
		transform.getRotation().y = 0.2f*time;
		
		shader.Bind();
		texture.Bind(0);
		shader.Update(transform);
		mesh.Draw();

		display.Update();
		time += 0.001f;
	}
	return 0;
}