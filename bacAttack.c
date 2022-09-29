#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include "animations.h"
#include "collision.h"

int main(void){

    const int screenWidth = 1600;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "HellCIN");

    SetTargetFPS(60);

    Texture2D bacAttack = LoadTexture("./Assets/Ball and Chain Bot/attack.png");

    int bacAttack_Width = bacAttack.width;
    int bacAttack_Heigth = bacAttack.height/8;

    Vector2 origin = {0.0f, 0.0f};

    Rectangle bacAttack_sourceRect = {0.0f, 0.0f, (float)bacAttack_Width, (float)bacAttack_Heigth};

    Rectangle bacAttack_destRect = {screenWidth/2.0f - 82, screenHeight/2.0f - 46, bacAttack_Width*2.0f, bacAttack_Heigth*2.0f };

    int rotation = 0;
    int bacAttack_framecounter = 0;
    int bacAttack_framespeed = 8;
    int bacAttack_currentframe = 0;
    bool bacAttack_active = false;

    while(!WindowShouldClose()){
        
        bacAttack_framecounter++;

        
        if(IsKeyPressed(KEY_B) && !bacAttack_active){
            
            bacAttack_active = true;
        }
        
        if(bacAttack_active){
            
            if(bacAttack_framecounter >= (60/bacAttack_framespeed)){
                bacAttack_framecounter++;
                
                if(bacAttack_framecounter>2){
                    bacAttack_currentframe++;
                    
                    if(bacAttack_currentframe >= 8){
                        
                        bacAttack_currentframe = 0;
                        bacAttack_active = false;
                    
                    }
                    
                    bacAttack_framecounter = 0;
                }    
            }            
        }
        bacAttack_sourceRect.y = (float)(bacAttack_currentframe) * (float)(bacAttack_Heigth);


        BeginDrawing();

        ClearBackground(RAYWHITE);
        

        DrawTexturePro(bacAttack, bacAttack_sourceRect, bacAttack_destRect, origin, rotation, RAYWHITE);

        EndDrawing();   


    }

    UnloadTexture(bacAttack);

    return 0;
}