# Ruby Touch (Ruby Mobile)

[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](LICENSE.md)
[![Platform](https://img.shields.io/badge/Platform-Android%2024%2B-green.svg)](https://developer.android.com)
[![Architecture](https://img.shields.io/badge/Architecture-ARM64--v8a%20%7C%20ARMv7%20(arm32)%20%7C%20x86__64%20%7C%20x86-orange.svg)](#multi-architecture-support)
[![UI Framework](https://img.shields.io/badge/UI-Qt%206.6%20Quick%20%2F%20QML-41cd52.svg)](https://www.qt.io/)
[![Version](https://img.shields.io/badge/Version-v1.2-blue.svg)](https://github.com/TheAevoraLabs/RubyTouch/releases)
[![Privacy: Zero Telemetry](https://img.shields.io/badge/Privacy-Zero%20Telemetry-success.svg)](PRIVACY_POLICY.md)
[![Upstream](https://img.shields.io/badge/Upstream-SwordigoDesktop-informational.svg)](https://github.com/TheAevoraLabs/SwordigoDesktop)

Ruby Touch (also called **Ruby Mobile**, formerly Ruby GG Mobile) is a high-performance, standalone mobile 3D scene studio and terrain editor tailored for Swordigo modders and level designers. Built entirely in modern C++20 and Qt 6 with OpenGL ES 3.0, Ruby Touch brings precision 3D viewport navigation, interactive ground mesh vertex editing, and in-place biome texturing to Android devices.

> **Upstream Project Notice**: Ruby Touch (Ruby Mobile) is the dedicated mobile distribution and mirror repository for the mobile 3D editor component of [SwordigoDesktop](https://github.com/TheAevoraLabs/SwordigoDesktop). All core engine improvements, tools, and bug fixes are maintained upstream and mirrored here for standalone mobile packaging and F-Droid distribution.

> **v1.2 Architecture Redesign**: v1.2 introduces comprehensive multi-architecture split APK distribution, bringing native device compatibility across 64-bit ARM (`arm64-v8a`), 32-bit legacy ARM (`armeabi-v7a`), 64-bit x86 (`x86_64`), and 32-bit x86 (`x86`) Android devices and emulators. Each architecture is packaged as an independent, lightweight APK with optimized native binaries and stripped symbol tables.

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
- Android NDK (r25b or later; tested with r28)
- Qt 6.6.3 for Android (ARM64-v8a target)
- CMake 3.22+ and Ninja
- JDK 17

### Build Commands

```bash
# Clone the repository
git clone https://github.com/TheAevoraLabs/RubyTouch.git
cd RubyTouch

# Build for specific architecture:
./build_android.sh --abi arm64-v8a    # 64-bit ARM
./build_android.sh --abi armeabi-v7a  # 32-bit ARM (ARMv7)
./build_android.sh --abi x86_64       # 64-bit x86 (emulators / Chromebooks)
./build_android.sh --abi x86          # 32-bit x86

# Or build for all architectures sequentially:
./build_android.sh --all-abis
```

The compiled and signed APK will be output to `bin/RubyTouch-<ABI>.apk`. If an Android device is connected via ADB with USB debugging enabled, the script will automatically install and launch the application.

---

## Multi-Architecture Support & Split APKs

Ruby Touch v1.2 is packaged as distinct, architecture-specific standalone APKs to minimize storage overhead and maximize execution efficiency on every class of hardware:

| Architecture | Android ABI | Target Hardware | APK Filename |
| :--- | :--- | :--- | :--- |
| **ARM 64-bit** | `arm64-v8a` | Modern Android smartphones & tablets (2016+) | `RubyTouch-v1.2-arm64-v8a.apk` |
| **ARM 32-bit** | `armeabi-v7a` | Legacy budget smartphones, older tablets | `RubyTouch-v1.2-armeabi-v7a.apk` |
| **x86 64-bit** | `x86_64` | Android emulators, ChromeOS / Chromebooks | `RubyTouch-v1.2-x86_64.apk` |
| **x86 32-bit** | `x86` | Older x86 virtualization & emulators | `RubyTouch-v1.2-x86.apk` |

---

## Translations & Localisation

Legal and license documentation is translated into 13 languages located in [.github/.localisation/](.github/.localisation/):

- Indian Languages: Hindi, Bengali, Telugu, Tamil, Marathi, Gujarati
- International Languages: Spanish, French, Chinese, German, Japanese, Russian, Portuguese

---

## Privacy Policy

Ruby Touch respects user privacy and operates 100% offline. The software does not collect, store, transmit, or monetize any personal data, telemetry, or user analytics. Device permissions are strictly utilized for local file modding and haptic feedback. See [PRIVACY_POLICY.md](PRIVACY_POLICY.md) for our complete privacy policy.

---

## License

Ruby Touch is free software licensed under the GNU General Public License v3.0 (GPLv3). See [LICENSE.md](LICENSE.md) for full terms and conditions.

Copyright (C) 2026 The Lawncher Team & The Aevora Labs.
