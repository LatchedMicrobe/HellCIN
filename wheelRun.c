#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include "animations.h"
#include "collision.h"

int main(){

    const int screenWidth = 1600;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "HellCIN");

    SetTargetFPS(60);

    Texture2D wheelRun = LoadTexture("./Assets/Bot Wheel/move with FX.png");

    int wheelRun_Width = wheelRun.width;
    int wheelRun_Heigth = wheelRun.height/8;

    Vector2 origin = {0.0f, 0.0f};

    Rectangle wheelRun_sourceRect = {0.0f, 0.0f, (float)wheelRun_Width, (float)wheelRun_Heigth};

    Rectangle wheelRun_destRect = {screenWidth/2.0f - 82, screenHeight/2.0f - 46, wheelRun_Width*2.0f, wheelRun_Heigth*2.0f };

    int rotation = 0;
    int wheelRun_framecounter = 0;
    int wheelRun_framespeed = 8;
    int wheelRun_currentframe = 0;
    
    while(!WindowShouldClose()){
    
        wheelRun_framecounter++;
        
        if(IsKeyDown(KEY_RIGHT)){
            wheelRun_destRect.x +=4;
            
             if(wheelRun_framecounter >= (60/(wheelRun_framespeed))){
                wheelRun_framecounter = 0;
                wheelRun_currentframe += 1;
                if(wheelRun_currentframe > 8)  
                    wheelRun_currentframe = 0;
                wheelRun_sourceRect.y = (float)(wheelRun_currentframe) * (float)wheelRun_Heigth;
            }
        }
        if(IsKeyDown(KEY_LEFT)){
            wheelRun_destRect.x -=4;

            if(wheelRun_framecounter >= (60/(wheelRun_framespeed))){
                wheelRun_framecounter = 0;
                wheelRun_currentframe += 1;
                if(wheelRun_currentframe > 8)  
                    wheelRun_currentframe = 0;
                wheelRun_sourceRect.y = (float)(wheelRun_currentframe) * (float)wheelRun_Heigth;
            }
        }
        if(IsKeyDown(KEY_DOWN)){
            wheelRun_destRect.y +=4;

            if(wheelRun_framecounter >= (60/(wheelRun_framespeed))){
                wheelRun_framecounter = 0;
                wheelRun_currentframe +=1;
                if(wheelRun_currentframe > 8)
                    wheelRun_currentframe = 0;
                wheelRun_sourceRect.y = (float)(wheelRun_currentframe) * (float)wheelRun_Heigth;
            }
        }
        if(IsKeyDown(KEY_UP)){
            wheelRun_destRect.y -=4;

            if(wheelRun_framecounter >= (60/(wheelRun_framespeed))){
                wheelRun_framecounter = 0;
                wheelRun_currentframe +=1;
                if(wheelRun_currentframe > 8)
                    wheelRun_currentframe = 0;
                wheelRun_sourceRect.y = (float)(wheelRun_currentframe) * (float)wheelRun_Heigth;
            }
        }
        
            BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawTexturePro(wheelRun, wheelRun_sourceRect, wheelRun_destRect, origin, rotation, RAYWHITE);            
            EndDrawing();       
    }
    
    UnloadTexture(wheelRun);


    return 0;
}