#include "Component\Mesh.h"
#include "Resources\Shader.h"
#include "Camera\Camera.h"

#include <glm\gtc\matrix_transform.hpp>

namespace sixday
{
	namespace render
	{
		Mesh::Mesh():DrawableComponent()
		{
			m_VAO = 0;
			m_VBO = 0;
			m_IBO = 0;

			m_Vertices.clear();
			m_Indices.clear();

			m_bIsEnable = true;
			m_IsBindedData = false;

			m_Position = glm::vec3(0.0f, 0.0f, 0.0f);
			m_Scale    = glm::vec3(1.0f, 1.0f, 1.0f);
			m_Rotation = glm::vec3(0.0f, 0.0f, 0.0f);

			m_pCamera = nullptr;
		}

		void Mesh::BindData()
		{
			if (m_IsBindedData)
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


			m_IsBindedData = true;
		}

		void Mesh::Draw(Shader & shader)
		{
			BindData();

			shader.Use();
			shader.SetMatrix4("model", m_Model);

			glBindVertexArray(m_VAO);
			glDrawElements(GL_TRIANGLES, m_Indices.size(), GL_UNSIGNED_INT, 0);
			glBindVertexArray(0);
		}

		void Mesh::Update(float fDeltaTime)
		{
			UpdateModelMatrix();
		}

		void Mesh::UpdateModelMatrix()
		{
			glm::mat4 model;

			model = glm::translate(model, m_Position);
			model = glm::scale(model, m_Scale);
			model = glm::rotate(model, glm::radians(m_Rotation.x), glm::vec3(1, 0, 0));
			model = glm::rotate(model, glm::radians(m_Rotation.y), glm::vec3(0, 1, 0));
			model = glm::rotate(model, glm::radians(m_Rotation.z), glm::vec3(0, 0, 1));

			m_Model = model;
		}
	}
}