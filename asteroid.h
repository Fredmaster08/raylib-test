
#ifndef ASTEROID_H_
#define ASTEROID_H_

#include <raylib.h>
#include <raymath.h>

#define ASTEROID_ROT_SPEED_MIN 5
#define ASTEROID_ROT_SPEED_MAX 240

typedef enum AsteroidSize {
    ASTEROID_SMALL = 1,
    ASTEROID_MEDIUM = 2,
    ASTEROID_LARGE = 4,
}AsteroidSize;

typedef struct Asteroid {
    bool active;

    Vector2 position;
    Vector2 velocity;
    AsteroidSize size;

    float rotation;
    float rotationSpeed;
}Asteroid;

Asteroid CreateAsteroid(Vector2 position, Vector2 velocity, AsteroidSize size);
void AsteroidUpdate(Asteroid* asteroid, float frametime);
void AsteroidDraw(Asteroid asteroid);

#endif