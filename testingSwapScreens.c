#include <stdio.h>
#include "raylib.h"

int main(void){

    int flagInicio = 0;

    const int screenWidth = 1600;
    const int screenHeight = 800;

    Vector2 vectorImage = {630,200};
    Rectangle player = {400,150,32,32};
    Camera2D camera = {0};

    camera.target = (Vector2){player.x + 20.0f, player.y + 20.0f};
    camera.offset = (Vector2){screenWidth/2.0f,screenHeight/2.0f};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    InitWindow(screenWidth, screenHeight, "HELLCIN");

    SetTargetFPS(60);

    Texture2D fireTexture = LoadTexture("./Assets/fogo.png");

    Texture2D memeTexture = LoadTexture("./Assets/memeMas_helth.png");
    Texture2D enter_button = LoadTexture("./Assets/enter.png");

    while(!WindowShouldClose()){

        if(IsKeyDown(KEY_ENTER)){
                flagInicio = 1;
        }else if(IsKeyDown(KEY_F11)){
                ToggleFullscreen();
        }

        if(IsKeyDown(KEY_RIGHT)){
            player.x += 2.0;
        }else if(IsKeyDown(KEY_LEFT)){
            player.x -= 2.0;
        }else if(IsKeyDown(KEY_UP)){
            player.y -= 2.0;
        }else if(IsKeyDown(KEY_DOWN)){
            player.y += 2.0;
        }

        if(flagInicio){

           BeginDrawing();
                BeginMode2D(camera);
                    ClearBackground(RAYWHITE);
                    DrawRectangleRec(player, RED);
                EndMode2D();
                DrawText("Aqui jaz uma história muito nova\nE muito sofrida...", 400, 150, 50, BLACK);
            EndDrawing(); 

        }else{
            BeginDrawing();
                ClearBackground(RAYWHITE);

                DrawText("HellCIN", 680, 150, 50, BLACK);
                DrawTextureV(fireTexture, vectorImage, WHITE);
                DrawTextureV(enter_button, (Vector2) {690, 520}, WHITE);

            EndDrawing();

        }

    }

    UnloadTexture(fireTexture);
    UnloadTexture(memeTexture);
    UnloadTexture(enter_button);

    CloseWindow();

    return 0;
}