#pragma once
#include <functional>
#include "../../../olcPixelGameEngine.h"

namespace olc {
	namespace managed {
		namespace wrapper {

			class olcPGEX_SoundWrapper
			{
			public:
				static bool InitialiseAudio(unsigned int nSampleRate = 44100, unsigned int nChannels = 1, unsigned int nBlocks = 8, unsigned int nBlockSamples = 512);
				static bool DestroyAudio();
				static void SetUserSynthFunction(std::function<float(int, float, float)> func);
				static void SetUserFilterFunction(std::function<float(int, float, float)> func);

			public:
				static int LoadAudioSample(std::string sWavFile, olc::ResourcePack* pack = nullptr);
				static void PlaySample(int id, bool bLoop = false);
				static void StopSample(int id);
				static void StopAll();
				static float GetMixerOutput(int nChannel, float fGlobalTime, float fTimeStep);
			};

		}
	}
}

