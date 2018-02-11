#include "Texture2D.h"
#include <image\stb_image.h>
#include <iostream>

namespace sixday
{
	const GLint Texture2D::DefaultWrapS = GL_REPEAT;
	const GLint Texture2D::DefaultWrapT = GL_REPEAT;
	const GLint Texture2D::DefaultMinFilter = GL_LINEAR;
	const GLint Texture2D::DefaultMaxFilter = GL_LINEAR;


	void Texture2D::GenTexture(GLint nWrapS/* = GL_REPEAT */, GLint nWrapT/* = GL_REPEAT */, GLint nMinFilter/* = GL_LINEAR */, GLint nMaxFilter/* = GL_LINEAR */)
	{
		glGenTextures(1, &id);
		glBindTexture(GL_TEXTURE_2D, id);


		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, nWrapS);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, nWrapT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, nMinFilter);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, nMaxFilter);

		glBindTexture(GL_TEXTURE_2D, 0);
	}

	void Texture2D::LoadFromFile(const char * path)
	{
		glBindTexture(GL_TEXTURE_2D, id);

		int width, height, channels;
		byte *data = stbi_load(path, &width, &height, &channels, 0);
		if (data)
		{
			GLenum format = (channels == 4) ? GL_RGBA : GL_RGB;
			//target mipmap_levels internal_format w h always_0 outernal_formal outernal_format image_data
			glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);

			this->width = width;
			this->height = height;
		}
		else
		{
			std::cout << "Load " << path << " Error!" << std::endl;
		}
		
		glBindTexture(GL_TEXTURE_2D, 0);
		stbi_image_free(data);
	}

}

