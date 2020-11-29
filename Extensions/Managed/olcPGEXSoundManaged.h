#pragma once
#define OLC_PGEX_SOUND
#include <Extensions/Managed/Wrapper/olcPGEX_SoundWrapper.h>
#include <Extensions/Managed/PixelGameEngineManaged.h>
//#include <vcclr.h>
//#include <msclr/marshal_cppstd.h>

namespace olc {
	namespace managed
	{
		public ref class olcPGEXSoundManaged
		{
			// We extend on our "pre-wrapper"
		public:
			static bool InitialiseAudio(unsigned int nSampleRate, unsigned int nChannels, unsigned int nBlocks, unsigned int nBlockSamples);
			static bool InitialiseAudio(unsigned int nSampleRate, unsigned int nChannels, unsigned int nBlocks);
			static bool InitialiseAudio(unsigned int nSampleRate, unsigned int nChannels);
			static bool InitialiseAudio(unsigned int nSampleRate);
			static bool InitialiseAudio();
			static bool DestroyAudio();
			static void SetUserSynthFunction(System::Func<int, float, float, float>^ func);
			static void SetUserFilterFunction(System::Func<int, float, float, float>^ func);

		public:
			static int LoadAudioSample(System::String^ sWavFile, ResourcePackManaged^ pack);
			static int LoadAudioSample(System::String^ sWavFile);
			static void PlaySample(int id, bool bLoop);
			static void PlaySample(int id);
			static void StopSample(int id);
			static void StopAll();
			static float GetMixerOutput(int nChannel, float fGlobalTime, float fTimeStep);

		private:
			static float WrapSynthFunc(int nChannel, float fGlobalTime, float fTimeStep);
			static float WrapFilterFunc(int nChannel, float fGlobalTime, float fTimeStep);

			static System::Func<int, float, float, float>^ SynthFunc;
			static System::Func<int, float, float, float>^ FilterFunc;
		};


		inline bool olcPGEXSoundManaged::InitialiseAudio(unsigned int nSampleRate, unsigned int nChannels, unsigned int nBlocks, unsigned int nBlockSamples) {
			return wrapper::olcPGEX_SoundWrapper::InitialiseAudio(nSampleRate, nChannels, nBlocks, nBlockSamples);
		}
		inline bool olcPGEXSoundManaged::InitialiseAudio(unsigned int nSampleRate, unsigned int nChannels, unsigned int nBlocks) {
			return wrapper::olcPGEX_SoundWrapper::InitialiseAudio(nSampleRate, nChannels, nBlocks);
		}
		inline bool olcPGEXSoundManaged::InitialiseAudio(unsigned int nSampleRate, unsigned int nChannels) {
			return wrapper::olcPGEX_SoundWrapper::InitialiseAudio(nSampleRate, nChannels);
		}
		inline bool olcPGEXSoundManaged::InitialiseAudio(unsigned int nSampleRate) {
			return wrapper::olcPGEX_SoundWrapper::InitialiseAudio(nSampleRate);
		}
		inline bool olcPGEXSoundManaged::InitialiseAudio() {
			return wrapper::olcPGEX_SoundWrapper::InitialiseAudio();
		}
		inline bool olcPGEXSoundManaged::DestroyAudio() {
			return wrapper::olcPGEX_SoundWrapper::DestroyAudio();
		}
		inline void olcPGEXSoundManaged::SetUserSynthFunction(System::Func<int, float, float, float>^ func) {
			SynthFunc = func;
			wrapper::olcPGEX_SoundWrapper::SetUserSynthFunction(WrapSynthFunc);
		}
		inline void olcPGEXSoundManaged::SetUserFilterFunction(System::Func<int, float, float, float>^ func) {
			FilterFunc = func;
			wrapper::olcPGEX_SoundWrapper::SetUserSynthFunction(WrapFilterFunc);
		}

		inline int olcPGEXSoundManaged::LoadAudioSample(System::String^ sWavFile, ResourcePackManaged^ pack) {
			return wrapper::olcPGEX_SoundWrapper::LoadAudioSample(Util::MarshalString(sWavFile), pack->GetImplementation());
		}

		inline int olcPGEXSoundManaged::LoadAudioSample(System::String^ sWavFile) {
			return wrapper::olcPGEX_SoundWrapper::LoadAudioSample(Util::MarshalString(sWavFile));
		}

		inline void olcPGEXSoundManaged::PlaySample(int id, bool bLoop) {
			wrapper::olcPGEX_SoundWrapper::PlaySample(id, bLoop);
		}
		inline void olcPGEXSoundManaged::PlaySample(int id) {
			wrapper::olcPGEX_SoundWrapper::PlaySample(id);
		}
		inline void olcPGEXSoundManaged::StopSample(int id) {
			wrapper::olcPGEX_SoundWrapper::StopSample(id);
		}
		inline void olcPGEXSoundManaged::StopAll() {
			wrapper::olcPGEX_SoundWrapper::StopAll();
		}
		inline float olcPGEXSoundManaged::GetMixerOutput(int nChannel, float fGlobalTime, float fTimeStep) {
			return wrapper::olcPGEX_SoundWrapper::GetMixerOutput(nChannel, fGlobalTime, fTimeStep);
		}

		inline float olcPGEXSoundManaged::WrapSynthFunc(int nChannel, float fGlobalTime, float fTimeStep)
		{
			return SynthFunc(nChannel, fGlobalTime, fTimeStep);
		}

		inline float olcPGEXSoundManaged::WrapFilterFunc(int nChannel, float fGlobalTime, float fTimeStep)
		{
			return FilterFunc(nChannel, fGlobalTime, fTimeStep);
		}

	}

}
