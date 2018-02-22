#include "Camera\Camera.h"
#include "Public\Utilits.h"
#include "RenderScene\RenderScene.h"
#include "glm\common.hpp"
#include "glm\gtc\matrix_transform.hpp"
#include "glm\gtc\type_ptr.hpp"

namespace sixday
{
	namespace render
	{
		const float Camera::DefaultFieldOfView = static_cast<float>(PI_DIV_4);
		const float Camera::DefaultNearPlane = 0.1f;
		const float Camera::DefatultFarPlane = 100.0f;

		Camera::Camera(RenderScene & rRenderScene)
			   :Component(rRenderScene),
				m_fFieldOfView(DefaultFieldOfView),
				m_fNearPlane(DefaultNearPlane),
				m_fFarPlane(DefatultFarPlane)
		{

		}

		Camera::Camera(RenderScene & rRenderScene, float fFieldOfView, float fNearPlane, float fFarPlane)
			   :Component(rRenderScene),
				m_fFieldOfView(fFieldOfView),
				m_fNearPlane(fNearPlane),
				m_fFarPlane(fFarPlane)
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

		void Camera::Initialize()
		{
			m_fFieldOfView = DefaultFieldOfView;
			m_fNearPlane = DefaultNearPlane;
			m_fFarPlane = DefatultFarPlane;
		}

		void Camera::Update(Timer& timer)
		{

		}

		void Camera::UpdateMatrix()
		{
			glm::lookAt(m_Position, m_Position + m_Direction, m_Up);
			glm::perspective(m_fFieldOfView, m_pRenderScene->Aspect(), m_fNearPlane, m_fFarPlane);
		}

		void Camera::UpdateDirections()
		{

		}

	}
}