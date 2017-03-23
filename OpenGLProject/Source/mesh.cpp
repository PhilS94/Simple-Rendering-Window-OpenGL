#include "mesh.h"

Mesh::Mesh(Vertex* vertices, unsigned int numberVertices) {
	drawCount = numberVertices;
	glGenVertexArrays(1, &vertexArrayObject);
	glBindVertexArray(vertexArrayObject);

	glGenBuffers(NUM_BUFFERS, vertexArrayBuffers);
	glBindBuffer(GL_ARRAY_BUFFER, vertexArrayBuffers[POSITION_VB]); //Buffer is Array
	glBufferData(GL_ARRAY_BUFFER, numberVertices * sizeof(vertices[0]), vertices, GL_STATIC_DRAW); //Takes data from RAM to GPU (kind of...) //GPU Data will never be changed...
	glEnableVertexAttribArray(0);	//Tell there is one Attribut as Array
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0); //Use 0th Attribute, skip 0 Elements in Array and start with offset 0


	glBindVertexArray(0);
}

void Mesh::Draw() {
	glBindVertexArray(vertexArrayObject);
	glDrawArrays(GL_TRIANGLES, 0, drawCount);//Start at count 0, draw drawCount vertices
	glBindVertexArray(0);
}

Mesh::~Mesh() {
	glDeleteVertexArrays(1, &vertexArrayObject);
}
