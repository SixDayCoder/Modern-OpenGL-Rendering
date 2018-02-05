#ifndef SIXDAY_CAMERA_H
#define SIXDAY_CAMERA_H

#include "Component\Component.h"
#include "glm\glm.hpp"
#include "glm\matrix.hpp"

namespace sixday
{
	namespace render
	{
		class RenderScene;

		class Camera : public Component
		{
		public:
			Camera(RenderScene& rRenderScene);
			Camera(RenderScene& rRenderScene, float fFieldOfView, float fAspect, float fNearPlane, float fFarPlane);
			virtual ~Camera();
			
			static const float DefaultFieldOfView;
			static const float DefaultAspect;
			static const float DefaultNearPlane;
			static const float DefatultFarPlane;

			const glm::vec3 Position()const { return m_Position; }
			const glm::vec3 Direction()const { return m_Direction; }
			const glm::vec3 Up()const { return m_Up; }
			const glm::vec3 Right()const { return m_Right; }

			float FieldOfView()const { return m_fFieldOfView; }
			float Aspect()const { return m_fAspect; }
			float NearPlane()const { return m_fNearPlane; }
			float FarPlane()const { return m_fFarPlane; }

			const glm::mat4 ViewMatrix()const { return m_ViewMatrix; }
			const glm::mat4 ProjectionMatrix()const { return m_ProjectionMatrix; }
			const glm::mat4 ViewProjectionMatrix()const { return m_ViewMatrix * m_ProjectionMatrix; }

			virtual void SetPosition(float x, float y, float z);
			virtual void SetPosition(const glm::vec3& pos);
			
		
		private:
			float m_fFieldOfView;
			float m_fAspect;
			float m_fNearPlane;
			float m_fFarPlane;

			glm::vec3 m_Position;
			glm::vec3 m_Direction;
			glm::vec3 m_Up;
			glm::vec3 m_Right;

			glm::mat4 m_ViewMatrix;
			glm::mat4 m_ProjectionMatrix;

			Camera(const Camera& rhs);
			Camera& operator=(const Camera& rhs);

		};
	}
}


#endif SIXDAY_CAMERA_H