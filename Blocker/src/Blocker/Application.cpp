#include "Application.h"
#include "Blocker/Events/ApplicationEvent.h"
#include "Blocker/Log.h"


namespace Blocker
{
	Application::Application()
	{

	}

	Application::~Application()
	{

	}
	void Application::Run()
	{
		WindowResizeEvent wre(1280, 720);
		BLCKR_TRACE(wre.ToString());
		while (true);
	}
}
