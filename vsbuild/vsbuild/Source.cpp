#include <iostream>
#include <filesystem>
#include "RenderScene\RenderScene.h"
#include "Utilits\FileUtilits.h"

using namespace sixday::render;
using namespace sixday::utilits;

int main()
{
	RenderScene scene(800, 600, "Test Window");

	scene.Exec();
	return 0;
}