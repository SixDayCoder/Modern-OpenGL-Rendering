#ifndef SIXDAY_CUBE_H_
#define SIXDAY_CUBE_H_

#include "Component\DrawableComponent.h"

namespace sixday
{
	namespace render
	{
		class RenderScene;

		class Cube : public DrawableComponent
		{
		public:

			Cube();

			Cube(RenderScene& rRenderScene);

			virtual void Initialize()override;

			virtual void Draw(Shader& shader) override;

		private:

			virtual void BindData()override;
		};
	}
}


#endif //!SIXDAY_CUBE_H_