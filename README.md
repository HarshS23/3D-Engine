
# 3D Engine (CPU Rasterizer)

A lightweight, 3D engine written in C (CPU rasterizer), using the Left-Handed Coordinate system.  
Focus: **clarity + performance** on the CPU — no OpenGL/DirectX required.

<p align="center">
  <img src="images/OP1.png" width="49%" alt="Clean wireframe"/>
  <img src="images/OP2.png" width="45%" alt="Wireframe with vertices"/>
  <img src="images/OP3.png" width="45%" alt="Filled"/>
  <img src="images/OP4.png" width="45%" alt="Wireframe with vertices"/>
  
</p>


## Features
- OBJ loader (verts/uvs/normals/faces)
- Draw modes: **Wireframe**, **Wireframe + vertices**, **Filled**, **Filled+wire**,
- Movable first-person camera
- Backface culling, near-plane clipping
- Solid black background


## Quick Start

### Dependencies
- C99 compiler (clang/gcc)
- **SDL2**

**macOS (Homebrew)**
```bash
brew install sdl2
make        
