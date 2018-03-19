#include "Camera\FPSCamera.h"
#include "RenderScene\Mouse.h"
#include "RenderScene\Keyboard.h"

namespace sixday
{
	namespace render
	{
		FPSCamera::FPSCamera(const glm::vec3 & pos, const glm::vec3 & worldUp)
			      :Camera(pos, worldUp)
		{
		}

		FPSCamera::FPSCamera(const glm::vec3 & pos, const glm::vec3 & worldUp, float fFieldOfView, float fNearPlane, float fFarPlane)
			      :Camera(pos, worldUp)
		{
		}

		FPSCamera::~FPSCamera()
		{

		}

		void FPSCamera::Update(float fDeltaTime)
		{
		}

		void FPSCamera::UpdateDirections()
		{
		}

		void FPSCamera::UpdateMatrix()
		{
		}

	}
}