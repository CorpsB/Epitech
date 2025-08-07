##
## EPITECH PROJECT, 2025
## B-OOP-400-STG-4-1-raytracer-noe.carabin
## File description:
## Makefile
##

CXX        := g++
CXXFLAGS   := -std=c++17 -Wall -Wextra -fopenmp -Iinclude
LDFLAGS    := -lconfig++
MAKEFLAGS += -j$(shell nproc)

GRAPH_SRC := src/core/Visualizer.cpp
GRAPH_OBJ := $(GRAPH_SRC:.cpp=.o)

SRC := src/core/main.cpp                \
       src/core/Raytracer.cpp           \
       src/core/Utils.cpp               \
       src/core/Vector3D.cpp            \
       src/core/Primitive.cpp			\
       src/loaders/STLLoader.cpp        \
       src/loaders/SceneParser.cpp   	\
       src/rendering/BVH.cpp            \
       src/rendering/Camera.cpp      	\
       src/rendering/CheckerTexture.cpp	\
       src/rendering/ImageTexture.cpp	\
       src/rendering/Material.cpp       \
       src/rendering/Mesh.cpp           \
       src/rendering/PostFX.cpp         \
       src/rendering/Scene.cpp          \
       src/rendering/ShadowShading.cpp	\
       src/rendering/Skybox.cpp         \
       src/primitives/Box.cpp           \
       src/primitives/Cone.cpp          \
       src/primitives/Cylinder.cpp      \
       src/primitives/Menger.cpp        \
       src/primitives/Plane.cpp         \
       src/primitives/Rectangle.cpp     \
       src/primitives/Sierpinski.cpp	\
       src/primitives/Sphere.cpp        \
       src/primitives/TangleCube.cpp	\
       src/primitives/Tetrahedron.cpp	\
       src/primitives/Torus.cpp			\
       src/primitives/Triangle.cpp		\
       src/geoTransf/Shear.cpp     \
       src/geoTransf/Rotation.cpp  \
       src/geoTransf/Matrix.cpp    \
       src/core/Parallel.cpp       \
       src/rendering/AmbientLight.cpp \
       src/rendering/DirectionalLight.cpp \
       src/rendering/PointLight.cpp       \
       src/rendering/NoiseTexture.cpp	\
       src/rendering/PerlinNoise.cpp	\

OBJ := $(SRC:.cpp=.o)
EXEC := raytracer

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

graph: CXXFLAGS += -DUSE_SFML
graph: LDFLAGS += -lsfml-graphics -lsfml-window -lsfml-system
graph: $(OBJ) $(GRAPH_OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $(EXEC) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(GRAPH_OBJ)

fclean: clean
	rm -f $(EXEC)

.PHONY: all clean fclean re graph

re:
	$(MAKE) fclean
	$(MAKE) all

test: all
	./$(EXEC) assets/scenes/test_showcase.cfg -f -t 32 > outputs/test_image.ppm
	./$(EXEC) assets/scenes/test_texture.cfg -f -t 32 > outputs/test_image2.ppm
	./$(EXEC) assets/scenes/test_checker.cfg -f -t 32 > outputs/test_image3.ppm

tclean: fclean
	rm -f outputs/test_image.ppm
	rm -f outputs/test_image2.ppm
	rm -f outputs/test_image3.ppm

.PHONY: all clean fclean re
