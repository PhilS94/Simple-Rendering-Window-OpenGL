#include "gameobject.h"
#include <iostream>

GameObject::GameObject(Mesh mesh, Shader shader, Texture texture) {
	this->transform = Transform();
	this->mesh = mesh;
	this->shader = shader;
	this->texture = texture;
}

void GameObject::Update() {
		float time=0.1f;
		float amplitude = 2;
		float velocity = 0.5f;
		float sinTime = amplitude*sinf(velocity*time);
		float cosTime = amplitude*cosf(velocity*time);

		//GLfloat radius = 10.0f;
		//cam.setPosition(glm::vec3(sinTime * radius, 0, cosTime * radius));
		//cam.setForward(-cam.getPosition());
		(*mesh.getTransform()).rotate(0.001f, glm::vec3(0, 1, 0));
		std::cout << (*mesh.getTransform()).getRotation()[1] << std::endl;
		//Test Mouseinput
		//int xpos, ypos;
		//SDL_GetMouseState(&xpos, &ypos);
		//transform.setRotation(transform.getRotation() + glm::vec3((float)ypos / 100000.0, (float)xpos / 100000.0, 0));
		//SDL_WarpMouseInWindow(display.getWindow(), display.getWidth() / 2, display.getHeigth() / 2);

		shader.Bind();
		texture.Bind(0);
		shader.Update(*mesh.getTransform(), cam);
		mesh.Draw();
}

