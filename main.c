#include <raylib.h>
#include <stdio.h>

int main(void) {

    InitWindow(700, 400, "Mattef");

    SetExitKey(0);

    int textX = 275;
    int textY = 175;
    int speed = 1;

    while(!WindowShouldClose()) {

        if(IsKeyDown(KEY_W)) {
            textY -= speed;
        }
        if(IsKeyDown(KEY_A)){
            textX -= speed;
        }
        if(IsKeyDown(KEY_S)){
            textY += speed;
        }
        if(IsKeyDown(KEY_D)){
            textX += speed;
        }

        BeginDrawing();
        ClearBackground(BLUE);
        DrawText("Mattef", textX, textY, 50,  LIGHTGRAY);
        EndDrawing();   

        if(IsKeyPressed(KEY_C)) {
            printf("cya!\n");
            CloseWindow();

        }
    }

    CloseWindow();

}