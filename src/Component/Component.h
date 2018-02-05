#ifndef SIXDAY_COMPONENT_H
#define SIXDAY_COMPONENT_H

#include "Public\PublicDefine.h"

namespace sixday
{
	namespace render
	{
		class RenderScene;

		class Component
		{

		protected:

			bool m_bIsEnable;
			RenderScene* m_pRenderScene;
		
		public:
			Component();
			Component(RenderScene& rRenderScene);
			virtual ~Component();

			bool Enable()const { return m_bIsEnable;  }
			void SetEnable(bool bEnable);

			RenderScene* GetRenderScene()const {  return m_pRenderScene;  }
			void SetRenderScene(RenderScene& rRenderScene);

		private:

			Component(const Component& rhs);
			Component& operator=(const Component& rhs);

		};

	}
}


#endif // !SIXDAY_COMPONENT_H
