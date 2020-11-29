#define OLC_PGE_APPLICATION
#pragma once
#include "Extensions/Managed/PixelGameEngineManaged.h"
#include "Extensions/Managed/olcPGEXSoundManaged.h"

public ref class ExampleManaged : public olc::wrapper::PixelGameEngineManaged
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
				Draw(x, y, gcnew  olc::wrapper::PixelManaged(rand() % 255, rand() % 255, rand()% 255));	
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
	if (demo->Construct(256, 240, 4, 4) == olc::wrapper::rcodeManaged::OK)
		demo->Start();
	
	return 0;
}
