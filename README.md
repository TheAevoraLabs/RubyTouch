# Ruby Touch

[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](LICENSE.md)
[![Platform](https://img.shields.io/badge/Platform-Android%2024%2B-green.svg)](https://developer.android.com)
[![Architecture](https://img.shields.io/badge/Architecture-ARM64--v8a%20%7C%20armeabi--v7a%20%7C%20x86__64-orange.svg)](#architecture)
[![UI Framework](https://img.shields.io/badge/UI-Qt%206.6%20Quick%20%2F%20QML-41cd52.svg)](https://www.qt.io/)
[![Upstream](https://img.shields.io/badge/Upstream-SwordigoDesktop-informational.svg)](https://gitlab.com/AevoralabsIN/SwordigoDesktop)

Ruby Touch is a high-performance, standalone mobile 3D scene studio and terrain editor tailored for Swordigo modders and level designers. Built entirely in modern C++20 and Qt 6 with OpenGL ES 3.0, Ruby Touch brings precision 3D viewport navigation, interactive ground mesh vertex editing, and in-place biome texturing to Android devices.

> **Upstream Project Notice**: Ruby Touch is the dedicated mobile distribution and mirror repository for the mobile 3D editor component of [SwordigoDesktop](https://gitlab.com/AevoralabsIN/SwordigoDesktop). All core engine improvements, tools, and bug fixes are maintained upstream and mirrored here for standalone mobile packaging and F-Droid distribution.
>
> **Repository homes**: primary development happens on [GitLab](https://gitlab.com/AevoralabsIN/RubyTouch), with a mirror on [Codeberg](https://codeberg.org/quantumcreeper/RubyTouch). Our previous GitHub organisation was terminated by automated moderation, so `github.com` links in older documents are historical.

---

## Key Features

### Touch-Optimized 3D Viewport
- **Dual Thumbstick Navigation**: Ergonomic floating thumbsticks for camera movement, flight elevation, and orbit control.
- **Hardware Refresh Rate**: Fully supports 90Hz and 120Hz high-refresh displays for smooth 3D viewport rendering.
- **OpenGL ES 3.0 Shaders**: Real-time rendering of terrain, alpha-blended geometry, sky domes, and bounding gizmos.

### Ground Mesh Studio
- **Direct 3D Vertex Editing**: Tap and drag terrain vertices in 3D space using ray-plane mathematical projection.
- **Native Overlay Rendering**: Diamond vertex selection handles and wireframe outlines rendered directly in the OpenGL pipeline.
- **Topology Tools**: Add new vertices, remove existing points, and cycle through control points via a floating mobile toolbar.
- **Non-Destructive In-Place Apply**: Retains existing component identifiers and dimension objects without geometric trashing.

### Biome Inspector & Terrain Texturing
- **In-Place Texture Swapping**: Change surface cap textures and vertical cliff textures instantly without mesh regeneration.
- **Authentic Biome Presets**: One-touch access to 10 verified biome profiles:
  - Plains (grass_subtle + maybegood)
  - Forest (forest_grass + forest_ground)
  - Grove (grove_grass + grove_ground)
  - Florennum (florennum_ground + florennum_ground)
  - Wasteland (grass_orange + wasteland_ground)
  - Snowy Peaks (snowy_snow + atlon_ground)
  - Ice Castle (icicle + icecastle_ground)
  - Volcano (fire_grass + graveyard_ground)
  - Caves (wasteland_ground + wasteland_ground2)
  - Crypt (crypt_tiles + crypt_tiles)
- **Custom Modder Presets**: Save, name, and manage custom texture combinations persisted via local device storage.

### Scene & Entity Inspection
- **Spatial Object Transform**: Position, rotate, and scale scene objects with touch feedback.
- **Component Inspector**: Read and update entity attributes, visual models, collision shapes, and entity tags.
- **File System Integration**: Integrated storage access for opening and saving .scene, .scl, and .swdm files.

### FileRift & Embedded Lua
- **Bytecode Inspection**: Schema analysis and syntax highlighting for game data structures.
- **Embedded Lua Runtime**: Headless ANSI C Lua engine for validating level scripts and event triggers.

---

## Architecture

```text
RubyTouch/
├── CMakeLists.txt                 # Root project wrapper
├── build_android.sh               # Standalone compilation and APK packaging script
├── fastlane/                      # Store and F-Droid metadata
│   └── metadata/android/en-US/
└── src/
    ├── ruby/                      # Mobile QML UI, C++ bridges, viewport math, and Android entry
    ├── tools/                     # Headless terrain, pod, scene, ufbx, and glTF loaders
    ├── platform/                  # PVR/ASTC texture decoders, zip archives, and data paths
    ├── stb/                       # Image encoding utilities
    ├── android/                   # Android native logging bridge
    └── sre/base/lua/              # Embedded Lua C runtime
```

---

## Building from Source

### Prerequisites
- Android SDK (API 34 or later) with Build-Tools 35.0.0+
- Android NDK (r25b or later; tested with r28c)
- Qt 6.6.3 for Android (`android_arm64_v8a` and/or `android_armv7`) plus host tools (`gcc_64`)
- CMake 3.22+ and Ninja
- JDK 17

Qt can be installed with [aqtinstall](https://aqtinstall.readthedocs.io/):

```bash
pip install aqtinstall
aqt install-qt linux android 6.6.3 android_arm64_v8a android_armv7 -O ~/Qt
aqt install-qt linux desktop 6.6.3 gcc_64 -O ~/Qt
```

### Build flavors

| Flavor | Command | Notes |
|---|---|---|
| FOSS | `./build_android.sh --foss --abi arm64-v8a` | Zero proprietary dependencies. The play-in-game / start-scene-in-game features (which need the proprietary GlossHook library) are compiled out and their buttons hidden; everything else works identically. |
| Full | `./build_android.sh --abi arm64-v8a` | All features, including play-in-game. Requires the proprietary GlossHook prebuilt at `libs/<abi>/libGlossHook.so` (not shipped in this repo). |

### Build Commands

```bash
# Clone the repository (GitLab primary, Codeberg mirror)
git clone https://gitlab.com/AevoralabsIN/RubyTouch.git
cd RubyTouch

# Point the build at your SDK and Qt
export ANDROID_SDK_ROOT=~/Android/Sdk
export QT_DIR=~/Qt            # must contain 6.6.3/android_arm64_v8a, 6.6.3/gcc_64, ...
export PATH=/usr/lib/jvm/java-17-openjdk/bin:$PATH

# FOSS build for the default ABI (arm64-v8a)
./build_android.sh --foss

# Or pick an ABI / build all of them (arm64-v8a, armeabi-v7a, x86_64, x86)
./build_android.sh --foss --abi armeabi-v7a
./build_android.sh --foss --all-abis
```

Signed APKs are written to `bin/` (e.g. `bin/RubyTouch-foss-arm64-v8a.apk`). Without signing configuration the script falls back to an auto-generated debug key; for release builds set `RUBY_KEYSTORE_PATH`, `RUBY_KEYSTORE_PASS`, `RUBY_KEY_ALIAS` and `RUBY_KEY_PASS` to sign with your persistent key.

---

## Translations & Localisation

Legal and license documentation is translated into 13 languages located in [.github/.localisation/](.github/.localisation/):

- Indian Languages: Hindi, Bengali, Telugu, Tamil, Marathi, Gujarati
- International Languages: Spanish, French, Chinese, German, Japanese, Russian, Portuguese

---

## License

Ruby Touch is free software licensed under the GNU General Public License v3.0 (GPLv3). See [LICENSE.md](LICENSE.md) for full terms and conditions.

Copyright (C) 2026 The Lawncher Team & The Aevora Labs.
