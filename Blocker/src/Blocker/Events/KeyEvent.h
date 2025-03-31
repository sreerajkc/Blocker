#pragma once

#include "Event.h"
#include <sstream>

namespace Blocker {

	class BLOCKER_API KeyEvent : public Event
	{
	public:
		inline int GetKeyCode() const { return m_KeyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

	protected:
		KeyEvent(int keyCode) : m_KeyCode(keyCode) {}

		int m_KeyCode;
	};

	class BLOCKER_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keyCode, int repeatCount) : KeyEvent(keyCode), m_RepeatCount(repeatCount) {}

		inline int GetRepeatCount() { return m_RepeatCount; }

		EVENT_CLASS_TYPE(KeyPressed)

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent:" << m_KeyCode << "(" << m_RepeatCount << " repeats)";
			return ss.str();
		}

	private:
		int m_RepeatCount;
	};

	class BLOCKER_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keyCode) : KeyEvent(keyCode){}

		EVENT_CLASS_TYPE(KeyReleased)

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent:" << m_KeyCode;
			return ss.str();
		}
	};
}