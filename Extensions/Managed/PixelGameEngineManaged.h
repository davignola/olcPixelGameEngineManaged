#pragma once
#include "olcPixelGameEngine.h"

#include <msclr\marshal_cppstd.h>

using namespace System::Collections::Generic;


/********************************************************
 ********************* INTERFACES ***********************
 ********************************************************/

namespace olc {
	namespace wrapper
	{

		// Predeclaration
		ref class PixelGameEngineManaged;


		/// <summary>
		/// Redirector for abstract methods
		/// </summary>
		class olcPixelGameEngineWithOwner : public PixelGameEngine
		{
		public:
			olcPixelGameEngineWithOwner() {}
			// Allocate the native object on the C++ Heap via a constructor
			olcPixelGameEngineWithOwner(PixelGameEngineManaged^ owner) : m_owner(owner) {}

			// Called once on application startup, use to load your resources
			bool OnUserCreate();
			// Called every frame, and provides you with a time per frame value
			bool OnUserUpdate(float fElapsedTime);
			// Called once on application termination, so you can be one clean coder
			bool OnUserDestroy();


		private:
			gcroot<PixelGameEngineManaged^> m_owner;
		};

		public enum class rcodeManaged : char { FAIL = 0, OK = 1, NO_FILE = -1 };

		// Thanks to scripticuk and others for updating the key maps
		// MOTE: The GLUT platform will need updating, open to contributions ;)
		public enum class KeyManaged : char
		{
			NONE,
			A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
			K0, K1, K2, K3, K4, K5, K6, K7, K8, K9,
			F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12,
			UP, DOWN, LEFT, RIGHT,
			SPACE, TAB, SHIFT, CTRL, INS, DEL, HOME, END, PGUP, PGDN,
			BACK, ESCAPE, RETURN, ENTER, PAUSE, SCROLL,
			NP0, NP1, NP2, NP3, NP4, NP5, NP6, NP7, NP8, NP9,
			NP_MUL, NP_DIV, NP_ADD, NP_SUB, NP_DECIMAL, PERIOD,
			EQUALS, COMMA, MINUS,
			OEM_1, OEM_2, OEM_3, OEM_4, OEM_5, OEM_6, OEM_7, OEM_8,
			CAPS_LOCK, ENUM_END
		};

		// UTILS
		static ref class Util
		{
		public:
			static std::string MarshalString(System::String^ s) {
				std::string standardString = msclr::interop::marshal_as<std::string>(s);
				return standardString;
			}
		};

		/// <summary>
		/// v2d_generic IMPL
		/// </summary>
		template <class T>
		public ref struct v2d_genericManaged
		{
		private:
			v2d_generic<T>* m_Impl;
			const v2d_generic<T>* m_ImplConst;
		public:
			v2d_genericManaged() : { m_Impl = new v2d_generic(0, 0); }
			v2d_genericManaged(v2d_generic<T>* _impl)
			{
				m_Impl = _impl;
				x = _impl->x;
				y = _impl->y;
			}
			v2d_genericManaged(const v2d_generic<T>* _impl)
			{
				m_ImplConst = _impl;
				IsConst = true;
				x = _impl->x;
				y = _impl->y;
			}
			v2d_genericManaged(T _x, T _y) { m_Impl = new v2d_generic(x, y); }

			bool IsConst = false;
			T x = 0;
			T y = 0;

			v2d_generic<T>* GetImplementation() { return m_Impl; }
			const v2d_generic<T>* GetImplementationConst() { return m_ImplConst; }

		};
		typedef v2d_genericManaged<int32_t> vi2dm;
		typedef v2d_genericManaged<uint32_t> vu2dm;
		typedef v2d_genericManaged<float> vf2dm;
		typedef v2d_genericManaged<double> vd2dm;


		/// <summary>
		/// PIXEL IMPL
		/// </summary>
		public ref struct PixelManaged {
		private:
			Pixel* m_Impl;

		public:

			PixelManaged() { m_Impl = new Pixel(); }
			PixelManaged(uint8_t red, uint8_t green, uint8_t blue) { m_Impl = new Pixel(red, green, blue); }
			PixelManaged(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) { m_Impl = new Pixel(red, green, blue, alpha); }
			PixelManaged(uint32_t p) { m_Impl = new Pixel(p); }
			PixelManaged(Pixel* _impl) { m_Impl = _impl; }
			~PixelManaged() { this->!PixelManaged(); }
			!PixelManaged() {
				if (m_Impl) {
					delete m_Impl;
					m_Impl = 0;
				}
			}

			Pixel* GetImplementation() { return m_Impl; }

		};


		/// <summary>
		/// RESOURCEPACK IMPL
		/// </summary>
		public ref struct ResourcePackManaged {
		private:
			ResourcePack* m_Impl;

		public:

		public:
			ResourcePackManaged() { m_Impl = new ResourcePack(); }
			~ResourcePackManaged() { this->!ResourcePackManaged(); }
			!ResourcePackManaged() {
				if (m_Impl) {
					delete m_Impl;
					m_Impl = 0;
				}
			}
			bool AddFile(System::String^ sFile);
			bool LoadPack(System::String^ sFile, System::String^ sKey);
			bool SavePack(System::String^ sFile, System::String^ sKey);
			System::Collections::Generic::List<char>^ GetFileBuffer(System::String^ sFile);
			bool Loaded();

		public:
			ResourcePack* GetImplementation() { return m_Impl; }

		};

		/// <summary>
		/// SPRITE IMPL
		/// </summary>
		public ref struct SpriteManaged {
		private:
			Sprite* m_Impl;

		public:
			SpriteManaged() { m_Impl = new Sprite(); }
			SpriteManaged(System::String^ sImageFile, ResourcePackManaged^ pack) { m_Impl = new Sprite(Util::MarshalString(sImageFile), pack->GetImplementation()); }
			SpriteManaged(System::String^ sImageFile) { m_Impl = new Sprite(Util::MarshalString(sImageFile)); }
			SpriteManaged(int32_t w, int32_t h) { m_Impl = new Sprite(w, h); }
			SpriteManaged(Sprite* _impl) { m_Impl = _impl; }
			~SpriteManaged() { this->!SpriteManaged(); }
			!SpriteManaged() {
				if (m_Impl) {
					delete m_Impl;
					m_Impl = 0;
				}
			}

		public:
			rcodeManaged LoadFromFile(System::String^ sImageFile, ResourcePackManaged^ pack);
			rcodeManaged LoadFromFile(System::String^ sImageFile);
			rcodeManaged LoadFromPGESprFile(System::String^ sImageFile, ResourcePackManaged^ pack);
			rcodeManaged LoadFromPGESprFile(System::String^ sImageFile);
			rcodeManaged SaveToPGESprFile(System::String^ sImageFile);

		public:
			int32_t width();
			int32_t height();
			enum class ModeManaged : byte { NORMAL, PERIODIC };
			enum class FlipManaged : byte { NONE = 0, HORIZ = 1, VERT = 2 };

		public:
			void SetSampleMode();
			void SetSampleMode(ModeManaged mode);
			PixelManaged^ GetPixel(int32_t x, int32_t y);
			bool  SetPixel(int32_t x, int32_t y, PixelManaged^ p);
			PixelManaged^ GetPixel(vi2dm^ a);
			bool  SetPixel(vi2dm^ a, PixelManaged^ p);
			PixelManaged^ Sample(float x, float y);
			PixelManaged^ SampleBL(float u, float v);
			PixelManaged^ GetData();
			SpriteManaged^ Duplicate();
			SpriteManaged^ Duplicate(vi2dm^ vPos, vi2dm^ vSize);

			PixelManaged^ pColData();
			ModeManaged^ modeSample();

			//static std::unique_ptr<olc::ImageLoader> loader;

			Sprite* GetImplementation() { return m_Impl; }

		};

		public ref struct HWButtonManaged
		{
		private:
			HWButton* m_Impl;

		public:
			HWButtonManaged() { m_Impl = new HWButton(); }
			HWButtonManaged(HWButton* _impl) { m_Impl = _impl; }

			bool bPressed() { return m_Impl->bPressed; }	// Set once during the frame the event occurs
			bool bReleased() { return m_Impl->bReleased; }	// Set once during the frame the event occurs
			bool bHeld() { return m_Impl->bHeld; }			// Set true for all frames between pressed and released events

			HWButton* GetImplementation() { return m_Impl; }
		};



		/// <summary>
		///  Managed wrapper class
		/// </summary>

		public ref class PixelGameEngineManaged abstract {
		private:
			PixelGameEngine* m_Impl;

		public:
			PixelGameEngineManaged() { m_Impl = new olcPixelGameEngineWithOwner(this); }
			~PixelGameEngineManaged() { this->!PixelGameEngineManaged(); }
			!PixelGameEngineManaged() {
				if (m_Impl) {
					delete m_Impl;
					m_Impl = 0;
				}
			}
		public:
			// Called once on application startup, use to load your resources
			virtual bool OnUserCreate() = 0;
			// Called every frame, and provides you with a time per frame value
			virtual bool OnUserUpdate(float fElapsedTime) = 0;
			// Called once on application termination, so you can be one clean coder
			virtual bool OnUserDestroy() = 0;

		public: // Hardware Interfaces
			// Returns true if window is currently in focus
			bool IsFocused();
			// Get the state of a specific keyboard button
			HWButtonManaged^ GetKey(KeyManaged k);
			// Get the state of a specific mouse button
			HWButtonManaged^ GetMouse(uint32_t b);
			// Get Mouse X coordinate in "pixel" space
			int32_t GetMouseX();
			// Get Mouse Y coordinate in "pixel" space
			int32_t GetMouseY();
			// Get Mouse Wheel Delta
			int32_t GetMouseWheel();
			//// Get the mouse in window space
			vi2dm^ GetWindowMouse();
			//// Gets the mouse as a vector to keep Tarriest happy
			vi2dm^ GetMousePos();

		public: // Core stuff
			rcodeManaged Construct(int32_t screen_w, int32_t screen_h, int32_t pixel_w, int32_t pixel_h, bool full_screen, bool vsync, bool cohesion);
			rcodeManaged Construct(int32_t screen_w, int32_t screen_h, int32_t pixel_w, int32_t pixel_h, bool full_screen, bool vsync);
			rcodeManaged Construct(int32_t screen_w, int32_t screen_h, int32_t pixel_w, int32_t pixel_h, bool full_screen);
			rcodeManaged Construct(int32_t screen_w, int32_t screen_h, int32_t pixel_w, int32_t pixel_h);
			rcodeManaged Start();

			void SetScreenSize(int w, int h);

			int32_t ScreenWidth();

			int32_t ScreenHeight();

		public: // Drawing

			bool Draw(vi2dm^ pos, PixelManaged^ p);
			bool Draw(int x, int y, PixelManaged^ p);

			// Draws a single line of text - traditional monospaced
			void DrawString(int32_t x, int32_t y, System::String^ sText, PixelManaged^, uint32_t scale);
			void DrawString(int32_t x, int32_t y, System::String^ sText, PixelManaged^ col);
			void DrawString(int32_t x, int32_t y, System::String^ sText);
			void DrawString(vi2dm^ pos, System::String^ sText, PixelManaged^ col, uint32_t scale);
			void DrawString(vi2dm^ pos, System::String^ sText, PixelManaged^ col);
			void DrawString(vi2dm^ pos, System::String^ sText);
			vi2dm^ GetTextSize(System::String^ s);

			// Draws an entire sprite at well location (x,y)
			void DrawSprite(int32_t x, int32_t y, SpriteManaged^ sprite, uint32_t scale, uint8_t flip);
			void DrawSprite(int32_t x, int32_t y, SpriteManaged^ sprite, uint32_t scale);
			void DrawSprite(int32_t x, int32_t y, SpriteManaged^ sprite);
			void DrawSprite(vi2dm^ pos, SpriteManaged^ sprite, uint32_t scale, uint8_t flip);
			void DrawSprite(vi2dm^ pos, SpriteManaged^ sprite, uint32_t scale);
			void DrawSprite(vi2dm^ pos, SpriteManaged^ sprite);

			// Draws a rectangle at (x,y) to (x+w,y+h)
			void DrawRect(int32_t x, int32_t y, int32_t w, int32_t h, PixelManaged^ p);
			void DrawRect(int32_t x, int32_t y, int32_t w, int32_t h);
			void DrawRect(vi2dm^ pos, vi2dm^ size, PixelManaged^ p );
			void DrawRect(vi2dm^ pos, vi2dm^ size);
			
			// Fills a rectangle at (x,y) to (x+w,y+h)
			void FillRect(int32_t x, int32_t y, int32_t w, int32_t h, PixelManaged^ p );
			void FillRect(int32_t x, int32_t y, int32_t w, int32_t h);
			void FillRect(vi2dm^ pos, vi2dm^ size, PixelManaged^ p );
			void FillRect(vi2dm^ pos, vi2dm^ size);

			void Clear(PixelManaged^ p);

		internal:
			bool CallOnUserCreate()
			{
				if (!m_Impl) throw gcnew System::ObjectDisposedException("olcPixelGameEngineWithOwner");
				return OnUserCreate();
			}
			bool CallOnUserUpdate(float fElapsedTime)
			{
				if (!m_Impl) throw gcnew System::ObjectDisposedException("olcPixelGameEngineWithOwner");
				return OnUserUpdate(fElapsedTime);
			}
			bool CallOnUserDestroy()
			{
				if (!m_Impl) throw gcnew System::ObjectDisposedException("olcPixelGameEngineWithOwner");
				return OnUserDestroy();
			}
		};


		// CONSTANTS

		public ref class PixelColor {
		public:
			static PixelManaged^ GREY = gcnew PixelManaged(192, 192, 192);
			static PixelManaged^ DARK_GREY = gcnew PixelManaged(128, 128, 128);
			static PixelManaged^ VERY_DARK_GREY = gcnew PixelManaged(64, 64, 64);
			static PixelManaged^ RED = gcnew PixelManaged(255, 0, 0);
			static PixelManaged^ DARK_RED = gcnew PixelManaged(128, 0, 0);
			static PixelManaged^ VERY_DARK_RED = gcnew PixelManaged(64, 0, 0);
			static PixelManaged^ YELLOW = gcnew PixelManaged(255, 255, 0);
			static PixelManaged^ DARK_YELLOW = gcnew PixelManaged(128, 128, 0);
			static PixelManaged^ VERY_DARK_YELLOW = gcnew PixelManaged(64, 64, 0);
			static PixelManaged^ GREEN = gcnew PixelManaged(0, 255, 0);
			static PixelManaged^ DARK_GREEN = gcnew PixelManaged(0, 128, 0);
			static PixelManaged^ VERY_DARK_GREEN = gcnew PixelManaged(0, 64, 0);
			static PixelManaged^ CYAN = gcnew PixelManaged(0, 255, 255);
			static PixelManaged^ DARK_CYAN = gcnew PixelManaged(0, 128, 128);
			static PixelManaged^ VERY_DARK_CYAN = gcnew PixelManaged(0, 64, 64);
			static PixelManaged^ BLUE = gcnew PixelManaged(0, 0, 255);
			static PixelManaged^ DARK_BLUE = gcnew PixelManaged(0, 0, 128);
			static PixelManaged^ VERY_DARK_BLUE = gcnew PixelManaged(0, 0, 64);
			static PixelManaged^ MAGENTA = gcnew PixelManaged(255, 0, 255);
			static PixelManaged^ DARK_MAGENTA = gcnew PixelManaged(128, 0, 128);
			static PixelManaged^ VERY_DARK_MAGENTA = gcnew PixelManaged(64, 0, 64);
			static PixelManaged^ WHITE = gcnew PixelManaged(255, 255, 255);
			static PixelManaged^ BLACK = gcnew PixelManaged(0, 0, 0);
			static PixelManaged^ BLANK = gcnew PixelManaged(0, 0, 0, 0);
		};

	}
}

/********************************************************
 ****************** IMPLEMENTATIONS *********************
 ********************************************************/


namespace olc {
	namespace wrapper
	{

		// =========== olcPixelGameEngineWithOwner ===================
		
		// Called once on application startup, use to load your resources
		bool olcPixelGameEngineWithOwner::OnUserCreate() {
			return m_owner->CallOnUserCreate();
		}
		// Called every frame, and provides you with a time per frame value
		bool olcPixelGameEngineWithOwner::OnUserUpdate(float fElapsedTime)
		{
			return m_owner->CallOnUserUpdate(fElapsedTime);
		}
		// Called once on application termination, so you can be one clean coder
		bool olcPixelGameEngineWithOwner::OnUserDestroy()
		{
			return m_owner->CallOnUserDestroy();
		}
		

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

		bool PixelGameEngineManaged::Draw(vi2dm^ pos, PixelManaged^ p) {
			return m_Impl->Draw(*pos->GetImplementation(), *p->GetImplementation());
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

		void PixelGameEngineManaged::DrawString(vi2dm^ pos, System::String^ sText, PixelManaged^ col, uint32_t scale) {
			return m_Impl->DrawString(*pos->GetImplementation(), Util::MarshalString(sText), *col->GetImplementation(), scale);
		}
		void PixelGameEngineManaged::DrawString(vi2dm^ pos, System::String^ sText, PixelManaged^ col) {
			return m_Impl->DrawString(*pos->GetImplementation(), Util::MarshalString(sText), *col->GetImplementation());
		}
		void PixelGameEngineManaged::DrawString(vi2dm^ pos, System::String^ sText) {
			return m_Impl->DrawString(*pos->GetImplementation(), Util::MarshalString(sText));
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
		void PixelGameEngineManaged::DrawSprite(vi2dm^ pos, SpriteManaged^ sprite, uint32_t scale, uint8_t flip)
		{
			m_Impl->DrawSprite(*pos->GetImplementation(), sprite->GetImplementation(), scale, flip);
		}
		void PixelGameEngineManaged::DrawSprite(vi2dm^ pos, SpriteManaged^ sprite, uint32_t scale)
		{
			m_Impl->DrawSprite(*pos->GetImplementation(), sprite->GetImplementation(), scale);
		}
		void PixelGameEngineManaged::DrawSprite(vi2dm^ pos, SpriteManaged^ sprite) {
			m_Impl->DrawSprite(*pos->GetImplementation(), sprite->GetImplementation());
		}

		// Draws a rectangle at (x,y) to (x+w,y+h)
		void PixelGameEngineManaged::DrawRect(int32_t x, int32_t y, int32_t w, int32_t h, PixelManaged^ p)
		{
			m_Impl->DrawRect(x, y, w, h, *p->GetImplementation());
		}
		void PixelGameEngineManaged::DrawRect(int32_t x, int32_t y, int32_t w, int32_t h) {
			m_Impl->DrawRect(x, y, w, h);
		}
		void PixelGameEngineManaged::DrawRect(vi2dm^ pos, vi2dm^ size, PixelManaged^ p)
		{
			m_Impl->DrawRect(*pos->GetImplementation(), *size->GetImplementation(), *p->GetImplementation());
		}
		void PixelGameEngineManaged::DrawRect(vi2dm^ pos, vi2dm^ size)
		{
			m_Impl->DrawRect(*pos->GetImplementation(), *size->GetImplementation());
		}

		// Fills a rectangle at (x,y) to (x+w,y+h)
		void PixelGameEngineManaged::FillRect(int32_t x, int32_t y, int32_t w, int32_t h, PixelManaged^ p) {
			m_Impl->FillRect(x, y, w, h, *p->GetImplementation());
		}
		void PixelGameEngineManaged::FillRect(int32_t x, int32_t y, int32_t w, int32_t h) {
			m_Impl->FillRect(x, y, w, h);
		}
		void PixelGameEngineManaged::FillRect(vi2dm^ pos, vi2dm^ size, PixelManaged^ p) {
			m_Impl->FillRect(*pos->GetImplementation(), *size->GetImplementation(), *p->GetImplementation());
		}
		void PixelGameEngineManaged::FillRect(vi2dm^ pos, vi2dm^ size) {
			m_Impl->FillRect(*pos->GetImplementation(), *size->GetImplementation());
		}
	}
}