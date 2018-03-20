#include <iostream>

#include "Component\Cube.h"
#include "RenderScene\RenderScene.h"
#include "Utilits\ResourcesUtilits.h"
#include "Camera\Camera.h"
#include "Camera\FPSCamera.h"

using namespace sixday::render;
using namespace sixday::utilits;

RenderScene scene(1024, 768, "Test Window");

int main()
{
	ResourcesUtilits::LoadShader("basic_cube_shader", "basic_cube.vs", "basic_cube.fs");

	//ResourcesUtilits::LoadModel("teapot", "teapot.obj");

	Camera camera(glm::vec3(0, 0, -3), glm::vec3(0, 1, 0));

	FPSCamera cam(glm::vec3(0, 0, -3), glm::vec3(0, 1, 0));

	Cube cube;
	cube.Initialize();
	cube.SetPosition(glm::vec3(0, 0, 0));
	cube.SetRotation(glm::vec3(5.0f, 45.0f, 3.0f));

	Cube xCube;
	xCube.Initialize();
	xCube.SetPosition(glm::vec3(1, 0, 0));

	scene.SetCamera(&cam);
	scene.AddComponent(cube.GetGuid(), cube);
	scene.AddComponent(xCube.GetGuid(), xCube);

	scene.Exec();
	return 0;
}