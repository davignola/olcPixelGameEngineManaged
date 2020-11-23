#pragma once
#include "PixelGameEngineManaged.h"

using namespace System::Collections::Generic;

namespace olc {
	namespace wrapper
	{


		// -------- Resource Pack --------
		bool ResourcePackManaged::AddFile(System::String^ sFile)
		{
			return m_Impl->AddFile(Util::MarshalString(sFile));
		}
		bool ResourcePackManaged::LoadPack(System::String^ sFile, System::String^ sKey)
		{
			return m_Impl->LoadPack(Util::MarshalString(sFile), Util::MarshalString(sKey));
		}
		bool ResourcePackManaged::SavePack(System::String^ sFile, System::String^ sKey)
		{
			return m_Impl->SavePack(Util::MarshalString(sFile), Util::MarshalString(sKey));
		}
		List<char>^ ResourcePackManaged::GetFileBuffer(System::String^ sFile)
		{
			std::vector<char> buffer = m_Impl->GetFileBuffer(Util::MarshalString(sFile)).vMemory;
			// Copy the contect of the vector into a list. There may be a faster way to pass the contect to the managed side...
			const int SIZE = buffer.size();
			List<char>^ tempArr = gcnew List<char>(SIZE);
			for (int i = 0; i < SIZE; i++)
			{
				tempArr[i] = buffer[i];
			}
			return tempArr;
		}
		bool ResourcePackManaged::Loaded()
		{
			return m_Impl->Loaded();
		}

		// -------- Sprite ----------

		rcodeManaged SpriteManaged::LoadFromFile(System::String^ sImageFile, ResourcePackManaged^ pack)
		{
			return (rcodeManaged)m_Impl->LoadFromFile(Util::MarshalString(sImageFile), pack->GetImplementation());
		}
		rcodeManaged SpriteManaged::LoadFromFile(System::String^ sImageFile) {
			return (rcodeManaged)m_Impl->LoadFromFile(Util::MarshalString(sImageFile));
		}
		rcodeManaged SpriteManaged::LoadFromPGESprFile(System::String^ sImageFile, ResourcePackManaged^ pack) {
			return (rcodeManaged)m_Impl->LoadFromPGESprFile(Util::MarshalString(sImageFile), pack->GetImplementation());
		}
		rcodeManaged SpriteManaged::LoadFromPGESprFile(System::String^ sImageFile) {
			return (rcodeManaged)m_Impl->LoadFromPGESprFile(Util::MarshalString(sImageFile));
		}
		rcodeManaged SpriteManaged::SaveToPGESprFile(System::String^ sImageFile) {
			return (rcodeManaged)m_Impl->SaveToPGESprFile(Util::MarshalString(sImageFile));
		}


		int32_t SpriteManaged::width()
		{
			return m_Impl->width;
		}
		int32_t SpriteManaged::height()
		{
			return m_Impl->height;
		}

		void SpriteManaged::SetSampleMode()
		{
			m_Impl->SetSampleMode();
		}
		void SpriteManaged::SetSampleMode(ModeManaged mode)
		{
			m_Impl->SetSampleMode((olc::Sprite::Mode)mode);
		}
		PixelManaged^ SpriteManaged::GetPixel(int32_t x, int32_t y)
		{
			return gcnew PixelManaged(&m_Impl->GetPixel(x, y));
		}
		bool  SpriteManaged::SetPixel(int32_t x, int32_t y, PixelManaged^ p)
		{
			return m_Impl->SetPixel(x, y, *p->GetImplementation());
		}
		PixelManaged^ SpriteManaged::GetPixel(vi2dm^ a)
		{
			return  gcnew PixelManaged(&m_Impl->GetPixel(*a->GetImplementation()));
		}
		bool  SpriteManaged::SetPixel(vi2dm^ a, PixelManaged^ p)
		{
			return m_Impl->SetPixel(*a->GetImplementation(), *p->GetImplementation());
		}
		PixelManaged^ SpriteManaged::Sample(float x, float y)
		{
			return  gcnew PixelManaged(&m_Impl->Sample(x, y));
		}
		PixelManaged^ SpriteManaged::SampleBL(float u, float v)
		{
			return  gcnew PixelManaged(&m_Impl->SampleBL(u, v));
		}
		PixelManaged^ SpriteManaged::GetData()
		{
			return  gcnew PixelManaged(m_Impl->GetData());
		}
		SpriteManaged^ SpriteManaged::Duplicate()
		{
			return  gcnew SpriteManaged(m_Impl->Duplicate());
		}
		SpriteManaged^ SpriteManaged::Duplicate(vi2dm^ vPos, vi2dm^ vSize)
		{
			return  gcnew SpriteManaged(m_Impl->Duplicate(*vPos->GetImplementation(), *vSize->GetImplementation()));
		}

		PixelManaged^ SpriteManaged::pColData()
		{
			return  gcnew PixelManaged(m_Impl->pColData);
		}
		SpriteManaged::ModeManaged^ SpriteManaged::modeSample()
		{
			return (SpriteManaged::ModeManaged)m_Impl->modeSample;
		}
	}
}