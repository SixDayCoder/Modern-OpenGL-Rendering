#include "RenderScene\Keyboard.h"
#include <cassert>
namespace sixday
{
	namespace render
	{
		GLFWwindow* KeyBoard::m_pWindow = nullptr;

		void KeyBoard::SetWindow(GLFWwindow * window)
		{
			assert(window);
			m_pWindow = window;
		}
	}
}