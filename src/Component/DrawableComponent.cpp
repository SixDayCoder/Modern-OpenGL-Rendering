#include "Component\DrawableComponent.h"
#include "Resources\Shader.h"
#include "RenderScene\RenderScene.h"
#include "glm\gtc\matrix_transform.hpp"

namespace sixday
{
	namespace render
	{
		DrawableComponent::DrawableComponent() : Component()
		{
			Initialize();
		}

		DrawableComponent::DrawableComponent(RenderScene & rRenderScene) : Component(rRenderScene)
		{
			Initialize();
		}

		void DrawableComponent::Update(float fEplasedTime)
		{
			UpdateModelMatrix();
		}

		void DrawableComponent::Initialize()
		{
			Component::Initialize();

			m_VAO = 0;
			m_VBO = 0;
			m_IBO = 0;

			m_Position = glm::vec3(0, 0, 0);
			m_Rotation = glm::vec3(0, 0, 0);
			m_Scale = glm::vec3(1, 1, 1);

			m_IsBindedData = false;

		}
		void DrawableComponent::UpdateModelMatrix()
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