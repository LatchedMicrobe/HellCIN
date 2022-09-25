#include "raylib.h"

int main(void){

    const int screenWidth = 1600;
    const int screenHeight = 800;
    
    InitWindow(screenWidth, screenHeight, "Teste - Quadrado");
    
    SetTargetFPS(60);
    
    while(!WindowShouldClose()){
        
        BeginDrawing();
        
        ClearBackground(RAYWHITE);
        
        DrawText("-- Testando Quadradinho --", 800, 380, 50, PURPLE);
        
        EndDrawing();     
        
    }
    
    CloseWindow();
    
    return 0;
}