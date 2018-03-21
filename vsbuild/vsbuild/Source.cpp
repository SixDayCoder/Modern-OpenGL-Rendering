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

	ResourcesUtilits::LoadShader("basic_teapot_shader", "basic_teapot.vs", "basic_teapot.fs");

	ResourcesUtilits::LoadModel("basic_teapot", "teapot.obj");

	FPSCamera camera(glm::vec3(0, 0, -3), glm::vec3(0, 1, 0));


	Model model = ResourcesUtilits::GetModel("basic_teapot");
	model.Initialize();
	model.SetPosition(0.0f, 0.0f, 0.0f);
	model.SetScale(0.1f, 0.1f, 0.1f);

	scene.SetCamera(&camera);
	scene.AddComponent(model.GetGuid(), model);

	scene.Exec();
	return 0;
}