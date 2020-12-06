#pragma once
#define OLC_PGEX_SOUND
#include <Extensions/PGEX_Utilities.h>
#include <Extensions/Managed/PixelGameEngineManaged.h>


namespace olc {
	namespace managed
	{
		public ref class SpriteUtilitiesManaged
		{
		public:
			static void SwitchAxis(SpriteManaged^ sprite);

		};

		inline void SpriteUtilitiesManaged::SwitchAxis(SpriteManaged^ sprite) {
			olc::utilities::SpriteUtilities::SwitchAxis(sprite->GetImplementation());
		}

	}
}


