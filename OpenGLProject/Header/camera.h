#ifndef  CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

class Camera {
public:
	Camera(glm::vec3 pos, float aspect, float fov, float zNear, float zFar);
	virtual ~Camera();
	//Getter
	glm::vec3 getPosition() { return position; }
	glm::vec3 getForward() { return forward; }
	glm::vec3 getUp() { return up; }
	glm::vec3 getRight() { return glm::cross(up, forward); }
	glm::mat4 getProjectionMatrix() { return projectionMatrix; }
	//Setter
	void setPosition(glm::vec3 pos) { this->position = pos; }
	void setForward(glm::vec3 forward) { this->forward = forward; }
	void setUp(glm::vec3 up) { this->up = forward; }
	glm::mat4 calculateViewMatrix();
	glm::mat4 calculateViewProjectionMatrix();
private:
	float aspect;
	float fov;
	float zNear;
	float zFar;
	glm::vec3 position;
	glm::vec3 forward;
	glm::vec3 up;
	glm::mat4 projectionMatrix;
};
#endif // ! CAMERA_H
