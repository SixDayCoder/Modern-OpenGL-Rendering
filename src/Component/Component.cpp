
#include "Component\Component.h"

namespace sixday
{
	namespace render
	{
		Component::Component()
				  :m_pRenderScene(nullptr),
				   m_bIsEnable(true)
		{
			m_Guid = GetNextGuid();
		}

		Component::Component(RenderScene& rRenderScene)
			      :m_pRenderScene(&rRenderScene),
			       m_bIsEnable(true)
		{

		}

		Component::~Component()
		{
			if (m_pRenderScene != nullptr)
			{
				m_pRenderScene = nullptr;
			}
		}

		void Component::SetEnable(bool bEnable)
		{
			m_bIsEnable = bEnable;
		}

		void Component::SetRenderScene(RenderScene& rRenderScene)
		{
			m_pRenderScene = &rRenderScene;
		}

		Guid Component::GetNextGuid()
		{
			time_type now = std::chrono::time_point_cast<microseconds>(std::chrono::high_resolution_clock::now());
			return now.time_since_epoch().count();
		}
	}
}