#include "Component\Cube.h"
#include "RenderScene\RenderScene.h"

namespace sixday
{
	namespace render
	{
		Cube::Cube() : DrawableComponent()
		{
			Initialize();
		}

		Cube::Cube(RenderScene & rRenderScene) : DrawableComponent(rRenderScene)
		{
			Initialize();
		}

		void Cube::BindData()
		{
			if (m_IsBindedData)
			{
				return;
			}
		}
		void Cube::Initialize()
		{
			DrawableComponent::Initialize();
		}
		void Cube::Draw(Shader & shader)
		{

		}
	}
}