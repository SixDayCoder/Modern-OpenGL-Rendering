#include "RenderScene.h"
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

			if (m_pWindow == nullptr)
			{
				std::cout << "Faild to create GLFW window" << std::endl;
				glfwTerminate();
			}

			glfwMakeContextCurrent(m_pWindow);

			if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
			{
				std::cout << "Faild to initailize GLAD" << std::endl;
				glfwTerminate();
			}

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

		void RenderScene::Update()
		{
			while (!glfwWindowShouldClose(m_pWindow))
			{
				glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
				glClear(GL_COLOR_BUFFER_BIT);


				glfwSwapBuffers(m_pWindow);
				glfwPollEvents();
			}
		}
	}
}
