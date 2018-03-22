#ifndef  SIXDAY_MODEL_H_
#define  SIXDAY_MODEL_H_

#include "Public\PublicDefine.h"
#include "Resources\Texture2D.h"
#include "Component\Mesh.h"

#include <string>


#include <assimp\Importer.hpp>
#include <assimp\scene.h>
#include <assimp\postprocess.h>

namespace sixday
{
	namespace render
	{
		class Model : public DrawableComponent
		{
		public:

			Model();

			void LoadFromFile(const std::string& filePath);

			virtual void Initialize()override;

			virtual void Draw(Shader& shader)override;

			virtual void Update(float fDeltaTime)override;

		private:

			std::vector<Mesh> m_Meshes;

			//Start----------����ģ�͵ĸ�������---------------Start//
			void ProcessNode(aiNode* node, const aiScene* scene);

			void ProcessMesh(aiMesh* mesh, const aiScene* scene);
			//End------------����ģ�͵ĸ�������-----------------End//
		};
	}
}

#endif // ! SIXDAY_MODEL_H_
