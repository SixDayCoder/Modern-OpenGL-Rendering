#include "RenderScene\Mouse.h"
#include <cassert>
#include <iostream>

namespace sixday
{
	namespace render
	{
		//�����ڳ�Ա��Ϊ�����ص��ǲ��������Ϊ
		//������Ϊ���ó�Ա������ʱ���Ĭ�ϴ���һ��thisָ�뵼�»ص��Ĳ�����ƥ��
		//�������Ĺؼ�����this��������,����static

		float Mouse::m_fX = 0.0f;
		float Mouse::m_fY = 0.0f;
		float Mouse::m_fLastX = 0.0f;
		float Mouse::m_fLastY = 0.0f;
		bool  Mouse::m_bIsFirstMouseMove = true;
		float Mouse::m_fDeltaX = 0.0f;
		float Mouse::m_fDeltaY = 0.0f;
		bool  Mouse::m_bIsMoving = false;

		GLFWwindow* Mouse::m_pWindow = nullptr;

		void Mouse::SetWindow(GLFWwindow * window)
		{
			assert(window);
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

		void Mouse::ClearMouseState()
		{
			m_bIsMoving = false;
		}

		void Mouse::MouseMoveCallBack(GLFWwindow* window, double xpos, double ypos)
		{
			m_bIsMoving = true;
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