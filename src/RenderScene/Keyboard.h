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

		class KeyBoard
		{
		private:

			static GLFWwindow* m_pWindow;

		public:

			void SetWindow(GLFWwindow* window);
		};
	}
}

#endif // ! SIXDAY_MOUSE_H_
