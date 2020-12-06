#pragma once
#define OLC_PGE_APPLICATION
#include "PixelGameEngineManaged.h"
#include "olcPGEXSoundManaged.h"
#include "PGEXUtilitiesManaged.h"

public ref class ExampleManaged : public olc::managed::PixelGameEngineManaged
{
public:
	ExampleManaged()
	{
		//sAppName = "Example";
	}

public:
	bool OnUserCreate() override
	{
		// Called once at the start, so create things here
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		// called once per frame
		for (int x = 0; x < ScreenWidth(); x++)
			for (int y = 0; y < ScreenHeight(); y++)
				Draw(x, y, gcnew  olc::managed::PixelManaged(rand() % 255, rand() % 255, rand() % 255));
		return true;
	}

	bool OnUserDestroy() override
	{
		return true;
	}
};


int main()
{
	ExampleManaged^ demo = gcnew  ExampleManaged();
	if (demo->Construct(256, 240, 4, 4) == olc::managed::rcodeManaged::OK)
		demo->Start();

	return 0;
}
