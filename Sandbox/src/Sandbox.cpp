#include <Blocker.h>

#include "ImGui.h"

using namespace Blocker;

class ExampleLayer : public Blocker::Layer
{
public:
	ExampleLayer() : Layer("Example Layer")
	{
	}

	void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Test");
		ImGui::End();
	}
};

class Sandbox : public Blocker::Application
{
public:
	Sandbox() 
	{
		PushLayer(new ExampleLayer());
	}
	~Sandbox() {}
private:

};

Blocker::Application* Blocker::CreateApplication()
{
	return new Sandbox();
}
