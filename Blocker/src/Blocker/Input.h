#pragma once

#include "Blocker/Core.h"

namespace Blocker
{
	class BLOCKER_API Input
	{
	public:
		inline static bool IsKeyPressed(int keyCode) { return s_Instance->IsKeyPressedImpl(keyCode); }
		inline static bool IsMouseButtonPressed(int keyCode) { return s_Instance->IsMouseButtonPressedImpl(keyCode);}
		inline static std::pair<float,float> GetMousePosition() { return s_Instance->GetMousePositionImpl(); }


		inline static float GetMouseX() { return s_Instance->GetMouseXImpl(); }
		inline static float GetMouseY(){ return s_Instance->GetMouseYImpl(); }

	protected:
		virtual bool IsKeyPressedImpl(int keyCode) = 0;// this will be implemented platform specifically
		virtual bool IsMouseButtonPressedImpl(int keyCode) = 0;
		virtual std::pair<float, float> GetMousePositionImpl() = 0;
		virtual float GetMouseXImpl() = 0;
		virtual float GetMouseYImpl() = 0;

	private:
		static Input* s_Instance;
	};
}