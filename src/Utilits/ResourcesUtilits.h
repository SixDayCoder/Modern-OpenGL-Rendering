#ifndef  SIXDAY_RESOURCES_UTILTIS_H
#define  SIXDAY_RESOURCES_UTILTIS_H

#include "Public\PublicDefine.h"
#include <map>
#include <string>
#include "Resources\Shader.h"
#include "Resources\Texture2D.h"
#include <filesystem>


namespace sixday
{
	namespace utilits
	{
		class ResourcesUtilits
		{
		public:


			using ShaderResourcesMap = std::map<std::string, sixday::render::Shader>;

			using Texture2DResourcesMap = std::map<std::string, sixday::render::Texture2D>;

		private:

			static ShaderResourcesMap ShaderMap;

			static Texture2DResourcesMap Texture2DMap;

			using Texture2D = sixday::render::Texture2D;

			using Shader = sixday::render::Shader;

		public:

			static void LoadShader(const std::string& name, const char* vShaderFile, const char* fShaderFile, const char* gShaderFile = nullptr);

			static Shader GetShader(const std::string& name);

			static void LoadTexture2D(const std::string& name, const char* file);

			static Texture2D GetTexture2D(const std::string& name);
		};
	}
}

#endif // ! SIXDAY_RESOURCES_UTILTIS_H
