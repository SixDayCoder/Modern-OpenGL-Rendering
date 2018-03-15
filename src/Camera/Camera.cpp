#include "Camera\Camera.h"
#include "RenderScene\RenderScene.h"
#include "Utilits\MathUtilits.h"
#include "glm\common.hpp"
#include "glm\gtc\matrix_transform.hpp"
#include "glm\gtc\type_ptr.hpp"

namespace sixday
{
	namespace render
	{
		const float Camera::DefaultFieldOfView = utilits::MathUtilits::PI_DIV_4;
		const float Camera::DefaultNearPlane = 0.1f;
		const float Camera::DefatultFarPlane = 1000.0f;

		Camera::Camera(const glm::vec3& pos, const glm::vec3& worldUp)
			   :Component(),
				m_fFieldOfView(DefaultFieldOfView),
				m_fNearPlane(DefaultNearPlane),
				m_fFarPlane(DefatultFarPlane)
		{
			m_Position = pos;
			m_Up = worldUp;
		}

		Camera::Camera(const glm::vec3& pos, const glm::vec3& wolrdUp, float fFieldOfView, float fNearPlane, float fFarPlane)
			   :Component(),
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
			Component::Initialize();
		}

		void Camera::Update(float fDeltaTime)
		{
			//根据deltatime调整相机的位置,角度
			UpdateDirections();

			//根据当前相机的位置、角度等调整ViewMatirx和ProjectionMatrix
			UpdateMatrix();
		}

		void Camera::SetRenderScene(RenderScene * pRenderScene)
		{
			assert(pRenderScene);
			m_pRenderScene = pRenderScene;
		}

		void Camera::UpdateMatrix()
		{
			m_ViewMatrix = glm::lookAt(m_Position, m_Position + m_Direction, m_Up);
			m_ProjectionMatrix = glm::perspective(m_fFieldOfView, m_pRenderScene->Aspect(), m_fNearPlane, m_fFarPlane);
		}

		void Camera::UpdateDirections()
		{
			//TODO : 临时Update
			m_Direction = glm::vec3(0, 0, 1.0f);

			m_Direction = glm::normalize(m_Direction);
			m_Right = glm::normalize(glm::cross(m_Direction, glm::vec3(0, 1, 0)));
			m_Up = glm::normalize(glm::cross(m_Right, m_Direction));
		}

	}
}