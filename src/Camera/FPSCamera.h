#ifndef SIXDAY_FPSCAMERA_H
#define SIXDAY_FPSCAMERA_H

#include "Camera\Camera.h"

namespace sixday
{
	namespace render
	{
		class FPSCamera : public Camera
		{
		public:

			FPSCamera(const glm::vec3& pos, const glm::vec3& worldUp);
			FPSCamera(const glm::vec3& pos, const glm::vec3& worldUp, float fFieldOfView, float fNearPlane, float fFarPlane);
			virtual ~FPSCamera();

			virtual void Update(float fDeltaTime)override;

		protected:

			virtual void UpdateDirections()override;

			virtual void UpdateMatrix()override;

		};
	}
}

#endif 
