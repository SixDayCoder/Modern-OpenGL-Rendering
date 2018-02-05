#include <iostream>
#include "RenderScene\RenderScene.h"

using namespace sixday::render;

int main()
{
	RenderScene scene(800, 600, "Test Window");

	scene.Update();


	return 0;
}