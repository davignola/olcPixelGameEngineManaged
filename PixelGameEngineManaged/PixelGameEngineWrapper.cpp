#pragma once
#include "PixelGameEngineWrapper.h"
#include "PixelGameEngineManaged.h"
namespace olc
{
	namespace wrapper
	{

		// Called once on application startup, use to load your resources
		bool PixelGameEngineWrapper::OnUserCreate() {
			return m_owner->CallOnUserCreate();
		}
		// Called every frame, and provides you with a time per frame value
		bool PixelGameEngineWrapper::OnUserUpdate(float fElapsedTime)
		{
			return m_owner->CallOnUserUpdate(fElapsedTime);
		}
		// Called once on application termination, so you can be one clean coder
		bool PixelGameEngineWrapper::OnUserDestroy()
		{
			return m_owner->CallOnUserDestroy();
		}
	}
}

