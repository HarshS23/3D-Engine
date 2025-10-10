
# 3D Engine in C (SDL2) CPU Rasterizer

A lightweight **software 3D rendering engine** written in **C** using **SDL2**.  
This project demonstrates the fundamentals of a real-time 3D graphics pipeline, including vector math, mesh loading, camera transformations, clipping, backface culling, and basic lighting.

<p align="center">
  <img src="images/OP1.png" width="45%" alt="Clean wireframe"/>
  <img src="images/OP2.png" width="45%" alt="Wireframe with vertices"/>
  <img src="images/OP3.png" width="45%" alt="Filled"/>
  <img src="images/OP4.png" width="45%" alt="Wireframe with vertices"/>
</p>



<!-- ## Demo Video
<p align="center">
  <a href="https://youtu.be/PCHrQZfpqto">
    <img src="https://img.youtube.com/vi/GSbUNflepYQ/0.jpg" width="720">
  </a>
</p> -->


## Demo Video
<p align="center">
  <a href="https://youtu.be/PCHrQZfpqto">
    <img src="https://img.youtube.com/vi/PCHrQZfpqto/0.jpg" width="720">
  </a>
</p>


---

##  Features
- **OBJ file parsing** – loads and stores mesh vertices, faces, normals, and texture coordinates.  
- **Multiple rendering modes**:
  1. Wireframe  
  2. Wireframe + Vertices (red dots)  
  3. Filled triangles (solid shading)  
  4. Filled + Wireframe overlay  
- **Camera system** – move and rotate freely with WASD + arrow keys.  
- **Backface culling** – skips rendering triangles not visible to the camera.  
- **Near-plane clipping** – prevents rendering artifacts when geometry crosses the camera plane.  
- **Basic directional lighting** – grayscale shading based on surface normals.  
- **Interactive model selection** – choose `.obj` files from the `assets/` folder at runtime.

---

##  Controls
| Key | Action |
|-----|---------|
| **W / S** | Move forward / backward |
| **A / D** | Strafe left / right |
| **Q / E** | Move camera up / down |
| **Arrow Keys** | Rotate camera (yaw / pitch) |
| **1–4** | Switch rendering mode |
| **R** | Reset camera to origin |
| **Close Window** | Quit program |
| **Exit Program (0)**| Quit program|
---


## Installation & Running

1. **Install SDL2**  
   - On macOS (Homebrew):  
     ```sh
     brew install sdl2
     ```

2. **Open the project in VS Code**  
   - Clone this repository.  
   - Open the folder in **Visual Studio Code** (or your preferred editor).  

3. **Build the program**  
   - In the VS Code terminal, run:  
     ```sh
     make
     ```  
   - This will compile the project and create the executable in the `./bin/` directory.  

4. **Run the program**  
   - Start the program with:  
     ```sh
     make run
     ```  
   - When prompted, type the name of the model file you want to render from the `assets/` directory.  
   - Be sure to **include the `.obj` extension**, for example:  
     ```
     f22.obj
     ```

5. **View your model**  
   - The program will open an SDL2 window and render the chosen `.obj` file.  


