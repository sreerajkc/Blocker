#pragma once
#include "Core.h"
#include "Events/Event.h"
#include "Platform/Windows/WindowsWindow.h"
#include "Blocker/Events/ApplicationEvent.h"
#include "Blocker/Layerstack.h"
#include "Window.h"

#include "Blocker/ImGui/ImGuiLayer.h"

namespace Blocker
{
	class BLOCKER_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }

	private :

		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;

		bool m_Running = true;

		LayerStack* m_LayerStack;

	private:
		static Application* s_Instance;
	};


	//To be defined in CLIENT
	Application* CreateApplication();
}

