#include "Component\Cube.h"
#include "Resources\Shader.h"
#include "RenderScene\RenderScene.h"

namespace sixday
{
	namespace render
	{
		Cube::Cube() : DrawableComponent()
		{
			Initialize();
		}

		Cube::Cube(RenderScene & rRenderScene) : DrawableComponent(rRenderScene)
		{
			Initialize();
		}

		void Cube::BindData()
		{
			if (m_IsBindedData)
			{
				return;
			}

			float vertices[] = {
				// positions          // texture Coords 
				 0.5f, -0.5f,  0.5f,  0.0f, 1.0f,         
				 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
				 0.5f,  0.5f, -0.5f,  1.0f, 0.0f,
				 0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

				-0.5f, -0.5f,  0.5f,  1.0f, 1.0f,
				-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
				-0.5f,  0.5f, -0.5f,  0.0f, 0.0f,
				-0.5f, -0.5f, -0.5f,  1.0f, 0.0f,				 
			};

			uint32 indices[] = {
				//front
				0, 1, 2,
				0, 2, 3,
				//back
				4, 5, 6,
				4, 6, 7,
				//left
				4, 0, 3,
				4, 3, 7,
				//right
				1, 5, 6,
				1, 6, 2,
				//top
				4, 5, 1,
				4, 1, 0,
				//bottom
				7, 6, 2,
				7, 2, 3
			};

			glGenVertexArrays(1, &m_VAO);
			glBindVertexArray(m_VAO);

			glGenBuffers(1, &m_VBO);
			glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
			glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

			glGenBuffers(1, &m_IBO);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IBO);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, false, sizeof(float) * 5, (void*)(0));
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 2, GL_FLOAT, false, sizeof(float) * 5, (void*)(3 * sizeof(float)));

			glBindVertexArray(0);

			m_IsBindedData = true;
		}

		void Cube::Initialize()
		{
			DrawableComponent::Initialize();
		}

		void Cube::Draw(Shader & shader)
		{
			shader.Use();
			shader.SetMatrix4("model", m_Model);

			uint32 indices[] = { 1 };

			glBindVertexArray(m_VAO);
			glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNALED, indices);
			glBindVertexArray(0);

		}
	}
}