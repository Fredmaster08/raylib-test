
#include <raylib.h>
#include <time.h>
#include <raymath.h>
#include <stdlib.h>
#include "asteroid.h"

#define NEARBLACK (Color){15, 15, 15, 255}
#define MAX_ASTEROIDS 64
static Asteroid _asteroids[MAX_ASTEROIDS] = {0};

const int screenWidth = 600;
const int screenHeight = 600;
const Vector2 screenSize = {screenWidth, screenHeight};

void UpdateDrawFrame(void);
void AddAsteroid();

int main() {

    srand(time(0));

    InitWindow(screenWidth, screenHeight, "Raylib Asteroids by Fredmaster08");

    SetTargetFPS(60);

    while(!WindowShouldClose) {
        UpdateDrawFrame();
    }
    CloseWindow();

    return 0;
}

void UpdateDrawFrame(){

    float frametime = GetFrameTime();

    for(int i = 0; i < MAX_ASTEROIDS; i++) {
        AsteroidUpdate(&_asteroids[i], frametime);
    }

    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        AddAsteroid(GetMousePosition(), (Vector2){200, 0}, ASTEROID_SMALL);
    }

    BeginDrawing();

        ClearBackground(NEARBLACK);

        for(int i = 0; i < MAX_ASTEROIDS; i++) {
            AsteroidDraw(_asteroids[i]);
        }

    EndDrawing();

}

void AddAsteroid(Vector2 position, Vector2 velocity, AsteroidSize size) {

    bool created = false;

    Asteroid asteroid = CreateAsteroid(position, velocity, size);

    for(int i = 0; i < MAX_ASTEROIDS; i++) {
        if(_asteroids[i].active) {
            continue;
        }

        _asteroids[i] = CreateAsteroid(position, velocity, size);
        created = true;
        break;
    }

    if(!created) {
        TraceLog(LOG_ERROR, "Failed to create an asteroid because there was no inactive spots in the array!");
    }
}

