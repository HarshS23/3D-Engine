# 3D-Engine
This Repo contains source code for a 3D Engine

# 3D Engine (CPU Rasterizer)

A lightweight, educational 3D engine written in C (CPU rasterizer).
Focus: **clarity + performance** on the CPU — no OpenGL/DirectX required.

<p align="center">
  <img src="images/wireframe_with_vertices.png" width="45%" alt="Wireframe with vertices"/>
  <img src="images/wireframe_clean.png" width="45%" alt="Clean wireframe"/>
</p>

## Features
- OBJ loader (verts/uvs/normals/faces)
- Draw modes: **Wireframe**, **Wireframe + vertices**, **Filled**, **Filled+wire**, (**Textured** WIP)
- Movable first-person camera
- Backface culling, near-plane clipping, simple depth sort
- Toggleable debug overlays (FPS, triangle count)
- Solid black or navy grid background


## Quick Start

### Dependencies
- C99 compiler (clang/gcc)
- **SDL2** (recommended)

**macOS (Homebrew)**
```bash
brew install sdl2
make            # or: clang -std=c99 -O2 src/*.c -lSDL2 -o 3d-engine
./3d-engine
