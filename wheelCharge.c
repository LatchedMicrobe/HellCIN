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

    Texture2D wheelCharge = LoadTexture("./Assets/Bot Wheel/charge.png");

    int wheelCharge_Width = wheelCharge.width;
    int wheelCharge_Heigth = wheelCharge.height/4;

    Vector2 origin = {0.0f, 0.0f};

    Rectangle wheelCharge_sourceRect = {0.0f, 0.0f, (float)wheelCharge_Width, (float)wheelCharge_Heigth};

    Rectangle wheelCharge_destRect = {screenWidth/2.0f - 82, screenHeight/2.0f - 46, wheelCharge_Width*2.0f, wheelCharge_Heigth*2.0f };

    int rotation = 0;
    int wheelCharge_framecounter = 0;
    int wheelCharge_framespeed = 8;
    int wheelCharge_currentframe = 0;
    bool wheelCharge_active = false;
    
   while(!WindowShouldClose()){
        
        wheelCharge_framecounter++;

        
        if(IsKeyPressed(KEY_C) && !wheelCharge_active){
            
            wheelCharge_active = true;
        }
        
        if(wheelCharge_active){
            
            if(wheelCharge_framecounter >= (60/wheelCharge_framespeed)){
                wheelCharge_framecounter++;
                
                if(wheelCharge_framecounter>2){
                    wheelCharge_currentframe++;
                    
                    if(wheelCharge_currentframe >= 4){
                        
                        wheelCharge_currentframe = 0;
                        wheelCharge_active = false;
                    
                    }
                    
                    wheelCharge_framecounter = 0;
                }    
            }            
        }
        wheelCharge_sourceRect.y = (float)(wheelCharge_currentframe) * (float)(wheelCharge_Heigth);


        BeginDrawing();

        ClearBackground(RAYWHITE);
        

        DrawTexturePro(wheelCharge, wheelCharge_sourceRect, wheelCharge_destRect, origin, rotation, RAYWHITE);

        EndDrawing();   


    }

    UnloadTexture(wheelCharge);



    return 0;
}