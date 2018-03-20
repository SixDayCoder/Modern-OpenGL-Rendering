#include "RenderScene.h"
#include "Component\Component.h"
#include "Component\DrawableComponent.h"
#include "Camera\Camera.h"
#include "Utilits\ResourcesUtilits.h"
#include "RenderScene\Mouse.h"
#include "RenderScene\Keyboard.h"
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

		void RenderScene::UpdateComponent(float fEplasedTime)
		{
			KeyBoard::UpdateKeyState();

			for (ComponentMap::iterator it = m_ComponentMap.begin(); it != m_ComponentMap.end(); ++it)
			{
				Component* component = it->second;
				
				if ( (component != nullptr) && component->Enable())
				{
					component->Update(fEplasedTime);
				}
			}

			if (m_pCamera != nullptr)
			{
				m_pCamera->Update(fEplasedTime);
			}
			
			//每一帧的结束清除Key的状态
			KeyBoard::ClearKeyState();
			//每一帧结束清除Mouse的状态
			Mouse::ClearMouseState();
		}

		void RenderScene::RenderComponent()
		{
			for (ComponentMap::iterator it = m_ComponentMap.begin(); it != m_ComponentMap.end(); it++)
			{
				Component* component = it->second;
				if (component != nullptr)
				{
					if (component->Enable() && component->IsDrawableComponent())
					{
						DrawableComponent* dComponent = dynamic_cast<DrawableComponent*>(component);
						Shader shader = sixday::utilits::ResourcesUtilits::GetShader("basic_cube_shader");
						if (dComponent != nullptr)
						{
							dComponent->Draw(shader);
						}
					}
				}
			}
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

			m_Clock.CleanUp();

			Mouse::SetWindow(m_pWindow);
			Mouse::ListenMouseMoveEvent();

			KeyBoard::SetWindow(m_pWindow);
			KeyBoard::ListenPushKeyDown();

			glfwSetInputMode(m_pWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
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

		void RenderScene::SetCamera(Camera * camera)
		{
			assert(camera);
			m_pCamera = camera;
			m_pCamera->SetRenderScene(this);
		}

		void RenderScene::AddComponent(Guid guid, Component & rComponent)
		{
			if (m_ComponentMap.find(guid) != m_ComponentMap.end())
			{
				return;
			}		

			if (m_pCamera == nullptr)
			{
				return;
			}

			rComponent.SetRenderScene(*this);
			if (rComponent.IsDrawableComponent())
			{
				DrawableComponent& dComponent = dynamic_cast<DrawableComponent&>(rComponent);
				dComponent.SetCamera(m_pCamera);
			}

			m_ComponentMap.insert(std::make_pair(guid, &rComponent));
		}

		const Component* RenderScene::GetComponentByGuid(Guid guid) const
		{
			auto it = m_ComponentMap.find(guid);
			if (it != m_ComponentMap.end())
			{
				assert(it->second);
				return it->second;
			}
			return nullptr;
		}

		void RenderScene::Exec()
		{
			m_Clock.Start();
			while (!glfwWindowShouldClose(m_pWindow))
			{
				m_Clock.Tick();
				float fEplasedTime = static_cast<float>(m_Clock.ElapsedTime());

				glEnable(GL_DEPTH);
				glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
				glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
				
				UpdateComponent(fEplasedTime);
				RenderComponent();

				glfwSwapBuffers(m_pWindow);
				glfwPollEvents();
			}
		}
	}
}
