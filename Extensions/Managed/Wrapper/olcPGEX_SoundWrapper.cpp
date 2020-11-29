#pragma once
// Some headers referenced by the Sound lib are not supported by c++/CLI 
// We need to "hide" them in the compiled lib by not including an unsuported header in wrapper headers
#define OLC_PGEX_SOUND
#include "olcPGEX_SoundWrapper.h"
#include "../../olcPGEX_Sound.h"

namespace olc {
	namespace managed {
		namespace wrapper {

			bool olcPGEX_SoundWrapper::InitialiseAudio(unsigned int nSampleRate, unsigned int nChannels, unsigned int nBlocks, unsigned int nBlockSamples) {
				return SOUND::InitialiseAudio(nSampleRate, nChannels, nBlocks, nBlockSamples);
			}
			bool olcPGEX_SoundWrapper::DestroyAudio() {
				return SOUND::DestroyAudio();
			}
			void olcPGEX_SoundWrapper::SetUserSynthFunction(std::function<float(int, float, float)> func) {
				SOUND::SetUserSynthFunction(func);
			}
			void olcPGEX_SoundWrapper::SetUserFilterFunction(std::function<float(int, float, float)> func) {
				SOUND::SetUserFilterFunction(func);
			}

			int olcPGEX_SoundWrapper::LoadAudioSample(std::string sWavFile, olc::ResourcePack* pack) {
				return SOUND::LoadAudioSample(sWavFile, pack);
			}
			void olcPGEX_SoundWrapper::PlaySample(int id, bool bLoop) {
				SOUND::PlaySample(id, bLoop);
			}
			void olcPGEX_SoundWrapper::StopSample(int id) {
				SOUND::StopSample(id);
			}
			void olcPGEX_SoundWrapper::StopAll() {
				SOUND::StopAll();
			}
			float olcPGEX_SoundWrapper::GetMixerOutput(int nChannel, float fGlobalTime, float fTimeStep) {
				return SOUND::GetMixerOutput(nChannel, fGlobalTime, fTimeStep);
			}

		}
	}
}

