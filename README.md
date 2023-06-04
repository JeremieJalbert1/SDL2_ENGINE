# SDL2 Game Engine

This project is a simple 2D game engine built with SDL2, inspired by and following the YouTube tutorial series 'How To Make Games' [(insert link to the series here)](https://www.youtube.com/@CarlBirch).

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
```

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
```
This will create an entity, give it a position, size, and scale via the `TransformComponent`, and then give it a sprite via the `SpriteComponent`.

## Contribution

This project is currently in development. Contributions are welcome! Please submit a pull request or open an issue if you want to make changes or find a bug.

## License

This project is open source, under the MIT license.

## Acknowledgements

- Thanks to the creator of the 'How To Make Games' YouTube tutorial series for the knowledge and inspiration to start this project.
