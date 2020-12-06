# olcPixelGameEngineManaged
This is a managed c++/CLI wrapper around OneLoneCoder's olcGameEngine components. This enable library access to managed C#,Vb.net,F# applications.
This wrapper is made using dotnet core 3.1 C++CLI support.

# Wrapper VS fully managed re-implementation
This projects wraps aroud native code to bridge between both runtime environments. This minimise overhead as most work is performed by native code as is.
Since the main focus of the engine should be ease of use and performance. I think this is the best compromise.
This also make staying up to date with the main code base much easier. As long as the method signatures are the same, there may be no changes to be made after merging.

This is still a long process since everything has to be wrapped 

# Disclaimer
I am a complete C++ noob ! 
I'm learning C++ quirks along with the .net framework interoperability layer quirks... There is much to improve.
Pretty much all functionnalities are currently supported, but the code is currently ugly, disorganised and I may have done some horrible things to the eyes of some !

Sadly this is Windows only as C++/CLI is not supported on other platforms.

I made this for fun as a learning experiement to see if it could be done and how performance is affected compared to the original.

But it works enough to fully support a C# implementation of olcNES
See : https://github.com/davignola/olcNESharp

Big thanks to OneLoneCoder for the original sources, this is a ton of fun to explore.

Original project banner ahead :

# olcPixelGameEngine
The official distribution of olcPixelGameEngine, a tool used in javidx9's YouTube videos and projects.

**You only need the one file - olcPixelGameEngine.h - included in your project!**

Provides a fast, richly featured, cross platform pixel drawing and user interface framework for
 * The development of games
 * Visualisation of algorithms
 * Prototyping and experimentation
 * Education

olcPixelGameEngine is easily extended! for example:
 * 2D Affine transforms
 * 3D Software renderer
 * Controller input
 * Sound
 * Hardware interfaces
 
olcPixelGameEngine is easy to port! Runs on:
 * Windows (all)
 * Linux / Raspberry Pi / ChromeOS
 * MacOS (coming soon to official, but already available in "Contributors")
 * PSP & Switch (Not supported by OneLoneCoder)
 
olcPixelGameEngine has been reimplemented in other languages!
 * C#
 * Rust
 * Lua
 * Java
  
olcPixelGameEngine is actively maintained and developed!

olcPixelGameEngine is used by 100s, if not 1000s of programmers at all levels of ability!


# Documentation
Please see https://github.com/OneLoneCoder/olcPixelGameEngine/wiki

# License (OLC-3)

Copyright 2018, 2019, 2020 OneLoneCoder.com

Redistribution and use in source and binary forms, with or without 
modification, are permitted provided that the following conditions 
are met:

1. Redistributions or derivations of source code must retain the above 
   copyright notice, this list of conditions and the following disclaimer.

2. Redistributions or derivative works in binary form must reproduce 
   the above copyright notice. This list of conditions and the following 
   disclaimer must be reproduced in the documentation and/or other 
   materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its 
   contributors may be used to endorse or promote products derived 
   from this software without specific prior written permission.
    
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR 
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, 
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY 
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
