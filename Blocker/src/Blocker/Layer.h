#pragma once

#include "Blocker/Core.h"
#include"Blocker/Events/Event.h"

namespace Blocker
{
	class BLOCKER_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {};
		virtual void OnDetach() {};
		virtual void OnUpdate() {};
		virtual void OnEvent(Event& e) {};
		virtual void OnImGuiRender() {};

		inline const std::string& GetName() const { return m_DebugName; }
	protected:
		std::string m_DebugName;
	};
}

