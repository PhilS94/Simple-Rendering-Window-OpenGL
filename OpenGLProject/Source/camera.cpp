#include "camera.h"
#include <iostream>


Camera::Camera(glm::vec3 pos, float aspect, float fov, float zNear, float zFar) {
	this->position = pos;
	this->aspect = aspect;
	this->fov = fov;
	this->zNear = zNear;
	this->zFar = zFar;
	forward = glm::vec3(0, 0, 1);
	up = glm::vec3(0, 1, 0);
	projectionMatrix = glm::perspective(fov, aspect, zNear, zFar);
}

Camera::~Camera() {

}

glm::mat4 Camera::calculateViewMatrix() {
	glm::mat4 viewMatrix = glm::lookAt(position, position + forward, up);
	return viewMatrix;
}

glm::mat4 Camera::calculateViewProjectionMatrix() {
	return projectionMatrix * calculateViewMatrix();
}
