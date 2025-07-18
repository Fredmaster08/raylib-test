#include <raylib.h>
#include <stdbool.h>

int main(void) {

    bool userInput = 0;

    InitWindow(700, 400, "Mattef");

    SetExitKey(0);

    while(!WindowShouldClose()) {

        BeginDrawing();
        ClearBackground(BLUE);
        DrawText("Mattef", 275, 175, 50,  LIGHTGRAY);
        EndDrawing();

        if(IsKeyPressed(KEY_W)) {
            CloseWindow();
        }
    }

    CloseWindow();

}