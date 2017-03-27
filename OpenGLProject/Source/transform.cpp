#include "transform.h"

glm::mat4 Transform::calculateTransformationMatrix() {
	glm::mat4 translateMatrix = glm::translate(position);
	glm::mat4 rotationMatrix = glm::toMat4(rotation);
	glm::mat4 scaleMatrix = glm::scale(scale);
	return translateMatrix*rotationMatrix *scaleMatrix;
}

void Transform::translate(glm::vec3 translationVector) {
	this->position += translationVector;
}

void Transform::rotate(float angle, glm::vec3 axis) {
	this->rotation *= glm::angleAxis(angle, axis);
}

void Transform::scaleBy(glm::vec3 scaleVector) {
	this->scale *= scale;
}