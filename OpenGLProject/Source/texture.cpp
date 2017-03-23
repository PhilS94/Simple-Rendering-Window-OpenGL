#include "texture.h"
#include "stb_image.h"
#include <cassert>
#include <iostream>

//Load texture from file, depends on textureLoader, here std_iage
Texture::Texture(const std::string& fileName) {
	int width, heigth, numComponents;
	unsigned char* imageData = stbi_load((fileName).c_str(), &width, &heigth, &numComponents, 4);

	if (imageData == NULL) {
		std::cerr << "Texture loading failed at file " << fileName << std::endl;
	}
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, heigth, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageData);
	//0=mipmaps...
	stbi_image_free(imageData);
}

Texture::~Texture() {
	glDeleteTextures(1, &texture);
}

void Texture::Bind(unsigned int unit) {
	assert(unit >= 0 && unit <= 31);
	glActiveTexture(GL_TEXTURE + unit);
	glBindTexture(GL_TEXTURE_2D, texture);
}
