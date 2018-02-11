#ifndef SIXDAY_SHADER_H
#define SIXDAY_SHADER_H

#include "Public\Utilits.h"

#include <glm\common.hpp>

#include <glad\glad.h>
#include <glfw\glfw3.h>


namespace sixday
{

	class Shader
	{
	public:

		Shader(const char* vertexPath, const char* fragmentPath);

		uint32 ID()const { return id; }
		

		void Use() { glUseProgram(id); }

		void SetBool(const std::string &name, bool value) const;

		void SetInt(const std::string &name, int value) const;

		void SetFloat(const std::string &name, float value) const;

		void SetFloat4(const std::string& name, float x, float y, float z, float w);

		void SetMatrix4(const std::string& name, glm::mat4& mat);

		void SetVec2(const std::string& name, glm::vec2& vec);

		void SetVec3(const std::string& name, glm::vec3& vec);

	private:

		uint32 id;

		void CheckCompileError(uint32 shader, std::string type);

	};
}





#endif 