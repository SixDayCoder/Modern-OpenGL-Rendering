#ifndef  SIXDAY_MESH_H_
#define  SIXDAY_MESH_H_

#include "Component\DrawableComponent.h"
#include <glad\glad.h>
#include <glfw\glfw3.h>

namespace sixday
{
	namespace render
	{
		class Mesh : public DrawableComponent
		{
		public:

			Mesh();

			virtual void BindData()override;

			virtual void Draw(Shader& shader)override;

			virtual void Update(float fDeltaTime)override;

			virtual void UpdateModelMatrix()override;
		};

	}
}

#endif // ! SIXDAY_MESH_H_
