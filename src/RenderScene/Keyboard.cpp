#include "RenderScene\Keyboard.h"
#include <cassert>
#include <iostream>
namespace sixday
{
	namespace render
	{
		GLFWwindow* KeyBoard::m_pWindow = nullptr;

		uint32 KeyBoard::m_KeyCode[KeyCode::KEY_MAX];


		void KeyBoard::SetWindow(GLFWwindow * window)
		{
			assert(window);
			m_pWindow = window;
		}
		void KeyBoard::ListenPushKeyDown()
		{
			assert(m_pWindow);
			memset(m_KeyCode, 0, sizeof(m_KeyCode));
		}

		bool KeyBoard::IsKeyPress(KeyCode key)
		{
			assert(0 <= key && key < KeyCode::KEY_MAX);
			return m_KeyCode[key] == KeyState::KEY_PRESS;
		}

		void KeyBoard::ClearKeyState()
		{
			memset(m_KeyCode, 0, sizeof(m_KeyCode));
		}

		void KeyBoard::UpdateKeyState()
		{
			if (glfwGetKey(m_pWindow, GLFW_KEY_W) == GLFW_PRESS)
			{
				m_KeyCode[KeyCode::KEY_W] = KeyState::KEY_PRESS;
			}

			if (glfwGetKey(m_pWindow, GLFW_KEY_A) == GLFW_PRESS)
			{
				m_KeyCode[KeyCode::KEY_A] = KeyState::KEY_PRESS;
			}

			if (glfwGetKey(m_pWindow, GLFW_KEY_S) == GLFW_PRESS)
			{
				m_KeyCode[KeyCode::KEY_S] = KeyState::KEY_PRESS;
			}

			if (glfwGetKey(m_pWindow, GLFW_KEY_D) == GLFW_PRESS)
			{
				m_KeyCode[KeyCode::KEY_D] = KeyState::KEY_PRESS;
			}
		}
	}
}