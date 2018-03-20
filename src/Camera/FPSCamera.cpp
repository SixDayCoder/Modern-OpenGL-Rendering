#include "Camera\FPSCamera.h"
#include "RenderScene\Mouse.h"
#include "RenderScene\Keyboard.h"
#include "Utilits\MathUtilits.h"

#include <iostream>

namespace sixday
{
	namespace render
	{
		const float FPSCamera::DefaultYaw = 90.0f;
		
		const float FPSCamera::DefaultPitch = 0.0f;

		const float FPSCamera::DefaultSensitivity = 0.1f;

		const float FPSCamera::DefaultMoveSpeed = 3.0f;

		FPSCamera::FPSCamera(const glm::vec3 & pos, const glm::vec3 & worldUp)
			      :Camera(pos, worldUp)
		{
			m_fYaw = DefaultYaw;
			m_fPitch = DefaultPitch;
			m_fSensitivity = DefaultSensitivity;
			m_fMoveSpeed = DefaultMoveSpeed;

			UpdateDirections();
		}

		FPSCamera::FPSCamera(const glm::vec3 & pos, const glm::vec3 & worldUp, float fFieldOfView, float fNearPlane, float fFarPlane)
			      :Camera(pos, worldUp)
		{
			m_fYaw = DefaultYaw;
			m_fPitch = DefaultPitch;
			m_fSensitivity = DefaultSensitivity;
			m_fMoveSpeed = DefaultMoveSpeed;

			UpdateDirections();
		}

		FPSCamera::~FPSCamera()
		{

		}

		void FPSCamera::Update(float fDeltaTime)
		{
			UpdateView();

			UpdateMove(fDeltaTime);

			UpdateDirections();

			UpdateMatrix();
		}

		void FPSCamera::UpdateDirections()
		{
			glm::vec3 front;
			front.x = cos(glm::radians(m_fYaw)) * cos(glm::radians(m_fPitch));
			front.y = sin(glm::radians(m_fPitch));
			front.z = sin(glm::radians(m_fYaw)) * cos(glm::radians(m_fPitch));

			m_Direction = glm::normalize(front);
			m_Right = glm::normalize(glm::cross(m_Direction, glm::vec3(0, 1, 0)));
			m_Up = glm::normalize(glm::cross(m_Right, m_Direction));
		}

		void FPSCamera::UpdateMove(float fDeltaTime)
		{
			if (KeyBoard::IsKeyPress(KeyCode::KEY_W))
			{
				Move(CameraMove::MOVE_FRONT, fDeltaTime);
			}

			if (KeyBoard::IsKeyPress(KeyCode::KEY_A))
			{
				Move(CameraMove::MOVE_LEFT, fDeltaTime);
			}

			if (KeyBoard::IsKeyPress(KeyCode::KEY_S))
			{
				Move(CameraMove::MOVE_BACK, fDeltaTime);
			}

			if (KeyBoard::IsKeyPress(KeyCode::KEY_D))
			{
				Move(CameraMove::MOVE_RIGHT, fDeltaTime);
			}
		}

		void FPSCamera::UpdateView()
		{
			float xoffset = Mouse::DeltaX() * m_fSensitivity;
			float yoffset = Mouse::DeltaY() * m_fSensitivity;

			m_fYaw += xoffset;
			m_fPitch += yoffset;

			glm::clamp(m_fPitch, -89.0f, 89.0f);

			UpdateDirections();			
		}

		void FPSCamera::Move(CameraMove dir, float fDeltaTime)
		{
			float distance = fDeltaTime * m_fMoveSpeed;

			if (dir == CameraMove::MOVE_FRONT)
			{
				m_Position += m_Direction * distance;
			}

			if (dir == CameraMove::MOVE_BACK)
			{
				m_Position -= m_Direction * distance;
			}

			if (dir == CameraMove::MOVE_LEFT)
			{
				m_Position -= m_Right * distance;
			}

			if (dir == CameraMove::MOVE_RIGHT)
			{
				m_Position += m_Right * distance;
			}
		}

	}
}