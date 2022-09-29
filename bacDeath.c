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

    Texture2D bacDeath = LoadTexture("./Assets/Ball and Chain Bot/death.png");

    int bacDeath_Width = bacDeath.width;
    int bacDeath_Heigth = bacDeath.height/5;

    Vector2 origin = {0.0f, 0.0f};

    Rectangle bacDeath_sourceRect = {0.0f, 0.0f, (float)bacDeath_Width, (float)bacDeath_Heigth};

    Rectangle bacDeath_destRect = {screenWidth/2.0f - 82, screenHeight/2.0f - 46, bacDeath_Width*2.0f, bacDeath_Heigth*2.0f };

    int rotation = 0;
    int bacDeath_framecounter = 0;
    int bacDeath_framespeed = 3;
    int bacDeath_currentframe = 0;
    bool bacDeath_active = false;
    bool bacDead = false;

    while(!WindowShouldClose()){
        
        bacDeath_framecounter++;

        
        if(IsKeyPressed(KEY_M) && !bacDeath_active){
            
            bacDeath_active = true;
        }
        
        if(bacDeath_active){
            
            if(bacDeath_framecounter >= (60/bacDeath_framespeed)){
                bacDeath_framecounter++;
                
                if(bacDeath_framecounter>2){
                    bacDeath_currentframe++;
                    
                    if(bacDeath_currentframe > 4){
                        
                        bacDeath_currentframe = 4;
                        bacDeath_active = false;
                        bacDead = true;
                    
                    }
                    
                    bacDeath_framecounter = 0;
                }    
            }            
        }
        
        bacDeath_sourceRect.y = (float)(bacDeath_currentframe) * (float)(bacDeath_Heigth);


        BeginDrawing();

        ClearBackground(RAYWHITE);
        

        DrawTexturePro(bacDeath, bacDeath_sourceRect, bacDeath_destRect, origin, rotation, RAYWHITE);
        

        EndDrawing();   


    }

    UnloadTexture(bacDeath);

    return 0;
}