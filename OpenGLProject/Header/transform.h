#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

class Transform {
public:
	Transform(const glm::vec3& pos = glm::vec3(), const glm::vec4& rot = glm::vec4(), const glm::vec3& scale = glm::vec3(1.0f, 1.0f, 1.0f));
	virtual ~Transform();

	glm::mat4 GetTransformation() const {
		glm::mat4 translateMatrix = glm::translate(pos);
		glm::mat4 rotXMatrix = glm::rotate(rot.x, glm::vec3(1, 0, 0));
		glm::mat4 rotYMatrix = glm::rotate(rot.y, glm::vec3(0, 1, 0));
		glm::mat4 rotZMatrix = glm::rotate(rot.z, glm::vec3(0, 0, 1));
		glm::mat4 scaleMatrix = glm::scale(scale);

		glm::mat4 rotationMatrix = rotZMatrix *rotYMatrix*rotXMatrix;
		return translateMatrix*rotationMatrix *scaleMatrix;
	}

	//Getter
	glm::vec3& getPosition() { return pos; };
	glm::vec3& getRotation() { return rot; };
	glm::vec3& getScale() { return scale; };

	//Setter
	void getPosition(glm::vec3& pos) { this->pos = pos; };
	void getRotation(glm::vec3& rot) { this->rot = rot; };
	void getScale(glm::vec3& scale) { this->scale = scale; };
private:
	glm::vec3 pos;
	glm::vec3 rot;
	glm::vec3 scale;
};
#endif //TRANSFORM_H