
#include "Shader.h"

#include <fstream>
#include <sstream>
#include <iostream>

#include <glm\common.hpp>
#include <glm\gtc\type_ptr.hpp>


namespace sixday
{
	namespace render
	{
		Shader::Shader(const char* vertexPath, const char* fragmentPath, const char* geometoryPath)
		{
			std::ifstream vShaderFile;
			std::ifstream fShaderFile;
			std::ifstream gShaderFile;
			std::string vShaderCode;
			std::string fShaderCode;
			std::string gShaderCode;

			vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
			fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
			gShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

			try
			{
				vShaderFile.open(vertexPath);
				fShaderFile.open(fragmentPath);

				std::stringstream vstream, fstream;

				vstream << vShaderFile.rdbuf();
				vShaderFile.close();

				fstream << fShaderFile.rdbuf();
				fShaderFile.close();

				vShaderCode = vstream.str();
				fShaderCode = fstream.str();
			}
			catch (const std::ifstream::failure&)
			{
				std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
			}

			uint32 vertex, fragment, geometry;
			const char* vshader = vShaderCode.c_str();
			const char* fshader = fShaderCode.c_str();

			vertex = glCreateShader(GL_VERTEX_SHADER);
			glShaderSource(vertex, 1, &vshader, nullptr);
			glCompileShader(vertex);
			CheckCompileError(vertex, "Vertex Shader");

			fragment = glCreateShader(GL_FRAGMENT_SHADER);
			glShaderSource(fragment, 1, &fshader, nullptr);
			glCompileShader(fragment);
			CheckCompileError(fragment, "Fragment Shader");

			id = glCreateProgram();
			glAttachShader(id, vertex);
			glAttachShader(id, fragment);
			

			if (geometoryPath != nullptr)
			{
				try
				{
					gShaderFile.open(geometoryPath);
					std::stringstream gstream;
					gstream << gShaderFile.rdbuf();
					gShaderFile.close();
				}
				catch (const std::ifstream::failure&)
				{
					std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
				}

				const char* gshader = gShaderCode.c_str();
				geometry = glCreateShader(GL_GEOMETRY_SHADER);
				glShaderSource(geometry, 1, &gshader, nullptr);

				glCompileShader(geometry);
				CheckCompileError(geometry, "Geometry Shader");

				glAttachShader(id, geometry);
			}

			glLinkProgram(id);
			CheckCompileError(id, "Shader Program");

			glDeleteShader(vertex);
			glDeleteShader(fragment);
			if (geometoryPath != nullptr)
			{
				glDeleteShader(geometry);
			}
		}

		void Shader::SetBool(const std::string & name, bool value) const
		{
			glUniform1i(glGetUniformLocation(id, name.c_str()), (int)value);
		}

		void Shader::SetInt(const std::string & name, int value) const
		{
			glUniform1i(glGetUniformLocation(id, name.c_str()), value);
		}

		void Shader::SetFloat(const std::string & name, float value) const
		{
			glUniform1f(glGetUniformLocation(id, name.c_str()), value);
		}

		void Shader::SetFloat4(const std::string & name, float x, float y, float z, float w)
		{
			glUniform4f(glGetUniformLocation(id, name.c_str()), x, y, z, w);
		}

		void Shader::SetMatrix4(const std::string & name, glm::mat4 & mat)
		{
			glUniformMatrix4fv(glGetUniformLocation(id, name.c_str()), 1, GL_FALSE, glm::value_ptr(mat));
		}

		void Shader::SetVec2(const std::string & name, glm::vec2 & vec)
		{
			glUniform2fv(glGetUniformLocation(id, name.c_str()), 1, glm::value_ptr(vec));
		}

		void Shader::SetVec3(const std::string & name, glm::vec3 & vec)
		{
			glUniform3fv(glGetUniformLocation(id, name.c_str()), 1, glm::value_ptr(vec));
		}


		void Shader::CheckCompileError(uint32 shader, std::string type)
		{
			int success;
			char log[1024];
			if (type != "Shader Program")
			{
				glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
				if (!success)
				{
					glGetShaderInfoLog(shader, 1024, NULL, log);
					std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << log << std::endl;
				}
			}
			else
			{
				glGetProgramiv(shader, GL_LINK_STATUS, &success);
				if (!success)
				{
					glGetProgramInfoLog(shader, 1024, NULL, log);
					std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << log << std::endl;
				}
			}
		}
	}
}