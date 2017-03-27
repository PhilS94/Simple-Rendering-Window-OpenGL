#include "mesh.h"
#include <vector>

Mesh::Mesh(const std::string& fileName) {
	model = OBJModel(fileName).ToIndexedModel();
	InitMesh(model);
}

Mesh::Mesh(Vertex* vertices, unsigned int numVertices, unsigned int* indices, unsigned int numIndices) {
	for (unsigned int i = 0; i < numVertices; i++) {
		model.positions.push_back(*vertices[i].getPosition());
		model.texCoords.push_back(*vertices[i].getUV());
		model.normals.push_back(*vertices[i].getNormal());
	}

	for (unsigned int i = 0; i < numIndices; i++) {
		model.indices.push_back(indices[i]);
	}

	InitMesh(model);
}

Mesh::Mesh(const IndexedModel model) {
	InitMesh(model);
}

void Mesh::InitMesh(const IndexedModel& model) {
	this->transform = Transform();
	//drawCount = numberVertices;
	drawCount = model.indices.size();
	glGenVertexArrays(1, &vertexArrayObject);
	glBindVertexArray(vertexArrayObject);

	//Generate certain amount of Buffers
	glGenBuffers(NUM_BUFFERS, vertexArrayBuffers);

	//Position Buffer
	glBindBuffer(GL_ARRAY_BUFFER, vertexArrayBuffers[POSITION_VB]); //Buffer is Array
	glBufferData(GL_ARRAY_BUFFER, model.positions.size() * sizeof(model.positions[0]), &model.positions[0], GL_STATIC_DRAW); //Takes data from RAM to GPU (kind of...) //GPU Data will never be changed...
	glEnableVertexAttribArray(0);	//Tell there is one Attribut as Array
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0); //Use 0th Attribute, skip 0 Elements in Array and start with offset 0

	//UV Buffer
	glBindBuffer(GL_ARRAY_BUFFER, vertexArrayBuffers[UV_VB]); //Buffer is Array
	glBufferData(GL_ARRAY_BUFFER, model.positions.size() * sizeof(model.texCoords[0]), &model.texCoords[0], GL_STATIC_DRAW); //Takes data from RAM to GPU (kind of...) //GPU Data will never be changed...
	glEnableVertexAttribArray(1);	//Tell there is one Attribut as Array
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0); //Use 0th Attribute, skip 0 Elements in Array and start with offset 0

	//Normal Buffer
	glBindBuffer(GL_ARRAY_BUFFER, vertexArrayBuffers[Normal_VB]); //Buffer is Array
	glBufferData(GL_ARRAY_BUFFER, model.normals.size() * sizeof(model.normals[0]), &model.normals[0], GL_STATIC_DRAW); //Takes data from RAM to GPU (kind of...) //GPU Data will never be changed...
	glEnableVertexAttribArray(2);	//Tell there is one Attribut as Array
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, 0); //Use 0th Attribute, skip 0 Elements in Array and start with offset 0

	//Indices Buffer
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vertexArrayBuffers[INDEX_VB]); //Buffers Elements are references to other Buffers
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, model.indices.size() * sizeof(model.indices[0]), &model.indices[0], GL_STATIC_DRAW); //Takes data from RAM to GPU (kind of...) //GPU Data will never be changed...

	//Transform
	glBindVertexArray(0);
	glBindVertexArray(1);
}
void Mesh::Draw() {
	glBindVertexArray(vertexArrayObject);

	glDrawElements(GL_TRIANGLES, drawCount, GL_UNSIGNED_INT, 0); //Start at count 0, draw drawCount vertices
		//glDrawArrays(GL_TRIANGLES, 0, drawCount);//Start at count 0, draw drawCount vertices
	glBindVertexArray(0);
}

Mesh::~Mesh() {
	glDeleteVertexArrays(1, &vertexArrayObject);
}
