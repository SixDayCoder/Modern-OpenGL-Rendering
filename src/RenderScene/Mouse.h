#ifndef SIXDAY_MOUESE_H_
#define SIXDAY_MOUESE_H_

#include "Public\PublicDefine.h"
#include <glad\glad.h>
#include <glfw\glfw3.h>

namespace sixday
{
	namespace render
	{
		class Mouse
		{
		private:

			static float m_fX;
			static float m_fY;
			static float m_fLastX;
			static float m_fLastY;
			static bool  m_bIsFirstMouseMove;
			static float m_fDeltaX;
			static float m_fDeltaY;

			static GLFWwindow* m_pWindow;

		public:

			static void SetWindow(GLFWwindow* window);

			static void SetX(float x) { m_fX = x; }
			static float X() { return m_fX; }

			static void SetY(float y) { m_fY = y; }
			static float Y() { return m_fY; }

			static void SetLastX(float x) { m_fLastX = x; }
			static float LastX() { return m_fLastX; }

			static void SetLastY(float y) { m_fLastY = y; }
			static float LastY() { return m_fLastY; }

			static float DeltaX() { return m_fDeltaX; }
			static float DeltaY() { return m_fDeltaY; }

			//监听mouse移动事件
			static void ListenMouseMoveEvent();

			//监听mouse滑轮事件
			static void ListenMouseScrollEvent();

			//监mouse按下事件
			static void ListenMousePressEvent();

			//监听mouse释放事件
			static void ListenMouseReleaseEvent();

		private:

			static void MouseMoveCallBack(GLFWwindow* window, double xoffset, double yoffset);

		};
	}
}

#endif // ! SIXDAY_MOUESE_H_
