#ifndef  SIXDAY_RENDER_SCENE_H
#define  SIXDAY_RENDER_SCENE_H

#include "Public\PublicDefine.h"
#include "Public\Timer.h"
#include "RenderScene\Mouse.h"
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
		class Camera;

		class RenderScene
		{
		private:
			
			using ComponentMap = std::map<Guid, Component*>;

			Timer m_Clock;

			GLFWwindow *m_pWindow;
			Camera* m_pCamera;

			float  m_fAspect;
			uint32 m_nWidth;
			uint32 m_nHeight;
			std::string m_strTitle;
			
			ComponentMap m_ComponentMap;

			void CalcAspect();


			void UpdateComponent(float fEplasedTime);

			void RenderComponent();

		public:

			RenderScene(uint32 width, uint32 height, const std::string& title);

			const GLFWwindow* Window()const { return m_pWindow; }

			void SetWidth(int width);
			const uint32 Width()const { return m_nWidth; }

			void SetHeight(int height);
			const uint32 Height()const { return m_nHeight; }

			void SetCamera(Camera* camera);
			const Camera* GetCamera()const { return m_pCamera; }

			const float Aspect()const { return m_fAspect; }

			void AddComponent(Guid guid, Component& rComponent);
			const Component* GetComponentByGuid(Guid guid)const;

			void Exec();
		};
	}
}


#endif // ! SIXDAY_RENDER_SCENE_H
