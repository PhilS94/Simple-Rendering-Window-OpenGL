#ifndef MESH_H
#define MESH_H

#include <glm/glm.hpp>
#include <GL/glew.h>

class Vertex {
public:
	Vertex::Vertex(const glm::vec3& pos) {
		this->position = pos;
	}

	glm::vec3* Vertex::getPosition() {
		return &position;
	}
private:
	glm::vec3 position;
};

enum MeshBufferPositions {
	POSITION_VB,
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
