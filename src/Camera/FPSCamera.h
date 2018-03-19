#ifndef SIXDAY_FPSCAMERA_H
#define SIXDAY_FPSCAMERA_H

#include "Camera\Camera.h"

namespace sixday
{
	namespace render
	{
		enum CameraMove
		{
			MOVE_FRONT = 0, //前进
			MOVE_BACK = 1,  //后退
			MOVE_LEFT = 2,  //左平移
			MOVE_RIGHT = 3,  //右平移
			MOVE_MAX = 4
		};

		class FPSCamera : public Camera
		{
		public:

			static const float DefaultYaw;

			static const float DefaultPitch;

			static const float DefaultSensitivity;

			static const float DefaultMoveSpeed;

			FPSCamera(const glm::vec3& pos, const glm::vec3& worldUp);
			FPSCamera(const glm::vec3& pos, const glm::vec3& worldUp, float fFieldOfView, float fNearPlane, float fFarPlane);
			virtual ~FPSCamera();

			virtual void Update(float fDeltaTime)override;

			float Yaw() { return m_fYaw; }
			void  SetYaw(float fYaw) { m_fYaw = fYaw; }

			float Pitch() { return m_fPitch; }
			void  SetPitch(float fPitch) { m_fPitch = fPitch; }

			float Sensitivity() { return m_fSensitivity; }
			void  SetSensitivity(float fSensity) { m_fSensitivity = fSensity; }

			float MoveSpeed() { return m_fMoveSpeed; }
			void  SetMoveSpeed(float fMoveSpeed) { m_fMoveSpeed = fMoveSpeed; }

		protected:

			virtual void UpdateDirections()override;
			
		private:

			float m_fYaw;       //偏航角
			float m_fPitch;     //俯仰角
			float m_fSensitivity;   //灵敏度
			float m_fMoveSpeed;    //移动速度

			void UpdateMove(float fDeltaTime);

			void UpdateView();

			void Move(CameraMove dir, float fDeltaTime);

		};
	}
}

#endif 
