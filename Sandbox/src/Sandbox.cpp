#include <Blocker.h>


class ExampleLayer : public Blocker::Layer
{
public:
	ExampleLayer() : Layer("Example Layer")
	{

	}

	void OnUpdate() override
	{
		BLCKR_INFO("ExampleLayer:Update");
	}

	void OnEvent(Blocker::Event& event) override
	{
		BLCKR_TRACE("{0}", event);
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
