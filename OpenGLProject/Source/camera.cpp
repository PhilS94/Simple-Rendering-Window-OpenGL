#include "camera.h"


Camera::Camera(glm::vec3 pos, float fov, float aspect, float zNear, float zFar) {
	this->position = pos;
	this->fov = fov;
	this->aspect = aspect;
	this->zNear = zNear;
	this->zFar = zFar;
	forward = glm::vec3(0, 0, 1);
	up = glm::vec3(0, 1, 0);
	perspectiveMatrix = glm::perspective(fov, aspect, zNear, zFar);
}

Camera::~Camera() {

}

glm::mat4 Camera::calculateViewMatrix() {
	glm::mat4 viewMatrix = //perspectiveMatrix * 
									glm::lookAt(position, position + forward, up);
	return viewMatrix;
}