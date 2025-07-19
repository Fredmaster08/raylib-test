
#include "asteroid.h"

Asteroid CreateAsteroid(Vector2 position, Vector2 velocity, AsteroidSize size) {
    Asteroid asteroid = {
        .active = true,
        .position = position,
        .velocity = velocity,
        .rotation = GetRandomValue(0, 360),
        .rotationSpeed = GetRandomValue(ASTEROID_ROT_SPEED_MIN, ASTEROID_ROT_SPEED_MAX),
        .size = size, 
    };
    return asteroid;
}

void AsteroidUpdate(Asteroid* asteroid, float frametime) {

    if(!asteroid->active) {
        return;
    }

    asteroid->position = Vector2Add(asteroid->position,
        Vector2Scale(asteroid->velocity, frametime));
    asteroid->rotation += asteroid->rotationSpeed * frametime;
}

void AsteroidDraw(Asteroid asteroid) {
    DrawPolyLines(asteroid.position, 5, 64, asteroid.rotation, WHITE);
}

