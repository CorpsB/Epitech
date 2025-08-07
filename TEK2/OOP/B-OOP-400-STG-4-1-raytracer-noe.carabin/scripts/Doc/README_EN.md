# 🧠 Design Patterns in RayTracer

This project implements several fundamental object-oriented design patterns to ensure extensibility, modularity, and maintainability. Below is a list of the identified patterns, including their definitions and how they are used in the context of this raytracer.

---

## 🏭 Factory Pattern

### ➤ What is it?
A **Factory** is a creational design pattern that provides an interface for creating objects in a superclass, but allows subclasses to alter the type of objects that will be created.

### ➤ How is it used?
The `SceneParser.cpp` file contains multiple parsing functions such as:
- `ParseSpheres`, `ParseBoxes`, `ParseCylinders`, etc.

Each of these acts as a factory method: given configuration data (usually from a `.cfg` file), it instantiates the corresponding primitive object (`Sphere`, `Box`, etc.) dynamically, often wrapping it with transformation decorators.

---

## 🧱 Composite Pattern

### ➤ What is it?
The **Composite** pattern lets you compose objects into tree structures to represent part-whole hierarchies. It allows clients to treat individual objects and compositions uniformly.

### ➤ How is it used?
The `Scene` class manages a list of `APrimitive` objects. All geometric shapes inherit from the same interface, allowing the rendering engine to treat them uniformly, regardless of whether the object is a simple shape (`Sphere`) or a complex one (`Mesh`, composed of many `Triangles`).

---

## 🧩 Decorator Pattern

### ➤ What is it?
A **Decorator** is a structural design pattern that lets you dynamically add behaviors or responsibilities to an object without modifying its class.

### ➤ How is it used?
Classes such as `Shear`, `Rotation`, and `Matrix` wrap a base `APrimitive` and override methods like `hits` and `bounds` to apply geometric transformations. These transformations are layered dynamically at runtime via the `ApplyTransforms` function in `SceneParser.cpp`.

---

## 🔁 Strategy Pattern

### ➤ What is it?
A **Strategy** pattern defines a family of algorithms, encapsulates each one, and makes them interchangeable. It lets the algorithm vary independently from clients that use it.

### ➤ How is it used?
In `Visualizer.cpp`, the rendering strategy is chosen based on a runtime flag (`-viz [mode]`). Three strategies are implemented:
- `renderScanline`
- `renderTiles`
- `renderRandom`

Each strategy encapsulates a different method for rendering pixels and can be swapped without changing the rest of the rendering logic.

---

## 🛠️ Builder Pattern (informal)

### ➤ What is it?
The **Builder** pattern is a creational pattern that lets you construct complex objects step by step. It provides more control over the construction process.

### ➤ How is it used?
While not fully formalized as a `Builder` class, the camera and scene are built step-by-step using parsed configuration settings:
- `ParseCamera` computes orientation vectors from position and rotation.
- `loadScene` composes the `Scene` by parsing and assembling all primitives, lights, and optional skybox data.

---

## ❗ Custom Exception Handling

### ➤ What is it?
Although not a design pattern per se, robust error handling is a best practice in large systems. A centralized exception class can act as a controller for runtime errors.

### ➤ How is it used?
The custom class `Raytracer::Error` is thrown throughout the codebase to encapsulate parsing and loading errors (e.g., in `loadSceneRecursive`). This centralizes error handling and improves clarity and debugging.

---

## Summary

| Pattern         | Responsibility                                | Location(s) in Project                        |
|----------------|------------------------------------------------|-----------------------------------------------|
| Factory         | Creates objects based on config               | `SceneParser.cpp`                             |
| Composite       | Manages primitives uniformly                  | `Scene` and all `APrimitive` derivatives      |
| Decorator       | Adds transformations to primitives            | `Shear`, `Rotation`, `Matrix`                 |
| Strategy        | Switches rendering algorithm at runtime       | `Visualizer.cpp` via `VizMode`                |
| Builder (soft)  | Builds scene/camera from multiple settings    | `loadScene`, `ParseCamera`                    |
| Error Handling  | Centralizes error reporting                   | `Raytracer::Error`                            |

---

These patterns help enforce separation of concerns, enable polymorphic behavior, and ensure your raytracer is extensible and easy to maintain as it grows.