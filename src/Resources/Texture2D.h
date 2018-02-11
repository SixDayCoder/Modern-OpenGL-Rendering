#ifndef SIXDAY_TEXTURE2D_H
#define SIXDAY_TEXTURE2D_H


#include "Public\Utilits.h"

#include <glad\glad.h>
#include <glfw\glfw3.h>

namespace sixday
{
	
	class Texture2D
	{
	private:

		uint32 id;
		uint32 width;
		uint32 height;

	public:

		static const GLint DefaultWrapS;
		static const GLint DefaultWrapT;
		static const GLint DefaultMinFilter;
		static const GLint DefaultMaxFilter;

		uint32 Id()const { return id; }
		uint32 Width()const { return width; }
		uint32 Height()const { return height; }

		void GenTexture(GLint nWrapS = DefaultWrapS, GLint nWrapT = DefaultWrapT, GLint nMinFilter = DefaultMinFilter, GLint nMaxFilter = DefaultMaxFilter);

		void LoadFromFile(const char* path);
	};
}

#endif
