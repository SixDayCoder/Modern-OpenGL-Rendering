#include "Camera\Camera.h"
#include "glm\common.hpp"

namespace sixday
{
	namespace render
	{
		const float Camera::DefaultAspect = 0.0f;
		const float Camera::DefaultFieldOfView = PI_DIV_4;
		const float Camera::DefaultNearPlane = 0.1f;
		const float Camera::DefatultFarPlane = 100.0f;

		Camera::Camera(RenderScene & rRenderScene)
			   :Component(rRenderScene)
		{

		}

		Camera::Camera(RenderScene & rRenderScene, float fFieldOfView, float fAspect, float fNearPlane, float fFarPlane)
		{
		}

		Camera::~Camera()
		{
		}
		
		void Camera::SetPosition(float x, float y, float z)
		{
			m_Position = glm::vec3(x, y, z);
		}

		void Camera::SetPosition(const glm::vec3 & pos)
		{
			m_Position = pos;
		}

		Camera::Camera(const Camera & rhs)
		{
		}

		Camera & Camera::operator=(const Camera & rhs)
		{
			return *this;
		}
	}
}