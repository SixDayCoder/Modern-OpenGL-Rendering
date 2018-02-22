#ifndef  SIXDAY_RENDER_SCENE_H
#define  SIXDAY_RENDER_SCENE_H

#include "Public\PublicDefine.h"
#include <glad\glad.h>
#include <glfw\glfw3.h>
#include <string>
#include <map>

namespace sixday
{
	namespace render
	{

		#define GLM_FORCE_RADIANS
		
		class Component;

		class RenderScene
		{
		private:

			float m_fAspect;
			uint32 m_nWidth;
			uint32 m_nHeight;
			std::string m_strTitle;
			GLFWwindow *m_pWindow;
			std::map<Guid, Component*> m_ComponentMap;

			void CalcAspect();


		public:

			RenderScene(uint32 width, uint32 height, const std::string& title);

			const GLFWwindow* Window()const { return m_pWindow; }
			void SetWidth(int width);
			const uint32 Width()const { return m_nWidth; }
			void SetHeight(int height);
			const uint32 Height()const { return m_nHeight; }
			const float Aspect()const { return m_fAspect; }

			const Component& GetComponentByGuid(Guid guid)const;
			Component& GetComponentByGuid(Guid guid);

			void Update();
		};
	}
}


#endif // ! SIXDAY_RENDER_SCENE_H
