#pragma once
#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

#include <msclr\marshal_cppstd.h>

using namespace System::Collections::Generic;


/********************************************************
 ********************* INTERFACES ***********************
 ********************************************************/

namespace olc {
	namespace managed
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
			v2d_generic<T>* nativeImpl;
		public:
			v2d_genericManaged() : nativeImpl(new v2d_generic<T>()) {}
			v2d_genericManaged(v2d_generic<T>* _impl) { nativeImpl = _impl; }
			v2d_genericManaged(T _x, T _y) { nativeImpl = new v2d_generic<T>(_x, _y); }

			property T X
			{
			public: T get() { return nativeImpl->x; }
			public: void set(T value)
			{
				nativeImpl->x = value;
			}
			}

			property T Y
			{
			public: T get() { return nativeImpl->y; }
			public: void set(T value)
			{
				nativeImpl->y = value;
			}
			}

			v2d_generic<T>* GetImplementation() { return nativeImpl; }

		};
		template <class T>
		public ref struct v2d_genericConstManaged
		{
		private:
			const v2d_generic<T>* nativeImpl;
		public:
			v2d_genericConstManaged() : nativeImpl(new v2d_generic<T>()) {}
			v2d_genericConstManaged(const v2d_generic<T>* _impl) { nativeImpl = _impl; }
			v2d_genericConstManaged(T _x, T _y) { nativeImpl = new v2d_generic<T>(_x, _y); }

			property T X
			{
			public: T get() { return nativeImpl->x; }
			}

			property T Y
			{
			public: T get() { return nativeImpl->y; }
			}

			const v2d_generic<T>* GetImplementation() { return nativeImpl; }

		};

		// Make the template c++/CLI exposable
		public ref class vi2dm : v2d_genericManaged<int32_t>
		{
		public:
			vi2dm() : v2d_genericManaged() {};
			vi2dm(v2d_generic<int32_t>* _impl) : v2d_genericManaged(_impl) {};
			vi2dm(int32_t _x, int32_t _y) : v2d_genericManaged(_x, _y) {};
		};
		public ref class vu2dm : v2d_genericManaged<uint32_t>
		{
		public:
			vu2dm() : v2d_genericManaged() {};
			vu2dm(v2d_generic<uint32_t>* _impl) : v2d_genericManaged(_impl) {};
			vu2dm(uint32_t _x, uint32_t _y) : v2d_genericManaged(_x, _y) {};
		};
		public ref class vf2dm : v2d_genericManaged<float>
		{
		public:
			vf2dm() : v2d_genericManaged() {};
			vf2dm(v2d_generic<float>* _impl) : v2d_genericManaged(_impl) {};
			vf2dm(float _x, float _y) : v2d_genericManaged(_x, _y) {};
		};
		public ref class vd2dm : v2d_genericManaged<double>
		{
		public:
			vd2dm() : v2d_genericManaged() {};
			vd2dm(v2d_generic<double>* _impl) : v2d_genericManaged(_impl) {};
			vd2dm(double _x, double _y) : v2d_genericManaged(_x, _y) {};
		};
		// Const version
		public ref class vi2dcm : v2d_genericConstManaged<int32_t>
		{
		public:
			vi2dcm() : v2d_genericConstManaged() {};
			vi2dcm(const v2d_generic<int32_t>* _impl) : v2d_genericConstManaged(_impl) {};
			vi2dcm(int32_t _x, int32_t _y) : v2d_genericConstManaged(_x, _y) {};
		};
		public ref class vu2dcm : v2d_genericConstManaged<uint32_t>
		{
		public:
			vu2dcm() : v2d_genericConstManaged() {};
			vu2dcm(const v2d_generic<uint32_t>* _impl) : v2d_genericConstManaged(_impl) {};
			vu2dcm(uint32_t _x, uint32_t _y) : v2d_genericConstManaged(_x, _y) {};
		};
		public ref class vf2dcm : v2d_genericConstManaged<float>
		{
		public:
			vf2dcm() : v2d_genericConstManaged() {};
			vf2dcm(const v2d_generic<float>* _impl) : v2d_genericConstManaged(_impl) {};
			vf2dcm(float _x, float _y) : v2d_genericConstManaged(_x, _y) {};
		};
		public ref class vd2dcm : v2d_genericConstManaged<double>
		{
		public:
			vd2dcm() : v2d_genericConstManaged() {};
			vd2dcm(const v2d_generic<double>* _impl) : v2d_genericConstManaged(_impl) {};
			vd2dcm(double _x, double _y) : v2d_genericConstManaged(_x, _y) {};
		};


		/// <summary>
		/// PIXEL IMPL
		/// </summary>
		public ref struct PixelManaged {
		private:
			Pixel* nativeImpl;

		public:

			enum class Mode { NORMAL, MASK, ALPHA, CUSTOM };

			PixelManaged() { nativeImpl = new Pixel(); }
			PixelManaged(uint8_t red, uint8_t green, uint8_t blue) { nativeImpl = new Pixel(red, green, blue); }
			PixelManaged(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) { nativeImpl = new Pixel(red, green, blue, alpha); }
			PixelManaged(uint32_t p) { nativeImpl = new Pixel(p); }
			PixelManaged(Pixel* _impl) { nativeImpl = _impl; }


			property uint32_t N
			{
			public: uint32_t get() { return nativeImpl->n; }
			public: void set(uint32_t value)
			{
				nativeImpl->n = value;
			}
			}

			property uint8_t R
			{
			public: uint8_t get() { return nativeImpl->r; }
			public: void set(uint8_t value)
			{
				nativeImpl->r = value;
			}
			}

			property uint8_t G
			{
			public: uint8_t get() { return nativeImpl->g; }
			public: void set(uint8_t value)
			{
				nativeImpl->g = value;
			}
			}

			property uint8_t B
			{
			public: uint8_t get() { return nativeImpl->b; }
			public: void set(uint8_t value)
			{
				nativeImpl->b = value;
			}
			}

			property uint8_t A
			{
			public: uint8_t get() { return nativeImpl->a; }
			public: void set(uint8_t value)
			{
				nativeImpl->a = value;
			}
			}

			Pixel* GetImplementation() { return nativeImpl; }

		};


		/// <summary>
		/// RESOURCEPACK IMPL
		/// </summary>
		public ref struct ResourcePackManaged {
		private:
			ResourcePack* nativeImpl;

		public:

		public:
			ResourcePackManaged() { nativeImpl = new ResourcePack(); }

			bool AddFile(System::String^ sFile);
			bool LoadPack(System::String^ sFile, System::String^ sKey);
			bool SavePack(System::String^ sFile, System::String^ sKey);
			System::Collections::Generic::List<char>^ GetFileBuffer(System::String^ sFile);
			bool Loaded();

		public:
			ResourcePack* GetImplementation() { return nativeImpl; }

		};

		/// <summary>
		/// SPRITE IMPL
		/// </summary>
		public ref struct SpriteManaged {
		private:
			Sprite* nativeImpl;

		public:
			SpriteManaged() { nativeImpl = new Sprite(); }
			SpriteManaged(System::String^ sImageFile, ResourcePackManaged^ pack) { nativeImpl = new Sprite(Util::MarshalString(sImageFile), pack->GetImplementation()); }
			SpriteManaged(System::String^ sImageFile) { nativeImpl = new Sprite(Util::MarshalString(sImageFile)); }
			SpriteManaged(int32_t w, int32_t h) { nativeImpl = new Sprite(w, h); }
			SpriteManaged(Sprite* _impl) { nativeImpl = _impl; }


		public:
			rcodeManaged LoadFromFile(System::String^ sImageFile, ResourcePackManaged^ pack);
			rcodeManaged LoadFromFile(System::String^ sImageFile);
			rcodeManaged LoadFromPGESprFile(System::String^ sImageFile, ResourcePackManaged^ pack);
			rcodeManaged LoadFromPGESprFile(System::String^ sImageFile);
			rcodeManaged SaveToPGESprFile(System::String^ sImageFile);

		public:

			property int32_t Width
			{
			public: int32_t get() { return nativeImpl->width; }
			public: void set(int32_t value)
			{
				nativeImpl->width = value;
			}
			}
			property int32_t Height
			{
			public: int32_t get() { return nativeImpl->height; }
			public: void set(int32_t value)
			{
				nativeImpl->height = value;
			}
			}

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

			Sprite* GetImplementation() { return nativeImpl; }

		};

		public ref struct HWButtonManaged
		{
		private:
			HWButton* nativeImpl;

		public:
			HWButtonManaged() { nativeImpl = new HWButton(); }
			HWButtonManaged(HWButton* _impl)
			{
				nativeImpl = _impl;
				bPressed = _impl->bPressed;
				bReleased = _impl->bReleased;
				bHeld = _impl->bHeld;
			}

			bool bPressed = false;		// Set once during the frame the event occurs
			bool bReleased = false;		// Set once during the frame the event occurs
			bool bHeld = false;			// Set true for all frames between pressed and released events

			HWButton* GetImplementation() { return nativeImpl; }
		};


		// ----- Decal managed -------
		public ref class DecalManaged
		{
		private:
			Decal* nativeImpl;

		public:
			DecalManaged(SpriteManaged^ spr, bool filter) { nativeImpl = new Decal(spr->GetImplementation(), filter); }
			DecalManaged(SpriteManaged^ spr) { nativeImpl = new Decal(spr->GetImplementation()); }
			DecalManaged(Decal* impl) { nativeImpl = impl; }


			void Update();

			property SpriteManaged^ Sprite {
		public: SpriteManaged^ get() { return gcnew SpriteManaged(nativeImpl->sprite); }
			}

			Decal* GetImplementation() { return nativeImpl; }
		};

		public enum class DecalModeManaged
		{
			NORMAL,
			ADDITIVE,
			MULTIPLICATIVE,
			STENCIL,
			ILLUMINATE,
		};


		public ref struct DecalInstanceManaged
		{
		private:
			DecalInstance* nativeImpl;

			DecalManaged^ decal;
			array<vf2dm^>^ pos;
			array<vf2dm^>^ uv;
			array<float>^ w;
			array<PixelManaged^>^ tint;
			DecalModeManaged mode;

		public:
			DecalInstanceManaged()
			{
				nativeImpl = new DecalInstance();
				CopyFromNative();
			}
			DecalInstanceManaged(DecalInstance* impl)
			{
				nativeImpl = impl;
				CopyFromNative();
			}
			DecalInstance* GetImplementation() { return nativeImpl; }

			void CopyFromNative()
			{
				if (pos == nullptr) { pos = gcnew array<vf2dm^>(4); }
				if (uv == nullptr) { uv = gcnew array<vf2dm^>(4); }
				if (w == nullptr) { w = gcnew array<float>(4); }
				if (tint == nullptr) { tint = gcnew array<PixelManaged^>(4); }

				decal = gcnew DecalManaged(nativeImpl->decal);
				for (int i = 0; i < 4; ++i)
				{
					pos[i] = gcnew vf2dm((&nativeImpl->pos)[i]);
					uv[i] = gcnew vf2dm((&nativeImpl->uv)[i]);
					w[i] = *(&nativeImpl->w)[i];
					tint[i] = gcnew PixelManaged((&nativeImpl->tint)[i]);
				}
				mode = (DecalModeManaged)nativeImpl->mode;
			}

			property DecalManaged^ Decal
			{
			public: DecalManaged^ get() { return decal; }
			public: void set(DecalManaged^ value)
			{
				decal = value;
				nativeImpl->decal = value->GetImplementation();
			}
			}

			property array<vf2dm^>^ Pos
			{
			public: array<vf2dm^>^ get() { return pos; }
			public: void set(array<vf2dm^>^ value)
			{
				pos = value;
				auto refArray = &nativeImpl->pos;

				for (int i = 0; i < sizeof(refArray); ++i)
				{
					*refArray[i] = *value[i]->GetImplementation();
				}
			}
			}

			property array<vf2dm^>^ Uv
			{
			public: array<vf2dm^>^ get() { return uv; }
			public: void set(array<vf2dm^>^ value)
			{
				uv = value;
				auto refArray = &nativeImpl->uv;

				for (int i = 0; i < sizeof(refArray); ++i)
				{
					*refArray[i] = *value[i]->GetImplementation();
				}
			}
			}

			property array<float>^ W
			{
			public: array<float>^ get() { return w; }
			public: void set(array<float>^ value)
			{
				w = value;
				auto refArray = &nativeImpl->w;

				for (int i = 0; i < sizeof(refArray); ++i)
				{
					*refArray[i] = value[i];
				}
			}
			}

			property array<PixelManaged^>^ Tint
			{
			public: array<PixelManaged^>^ get() { return tint; }
			public: void set(array<PixelManaged^>^ value)
			{
				tint = value;
				auto refArray = &nativeImpl->tint;

				for (int i = 0; i < sizeof(refArray); ++i)
				{
					*refArray[i] = *value[i]->GetImplementation();
				}
			}
			}

			property DecalModeManaged Mode
			{
			public: DecalModeManaged get() { return mode; }
			public: void set(DecalModeManaged value)
			{
				mode = value;
				nativeImpl->mode = (DecalMode)value;
			}
			}
		};

		// LayerDesc
		public ref struct LayerDescManaged
		{
		private:
			LayerDesc* nativeImpl;

			vf2dm^ vOffset;
			vf2dm^ vScale;
			SpriteManaged^ pDrawTarget;
			uint32_t nResID;
			List<DecalInstanceManaged^>^ vecDecalInstance;
			PixelManaged^ tint;
			//System::Action^ funcHook;

		public:
			LayerDescManaged()
			{
				nativeImpl = new LayerDesc();
				CopyFromNative();
			}
			LayerDescManaged(LayerDesc* impl)
			{
				nativeImpl = impl;
				CopyFromNative();
			}
			LayerDesc* GetImplementation() { return nativeImpl; }

			void CopyFromNative()
			{
				if (vecDecalInstance == nullptr) { vecDecalInstance = gcnew List<DecalInstanceManaged^>(); }

				vOffset = gcnew vf2dm(&nativeImpl->vOffset);
				vScale = gcnew vf2dm(&nativeImpl->vScale);
				pDrawTarget = gcnew SpriteManaged(nativeImpl->pDrawTarget);
				nResID = nResID;
				tint = gcnew PixelManaged(&nativeImpl->tint);
				vecDecalInstance->Clear();
				for (int i = 0; i < nativeImpl->vecDecalInstance.size(); ++i)
				{
					vecDecalInstance->Add(gcnew DecalInstanceManaged(&nativeImpl->vecDecalInstance.at(i)));
				}
			}

			property vf2dm^ Offset
			{
			public: vf2dm^ get() { return vOffset; }
			public: void set(vf2dm^ value)
			{
				vOffset = value;
				nativeImpl->vOffset = *value->GetImplementation();
			}
			}


			property vf2dm^ Scale
			{
			public: vf2dm^ get() { return vScale; }
			public: void set(vf2dm^ value)
			{
				vScale = value;
				nativeImpl->vScale = *value->GetImplementation();
			}
			}

			property bool Show
			{
			public: bool get() { return nativeImpl->bShow; }
			public: void set(bool value)
			{
				nativeImpl->bShow = value;
			}
			}

			property bool Update
			{
			public: bool get() { return nativeImpl->bUpdate; }
			public: void set(bool value)
			{
				nativeImpl->bUpdate = value;
			}
			}

			property SpriteManaged^ DrawTarget
			{
			public: SpriteManaged^ get() { return pDrawTarget; }
			public: void set(SpriteManaged^ value)
			{
				pDrawTarget = value;
				nativeImpl->pDrawTarget = value->GetImplementation();
			}
			}

			property uint32_t ResID
			{
			public: uint32_t get() { return nResID; }
			public: void set(uint32_t value)
			{
				nResID = value;
				nativeImpl->nResID = value;
			}
			}

			property List<DecalInstanceManaged^>^ DecalInstance
			{
			public: List<DecalInstanceManaged^>^ get() { return vecDecalInstance; }
			public: void set(List<DecalInstanceManaged^>^ value)
			{
				vecDecalInstance = value;
				auto refArray = &nativeImpl->vecDecalInstance;

				for (int i = 0; i < sizeof(refArray); ++i)
				{
					refArray->at(i) = *value[i]->GetImplementation();
				}
			}
			}

			property PixelManaged^ Tint
			{
			public: PixelManaged^ get() { return tint; }
			public: void set(PixelManaged^ value)
			{
				tint = value;
				nativeImpl->tint = *value->GetImplementation();
			}
			}

		};



		/// <summary>
		///  Managed wrapper class
		/// </summary>

		public ref class PixelGameEngineManaged abstract {
		private:
			PixelGameEngine* nativeImpl;

		public:
			PixelGameEngineManaged() { nativeImpl = new olcPixelGameEngineWithOwner(this); }

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
			vi2dcm^ GetWindowMouse();
			//// Gets the mouse as a vector to keep Tarriest happy
			vi2dcm^ GetMousePos();

		public: // Core stuff
			rcodeManaged Construct(int32_t screen_w, int32_t screen_h, int32_t pixel_w, int32_t pixel_h, bool full_screen, bool vsync, bool cohesion);
			rcodeManaged Construct(int32_t screen_w, int32_t screen_h, int32_t pixel_w, int32_t pixel_h, bool full_screen, bool vsync);
			rcodeManaged Construct(int32_t screen_w, int32_t screen_h, int32_t pixel_w, int32_t pixel_h, bool full_screen);
			rcodeManaged Construct(int32_t screen_w, int32_t screen_h, int32_t pixel_w, int32_t pixel_h);
			rcodeManaged Start();


		public: // Utilities
			// Returns the width of the screen in "pixels"
			int32_t ScreenWidth();
			// Returns the height of the screen in "pixels"
			int32_t ScreenHeight();
			// Returns the width of the currently selected drawing target in "pixels"
			int32_t GetDrawTargetWidth();
			// Returns the height of the currently selected drawing target in "pixels"
			int32_t GetDrawTargetHeight();
			// Returns the currently active draw target
			SpriteManaged^ GetDrawTarget();
			// Resize the primary screen sprite
			void SetScreenSize(int w, int h);
			// Specify which Sprite should be the target of drawing functions, use nullptr
			// to specify the primary screen
			void SetDrawTarget(SpriteManaged^ target);
			// Gets the current Frames Per Second
			uint32_t GetFPS();
			// Gets last update of elapsed time
			float GetElapsedTime();
			// Gets Actual Window size
			vi2dcm^ GetWindowSize();
			// Gets pixel scale
			vi2dcm^ GetPixelSize();
			// Gets actual pixel scale
			vi2dcm^ GetScreenPixelSize();

		public: // CONFIGURATION ROUTINES
			// Layer targeting functions
			void SetDrawTarget(uint8_t layer);
			void EnableLayer(uint8_t layer, bool b);
			void SetLayerOffset(uint8_t layer, vf2dm^ offset);
			void SetLayerOffset(uint8_t layer, float x, float y);
			void SetLayerScale(uint8_t layer, vf2dm^ scale);
			void SetLayerScale(uint8_t layer, float x, float y);
			void SetLayerTint(uint8_t layer, PixelManaged^ tint);
			//void SetLayerCustomRenderFunction(uint8_t layer, System::Action^);

			List<LayerDescManaged^>^ GetLayers();
			uint32_t CreateLayer();

			// Change the pixel mode for different optimisations
			// olc::Pixel::NORMAL = No transparency
			// olc::Pixel::MASK   = Transparent if alpha is < 255
			// olc::Pixel::ALPHA  = Full transparency
			void SetPixelMode(PixelManaged::Mode m);
			PixelManaged::Mode GetPixelMode();
			// Use a custom blend function
			//void SetPixelMode(std::function<olc::Pixel(const int x, const int y, const olc::Pixel& pSource, const olc::Pixel& pDest)> pixelMode);
			// Change the blend factor form between 0.0f to 1.0f;
			void SetPixelBlend(float fBlend);


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
			void DrawRect(vi2dm^ pos, vi2dm^ size, PixelManaged^ p);
			void DrawRect(vi2dm^ pos, vi2dm^ size);

			// Fills a rectangle at (x,y) to (x+w,y+h)
			void FillRect(int32_t x, int32_t y, int32_t w, int32_t h, PixelManaged^ p);
			void FillRect(int32_t x, int32_t y, int32_t w, int32_t h);
			void FillRect(vi2dm^ pos, vi2dm^ size, PixelManaged^ p);
			void FillRect(vi2dm^ pos, vi2dm^ size);

			// Draws a line from (x1,y1) to (x2,y2)
			void DrawLine(int32_t x1, int32_t y1, int32_t x2, int32_t y2, PixelManaged^ p, uint32_t pattern);
			void DrawLine(int32_t x1, int32_t y1, int32_t x2, int32_t y2, PixelManaged^ p);
			void DrawLine(int32_t x1, int32_t y1, int32_t x2, int32_t y2);
			void DrawLine(vi2dm^ pos1, vi2dm^ pos2, PixelManaged^ p, uint32_t pattern);
			void DrawLine(vi2dm^ pos1, vi2dm^ pos2, PixelManaged^ p);
			void DrawLine(vi2dm^ pos1, vi2dm^ pos2);
			// Draws a circle located at (x,y) with radius
			void DrawCircle(int32_t x, int32_t y, int32_t radius, PixelManaged^ p, uint8_t mask);
			void DrawCircle(int32_t x, int32_t y, int32_t radius, PixelManaged^ p);
			void DrawCircle(int32_t x, int32_t y, int32_t radius);
			void DrawCircle(vi2dm^ pos, int32_t radius, PixelManaged^ p, uint8_t mask);
			void DrawCircle(vi2dm^ pos, int32_t radius, PixelManaged^ p);
			void DrawCircle(vi2dm^ pos, int32_t radius);
			// Fills a circle located at (x,y) with radius
			void FillCircle(int32_t x, int32_t y, int32_t radius, PixelManaged^ p);
			void FillCircle(int32_t x, int32_t y, int32_t radius);
			void FillCircle(vi2dm^ pos, int32_t radius, PixelManaged^ p);
			void FillCircle(vi2dm^ pos, int32_t radius);

			// Draws a triangle between points (x1,y1), (x2,y2) and (x3,y3)
			void DrawTriangle(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3, PixelManaged^ p);
			void DrawTriangle(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3);
			void DrawTriangle(vi2dm^ pos1, vi2dm^ pos2, vi2dm^ pos3, PixelManaged^ p);
			void DrawTriangle(vi2dm^ pos1, vi2dm^ pos2, vi2dm^ pos3);
			// Flat fills a triangle between points (x1,y1), (x2,y2) and (x3,y3)
			void FillTriangle(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3, PixelManaged^ p);
			void FillTriangle(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3);
			void FillTriangle(vi2dm^ pos1, vi2dm^ pos2, vi2dm^ pos3, PixelManaged^ p);
			void FillTriangle(vi2dm^ pos1, vi2dm^ pos2, vi2dm^ pos3);

			// ---------- Decals -----------
			// Decal Quad functions
			void SetDecalMode(DecalModeManaged mode);
			// Draws a whole decal, with optional scale and tinting
			void DrawDecal(vf2dm^ pos, DecalManaged^ decal, vf2dm^ scale, PixelManaged^ tint);
			void DrawDecal(vf2dm^ pos, DecalManaged^ decal, vf2dm^ scale);
			void DrawDecal(vf2dm^ pos, DecalManaged^ decal);
			// Draws a region of a decal, with optional scale and tinting
			void DrawPartialDecal(vf2dm^ pos, DecalManaged^ decal, vf2dm^ source_pos, vf2dm^ source_size, vf2dm^ scale, PixelManaged^ tint);
			void DrawPartialDecal(vf2dm^ pos, DecalManaged^ decal, vf2dm^ source_pos, vf2dm^ source_size, vf2dm^ scale);
			void DrawPartialDecal(vf2dm^ pos, DecalManaged^ decal, vf2dm^ source_pos, vf2dm^ source_size);
			void DrawPartialDecal(vf2dm^ pos, vf2dm^ size, DecalManaged^ decal, vf2dm^ source_pos, vf2dm^ source_size, PixelManaged^ tint);
			void DrawPartialDecal(vf2dm^ pos, vf2dm^ size, DecalManaged^ decal, vf2dm^ source_pos, vf2dm^ source_size);
			// Draws fully user controlled 4 vertices, pos(pixels), uv(pixels), colours
			void DrawExplicitDecal(DecalManaged^ decal, vf2dm^ pos, vf2dm^ uv, PixelManaged^ col);
			// Draws a decal with 4 arbitrary points, warping the texture to look "correct"
			void DrawWarpedDecal(DecalManaged^ decal, vf2dm^ pos, PixelManaged^ tint);
			void DrawWarpedDecal(DecalManaged^ decal, vf2dm^ pos);
			void DrawWarpedDecal(DecalManaged^ decal, List<vf2dm^>^ pos, PixelManaged^ tint);
			void DrawWarpedDecal(DecalManaged^ decal, List<vf2dm^>^ pos);
			// As above, but you can specify a region of a decal source sprite
			void DrawPartialWarpedDecal(DecalManaged^ decal, vf2dm^ pos, vf2dm^ source_pos, vf2dm^ source_size, PixelManaged^ tint);
			void DrawPartialWarpedDecal(DecalManaged^ decal, vf2dm^ pos, vf2dm^ source_pos, vf2dm^ source_size);
			void DrawPartialWarpedDecal(DecalManaged^ decal, List<vf2dm^>^ pos, vf2dm^ source_pos, vf2dm^ source_size, PixelManaged^ tint);
			void DrawPartialWarpedDecal(DecalManaged^ decal, List<vf2dm^>^ pos, vf2dm^ source_pos, vf2dm^ source_size);
			// Draws a decal rotated to specified angle, wit point of rotation offset
			void DrawRotatedDecal(vf2dm^ pos, DecalManaged^ decal, float fAngle, vf2dm^ center, vf2dm^ scale, PixelManaged^ tint);
			void DrawRotatedDecal(vf2dm^ pos, DecalManaged^ decal, float fAngle, vf2dm^ center, vf2dm^ scale);
			void DrawRotatedDecal(vf2dm^ pos, DecalManaged^ decal, float fAngle, vf2dm^ center);
			void DrawRotatedDecal(vf2dm^ pos, DecalManaged^ decal, float fAngle);
			void DrawPartialRotatedDecal(vf2dm^ pos, DecalManaged^ decal, float fAngle, vf2dm^ center, vf2dm^ source_pos, vf2dm^ source_size, vf2dm^ scale, PixelManaged^ tint);
			void DrawPartialRotatedDecal(vf2dm^ pos, DecalManaged^ decal, float fAngle, vf2dm^ center, vf2dm^ source_pos, vf2dm^ source_size, vf2dm^ scale);
			void DrawPartialRotatedDecal(vf2dm^ pos, DecalManaged^ decal, float fAngle, vf2dm^ center, vf2dm^ source_pos, vf2dm^ source_size);
			// Draws a multiline string as a decal, with tiniting and scaling
			void DrawStringDecal(vf2dm^ pos, System::String^ sText, PixelManaged^ col, vf2dm^ scale);
			void DrawStringDecal(vf2dm^ pos, System::String^ sText, PixelManaged^ col);
			void DrawStringDecal(vf2dm^ pos, System::String^ sText);
			void DrawStringPropDecal(vf2dm^ pos, System::String^ sText, PixelManaged^ col, vf2dm^ scale);
			void DrawStringPropDecal(vf2dm^ pos, System::String^ sText, PixelManaged^ col);
			void DrawStringPropDecal(vf2dm^ pos, System::String^ sText);
			// Draws a single shaded filled rectangle as a decal
			void FillRectDecal(vf2dm^ pos, vf2dm^ size, PixelManaged^ col);
			void FillRectDecal(vf2dm^ pos, vf2dm^ size);
			// Draws a corner shaded rectangle as a decal
			void GradientFillRectDecal(vf2dm^ pos, vf2dm^ size, PixelManaged^ colTL, PixelManaged^ colBL, PixelManaged^ colBR, PixelManaged^ colTR);

			void Clear(PixelManaged^ p);

		internal:
			bool CallOnUserCreate()
			{
				if (!nativeImpl) throw gcnew System::ObjectDisposedException("olcPixelGameEngineWithOwner");
				return OnUserCreate();
			}
			bool CallOnUserUpdate(float fElapsedTime)
			{
				if (!nativeImpl) throw gcnew System::ObjectDisposedException("olcPixelGameEngineWithOwner");
				return OnUserUpdate(fElapsedTime);
			}
			bool CallOnUserDestroy()
			{
				if (!nativeImpl) throw gcnew System::ObjectDisposedException("olcPixelGameEngineWithOwner");
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
	namespace managed
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
			return nativeImpl->AddFile(Util::MarshalString(sFile));
		}
		bool ResourcePackManaged::LoadPack(System::String^ sFile, System::String^ sKey)
		{
			return nativeImpl->LoadPack(Util::MarshalString(sFile), Util::MarshalString(sKey));
		}
		bool ResourcePackManaged::SavePack(System::String^ sFile, System::String^ sKey)
		{
			return nativeImpl->SavePack(Util::MarshalString(sFile), Util::MarshalString(sKey));
		}
		List<char>^ ResourcePackManaged::GetFileBuffer(System::String^ sFile)
		{
			std::vector<char> buffer = nativeImpl->GetFileBuffer(Util::MarshalString(sFile)).vMemory;
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
			return nativeImpl->Loaded();
		}

		// -------- Sprite ----------

		rcodeManaged SpriteManaged::LoadFromFile(System::String^ sImageFile, ResourcePackManaged^ pack)
		{
			return (rcodeManaged)nativeImpl->LoadFromFile(Util::MarshalString(sImageFile), pack->GetImplementation());
		}
		rcodeManaged SpriteManaged::LoadFromFile(System::String^ sImageFile) {
			return (rcodeManaged)nativeImpl->LoadFromFile(Util::MarshalString(sImageFile));
		}
		rcodeManaged SpriteManaged::LoadFromPGESprFile(System::String^ sImageFile, ResourcePackManaged^ pack) {
			return (rcodeManaged)nativeImpl->LoadFromPGESprFile(Util::MarshalString(sImageFile), pack->GetImplementation());
		}
		rcodeManaged SpriteManaged::LoadFromPGESprFile(System::String^ sImageFile) {
			return (rcodeManaged)nativeImpl->LoadFromPGESprFile(Util::MarshalString(sImageFile));
		}
		rcodeManaged SpriteManaged::SaveToPGESprFile(System::String^ sImageFile) {
			return (rcodeManaged)nativeImpl->SaveToPGESprFile(Util::MarshalString(sImageFile));
		}


		void SpriteManaged::SetSampleMode()
		{
			nativeImpl->SetSampleMode();
		}
		void SpriteManaged::SetSampleMode(ModeManaged mode)
		{
			nativeImpl->SetSampleMode((olc::Sprite::Mode)mode);
		}
		PixelManaged^ SpriteManaged::GetPixel(int32_t x, int32_t y)
		{
			return gcnew PixelManaged(&nativeImpl->GetPixel(x, y));
		}
		bool  SpriteManaged::SetPixel(int32_t x, int32_t y, PixelManaged^ p)
		{
			return nativeImpl->SetPixel(x, y, *p->GetImplementation());
		}
		PixelManaged^ SpriteManaged::GetPixel(vi2dm^ a)
		{
			return  gcnew PixelManaged(&nativeImpl->GetPixel(*a->GetImplementation()));
		}
		bool  SpriteManaged::SetPixel(vi2dm^ a, PixelManaged^ p)
		{
			return nativeImpl->SetPixel(*a->GetImplementation(), *p->GetImplementation());
		}
		PixelManaged^ SpriteManaged::Sample(float x, float y)
		{
			return  gcnew PixelManaged(&nativeImpl->Sample(x, y));
		}
		PixelManaged^ SpriteManaged::SampleBL(float u, float v)
		{
			return  gcnew PixelManaged(&nativeImpl->SampleBL(u, v));
		}
		PixelManaged^ SpriteManaged::GetData()
		{
			return  gcnew PixelManaged(nativeImpl->GetData());
		}
		SpriteManaged^ SpriteManaged::Duplicate()
		{
			return  gcnew SpriteManaged(nativeImpl->Duplicate());
		}
		SpriteManaged^ SpriteManaged::Duplicate(vi2dm^ vPos, vi2dm^ vSize)
		{
			return  gcnew SpriteManaged(nativeImpl->Duplicate(*vPos->GetImplementation(), *vSize->GetImplementation()));
		}

		PixelManaged^ SpriteManaged::pColData()
		{
			return  gcnew PixelManaged(nativeImpl->pColData);
		}
		SpriteManaged::ModeManaged^ SpriteManaged::modeSample()
		{
			return (SpriteManaged::ModeManaged)nativeImpl->modeSample;
		}

		// -------- Decals ----------
		void DecalManaged::Update()
		{
			nativeImpl->Update();
		}


		// =============== OLC GAME ENGINE ============

// Hardware
		bool PixelGameEngineManaged::IsFocused()
		{
			return nativeImpl->IsFocused();
		}
		// Get the state of a specific keyboard button
		HWButtonManaged^ PixelGameEngineManaged::GetKey(KeyManaged k)
		{
			return gcnew HWButtonManaged(&nativeImpl->GetKey((Key)k));
		}
		// Get the state of a specific mouse button
		HWButtonManaged^ PixelGameEngineManaged::GetMouse(uint32_t b)
		{
			return gcnew HWButtonManaged(&nativeImpl->GetMouse(b));
		}
		// Get Mouse X coordinate in "pixel" space
		int32_t PixelGameEngineManaged::GetMouseX()
		{
			return nativeImpl->GetMouseX();
		}
		// Get Mouse Y coordinate in "pixel" space
		int32_t PixelGameEngineManaged::GetMouseY()
		{
			return nativeImpl->GetMouseY();
		}
		// Get Mouse Wheel Delta
		int32_t PixelGameEngineManaged::GetMouseWheel()
		{
			return nativeImpl->GetMouseWheel();
		}
		//// Get the mouse in window space
		vi2dcm^ PixelGameEngineManaged::GetWindowMouse()
		{
			return gcnew vi2dcm(&nativeImpl->GetWindowMouse());
		}
		//// Gets the mouse as a vector to keep Tarriest happy
		vi2dcm^ PixelGameEngineManaged::GetMousePos()
		{
			return gcnew vi2dcm(&nativeImpl->GetMousePos());
		}
		// Core methods

		rcodeManaged PixelGameEngineManaged::Construct(int32_t screen_w, int32_t screen_h, int32_t pixel_w, int32_t pixel_h, bool full_screen, bool vsync, bool cohesion)
		{
			return (rcodeManaged)nativeImpl->Construct(screen_w, screen_h, pixel_w, pixel_h, full_screen, vsync, cohesion);
		}

		rcodeManaged PixelGameEngineManaged::Construct(int32_t screen_w, int32_t screen_h, int32_t pixel_w, int32_t pixel_h, bool full_screen, bool vsync)
		{
			return (rcodeManaged)nativeImpl->Construct(screen_w, screen_h, pixel_w, pixel_h, full_screen);
		}

		rcodeManaged PixelGameEngineManaged::Construct(int32_t screen_w, int32_t screen_h, int32_t pixel_w, int32_t pixel_h, bool full_screen)
		{
			return (rcodeManaged)nativeImpl->Construct(screen_w, screen_h, pixel_w, pixel_h, full_screen);
		}

		rcodeManaged PixelGameEngineManaged::Construct(int32_t screen_w, int32_t screen_h, int32_t pixel_w, int32_t pixel_h)
		{
			return (rcodeManaged)nativeImpl->Construct(screen_w, screen_h, pixel_w, pixel_h);
		}

		rcodeManaged PixelGameEngineManaged::Start()
		{
			return (rcodeManaged)nativeImpl->Start();
		}


		// Utilities

		// Returns the width of the screen in "pixels"
		int32_t PixelGameEngineManaged::ScreenWidth() {
			return nativeImpl->ScreenWidth();
		}

		// Returns the height of the screen in "pixels"
		int32_t PixelGameEngineManaged::ScreenHeight() {
			return nativeImpl->ScreenHeight();
		}

		// Returns the width of the currently selected drawing target in "pixels"
		int32_t PixelGameEngineManaged::GetDrawTargetWidth()
		{
			return nativeImpl->GetDrawTargetWidth();
		}
		// Returns the height of the currently selected drawing target in "pixels"
		int32_t PixelGameEngineManaged::GetDrawTargetHeight()
		{
			return nativeImpl->GetDrawTargetHeight();
		}
		// Returns the currently active draw target
		SpriteManaged^ PixelGameEngineManaged::GetDrawTarget()
		{
			return gcnew SpriteManaged(nativeImpl->GetDrawTarget());
		}
		// Resize the primary screen sprite
		void PixelGameEngineManaged::SetScreenSize(int w, int h)
		{
			nativeImpl->SetScreenSize(w, h);
		}
		// Specify which Sprite should be the target of drawing functions, use nullptr
		// to specify the primary screen
		void PixelGameEngineManaged::SetDrawTarget(SpriteManaged^ target)
		{
			nativeImpl->SetDrawTarget(target->GetImplementation());
		}
		// Gets the current Frames Per Second
		uint32_t PixelGameEngineManaged::GetFPS()
		{
			return nativeImpl->GetFPS();
		}
		// Gets last update of elapsed time
		float PixelGameEngineManaged::GetElapsedTime()
		{
			return nativeImpl->GetElapsedTime();
		}
		// Gets Actual Window size
		vi2dcm^ PixelGameEngineManaged::GetWindowSize()
		{
			return gcnew vi2dcm(&nativeImpl->GetWindowSize());
		}
		// Gets pixel scale
		vi2dcm^ PixelGameEngineManaged::GetPixelSize()
		{
			return gcnew vi2dcm(&nativeImpl->GetPixelSize());
		}
		// Gets actual pixel scale
		vi2dcm^ PixelGameEngineManaged::GetScreenPixelSize()
		{
			return gcnew vi2dcm(&nativeImpl->GetScreenPixelSize());
		}

		// CONFIGURATION ROUTINES
		// Layer targeting functions
		void PixelGameEngineManaged::SetDrawTarget(uint8_t layer)
		{
			nativeImpl->SetDrawTarget(layer);
		}
		void PixelGameEngineManaged::EnableLayer(uint8_t layer, bool b)
		{
			nativeImpl->EnableLayer(layer, b);
		}
		void PixelGameEngineManaged::SetLayerOffset(uint8_t layer, vf2dm^ offset)
		{
			nativeImpl->SetLayerOffset(layer, *offset->GetImplementation());
		}
		void PixelGameEngineManaged::SetLayerOffset(uint8_t layer, float x, float y)
		{
			nativeImpl->SetLayerOffset(layer, x, y);
		}
		void PixelGameEngineManaged::SetLayerScale(uint8_t layer, vf2dm^ scale)
		{
			nativeImpl->SetLayerScale(layer, *scale->GetImplementation());
		}
		void PixelGameEngineManaged::SetLayerScale(uint8_t layer, float x, float y)
		{
			nativeImpl->SetLayerScale(layer, x, y);
		}
		void PixelGameEngineManaged::SetLayerTint(uint8_t layer, PixelManaged^ tint)
		{
			nativeImpl->SetLayerTint(layer, *tint->GetImplementation());
		}
		/*void PixelGameEngineManaged::SetLayerCustomRenderFunction(uint8_t layer, System::Action^)
		{
			nativeImpl->SetLayerOffset(layer, *offset->GetImplementation());
		}*/

		List<LayerDescManaged^>^ PixelGameEngineManaged::GetLayers()
		{
			// TODO: Make this generic util
			auto native = nativeImpl->GetLayers();
			auto result = gcnew List<LayerDescManaged^>(native.size());
			for (int i = 0; i < result->Capacity; ++i)
			{
				result->Add(gcnew LayerDescManaged(&native.at(i)));
			}
			return result;
		}
		uint32_t PixelGameEngineManaged::CreateLayer()
		{
			return nativeImpl->CreateLayer();
		}

		// Change the pixel mode for different optimisations
		// olc::Pixel::NORMAL = No transparency
		// olc::Pixel::MASK   = Transparent if alpha is < 255
		// olc::Pixel::ALPHA  = Full transparency
		void PixelGameEngineManaged::SetPixelMode(PixelManaged::Mode m)
		{
			nativeImpl->SetPixelMode((Pixel::Mode)m);
		}
		PixelManaged::Mode PixelGameEngineManaged::GetPixelMode()
		{
			return (PixelManaged::Mode)nativeImpl->GetPixelMode();
		}
		// Use a custom blend function
		//void SetPixelMode(std::function<olc::Pixel(const int x, const int y, const olc::Pixel& pSource, const olc::Pixel& pDest)> pixelMode);
		// Change the blend factor form between 0.0f to 1.0f;
		void PixelGameEngineManaged::SetPixelBlend(float fBlend)
		{
			nativeImpl->SetPixelBlend(fBlend);
		}

		// DRAW

		void PixelGameEngineManaged::Clear(PixelManaged^ p)
		{
			nativeImpl->Clear(*p->GetImplementation());
		}

		bool PixelGameEngineManaged::Draw(vi2dm^ pos, PixelManaged^ p) {
			return nativeImpl->Draw(*pos->GetImplementation(), *p->GetImplementation());
		}
		bool PixelGameEngineManaged::Draw(int x, int y, PixelManaged^ p) {
			return nativeImpl->Draw((int32_t)x, (int32_t)y, *p->GetImplementation());
		}

		void PixelGameEngineManaged::DrawString(int32_t x, int32_t y, System::String^ sText, PixelManaged^ col, uint32_t scale) {
			return nativeImpl->DrawString((int32_t)x, (int32_t)y, Util::MarshalString(sText), *col->GetImplementation(), scale);
		}
		void PixelGameEngineManaged::DrawString(int32_t x, int32_t y, System::String^ sText, PixelManaged^ col) {
			return nativeImpl->DrawString((int32_t)x, (int32_t)y, Util::MarshalString(sText), *col->GetImplementation());
		}
		void PixelGameEngineManaged::DrawString(int32_t x, int32_t y, System::String^ sText) {
			return nativeImpl->DrawString((int32_t)x, (int32_t)y, Util::MarshalString(sText));
		}

		void PixelGameEngineManaged::DrawString(vi2dm^ pos, System::String^ sText, PixelManaged^ col, uint32_t scale) {
			return nativeImpl->DrawString(*pos->GetImplementation(), Util::MarshalString(sText), *col->GetImplementation(), scale);
		}
		void PixelGameEngineManaged::DrawString(vi2dm^ pos, System::String^ sText, PixelManaged^ col) {
			return nativeImpl->DrawString(*pos->GetImplementation(), Util::MarshalString(sText), *col->GetImplementation());
		}
		void PixelGameEngineManaged::DrawString(vi2dm^ pos, System::String^ sText) {
			return nativeImpl->DrawString(*pos->GetImplementation(), Util::MarshalString(sText));
		}
		vi2dm^ PixelGameEngineManaged::GetTextSize(System::String^ s) {
			return gcnew vi2dm(&nativeImpl->GetTextSize(Util::MarshalString(s)));
		}

		void PixelGameEngineManaged::DrawSprite(int32_t x, int32_t y, SpriteManaged^ sprite, uint32_t scale, uint8_t flip)
		{
			nativeImpl->DrawSprite(x, y, sprite->GetImplementation(), scale, flip);
		}
		void PixelGameEngineManaged::DrawSprite(int32_t x, int32_t y, SpriteManaged^ sprite, uint32_t scale)
		{
			nativeImpl->DrawSprite(x, y, sprite->GetImplementation(), scale);
		}
		void PixelGameEngineManaged::DrawSprite(int32_t x, int32_t y, SpriteManaged^ sprite)
		{
			nativeImpl->DrawSprite(x, y, sprite->GetImplementation());
		}
		void PixelGameEngineManaged::DrawSprite(vi2dm^ pos, SpriteManaged^ sprite, uint32_t scale, uint8_t flip)
		{
			nativeImpl->DrawSprite(*pos->GetImplementation(), sprite->GetImplementation(), scale, flip);
		}
		void PixelGameEngineManaged::DrawSprite(vi2dm^ pos, SpriteManaged^ sprite, uint32_t scale)
		{
			nativeImpl->DrawSprite(*pos->GetImplementation(), sprite->GetImplementation(), scale);
		}
		void PixelGameEngineManaged::DrawSprite(vi2dm^ pos, SpriteManaged^ sprite) {
			nativeImpl->DrawSprite(*pos->GetImplementation(), sprite->GetImplementation());
		}

		// Draws a rectangle at (x,y) to (x+w,y+h)
		void PixelGameEngineManaged::DrawRect(int32_t x, int32_t y, int32_t w, int32_t h, PixelManaged^ p)
		{
			nativeImpl->DrawRect(x, y, w, h, *p->GetImplementation());
		}
		void PixelGameEngineManaged::DrawRect(int32_t x, int32_t y, int32_t w, int32_t h) {
			nativeImpl->DrawRect(x, y, w, h);
		}
		void PixelGameEngineManaged::DrawRect(vi2dm^ pos, vi2dm^ size, PixelManaged^ p)
		{
			nativeImpl->DrawRect(*pos->GetImplementation(), *size->GetImplementation(), *p->GetImplementation());
		}
		void PixelGameEngineManaged::DrawRect(vi2dm^ pos, vi2dm^ size)
		{
			nativeImpl->DrawRect(*pos->GetImplementation(), *size->GetImplementation());
		}

		// Fills a rectangle at (x,y) to (x+w,y+h)
		void PixelGameEngineManaged::FillRect(int32_t x, int32_t y, int32_t w, int32_t h, PixelManaged^ p) {
			nativeImpl->FillRect(x, y, w, h, *p->GetImplementation());
		}
		void PixelGameEngineManaged::FillRect(int32_t x, int32_t y, int32_t w, int32_t h) {
			nativeImpl->FillRect(x, y, w, h);
		}
		void PixelGameEngineManaged::FillRect(vi2dm^ pos, vi2dm^ size, PixelManaged^ p) {
			nativeImpl->FillRect(*pos->GetImplementation(), *size->GetImplementation(), *p->GetImplementation());
		}
		void PixelGameEngineManaged::FillRect(vi2dm^ pos, vi2dm^ size) {
			nativeImpl->FillRect(*pos->GetImplementation(), *size->GetImplementation());
		}

		// Draws a line from (x1,y1) to (x2,y2)
		void PixelGameEngineManaged::DrawLine(int32_t x1, int32_t y1, int32_t x2, int32_t y2, PixelManaged^ p, uint32_t pattern)
		{
			nativeImpl->DrawLine(x1, y1, x2, y2, *p->GetImplementation(), pattern);
		}
		void PixelGameEngineManaged::DrawLine(int32_t x1, int32_t y1, int32_t x2, int32_t y2, PixelManaged^ p) {
			nativeImpl->DrawLine(x1, y1, x2, y2, *p->GetImplementation());
		}
		void PixelGameEngineManaged::DrawLine(int32_t x1, int32_t y1, int32_t x2, int32_t y2) {
			nativeImpl->DrawLine(x1, y1, x2, y2);
		}
		void PixelGameEngineManaged::DrawLine(vi2dm^ pos1, vi2dm^ pos2, PixelManaged^ p, uint32_t pattern) {
			nativeImpl->DrawLine(*pos1->GetImplementation(), *pos2->GetImplementation(), *p->GetImplementation(), pattern);
		}
		void PixelGameEngineManaged::DrawLine(vi2dm^ pos1, vi2dm^ pos2, PixelManaged^ p) {
			nativeImpl->DrawLine(*pos1->GetImplementation(), *pos2->GetImplementation(), *p->GetImplementation());
		}
		void PixelGameEngineManaged::DrawLine(vi2dm^ pos1, vi2dm^ pos2) {
			nativeImpl->DrawLine(*pos1->GetImplementation(), *pos2->GetImplementation());
		}
		// Draws a circle located at (x,y) with radius
		void PixelGameEngineManaged::DrawCircle(int32_t x, int32_t y, int32_t radius, PixelManaged^ p, uint8_t mask) {
			nativeImpl->DrawCircle(x, y, radius, *p->GetImplementation(), mask);
		}
		void PixelGameEngineManaged::DrawCircle(int32_t x, int32_t y, int32_t radius, PixelManaged^ p) {
			nativeImpl->DrawCircle(x, y, radius, *p->GetImplementation());
		}
		void PixelGameEngineManaged::DrawCircle(int32_t x, int32_t y, int32_t radius) {
			nativeImpl->DrawCircle(x, y, radius);
		}
		void PixelGameEngineManaged::DrawCircle(vi2dm^ pos, int32_t radius, PixelManaged^ p, uint8_t mask) {
			nativeImpl->DrawCircle(*pos->GetImplementation(), radius, *p->GetImplementation(), mask);
		}
		void PixelGameEngineManaged::DrawCircle(vi2dm^ pos, int32_t radius, PixelManaged^ p) {
			nativeImpl->DrawCircle(*pos->GetImplementation(), radius, *p->GetImplementation());
		}
		void PixelGameEngineManaged::DrawCircle(vi2dm^ pos, int32_t radius) {
			nativeImpl->DrawCircle(*pos->GetImplementation(), radius);
		}
		// Fills a circle located at (x,y) with radius
		void PixelGameEngineManaged::FillCircle(int32_t x, int32_t y, int32_t radius, PixelManaged^ p) {
			nativeImpl->FillCircle(x, y, radius, *p->GetImplementation());
		}
		void PixelGameEngineManaged::FillCircle(int32_t x, int32_t y, int32_t radius) {
			nativeImpl->FillCircle(x, y, radius);
		}
		void PixelGameEngineManaged::FillCircle(vi2dm^ pos, int32_t radius, PixelManaged^ p) {
			nativeImpl->DrawCircle(*pos->GetImplementation(), radius, *p->GetImplementation());
		}
		void PixelGameEngineManaged::FillCircle(vi2dm^ pos, int32_t radius) {
			nativeImpl->DrawCircle(*pos->GetImplementation(), radius);
		}

		// Draws a triangle between points (x1,y1), (x2,y2) and (x3,y3)
		void PixelGameEngineManaged::DrawTriangle(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3, PixelManaged^ p) {}
		void PixelGameEngineManaged::DrawTriangle(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3) {}
		void PixelGameEngineManaged::DrawTriangle(vi2dm^ pos1, vi2dm^ pos2, vi2dm^ pos3, PixelManaged^ p) {}
		void PixelGameEngineManaged::DrawTriangle(vi2dm^ pos1, vi2dm^ pos2, vi2dm^ pos3) {}
		// Flat fills a triangle between points (x1,y1), (x2,y2) and (x3,y3)
		void PixelGameEngineManaged::FillTriangle(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3, PixelManaged^ p) {}
		void PixelGameEngineManaged::FillTriangle(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3) {}
		void PixelGameEngineManaged::FillTriangle(vi2dm^ pos1, vi2dm^ pos2, vi2dm^ pos3, PixelManaged^ p) {}
		void PixelGameEngineManaged::FillTriangle(vi2dm^ pos1, vi2dm^ pos2, vi2dm^ pos3) {}

		// ---------- Decals -----------
		// Decal Quad functions
		void PixelGameEngineManaged::SetDecalMode(DecalModeManaged mode)
		{
			nativeImpl->SetDecalMode((DecalMode)mode);
		}
		// Draws a whole decal, with optional scale and tinting
		void PixelGameEngineManaged::DrawDecal(vf2dm^ pos, DecalManaged^ decal, vf2dm^ scale, PixelManaged^ tint)
		{
			nativeImpl->DrawDecal(*pos->GetImplementation(), decal->GetImplementation(), *scale->GetImplementation(), *tint->GetImplementation());
		}
		void PixelGameEngineManaged::DrawDecal(vf2dm^ pos, DecalManaged^ decal, vf2dm^ scale)
		{
			nativeImpl->DrawDecal(*pos->GetImplementation(), decal->GetImplementation(), *scale->GetImplementation());
		}
		void PixelGameEngineManaged::DrawDecal(vf2dm^ pos, DecalManaged^ decal)
		{
			nativeImpl->DrawDecal(*pos->GetImplementation(), decal->GetImplementation());
		}
		// Draws a region of a decal, with optional scale and tinting
		void PixelGameEngineManaged::DrawPartialDecal(vf2dm^ pos, DecalManaged^ decal, vf2dm^ source_pos, vf2dm^ source_size, vf2dm^ scale, PixelManaged^ tint)
		{
			nativeImpl->DrawPartialDecal(*pos->GetImplementation(), decal->GetImplementation(), *source_pos->GetImplementation(), *source_size->GetImplementation(), *scale->GetImplementation(), *tint->GetImplementation());
		}
		void PixelGameEngineManaged::DrawPartialDecal(vf2dm^ pos, DecalManaged^ decal, vf2dm^ source_pos, vf2dm^ source_size, vf2dm^ scale)
		{
			nativeImpl->DrawPartialDecal(*pos->GetImplementation(), decal->GetImplementation(), *source_pos->GetImplementation(), *source_size->GetImplementation(), *scale->GetImplementation());
		}
		void PixelGameEngineManaged::DrawPartialDecal(vf2dm^ pos, DecalManaged^ decal, vf2dm^ source_pos, vf2dm^ source_size)
		{
			nativeImpl->DrawPartialDecal(*pos->GetImplementation(), decal->GetImplementation(), *source_pos->GetImplementation(), *source_size->GetImplementation());
		}
		void PixelGameEngineManaged::DrawPartialDecal(vf2dm^ pos, vf2dm^ size, DecalManaged^ decal, vf2dm^ source_pos, vf2dm^ source_size, PixelManaged^ tint)
		{
			nativeImpl->DrawPartialDecal(*pos->GetImplementation(), *size->GetImplementation(), decal->GetImplementation(), *source_pos->GetImplementation(), *source_size->GetImplementation(), *tint->GetImplementation());
		}
		void PixelGameEngineManaged::DrawPartialDecal(vf2dm^ pos, vf2dm^ size, DecalManaged^ decal, vf2dm^ source_pos, vf2dm^ source_size)
		{
			nativeImpl->DrawPartialDecal(*pos->GetImplementation(), *size->GetImplementation(), decal->GetImplementation(), *source_pos->GetImplementation(), *source_size->GetImplementation());
		}
		// Draws fully user controlled 4 vertices, pos(pixels), uv(pixels), colours
		void PixelGameEngineManaged::DrawExplicitDecal(DecalManaged^ decal, vf2dm^ pos, vf2dm^ uv, PixelManaged^ col)
		{
			nativeImpl->DrawExplicitDecal(decal->GetImplementation(), pos->GetImplementation(), uv->GetImplementation(), col->GetImplementation());
		}
		// Draws a decal with 4 arbitrary points, warping the texture to look "correct"
		void PixelGameEngineManaged::DrawWarpedDecal(DecalManaged^ decal, vf2dm^ pos, PixelManaged^ tint)
		{
			nativeImpl->DrawWarpedDecal(decal->GetImplementation(), pos->GetImplementation(), *tint->GetImplementation());
		}
		void PixelGameEngineManaged::DrawWarpedDecal(DecalManaged^ decal, vf2dm^ pos)
		{
			nativeImpl->DrawWarpedDecal(decal->GetImplementation(), pos->GetImplementation());
		}
		void PixelGameEngineManaged::DrawWarpedDecal(DecalManaged^ decal, List<vf2dm^>^ pos, PixelManaged^ tint)
		{
			auto posNative = new std::array<vf2d, 4>();

			for (int i = 0; i < 4; ++i)
			{
				(*posNative).at(i) = *pos[0]->GetImplementation();
			}

			nativeImpl->DrawWarpedDecal(decal->GetImplementation(), *posNative, *tint->GetImplementation());
		}
		void PixelGameEngineManaged::DrawWarpedDecal(DecalManaged^ decal, List<vf2dm^>^ pos)
		{
			auto posNative = new std::array<vf2d, 4>();

			for (int i = 0; i < 4; ++i)
			{
				(*posNative).at(i) = *pos[0]->GetImplementation();
			}

			nativeImpl->DrawWarpedDecal(decal->GetImplementation(), *posNative);
		}
		// As above, but you can specify a region of a decal source sprite
		void PixelGameEngineManaged::DrawPartialWarpedDecal(DecalManaged^ decal, vf2dm^ pos, vf2dm^ source_pos, vf2dm^ source_size, PixelManaged^ tint)
		{
			nativeImpl->DrawPartialWarpedDecal(decal->GetImplementation(), pos->GetImplementation(), *source_pos->GetImplementation(), *source_size->GetImplementation(), *tint->GetImplementation());
		}
		void PixelGameEngineManaged::DrawPartialWarpedDecal(DecalManaged^ decal, vf2dm^ pos, vf2dm^ source_pos, vf2dm^ source_size)
		{
			nativeImpl->DrawPartialWarpedDecal(decal->GetImplementation(), pos->GetImplementation(), *source_pos->GetImplementation(), *source_size->GetImplementation());
		}
		void PixelGameEngineManaged::DrawPartialWarpedDecal(DecalManaged^ decal, List<vf2dm^>^ pos, vf2dm^ source_pos, vf2dm^ source_size, PixelManaged^ tint)
		{
			auto posNative = new std::array<vf2d, 4>();

			for (int i = 0; i < 4; ++i)
			{
				(*posNative).at(i) = *pos[0]->GetImplementation();
			}
			nativeImpl->DrawPartialWarpedDecal(decal->GetImplementation(), *posNative, *source_pos->GetImplementation(), *source_size->GetImplementation(), *tint->GetImplementation());
		}
		void PixelGameEngineManaged::DrawPartialWarpedDecal(DecalManaged^ decal, List<vf2dm^>^ pos, vf2dm^ source_pos, vf2dm^ source_size)
		{
			auto posNative = new std::array<vf2d, 4>();

			for (int i = 0; i < 4; ++i)
			{
				(*posNative).at(i) = *pos[0]->GetImplementation();
			}
			nativeImpl->DrawPartialWarpedDecal(decal->GetImplementation(), *posNative, *source_pos->GetImplementation(), *source_size->GetImplementation());
		}
		// Draws a decal rotated to specified angle, wit point of rotation offset
		void PixelGameEngineManaged::DrawRotatedDecal(vf2dm^ pos, DecalManaged^ decal, float fAngle, vf2dm^ center, vf2dm^ scale, PixelManaged^ tint)
		{
			nativeImpl->DrawRotatedDecal(*pos->GetImplementation(), decal->GetImplementation(), fAngle, *center->GetImplementation(), *scale->GetImplementation(), *tint->GetImplementation());
		}
		void PixelGameEngineManaged::DrawRotatedDecal(vf2dm^ pos, DecalManaged^ decal, float fAngle, vf2dm^ center, vf2dm^ scale)
		{
			nativeImpl->DrawRotatedDecal(*pos->GetImplementation(), decal->GetImplementation(), fAngle, *center->GetImplementation(), *scale->GetImplementation());
		}
		void PixelGameEngineManaged::DrawRotatedDecal(vf2dm^ pos, DecalManaged^ decal, float fAngle, vf2dm^ center)
		{
			nativeImpl->DrawRotatedDecal(*pos->GetImplementation(), decal->GetImplementation(), fAngle, *center->GetImplementation());
		}
		void PixelGameEngineManaged::DrawRotatedDecal(vf2dm^ pos, DecalManaged^ decal, float fAngle)
		{
			nativeImpl->DrawRotatedDecal(*pos->GetImplementation(), decal->GetImplementation(), fAngle);
		}
		void PixelGameEngineManaged::DrawPartialRotatedDecal(vf2dm^ pos, DecalManaged^ decal, float fAngle, vf2dm^ center, vf2dm^ source_pos, vf2dm^ source_size, vf2dm^ scale, PixelManaged^ tint)
		{
			nativeImpl->DrawPartialRotatedDecal(*pos->GetImplementation(), decal->GetImplementation(), fAngle, *center->GetImplementation(), *source_pos->GetImplementation(), *source_size->GetImplementation(), *scale->GetImplementation(), *tint->GetImplementation());
		}
		void PixelGameEngineManaged::DrawPartialRotatedDecal(vf2dm^ pos, DecalManaged^ decal, float fAngle, vf2dm^ center, vf2dm^ source_pos, vf2dm^ source_size, vf2dm^ scale)
		{
			nativeImpl->DrawPartialRotatedDecal(*pos->GetImplementation(), decal->GetImplementation(), fAngle, *center->GetImplementation(), *source_pos->GetImplementation(), *source_size->GetImplementation(), *scale->GetImplementation());
		}
		void PixelGameEngineManaged::DrawPartialRotatedDecal(vf2dm^ pos, DecalManaged^ decal, float fAngle, vf2dm^ center, vf2dm^ source_pos, vf2dm^ source_size)
		{
			nativeImpl->DrawPartialRotatedDecal(*pos->GetImplementation(), decal->GetImplementation(), fAngle, *center->GetImplementation(), *source_pos->GetImplementation(), *source_size->GetImplementation());
		}
		// Draws a multiline string as a decal, with tiniting and scaling
		void PixelGameEngineManaged::DrawStringDecal(vf2dm^ pos, System::String^ sText, PixelManaged^ col, vf2dm^ scale)
		{
			nativeImpl->DrawStringDecal(*pos->GetImplementation(), Util::MarshalString(sText), *col->GetImplementation(), *scale->GetImplementation());
		}
		void PixelGameEngineManaged::DrawStringDecal(vf2dm^ pos, System::String^ sText, PixelManaged^ col)
		{
			nativeImpl->DrawStringDecal(*pos->GetImplementation(), Util::MarshalString(sText), *col->GetImplementation());
		}
		void PixelGameEngineManaged::DrawStringDecal(vf2dm^ pos, System::String^ sText)
		{
			nativeImpl->DrawStringDecal(*pos->GetImplementation(), Util::MarshalString(sText));
		}
		void PixelGameEngineManaged::DrawStringPropDecal(vf2dm^ pos, System::String^ sText, PixelManaged^ col, vf2dm^ scale)
		{
			nativeImpl->DrawStringPropDecal(*pos->GetImplementation(), Util::MarshalString(sText), *col->GetImplementation(), *scale->GetImplementation());
		}
		void PixelGameEngineManaged::DrawStringPropDecal(vf2dm^ pos, System::String^ sText, PixelManaged^ col)
		{
			nativeImpl->DrawStringPropDecal(*pos->GetImplementation(), Util::MarshalString(sText), *col->GetImplementation());
		}
		void PixelGameEngineManaged::DrawStringPropDecal(vf2dm^ pos, System::String^ sText)
		{
			nativeImpl->DrawStringPropDecal(*pos->GetImplementation(), Util::MarshalString(sText));
		}
		// Draws a single shaded filled rectangle as a decal
		void PixelGameEngineManaged::FillRectDecal(vf2dm^ pos, vf2dm^ size, PixelManaged^ col)
		{
			nativeImpl->FillRectDecal(*pos->GetImplementation(), *size->GetImplementation(), *col->GetImplementation());
		}
		void PixelGameEngineManaged::FillRectDecal(vf2dm^ pos, vf2dm^ size)
		{
			nativeImpl->FillRectDecal(*pos->GetImplementation(), *size->GetImplementation());
		}
		// Draws a corner shaded rectangle as a decal
		void PixelGameEngineManaged::GradientFillRectDecal(vf2dm^ pos, vf2dm^ size, PixelManaged^ colTL, PixelManaged^ colBL, PixelManaged^ colBR, PixelManaged^ colTR)
		{
			nativeImpl->GradientFillRectDecal(*pos->GetImplementation(), *size->GetImplementation(), *colTL->GetImplementation(), *colBL->GetImplementation(), *colBR->GetImplementation(), *colTR->GetImplementation());
		}
	}
}