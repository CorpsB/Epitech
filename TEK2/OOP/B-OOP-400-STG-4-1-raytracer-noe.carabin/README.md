
# Raytracer - OOP

### your CPU goes BRRRRRR!

---

```bash
./raytracer bonus/assets/scenes/scene1.cfg > output_image.ppm
```
Or to run it on 10 threads :
```bash
./raytracer bonus/assets/scenes/scene1.cfg -t 10 > output_image.ppm
```
Useful tip : Pass the -p flag to get realtime percentage completion updates in CLI. That way you can track performances and ETA easily.
```bash
./raytracer assets/scenes/scene1.cfg -t 10 > output_image.ppm
```


---

## Features

### Must
- **Primitives**
    - [x] Sphere
    - [x] Plane
- **Transformations**
    - [x] Translation
- **Light**
    - [x] Directional light
    - [x] Ambient light
- **Material**
    - [x] Flat color
- **Scene configuration**
    - [x] Add primitives to scene
    - [x] Set up lighting
    - [x] Set up camera
- **Interface**
    - [x] No GUI, output to PPM file

### Should
- **Primitives**
    - [x] Cylinder
    - [x] Cone
- **Transformations**
    - [x] Rotation
- **Light**
    - [x] Drop shadows

### Could
- **Primitives**
    - [x] Limited cylinder (0.5)
    - [x] Limited cone (0.5)
    - [x] Torus (1)
    - [x] Tanglecube (1)
    - [x] Triangles (1)
    - [x] .OBJ file import (1) (We have .STL)
    - [x] Fractals (2)
    - [ ] Möbius strip (2)

- **Transformations**
    - [x] Scale (0.5)
    - [x] Shear (0.5)
    - [x] Transformation matrix (2)
    - [ ] Scene graph (2)

- **Light**
    - [x] Multiple directional lights (0.5)
    - [x] Multiple point lights (1)
    - [x] Colored light (0.5)
    - [x] Phong reflection model (2)
    - [ ] Ambient occlusion (2)

- **Material**
    - [x] Transparency (0.5)
    - [x] Refraction (1)
    - [x] Reflection (0.5)
    - [x] Texturing from file (1)
    - [x] Procedural chessboard (1)
    - [ ] Procedural Perlin noise (1)
    - [ ] Normal mapping (2)

- **Scene configuration**
    - [ ] Import a scene in a scene (2)
    - [x] Supersampling antialiasing (0.5)
    - [ ] Adaptive antialiasing (1)

- **Optimizations**
    - [x] Space partitionning (2)
    - [x] Multithreading (1)
    - [ ] Clustering (3)

- **Interface**
    - [ ] Display image during and after generation (1)
    - [ ] Exit during generation (0.5)
    - [ ] Scene preview (2)
    - [ ] Automatic reload on file change (1)

- **Unlisted Initiatives**
    - [x] Tone Mapping