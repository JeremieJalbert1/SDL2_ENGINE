# SDL2 Game Engine - Tycoon Game Development

This project is a dedicated 2D game engine built with SDL2, designed with the specific goal of developing engaging and intricate tycoon-style management games. Inspired by and building upon the knowledge gained from the YouTube tutorial series ['How To Make Games'](https://www.youtube.com/@CarlBirch), this engine seeks to provide a solid foundation for the creation of detailed simulation and management games.

From the simplicity of resource allocation to the complexity of AI-driven systems, this game engine aims to provide a comprehensive set of features that are commonly found in popular tycoon games. By focusing on providing a highly customizable entity-component system, the engine ensures the flexibility and scalability needed to handle the diverse requirements of a management game.

The project is in active development and contributions are very welcome. Whether you're interested in developing games or game engines, or simply have a passion for tycoon games, your involvement can help to create a powerful tool for developing tycoon games.

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
- Resource management system


## Future Features
- AI-driven characters (NPCs) with basic decision-making capabilities
- Grid-based or free placement system for building construction and management
- Basic economic system with supply, demand, and variable pricing
- Time progression and event scheduling system
- Pathfinding and navigation for AI entities
- Save and load game state system
- UI system for displaying information and player interaction
- Basic audio system for sound effects and music

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

- Thanks to the creator of the 'How To Make Games' YouTube tutorial series for the knowledge to start this project.
