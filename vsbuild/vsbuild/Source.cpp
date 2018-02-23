#include <iostream>
#include <filesystem>
#include "RenderScene\RenderScene.h"
#include "Utilits\FileUtilits.h"
#include <ctime>
using namespace sixday::render;
using namespace sixday::utilits;

int main()
{
	//RenderScene scene(800, 600, "Test Window");

	//scene.Exec();

	std::time_t rawtime;
	struct std::tm *localtm;

	std::time(&rawtime);
	localtm = std::localtime(&rawtime);

	std::cout << std::string(std::asctime(localtm)) << std::endl;

	return 0;
}