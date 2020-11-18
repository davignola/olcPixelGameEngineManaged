#pragma once
#include "PixelGameEngineManaged.h"

namespace olc {
	namespace wrapper
	{
		// =============== OLC GAME ENGINE ============

		// Hardware
		bool PixelGameEngineManaged::IsFocused()
		{
			return m_Impl->IsFocused();
		}
		// Get the state of a specific keyboard button
		HWButtonManaged^ PixelGameEngineManaged::GetKey(KeyManaged k)
		{
			return gcnew HWButtonManaged(&m_Impl->GetKey((Key)k));
		}
		// Get the state of a specific mouse button
		HWButtonManaged^ PixelGameEngineManaged::GetMouse(uint32_t b)
		{
			return gcnew HWButtonManaged(&m_Impl->GetMouse(b));
		}
		// Get Mouse X coordinate in "pixel" space
		int32_t PixelGameEngineManaged::GetMouseX()
		{
			return m_Impl->GetMouseX();
		}
		// Get Mouse Y coordinate in "pixel" space
		int32_t PixelGameEngineManaged::GetMouseY()
		{
			return m_Impl->GetMouseY();
		}
		// Get Mouse Wheel Delta
		int32_t PixelGameEngineManaged::GetMouseWheel()
		{
			return m_Impl->GetMouseWheel();
		}
		//// Get the mouse in window space
		vi2dm^ PixelGameEngineManaged::GetWindowMouse()
		{
			return gcnew vi2dm(&m_Impl->GetWindowMouse());
		}
		//// Gets the mouse as a vector to keep Tarriest happy
		vi2dm^ PixelGameEngineManaged::GetMousePos()
		{
			return gcnew vi2dm(&m_Impl->GetMousePos());
		}
		// Core methods

		rcodeManaged PixelGameEngineManaged::Construct(int32_t screen_w, int32_t screen_h, int32_t pixel_w, int32_t pixel_h, bool full_screen, bool vsync, bool cohesion)
		{
			return (rcodeManaged)m_Impl->Construct(screen_w, screen_h, pixel_w, pixel_h, full_screen, vsync, cohesion);
		}

		rcodeManaged PixelGameEngineManaged::Construct(int32_t screen_w, int32_t screen_h, int32_t pixel_w, int32_t pixel_h, bool full_screen, bool vsync)
		{
			return (rcodeManaged)m_Impl->Construct(screen_w, screen_h, pixel_w, pixel_h, full_screen);
		}

		rcodeManaged PixelGameEngineManaged::Construct(int32_t screen_w, int32_t screen_h, int32_t pixel_w, int32_t pixel_h, bool full_screen)
		{
			return (rcodeManaged)m_Impl->Construct(screen_w, screen_h, pixel_w, pixel_h, full_screen);
		}

		rcodeManaged PixelGameEngineManaged::Construct(int32_t screen_w, int32_t screen_h, int32_t pixel_w, int32_t pixel_h)
		{
			return (rcodeManaged)m_Impl->Construct(screen_w, screen_h, pixel_w, pixel_h);
		}

		rcodeManaged PixelGameEngineManaged::Start()
		{
			return (rcodeManaged)m_Impl->Start();
		}
		void PixelGameEngineManaged::SetScreenSize(int w, int h)
		{
			m_Impl->SetScreenSize(w, h);
		}

		int32_t PixelGameEngineManaged::ScreenWidth() {
			return m_Impl->ScreenWidth();
		}

		int32_t PixelGameEngineManaged::ScreenHeight() {
			return m_Impl->ScreenHeight();
		}

		// DRAW

		void PixelGameEngineManaged::Clear(PixelManaged^ p)
		{
			m_Impl->Clear(*p->GetImplementation());
		}

		bool PixelGameEngineManaged::Draw(vi2dm pos, PixelManaged^ p) {
			return m_Impl->Draw(*pos.GetImplementation(), *p->GetImplementation());
		}
		bool PixelGameEngineManaged::Draw(int x, int y, PixelManaged^ p) {
			return m_Impl->Draw((int32_t)x, (int32_t)y, *p->GetImplementation());
		}

		void PixelGameEngineManaged::DrawString(int32_t x, int32_t y, System::String^ sText, PixelManaged^ col, uint32_t scale) {
			return m_Impl->DrawString((int32_t)x, (int32_t)y, Util::MarshalString(sText), *col->GetImplementation(), scale);
		}
		void PixelGameEngineManaged::DrawString(int32_t x, int32_t y, System::String^ sText, PixelManaged^ col) {
			return m_Impl->DrawString((int32_t)x, (int32_t)y, Util::MarshalString(sText), *col->GetImplementation());
		}
		void PixelGameEngineManaged::DrawString(int32_t x, int32_t y, System::String^ sText) {
			return m_Impl->DrawString((int32_t)x, (int32_t)y, Util::MarshalString(sText));
		}

		void PixelGameEngineManaged::DrawString(vi2dm pos, System::String^ sText, PixelManaged^ col, uint32_t scale) {
			return m_Impl->DrawString(*pos.GetImplementation(), Util::MarshalString(sText), *col->GetImplementation(), scale);
		}
		void PixelGameEngineManaged::DrawString(vi2dm pos, System::String^ sText, PixelManaged^ col) {
			return m_Impl->DrawString(*pos.GetImplementation(), Util::MarshalString(sText), *col->GetImplementation());
		}
		void PixelGameEngineManaged::DrawString(vi2dm pos, System::String^ sText) {
			return m_Impl->DrawString(*pos.GetImplementation(), Util::MarshalString(sText));
		}
		vi2dm^ PixelGameEngineManaged::GetTextSize(System::String^ s) {
			return gcnew vi2dm(&m_Impl->GetTextSize(Util::MarshalString(s)));
		}

		void PixelGameEngineManaged::DrawSprite(int32_t x, int32_t y, SpriteManaged^ sprite, uint32_t scale, uint8_t flip)
		{
			m_Impl->DrawSprite(x, y, sprite->GetImplementation(), scale, flip);
		}
		void PixelGameEngineManaged::DrawSprite(int32_t x, int32_t y, SpriteManaged^ sprite, uint32_t scale)
		{
			m_Impl->DrawSprite(x, y, sprite->GetImplementation(), scale);
		}
		void PixelGameEngineManaged::DrawSprite(int32_t x, int32_t y, SpriteManaged^ sprite)
		{
			m_Impl->DrawSprite(x, y, sprite->GetImplementation());
		}
		void PixelGameEngineManaged::DrawSprite(vi2dm pos, SpriteManaged^ sprite, uint32_t scale, uint8_t flip)
		{
			m_Impl->DrawSprite(*pos.GetImplementation(), sprite->GetImplementation(), scale, flip);
		}
		void PixelGameEngineManaged::DrawSprite(vi2dm pos, SpriteManaged^ sprite, uint32_t scale)
		{
			m_Impl->DrawSprite(*pos.GetImplementation(), sprite->GetImplementation(), scale);
		}
		void PixelGameEngineManaged::DrawSprite(vi2dm pos, SpriteManaged^ sprite) {
			m_Impl->DrawSprite(*pos.GetImplementation(), sprite->GetImplementation());
		}

		// Draws a rectangle at (x,y) to (x+w,y+h)
		void PixelGameEngineManaged::DrawRect(int32_t x, int32_t y, int32_t w, int32_t h, PixelManaged^ p)
		{
			m_Impl->DrawRect(x, y, w, h, *p->GetImplementation());
		}
		void PixelGameEngineManaged::DrawRect(int32_t x, int32_t y, int32_t w, int32_t h) {
			m_Impl->DrawRect(x, y, w, h);
		}
		void PixelGameEngineManaged::DrawRect(vi2dm pos, vi2dm size, PixelManaged^ p)
		{
			m_Impl->DrawRect(*pos.GetImplementation(), *size.GetImplementation(), *p->GetImplementation());
		}
		void PixelGameEngineManaged::DrawRect(vi2dm pos, vi2dm size)
		{
			m_Impl->DrawRect(*pos.GetImplementation(), *size.GetImplementation());
		}

		// Fills a rectangle at (x,y) to (x+w,y+h)
		void PixelGameEngineManaged::FillRect(int32_t x, int32_t y, int32_t w, int32_t h, PixelManaged^ p) {
			m_Impl->FillRect(x, y, w, h, *p->GetImplementation());
		}
		void PixelGameEngineManaged::FillRect(int32_t x, int32_t y, int32_t w, int32_t h) {
			m_Impl->FillRect(x, y, w, h);
		}
		void PixelGameEngineManaged::FillRect(vi2dm pos, vi2dm size, PixelManaged^ p) {
			m_Impl->FillRect(*pos.GetImplementation(), *size.GetImplementation(), *p->GetImplementation());
		}
		void PixelGameEngineManaged::FillRect(vi2dm pos, vi2dm size) {
			m_Impl->FillRect(*pos.GetImplementation(), *size.GetImplementation());
		}


	}
}