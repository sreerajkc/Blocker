#pragma once


#include "Blocker/Input.h"

namespace Blocker
{
	class BLOCKER_API WindowsInput : public Input
	{
	protected:
		bool IsKeyPressedImpl(int keyCode) override;
		bool IsMouseButtonPressedImpl(int keyCode) override;
		float GetMouseXImpl() override;
		float GetMouseYImpl() override;
		std::pair<float, float> GetMousePositionImpl() override;
	};
}