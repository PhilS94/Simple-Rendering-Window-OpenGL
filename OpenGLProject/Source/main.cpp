#include <iostream>
#include "display.h"
#include "mesh.h"

int main(int argc, char** argv) {
	Display display(800, 600, "Nice Display");
	//X geht von ´links nach rechts -1 bis 1
	// Y geht von unten nach oben -1 bis 1

	Vertex vertices[] = {	Vertex((glm::vec3(-0.5,-0.5,0))),
							Vertex(glm::vec3(0,0.5,0)),
							Vertex(glm::vec3(0.5,-0.5,0)),
							Vertex((glm::vec3(-1,1,0))),
							Vertex((glm::vec3(-1,0,0))),
							Vertex(glm::vec3(0,1,0)) };

	Mesh mesh(vertices,sizeof(vertices)/sizeof(vertices[0]));

	while (!display.getIsClosed()) {

		display.Clear(0.0f,0.15f,0.3f,1.0f);
		mesh.Draw();
		display.Update();
	}
	return 0;
}