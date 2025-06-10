#pragma once

#include "Blocker/Renderer/GraphicsContext.h"

struct GLFWwindow;

namespace Blocker
{
	class BLOCKER_API OpenGLContext : public GraphicsContext
	{
	public:
		OpenGLContext(GLFWwindow* windowHandle);

		virtual void Init() override;
		virtual void SwapBuffers() override;

	private:
		GLFWwindow* m_WindowHandle;
	};
}

