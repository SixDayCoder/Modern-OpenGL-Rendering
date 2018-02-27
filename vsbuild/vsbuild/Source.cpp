#include <iostream>

#include "Component\Cube.h"
#include "RenderScene\RenderScene.h"
#include "Utilits\ResourcesUtilits.h"
#include "Camera\Camera.h"

using namespace sixday::render;
using namespace sixday::utilits;

RenderScene scene(800, 600, "Test Window");

int main()
{
	ResourcesUtilits::LoadShader("basic_cube_shader", "basic_cube.vs", "basic_cube.fs");

	Camera camera(scene);

	Cube cube;
	cube.Initialize();
	//cube.SetRotation(glm::vec3(5.0f, 45.0f, 3.0f));
	scene.AddComponent(cube.GetGuid(), cube);

	scene.Exec();
	return 0;
}