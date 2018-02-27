#include "RenderScene\Mouse.h"

namespace sixday
{
	namespace render
	{
		//将类内成员作为函数回调是不合理的行为
		//这是因为调用成员函数的时候会默认传递一个this指针导致回调的参数不匹配
		//解决问题的关键是让this不起作用,例如static

		float Mouse::m_fX = 0.0f;
		float Mouse::m_fY = 0.0f;
		float Mouse::m_fLastX = 0.0f;
		float Mouse::m_fLastY = 0.0f;
		bool  Mouse::m_bIsFirstMouseMove = true;
		float Mouse::m_fDeltaX = 0.0f;
		float Mouse::m_fDeltaY = 0.0f;

		GLFWwindow* Mouse::m_pWindow = nullptr;

		void Mouse::SetWindow(GLFWwindow * window)
		{
			m_pWindow = window;
		}

		void Mouse::ListenMouseMoveEvent()
		{
			glfwSetCursorPosCallback(m_pWindow, MouseMoveCallBack);
		}

		void Mouse::ListenMouseScrollEvent()
		{
		}

		void Mouse::ListenMousePressEvent()
		{
		}

		void Mouse::ListenMouseReleaseEvent()
		{
		}

		void Mouse::MouseMoveCallBack(GLFWwindow* window, double xpos, double ypos)
		{
			if (m_bIsFirstMouseMove)
			{
				m_fLastX = (float)xpos;
				m_fLastY = (float)ypos;
				m_bIsFirstMouseMove = false;
			}

			m_fDeltaX = (float)xpos - m_fLastX;
			m_fDeltaY = m_fLastY - (float)ypos;
		
			m_fLastX = (float)xpos;
			m_fLastY = (float)ypos;

		}
	}
}