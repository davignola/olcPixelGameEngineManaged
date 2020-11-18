#pragma once
#include "PixelGameEngineWrapper.h"

#include <msclr\marshal_cppstd.h>

namespace olc {
	namespace wrapper
	{

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
			PixelManaged^ GetPixel(vi2dm a);
			bool  SetPixel(vi2dm a, PixelManaged^ p);
			PixelManaged^ Sample(float x, float y);
			PixelManaged^ SampleBL(float u, float v);
			PixelManaged^ GetData();
			SpriteManaged^ Duplicate();
			SpriteManaged^ Duplicate(vi2dm vPos, vi2dm vSize);

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
			PixelGameEngineManaged() { m_Impl = new PixelGameEngineWrapper(this); }
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

			bool Draw(const vi2dm pos, PixelManaged^ p);
			bool Draw(int x, int y, PixelManaged^ p);

			// Draws a single line of text - traditional monospaced
			void DrawString(int32_t x, int32_t y, System::String^ sText, PixelManaged^, uint32_t scale);
			void DrawString(int32_t x, int32_t y, System::String^ sText, PixelManaged^ col);
			void DrawString(int32_t x, int32_t y, System::String^ sText);
			void DrawString(vi2dm pos, System::String^ sText, PixelManaged^ col, uint32_t scale);
			void DrawString(vi2dm pos, System::String^ sText, PixelManaged^ col);
			void DrawString(vi2dm pos, System::String^ sText);
			vi2dm^ GetTextSize(System::String^ s);

			// Draws an entire sprite at well location (x,y)
			void DrawSprite(int32_t x, int32_t y, SpriteManaged^ sprite, uint32_t scale, uint8_t flip);
			void DrawSprite(int32_t x, int32_t y, SpriteManaged^ sprite, uint32_t scale);
			void DrawSprite(int32_t x, int32_t y, SpriteManaged^ sprite);
			void DrawSprite(vi2dm pos, SpriteManaged^ sprite, uint32_t scale, uint8_t flip);
			void DrawSprite(vi2dm pos, SpriteManaged^ sprite, uint32_t scale);
			void DrawSprite(vi2dm pos, SpriteManaged^ sprite);

			// Draws a rectangle at (x,y) to (x+w,y+h)
			void DrawRect(int32_t x, int32_t y, int32_t w, int32_t h, PixelManaged^ p);
			void DrawRect(int32_t x, int32_t y, int32_t w, int32_t h);
			void DrawRect(vi2dm pos, vi2dm size, PixelManaged^ p );
			void DrawRect(vi2dm pos, vi2dm size);
			
			// Fills a rectangle at (x,y) to (x+w,y+h)
			void FillRect(int32_t x, int32_t y, int32_t w, int32_t h, PixelManaged^ p );
			void FillRect(int32_t x, int32_t y, int32_t w, int32_t h);
			void FillRect(vi2dm pos, vi2dm size, PixelManaged^ p );
			void FillRect(vi2dm pos, vi2dm size);

			void Clear(PixelManaged^ p);

		internal:
			bool CallOnUserCreate()
			{
				if (!m_Impl) throw gcnew System::ObjectDisposedException("PixelGameEngineWrapper");
				return OnUserCreate();
			}
			bool CallOnUserUpdate(float fElapsedTime)
			{
				if (!m_Impl) throw gcnew System::ObjectDisposedException("PixelGameEngineWrapper");
				return OnUserUpdate(fElapsedTime);
			}
			bool CallOnUserDestroy()
			{
				if (!m_Impl) throw gcnew System::ObjectDisposedException("PixelGameEngineWrapper");
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