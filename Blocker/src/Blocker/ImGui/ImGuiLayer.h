#pragma once
#include "Blocker/Layer.h"

#include "Blocker/Events/MouseEvent.h"
#include "Blocker/Events/KeyEvent.h"
#include "Blocker/Events/ApplicationEvent.h"

namespace Blocker
{
	class BLOCKER_API ImGuiLayer :public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();
		void OnAttach() override;
		void OnDetach() override;
		void OnUpdate() override;
		void OnImGuiRender() override;

		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};
}