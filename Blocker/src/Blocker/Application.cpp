#include "blockerpch.h"
#include "Application.h"
#include "Blocker/Log.h"

#include "glad/glad.h"
#include "Input.h"
namespace Blocker
{
	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		BLCKR_CORE_ASSERT(s_Instance != nullptr, "Application already exists")
			s_Instance = this;

		m_LayerStack = new LayerStack();

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallBacks(BIND_EVENT_FN(Application::OnEvent));

		m_ImGuiLayer = new ImGuiLayer();
		PushOverlay(m_ImGuiLayer);
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

			m_ImGuiLayer->Begin();
			for (auto it = m_LayerStack->begin(); it != m_LayerStack->end();++it)
			{
				(*it)->OnImGuiRender();
			}
			m_ImGuiLayer->End();

			auto [x, y] = Input::GetMousePosition();
			BLCKR_CORE_INFO("{0},{1}", x, y);
		}
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));

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
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* overlay)
	{
		m_LayerStack->PushOverlay(overlay);
		overlay->OnAttach();
	}
}
