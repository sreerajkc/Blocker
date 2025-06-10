#pragma once

#include "blockerpch.h"

namespace Blocker
{
	class BLOCKER_API GraphicsContext
	{
	public:
		virtual void Init() = 0;
		virtual void SwapBuffers() = 0;
	};
}
