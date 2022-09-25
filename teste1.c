#include <stdio.h>
#include "raylib.h"

int main(){

    const int screenWidth = 1600;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "Testando imagens");

    SetTargetFPS(60);

    Texture2D player = LoadTexture("./Assets/fogo.png");
    Texture2D enter_button = LoadTexture("./Assets/enter.png");

    while(!WindowShouldClose()){

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("HellCIN", 680, 150, 50, BLACK);
        DrawTextureV(player, (Vector2) {630, 200}, WHITE);
        DrawTextureV(enter_button, (Vector2) {690, 520}, WHITE);

        EndDrawing();
    }

    UnloadTexture(player);
    UnloadTexture(enter_button);

    CloseWindow();

    return 0;
}