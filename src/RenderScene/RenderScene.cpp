#include "RenderScene.h"
#include "Component\Component.h"
#include "Component\DrawableComponent.h"
#include <cassert>
#include <iostream>

namespace sixday
{
	namespace render
	{
		void RenderScene::CalcAspect()
		{		
			m_fAspect = static_cast<float>(m_nWidth) / static_cast<float>(m_nHeight);
		}

		RenderScene::RenderScene(uint32 width, uint32 height, const std::string & title)
					:m_nWidth(width),
					 m_nHeight(height),
					 m_strTitle(title)
		{
			glfwInit();
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

			m_pWindow = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

			assert(m_pWindow);

			glfwMakeContextCurrent(m_pWindow);

			assert(gladLoadGLLoader((GLADloadproc)glfwGetProcAddress) > 0);
	
			CalcAspect();
		}

		void RenderScene::SetWidth(int width)
		{
			m_nWidth = width;
			CalcAspect();
		}

		void RenderScene::SetHeight(int height)
		{
			m_nHeight = height;
			CalcAspect();
		}

		void RenderScene::AddComponent(Guid guid, Component & rComponent)
		{
			if (m_ComponentMap.find(guid) != m_ComponentMap.end())
			{
				return;
			}		
			rComponent.SetRenderScene(*this);
			m_ComponentMap.insert(std::make_pair(guid, &rComponent));
		}

		const Component & RenderScene::GetComponentByGuid(Guid guid) const
		{
			auto it = m_ComponentMap.find(guid);
			if (it != m_ComponentMap.end())
			{
				assert(it->second);
				return *it->second;
			}
			assert(false);
		}

		Component & RenderScene::GetComponentByGuid(Guid guid)
		{
			auto it = m_ComponentMap.find(guid);
			if (it != m_ComponentMap.end())
			{
				assert(it->second);
				return *it->second;
			}
			assert(false);
		}

		void RenderScene::Exec()
		{
			clock.Start();
			while (!glfwWindowShouldClose(m_pWindow))
			{

				float fEplasedTime = static_cast<float>(clock.ElapsedTime());
				
				for (ComponentMap::iterator it = m_ComponentMap.begin(); it != m_ComponentMap.end(); ++it)
				{
					Component* component = it->second;
					if (component->Enable())
					{
						component->Update(fEplasedTime);
					}
				}

				glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
				glClear(GL_COLOR_BUFFER_BIT);

				for (ComponentMap::iterator it = m_ComponentMap.begin(); it != m_ComponentMap.end(); it++)
				{
					Component* component = it->second;
					if (component->Enable() && component->IsDrawableComponent())
					{
						DrawableComponent* dComponent = dynamic_cast<DrawableComponent*>(component);
						//dComponent->Draw();
					}
				}

				glfwSwapBuffers(m_pWindow);
				glfwPollEvents();
			}
		}
	}
}
