#pragma once
#include <vcclr.h>
#include "../olcPixelGameEngine.h"

namespace olc {
	namespace wrapper
	{
		// Predeclaration
		ref class PixelGameEngineManaged;

		
		/// <summary>
		/// Redirector for abstract methods
		/// </summary>
		class PixelGameEngineWrapper : public PixelGameEngine
		{
		public:
			PixelGameEngineWrapper() {}
			// Allocate the native object on the C++ Heap via a constructor
			PixelGameEngineWrapper(PixelGameEngineManaged^ owner) : m_owner(owner) {}

			// Called once on application startup, use to load your resources
			bool OnUserCreate();
			// Called every frame, and provides you with a time per frame value
			bool OnUserUpdate(float fElapsedTime);
			// Called once on application termination, so you can be one clean coder
			bool OnUserDestroy();


		private:
			gcroot<PixelGameEngineManaged^> m_owner;
		};
	}
}

