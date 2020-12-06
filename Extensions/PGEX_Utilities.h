#pragma once
#include "../olcPixelGameEngine.h"
namespace olc
{
	namespace utilities
	{
		class SpriteUtilities : PGEX
		{
		public:
			/// <summary>
			/// Switch both axis of a sprite in place making the transform permanent
			/// </summary>
			/// <param name="sprite"></param>
			static void SwitchAxis(Sprite* sprite)
			{
				Pixel* data = sprite->GetData();
				int size = sprite->width * sprite->height;
				Pixel* newData = new Pixel[size];
				
				// Switch axis
				for (int x = 0; x < sprite->width; x++)
					for (int y = 0; y < sprite->height; y++)
						newData[y + x * sprite->height] = data[x + y * sprite->width];
				// transfer buffer
				std::memcpy(data, newData, size * sizeof(olc::Pixel));

				// Swap height and width
				int width = sprite->width;
				sprite->width = sprite->height;
				sprite->height = width;				
			}
		};
	}
}