#ifndef SIXDAY_SHADER_H
#define SIXDAY_SHADER_H

#include "Public\PublicDefine.h"

#include <glm\common.hpp>

#include <glad\glad.h>
#include <glfw\glfw3.h>


namespace sixday
{
	namespace render
	{
		class Shader
		{
		public:

			Shader(const char* vertexPath, const char* fragmentPath, const char* geometoryPath = nullptr);

			uint32 ID()const { return id; }

			void Use() { glUseProgram(id); }

			void SetBool(const std::string &name, bool value) const;

			void SetInt(const std::string &name, int value) const;

			void SetFloat(const std::string &name, float value) const;

			void SetFloat4(const std::string& name, float x, float y, float z, float w)const;

			void SetMatrix4(const std::string& name, const glm::mat4& mat)const;

			void SetVec2(const std::string& name, const glm::vec2& vec)const;

			void SetVec3(const std::string& name, const glm::vec3& vec)const;

		private:

			uint32 id;

			void CheckCompileError(uint32 shader, std::string type);

		};
	}
}





#endif 