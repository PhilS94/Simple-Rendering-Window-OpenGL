#ifndef MESH_H
#define MESH_H

#include <glm/glm.hpp>
#include <GL/glew.h>
#include "obj_loader.h"
#include <vector>

class Vertex {
public:
	Vertex::Vertex(const glm::vec3& pos, const glm::vec2& uv, const glm::vec3& normal = glm::vec3(0,0,0)) {
		this->position = pos;
		this->uv = uv;
		this->normal = normal;
	}

	glm::vec3* Vertex::getPosition() { return &position; }
	glm::vec2* Vertex::getUV() { return &uv; }
	glm::vec3* Vertex::getNormal() { return &normal; }
private:
	glm::vec3 position;
	glm::vec2 uv;
	glm::vec3 normal;
};

enum MeshBufferPositions {
	POSITION_VB,
	UV_VB,
	INDEX_VB,	//Dont use Vertices more than twice, e.g. cube
	Normal_VB,
	NUM_BUFFERS
};

class Mesh {
public:
	Mesh(Vertex* vertices, unsigned int numberVertices, unsigned int* indices, unsigned int numIndices);
	Mesh(const std::string& fileName);
	void Draw();
	virtual ~Mesh();
private:
	GLuint vertexArrayObject;
	GLuint vertexArrayBuffers[NUM_BUFFERS];
	unsigned int drawCount;
	void InitMesh(const IndexedModel& model);
};


#endif 