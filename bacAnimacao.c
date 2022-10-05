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

    Texture2D bacRun = LoadTexture("./Assets/Ball and Chain Bot/run.png");
    Texture2D bacAttack = LoadTexture("./Assets/Ball and Chain Bot/attack.png");
    Texture2D bacDeath = LoadTexture("./Assets/Ball and Chain Bot/death.png");

    int bacRun_nSprites = 8;
    int bacRun_Width = bacRun.width;
    int bacRun_Heigth = bacRun.height/bacRun_nSprites;
    
    int bacAttack_Width = bacAttack.width;
    int bacAttack_Heigth = bacAttack.height/8;
    
    int bacDeath_Width = bacDeath.width;
    int bacDeath_Heigth = bacDeath.height/5;
    

    Vector2 origin = {0.0f, 0.0f};

    Rectangle bacRun_sourceRect = {0.0f, 0.0f, (float)bacRun_Width, (float)bacRun_Heigth};
    Rectangle bacRun_destRect = {screenWidth/2.0f - 82, screenHeight/2.0f - 46, bacRun_Width*2.0f, bacRun_Heigth*2.0f };
    
    
    Rectangle bacAttack_sourceRect = {0.0f, 0.0f, (float)bacAttack_Width, (float)bacAttack_Heigth};
    Rectangle bacAttack_destRect = {screenWidth/2.0f - 82, screenHeight/2.0f - 46, bacAttack_Width*2.0f, bacAttack_Heigth*2.0f };
    
    Rectangle bacDeath_sourceRect = {0.0f, 0.0f, (float)bacDeath_Width, (float)bacDeath_Heigth};
    Rectangle bacDeath_destRect = {screenWidth/2.0f - 82, screenHeight/2.0f - 46, bacDeath_Width*2.0f, bacDeath_Heigth*2.0f };

    int rotation = 0;
    int bacRun_framecounter = 0;
    int bacRun_framespeed = 8;
    int bacRun_currentframe = 0;
    
    int bacAttack_framecounter = 0;
    int bacAttack_framespeed = 8;
    int bacAttack_currentframe = 0;
    bool bacAttack_active = false;
    
    int bacDeath_framecounter = 0;
    int bacDeath_framespeed = 3;
    int bacDeath_currentframe = 0;
    bool bacDeath_active = false;
    bool IsBacDead = false;

    while(!WindowShouldClose()){

        bacRun_framecounter++;
        bacDeath_framecounter++;
        bacAttack_framecounter++;

        if(IsKeyDown(KEY_RIGHT)){

            bacRun_destRect.x +=4;
            
            if(bacRun_sourceRect.width < 0){
                bacRun_sourceRect.width = -1 * bacRun_sourceRect.width;
                bacAttack_sourceRect.width = -1 * bacAttack_sourceRect.width;
            }

            bacRun_sourceRect.y = runningAnimations(&bacRun_framecounter, &bacRun_framespeed, &bacRun_currentframe, bacRun_sourceRect.y, bacRun_Heigth, bacRun_nSprites);

        }
        if(IsKeyDown(KEY_LEFT)){
            
            bacRun_destRect.x -=4;

            if(bacRun_sourceRect.width > 0){
                bacRun_sourceRect.width = -1 * bacRun_sourceRect.width;
                bacAttack_sourceRect.width = -1 * bacAttack_sourceRect.width;
            }

            bacRun_sourceRect.y = runningAnimations(&bacRun_framecounter, &bacRun_framespeed, &bacRun_currentframe, bacRun_sourceRect.y, bacRun_Heigth, bacRun_nSprites);
        }
        if(IsKeyDown(KEY_DOWN)){
            bacRun_destRect.y +=4;

            bacRun_sourceRect.y = runningAnimations(&bacRun_framecounter, &bacRun_framespeed, &bacRun_currentframe, bacRun_sourceRect.y, bacRun_Heigth, bacRun_nSprites);
        }
        if(IsKeyDown(KEY_UP)){
            bacRun_destRect.y -=4;

            bacRun_sourceRect.y = runningAnimations(&bacRun_framecounter, &bacRun_framespeed, &bacRun_currentframe, bacRun_sourceRect.y, bacRun_Heigth, bacRun_nSprites);
        }
        
        
        
        if(IsKeyPressed(KEY_B) && !bacAttack_active)
           bacAttack_active = true;
        
        if(IsKeyPressed(KEY_M) && !bacDeath_active){
            
            bacDeath_active = true;
        }
        
        if(bacAttack_active){
            
            bacAttack_destRect.x = bacRun_destRect.x;
            bacAttack_destRect.y = bacRun_destRect.y;
            
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
               bacAttack_sourceRect.y = (float)(bacAttack_currentframe) * (float)(bacAttack_Heigth);    
            } 
                
        }        
        
        if(bacDeath_active){
            
            bacDeath_destRect.x = bacRun_destRect.x;
            bacDeath_destRect.y = bacRun_destRect.y;
            
            if(bacDeath_framecounter >= (60/bacDeath_framespeed)){
                bacDeath_framecounter++;
                
                if(bacDeath_framecounter>2){
                    bacDeath_currentframe++;
                    
                    if(bacDeath_currentframe > 4){
                        
                        bacDeath_currentframe = 4;
                        bacDeath_active = false;
                        IsBacDead = true;
                    
                    }
                    
                    bacDeath_framecounter = 0;
                }    
            }            
        } 

        bacDeath_sourceRect.y = (float)(bacDeath_currentframe) * (float)(bacDeath_Heigth);   

        mapBorders(&bacRun_destRect.x,&bacRun_destRect.y,bacRun_destRect.width,bacRun_destRect.height, 1600,800);  
        mapBorders(&bacAttack_destRect.x,&bacAttack_destRect.y,bacAttack_destRect.width,bacAttack_destRect.height, 1600,800);  
        mapBorders(&bacDeath_destRect.x,&bacDeath_destRect.y,bacDeath_destRect.width,bacDeath_destRect.height, 1600,800);   
                
        if(bacAttack_active && !IsBacDead){
            BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawTexturePro(bacAttack, bacAttack_sourceRect, bacAttack_destRect, origin, rotation, RAYWHITE);
            EndDrawing(); 
        
        }else if(bacDeath_active){
            BeginDrawing();            
            ClearBackground(RAYWHITE);            
            DrawTexturePro(bacDeath, bacDeath_sourceRect, bacDeath_destRect, origin, rotation, RAYWHITE);            
            EndDrawing();
        
        }else if(!IsBacDead){      
            BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawTexturePro(bacRun, bacRun_sourceRect, bacRun_destRect, origin, rotation, RAYWHITE);            
            EndDrawing();   
            
        }else if(IsBacDead){
            BeginDrawing();            
            ClearBackground(RAYWHITE);            
            DrawTexturePro(bacDeath, bacDeath_sourceRect, bacDeath_destRect, origin, rotation, RAYWHITE);            
            EndDrawing();
        }
          
    }

    UnloadTexture(bacAttack);
    UnloadTexture(bacRun);
    UnloadTexture(bacDeath);

    return 0;
}