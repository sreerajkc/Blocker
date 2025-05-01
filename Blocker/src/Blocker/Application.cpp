#include "blockerpch.h"
#include "Application.h"
#include "Blocker/Log.h"

#include "glad/glad.h"

namespace Blocker
{
#define BIND_EVENT_FN(x) std::bind(&Application::x,this,std::placeholders::_1)

	Application::Application()
	{
		m_LayerStack = new LayerStack();

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallBacks(BIND_EVENT_FN(OnEvent));
	}

	Application::~Application()
	{

	}
	void Application::Run()
	{
		while (m_Running)
		{
			m_Window->OnUpdate();

			for (auto it = m_LayerStack->begin(); it != m_LayerStack->end();++it)
			{
				(*it)->OnUpdate();
			}
		}
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

		// Going backwards because events should trigger in reverse order
		// that is the top most layer event should be firing first

		for (auto it = m_LayerStack->end(); it != m_LayerStack->begin();) 
		{
			(*--it)->OnEvent(e);
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack->PushLayer(layer);
	}

	void Application::PushOverlay(Layer* overlay)
	{
		m_LayerStack->PushOverlay(overlay);
	}


}
