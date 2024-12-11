#pragma once

#include "stb_image.h"

#include "Shader.h"
#include "Mesh.h"

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <vector>

class Model
{
public:
	Model(char* path);
	void Draw(Shader shader);

private:
	void loadModel(std::string path);
	void processNode(aiNode* node, const aiScene* scene);
	Mesh processMesh(aiMesh* mesh, const aiScene* scene);
	std::vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string typeName);
	unsigned int TextureFromFile(const char* path, const std::string& direcctory, bool gama = false);
private:
	std::vector<Mesh> meshes;
	std::vector<Texture> textures_loaded;
	std::string directory;
};

