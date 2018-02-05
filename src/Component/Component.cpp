
#include "Component\Component.h"

namespace sixday
{
	namespace render
	{
		Component::Component()
				  :m_pRenderScene(nullptr),
				   m_bIsEnable(true)
		{
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

		Component::Component(const Component & rhs)
		{
		}

		Component & Component::operator=(const Component & rhs)
		{
			// TODO: insert return statement here
			return *this;
		}
	}
}