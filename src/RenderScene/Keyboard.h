#ifndef  SIXDAY_MOUSE_H_
#define  SIXDAY_MOUSE_H_

#include "Public\PublicDefine.h"
#include <glad\glad.h>
#include <glfw\glfw3.h>

namespace sixday
{
	namespace render
	{
		class RenderScene;

		enum KeyCode
		{
			KEY_W,
			KEY_A,
			KEY_S,
			KEY_D,
			KEY_MAX = 256
		};

		enum KeyState
		{
			KEY_PRESS = 1,
			KEY_RELEASE = 2,
		};

		class KeyBoard
		{		

		private:

			static GLFWwindow* m_pWindow;

			static uint32 m_KeyCode[KeyCode::KEY_MAX];

		public:

			static void SetWindow(GLFWwindow* window);

			//监听键盘按下事件
			static void ListenPushKeyDown();

			//某按键按下
			static bool IsKeyPress(KeyCode key);

			//每一帧结束清空按键状态
			static void ClearKeyState();

			//每一帧更新按键的状态
			static void UpdateKeyState();
		};
	}
}

#endif // ! SIXDAY_MOUSE_H_
