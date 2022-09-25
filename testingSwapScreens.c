#include <stdio.h>
#include "raylib.h"

int main(void){

    int flagInicio = 0;

    const int screenWidth = 1600;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "HELLCIN");

    SetTargetFPS(60);

    Texture2D fireTexture = LoadTexture("./Assets/fogo.png");

    Texture2D memeTexture = LoadTexture("./Assets/memeMas_helth.png");

    Texture2D enter_button = LoadTexture("./Assets/enter.png");

    int frameWidth = fireTexture.width;
    int frameHeight = fireTexture.height;

    Vector2 vectorImage = {630,200};
    Rectangle sourceRect = {0.0f, 0.0f, (float)frameWidth, (float)frameHeight}; 
    Rectangle destRect = { screenWidth/2.0f - 64, screenHeight/2.0f - 64, frameWidth*0.5f, frameHeight*0.5f };
    Camera2D camera = {0};

    camera.target = (Vector2){destRect.x + 20.0f, destRect.y + 20.0f};
    camera.offset = (Vector2){screenWidth/2.0f,screenHeight/2.0f};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    Vector2 origin = {0.0f, 0.0f};

    int rotation = 0;
   

    while(!WindowShouldClose()){
        

        if(IsKeyDown(KEY_ENTER)){
                flagInicio = 1;
        }else if(IsKeyDown(KEY_F11)){
                ToggleFullscreen();
        }

        if(IsKeyDown(KEY_RIGHT)){
            destRect.x += 2.0;
        }if(IsKeyDown(KEY_LEFT)){
            destRect.x -= 2.0;
        }if(IsKeyDown(KEY_UP)){
            destRect.y -= 2.0;
        }if(IsKeyDown(KEY_DOWN)){
            destRect.y += 2.0;
        }

        if(flagInicio){

            BeginDrawing();

                    ClearBackground(RAYWHITE);
                    DrawTexturePro(fireTexture, sourceRect, destRect, origin, (float)rotation, WHITE);
                
                BeginMode2D(camera);
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