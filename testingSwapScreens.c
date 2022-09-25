#include <stdio.h>
#include "raylib.h"

int main(void){

    int flagInicio = 0;

    const int screenWidth = 1600;
    const int screenHeight = 800;

    Vector2 vetorImagem = {630,200};

    InitWindow(screenWidth, screenHeight, "HELLCIN");

    SetTargetFPS(60);

    Texture2D fireTexture = LoadTexture("./Assets/fogo.png");

    Texture2D memeTexture = LoadTexture("./Assets/memeMas_helth.png");
    Texture2D enter_button = LoadTexture("./Assets/enter.png");

    while(!WindowShouldClose()){

        if(flagInicio){

           BeginDrawing();
                ClearBackground(RAYWHITE);
                DrawText("Aqui jaz uma história muito nova\nE muito sofrida...", 400, 150, 50, BLACK);
            EndDrawing(); 

        }else{
            BeginDrawing();
                ClearBackground(RAYWHITE);

                DrawText("HellCIN", 680, 150, 50, BLACK);
                DrawTextureV(fireTexture, vetorImagem, WHITE);
                DrawTextureV(enter_button, (Vector2) {690, 520}, WHITE);

                if(IsKeyDown(KEY_ENTER)){
                    flagInicio = 1;
                }

            EndDrawing();

        }

    }

    UnloadTexture(fireTexture);
    UnloadTexture(memeTexture);
    UnloadTexture(enter_button);

    CloseWindow();

    return 0;
}