#ifndef MESH_H
#define MESH_H

#include <glm/glm.hpp>
#include <GL/glew.h>
#include <vector>

class Vertex {
public:
	Vertex::Vertex(const glm::vec3& pos, const glm::vec2& uv) {
		this->position = pos;
		this->uv = uv;
	}

	glm::vec3* Vertex::getPosition() {
		return &position;
	}

	glm::vec2* Vertex::getUV() {
		return &uv;
	}
private:
	glm::vec3 position;
	glm::vec2 uv;
};

enum MeshBufferPositions {
	POSITION_VB,
	UV_VB,
	NUM_BUFFERS
};

class Mesh {
public:
	Mesh(Vertex* vertices, unsigned int numberVertices);
	void Draw();
	virtual ~Mesh();
private:
	GLuint vertexArrayObject;
	GLuint vertexArrayBuffers[NUM_BUFFERS];
	unsigned int drawCount;
};


#endif 
