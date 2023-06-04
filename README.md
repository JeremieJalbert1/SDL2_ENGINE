# SDL2 Game Engine

This project is a simple 2D game engine built with SDL2, inspired by and following the YouTube tutorial series 'How To Make Games' (insert link to the series here).

## Prerequisites

This project requires the SDL2, SDL2_image, and SDL2_ttf libraries. You can download them from the following links:

- [SDL2](https://www.libsdl.org/download-2.0.php)
- [SDL2_image](https://www.libsdl.org/projects/SDL_image/)
- [SDL2_ttf](https://www.libsdl.org/projects/SDL_ttf/)

Please ensure these libraries are installed before trying to build and run the project.

## Build and Run

Clone the repository with `git clone https://github.com/JeremieJalbert1/SDL2_ENGINE`. Navigate into the directory and build the project using your chosen C++ compiler.

```bash
cd your-project-directory
make
./your-executable-name

## Features

The SDL2 game engine currently supports:

- Basic 2D rendering
- Texture loading and rendering
- Basic entity-component system (ECS)
- Basic collision detection
- Simple user input handling

## Example Usage

```cpp
// Create an entity
Entity& newEntity = entityManager.addEntity();

// Add components to the entity
newEntity.addComponent<TransformComponent>(x_position, y_position, width, height, scale);
newEntity.addComponent<SpriteComponent>("path-to-texture");
