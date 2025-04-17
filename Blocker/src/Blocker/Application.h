#pragma once
#include "Core.h"
#include "Events/Event.h"
#include "Platform/Windows/WindowsWindow.h"
#include "Blocker/Events/ApplicationEvent.h"

namespace Blocker
{
	class BLOCKER_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event& e);

	private :

		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	//To be defined in CLIENT
	Application* CreateApplication();
}

