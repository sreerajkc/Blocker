#pragma once

#include "Blocker/Window.h"
#include "Blocker/Renderer/GraphicsContext.h"

#include <GLFW/glfw3.h>


namespace Blocker
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		inline unsigned int GetWidth() const override { return m_Data.Width; }
		inline unsigned int GetHeight() const override { return m_Data.Height; }

		inline void SetEventCallBacks(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

		inline void* GetNativeWindow() const override { return m_Window; };

	private:
		virtual void Init(const WindowProps& props);
		virtual void ShutDown();

	private:
		GLFWwindow* m_Window;
		GraphicsContext* m_Context;

		struct WindowData
		{
			std::string Title;
			unsigned int Width;
			unsigned int Height;
			bool VSync;
			EventCallbackFn EventCallback;
		};

		WindowData m_Data;

	};
}

