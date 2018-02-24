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

		public:

			static Guid GetNextGuid();

		protected:

			Guid m_Guid;
			bool m_bIsEnable;
			RenderScene* m_pRenderScene;
		
		public:

			Component();
			Component(RenderScene& rRenderScene);
			virtual ~Component();

			Guid GetGuid() { return m_Guid; }
			bool Enable()const { return m_bIsEnable;  }
			void SetEnable(bool bEnable);

			RenderScene* GetRenderScene()const {  return m_pRenderScene;  }
			void SetRenderScene(RenderScene& rRenderScene);

			virtual void Initialize() {}
			virtual void Update(float fDeltaTime) {}

			virtual bool IsDrawableComponent() { return false; }

		private:

			Component(const Component& rhs);
			Component& operator=(const Component& rhs);

		};

	}
}


#endif // !SIXDAY_COMPONENT_H
