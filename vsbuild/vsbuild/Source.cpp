#include <iostream>

#include "Component\Cube.h"
#include "RenderScene\RenderScene.h"

using namespace sixday::render;

int main()
{
	RenderScene scene(800, 600, "Test Window");


	Cube cube;
	cube.Initialize();
	scene.AddComponent(cube.GetGuid(), cube);

	scene.Exec();
	return 0;
}