#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtc/quaternion.hpp>

class Transform {
public:
	Transform(const glm::vec3& pos = glm::vec3(), const glm::quat rot = glm::quat(), const glm::vec3& scale = glm::vec3(1.0f, 1.0f, 1.0f)) {
		this->position = pos;
		this->rotation = rot;
		this->scale = scale;
	}

	//~Transform();

	//Getter
	glm::vec3& getPosition() { return position; };
	glm::quat& getRotation() { return rotation; };
	glm::vec3& getScale() { return scale; };

	void translate(glm::vec3 translationVector);
	void rotate(float angle, glm::vec3 axis);
	void scaleBy(glm::vec3 scaleVector);
	glm::mat4 calculateTransformationMatrix();

private:
	glm::vec3 position;
	glm::quat rotation;
	glm::vec3 scale;
};
#endif //TRANSFORM_H