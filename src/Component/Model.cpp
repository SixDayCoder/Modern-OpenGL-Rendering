#include "Component\Model.h"
#include "Component\Mesh.h"
#include "Resources\Shader.h"
#include "Camera\Camera.h"

#include <iostream>


namespace sixday
{
	namespace render
	{
		Model::Model() : DrawableComponent()
		{

		}

		void Model::LoadFromFile(const std::string & filePath)
		{
			assert(!filePath.empty());

			m_Meshes.clear();

			Assimp::Importer importer;

			const aiScene* scene = importer.ReadFile
			(
				filePath.c_str(),
				aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_FixInfacingNormals | aiProcess_JoinIdenticalVertices
			);
			
			assert(scene);

			if (scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
			{
				std::cout << "ERROR::ASSIMP::" << importer.GetErrorString() << std::endl;
				return;
			}

			ProcessNode(scene->mRootNode, scene);

		}

		void Model::Initialize()
		{
			for (auto it : m_Meshes)
			{
				it.Initialize();
			}
		}

		void Model::BindData()
		{
			for (auto it : m_Meshes)
			{
				it.BindData();
			}
		}

		void Model::Draw(Shader & shader)
		{
			assert(m_pCamera);

			shader.Use();
			shader.SetMatrix4("view", m_pCamera->ViewMatrix());
			shader.SetMatrix4("projection", m_pCamera->ProjectionMatrix());

			for (auto it : m_Meshes)
			{
				it.Draw(shader);
			}
		}

		void Model::Update(float fDeltaTime)
		{
			for (auto it : m_Meshes)
			{
				it.Update(fDeltaTime);
			}
		}

		void Model::ProcessNode(aiNode * node, const aiScene * scene)
		{
			for (uint32 i = 0; i < node->mNumMeshes; ++i)
			{
				aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
				ProcessMesh(mesh, scene);
			}

			for (uint32 i = 0; i < node->mNumChildren; ++i)
			{
				ProcessNode(node->mChildren[i], scene);
			}
		}

		void Model::ProcessMesh(aiMesh * mesh, const aiScene * scene)
		{
			std::vector<Vertex> vertices;
			std::vector<uint32> indices;
			std::vector<Texture2D> textures;

			//vertices
			for (uint32 i = 0; i < mesh->mNumVertices; ++i)
			{
				Vertex v;

				glm::vec3 pos(0.0f, 0.0f, 0.0f);
				if (mesh->HasPositions())
				{
					pos.x = mesh->mVertices[i].x;
					pos.y = mesh->mVertices[i].y;
					pos.z = mesh->mVertices[i].z;
				}
				v.position = pos;
				

				glm::vec3 normal(0.0f, 0.0f, 0.0f);
				if (mesh->HasNormals())
				{
					normal.x = mesh->mNormals[i].x;
					normal.y = mesh->mNormals[i].y;
					normal.z = mesh->mNormals[i].z;
				}
				v.normal = normal;

				glm::vec2 tcoord(0.0f, 0.0f);
				if (mesh->HasTextureCoords(0))
				{
					tcoord.x = mesh->mTextureCoords[0][i].x;
					tcoord.y = mesh->mTextureCoords[0][i].y;
				}
				v.texcoord = tcoord;

				glm::vec3 tangent(0.0f, 0.0f, 0.0f);
				glm::vec3 bitangent(0.0f, 0.0f, 0.0f);
				if (mesh->HasTangentsAndBitangents())
				{					
					tangent.x = mesh->mTangents[i].x;
					tangent.y = mesh->mTangents[i].y;
					tangent.z = mesh->mTangents[i].z;
					
					bitangent.x = mesh->mBitangents[i].x;
					bitangent.y = mesh->mBitangents[i].y;
					bitangent.z = mesh->mBitangents[i].z;
					
				}

				v.tangent = tangent;
				v.bitangent = bitangent;

				vertices.push_back(v);

			}

			//indices
			for (uint32 i = 0; i < mesh->mNumFaces; ++i)
			{
				aiFace face = mesh->mFaces[i];
				for (uint32 j = 0; j < face.mNumIndices; ++j)
				{
					indices.push_back(face.mIndices[j]);
				}

			}

			//textures

			Mesh m;
			
			m.SetVertices(vertices);
			m.SetIndices(indices);
			m.BindData();

			m_Meshes.push_back(m);
		}
	}
}