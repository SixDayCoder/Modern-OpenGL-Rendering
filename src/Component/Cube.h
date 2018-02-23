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

			Cube() : DrawableComponent(){}

			Cube(RenderScene& rRenderScene);

			virtual void Draw(Shader& shader) override;
		};
	}
}


#endif //!SIXDAY_CUBE_H_