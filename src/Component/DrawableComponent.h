#ifndef SIXDAY_DRAWABLE_COMPONENT_H
#define SIXDAY_DRAWABLE_COMPONENT_H

#include "Component\Component.h"
#include "Structure\Vertex.h"

#include <glm\common.hpp>
#include <glm\gtc\type_ptr.hpp>
#include <vector>

namespace sixday
{
	namespace render
	{
		class Shader;
		class RenderScene;
		class Camera;

		class DrawableComponent : public Component
		{
		public:

			DrawableComponent();

			DrawableComponent(RenderScene& rRenderScene);

			void SetPosition(const glm::vec3& pos) { m_Position = pos; }
			void SetPosition(float x, float y, float z) { m_Position = glm::vec3(x, y, z); }
			glm::vec3 GetPosition()const { return m_Position; }

			void SetRotation(const glm::vec3& rotation) { m_Rotation = rotation; }
			void SetRotation(float xAngle, float yAngle, float zAngle) { m_Rotation = glm::vec3(xAngle, yAngle, zAngle); }
			glm::vec3 GetRotation()const { return m_Rotation; }

			void SetScale(const glm::vec3& scale) { m_Scale = scale; }
			void SetScale(float xScale, float yScale, float zScale) { m_Scale = glm::vec3(xScale, yScale, zScale); }
			glm::vec3 GetScale()const { return m_Scale; }

			void SetModelMatrix(const glm::mat4& model) { m_Model = model; }
			glm::mat4 GetModleMatrix()const { return m_Model; }

			void SetCamera(Camera* camera);
			Camera* GetCamera()const { return m_pCamera; }

			virtual void Draw(Shader& shader) {}

			virtual bool IsDrawableComponent()override { return true; }

			virtual void Update(float fEplasedTime) override;

			virtual void Initialize()override;

			virtual void BindData() {};

			virtual void UpdateModelMatrix();

		protected:

			uint32 m_VAO;
			uint32 m_VBO;
			uint32 m_IBO;

			glm::vec3 m_Position;//Î»ÖÃ
			glm::vec3 m_Rotation;//Ðý×ª
			glm::vec3 m_Scale;//·ÅËõ

			glm::mat4 m_Model;

			bool m_IsBindedData;

			std::vector<Vertex> m_Vertices;
			std::vector<uint32> m_Indices;

			Camera* m_pCamera;
		};
	}
}

#endif