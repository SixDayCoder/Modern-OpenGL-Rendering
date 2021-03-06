#ifndef SIXDAY_TEXTURE2D_H
#define SIXDAY_TEXTURE2D_H


#include "Public\PublicDefine.h"

#include <glad\glad.h>
#include <glfw\glfw3.h>

namespace sixday
{
	
	namespace render
	{
		enum class Texture2DType
		{
			TEXTURE_2D_TYPE_ALBEDO   = 0, //��������ͼ
			TEXTURE_2D_TYPE_SPECULAR = 1, //�߹ⷴ����ͼ
			TEXTURE_2D_TYPE_NORMAL   = 2, //������ͼ
			TEXTURE_2D_TYPE_BUMP     = 3, //��͹��ͼ
			TEXTURE_2D_TYPE_SHADOW   = 4, //��Ӱ��ͼ
			TEXTURE_2D_TYPE_MAX    = 10
		};

		class Texture2D
		{
		private:

			uint32 m_nId;
			uint32 m_nWidth;
			uint32 m_nHeight;
			bool   m_bIsGenerated;

		public:

			Texture2D() :
				m_nId(0),
				m_nWidth(0),
				m_nHeight(0),
				m_bIsGenerated(false)
			{
			}

			static const GLint DefaultWrapS;
			static const GLint DefaultWrapT;
			static const GLint DefaultMinFilter;
			static const GLint DefaultMaxFilter;

			uint32 Id()const { return m_nId; }
			uint32 Width()const { return m_nWidth; }
			uint32 Height()const { return m_nHeight; }

			void GenTexture(GLint nWrapS = DefaultWrapS, GLint nWrapT = DefaultWrapT, GLint nMinFilter = DefaultMinFilter, GLint nMaxFilter = DefaultMaxFilter);

			void LoadFromFile(const char* path);
		};
	}
}

#endif
