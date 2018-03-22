#include "Component\Cube.h"
#include "Resources\Shader.h"
#include "RenderScene\RenderScene.h"
#include "Camera\Camera.h"

namespace sixday
{
	namespace render
	{
		Cube::Cube() : DrawableComponent()
		{
		}

		Cube::Cube(RenderScene & rRenderScene) : DrawableComponent(rRenderScene)
		{
		}

		void Cube::BindData()
		{
			if (m_bIsBindedData)
			{
				return;
			}

		
			glGenVertexArrays(1, &m_VAO);
			glBindVertexArray(m_VAO);

			glGenBuffers(1, &m_VBO);
			glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
			glBufferData(GL_ARRAY_BUFFER, m_Vertices.size() * sizeof(Vertex), &m_Vertices[0], GL_STATIC_DRAW);

			glGenBuffers(1, &m_IBO);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IBO);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_Indices.size() * sizeof(uint32), &m_Indices[0], GL_STATIC_DRAW);

			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(offsetof(Vertex, position)));
			glEnableVertexAttribArray(0);

			glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(offsetof(Vertex, texcoord)));
			glEnableVertexAttribArray(1);

			glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(offsetof(Vertex, normal)));
			glEnableVertexAttribArray(2);

			glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(offsetof(Vertex, tangent)));
			glEnableVertexAttribArray(3);

			glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(offsetof(Vertex, bitangent)));
			glEnableVertexAttribArray(4);

			glBindVertexArray(0);

			m_bIsBindedData = true;
		}

		void Cube::Initialize()
		{
			DrawableComponent::Initialize();

			//position //texcooord
			m_Vertices.push_back(Vertex( 0.5f, -0.5f,  0.5f, 0.0f, 1.0f));
			m_Vertices.push_back(Vertex( 0.5f,  0.5f,  0.5f, 1.0f, 1.0f));
			m_Vertices.push_back(Vertex( 0.5f,  0.5f, -0.5f, 1.0f, 0.0f));
			m_Vertices.push_back(Vertex( 0.5f, -0.5f, -0.5f, 0.0f, 0.0f));
			m_Vertices.push_back(Vertex(-0.5f, -0.5f,  0.5f, 1.0f, 1.0f));
			m_Vertices.push_back(Vertex(-0.5f,  0.5f,  0.5f, 0.0f, 1.0f));
			m_Vertices.push_back(Vertex(-0.5f,  0.5f, -0.5f, 0.0f, 0.0f));
			m_Vertices.push_back(Vertex(-0.5f, -0.5f, -0.5f, 1.0f, 0.0f));

			m_Indices = {
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

			BindData();

		}

		void Cube::Draw(Shader & shader)
		{
			BindData();

			assert(m_pCamera);

			shader.Use();
			shader.SetMatrix4("model", m_Model);
			shader.SetMatrix4("view", m_pCamera->ViewMatrix());
			shader.SetMatrix4("projection", m_pCamera->ProjectionMatrix());

			glBindVertexArray(m_VAO);
			glDrawElements(GL_TRIANGLES, m_Indices.size(), GL_UNSIGNED_INT, 0);
			glBindVertexArray(0);

		}
	}
}