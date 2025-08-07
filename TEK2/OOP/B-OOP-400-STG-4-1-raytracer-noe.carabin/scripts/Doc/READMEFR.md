# 🧠 Patrons de conception dans RayTracer

Ce projet implémente plusieurs **patrons de conception** orientés objet pour assurer l’extensibilité, la modularité et la maintenabilité du raytracer. Voici la liste des patterns détectés, accompagnée d'une explication, d'une justification de leur utilisation dans le projet, et de leur rôle.

---

## 🏭 Patron Factory (Usine)

### ➤ Définition
Le **Factory Pattern** est un patron de création qui fournit une interface pour créer des objets, tout en laissant les sous-classes définir quelle classe instancier.

### ➤ Utilisation dans le projet
Dans `SceneParser.cpp`, les fonctions comme :
- `ParseSpheres`, `ParseBoxes`, `ParseCylinders`, etc.

agissent comme des usines (factories) qui instancient dynamiquement des primitives en fonction d’un fichier de configuration `.cfg`. Elles encapsulent aussi les décorateurs de transformation.

---

## 🧱 Patron Composite

### ➤ Définition
Le **Composite Pattern** permet de composer des objets en structures arborescentes (hiérarchies) afin que les clients puissent manipuler des objets individuels ou composés de manière uniforme.

### ➤ Utilisation dans le projet
La classe `Scene` contient une liste d’objets `APrimitive`. Toutes les primitives (`Sphere`, `Box`, `Triangle`, etc.) partagent cette interface, permettant à la scène de les traiter de manière uniforme.

---

## 🧩 Patron Decorator

### ➤ Définition
Le **Decorator Pattern** est un patron structurel qui permet d’ajouter dynamiquement des fonctionnalités à un objet sans modifier sa classe.

### ➤ Utilisation dans le projet
Les classes `Shear`, `Rotation` et `Matrix` décorent une primitive existante et redéfinissent des méthodes comme `hits` et `bounds`. Cela permet d’appliquer dynamiquement des transformations géométriques aux objets via `ApplyTransforms`.

---

## 🔁 Patron Strategy

### ➤ Définition
Le **Strategy Pattern** permet de définir une famille d’algorithmes, de les encapsuler et de les rendre interchangeables dynamiquement.

### ➤ Utilisation dans le projet
Dans `Visualizer.cpp`, le mode de rendu est choisi à l’exécution selon un flag `-viz [mode]`. Les stratégies sont :
- `renderScanline`
- `renderTiles`
- `renderRandom`

Chaque fonction implémente une stratégie de rendu différente, interchangeable sans changer le reste du système.

---

## 🛠️ Patron Builder (informel)

### ➤ Définition
Le **Builder Pattern** est un patron de création qui permet de construire un objet complexe pas à pas.

### ➤ Utilisation dans le projet
Bien que non formalisé en tant que classe `Builder`, la caméra et la scène sont construites en plusieurs étapes via :
- `ParseCamera` (calcul des vecteurs orientation)
- `loadScene` (assemblage des matériaux, objets, lumières, etc.)

---

## ❗ Gestion d’erreur personnalisée

### ➤ Définition
Ce n’est pas un patron à proprement parler, mais centraliser la gestion des erreurs est une bonne pratique pour assurer la robustesse d’un système.

### ➤ Utilisation dans le projet
La classe `Raytracer::Error` est utilisée comme exception personnalisée dans toute la logique de parsing et de chargement (ex. : `loadSceneRecursive`). Cela permet une gestion cohérente et claire des erreurs.

---

## Récapitulatif

| Patron          | Rôle principal                                 | Emplacement(s) dans le projet                 |
|-----------------|------------------------------------------------|-----------------------------------------------|
| Factory         | Création d’objets à partir d’un fichier        | `SceneParser.cpp`                             |
| Composite       | Manipulation uniforme des primitives           | `Scene`, `APrimitive` et ses dérivés          |
| Decorator       | Ajout de transformations aux objets            | `Shear`, `Rotation`, `Matrix`                 |
| Strategy        | Choix de l’algorithme de rendu à l’exécution   | `Visualizer.cpp`, selon `VizMode`             |
| Builder (soft)  | Construction en étapes de la scène/caméra      | `loadScene`, `ParseCamera`                    |
| Exception       | Gestion centralisée des erreurs                | `Raytracer::Error`                            |

---

Ces patrons garantissent une **séparation des responsabilités**, favorisent l’**extensibilité**, et rendent le système plus **robuste** et **maintenable**.
