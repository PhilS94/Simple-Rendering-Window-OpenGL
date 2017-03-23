#include "transform.h"

Transform::Transform(const glm::vec3& pos, const glm::vec4& rot, const glm::vec3& scale) {
	this->pos = pos;
	this->rot = rot;
	this->scale = scale;
}

Transform::~Transform() {

}