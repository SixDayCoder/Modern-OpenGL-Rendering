#include <iostream>

#include "Component\Cube.h"
#include "RenderScene\RenderScene.h"
#include "Utilits\ResourcesUtilits.h"

using namespace sixday::render;
using namespace sixday::utilits;

int main()
{
	RenderScene scene(800, 600, "Test Window");
	
	ResourcesUtilits::LoadShader("basic_cube_shader", "basic_cube.vs", "basic_cube.fs");

	Cube cube;
	cube.Initialize();
	scene.AddComponent(cube.GetGuid(), cube);

	scene.Exec();
	return 0;
}