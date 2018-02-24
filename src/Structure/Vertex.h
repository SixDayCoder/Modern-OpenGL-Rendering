#ifndef  SIXDAY_VERTEX_H_
#define  SIXDAY_VERTEX_H_

#include <glm\common.hpp>

namespace sixday
{
	namespace render
	{
		struct Vertex
		{
			glm::vec3 position;
			glm::vec2 texcoord;
			glm::vec3 normal;
			glm::vec3 tangent;
			glm::vec3 bitangent;

			Vertex(float f1, float f2, float f3, float f4, float f5) :
				  position(f1, f2, f3),
				  texcoord(f4, f5),
				  normal(0,0,0),
				  tangent(0,0,0),
				  bitangent(0,0,0)
			{

			}

		};
	}
}




#endif // ! SIXDAY_VERTEX_H_
