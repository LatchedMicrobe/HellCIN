#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include "animations.h"
#include "menu.h"
#include "collision.h"

int main(void){
    //Definição de variaveis de tela e jogo
    const int screenWidth = 1600;
    const int screenHeight = 800;

    bool beginFlag = false;
    bool flagFirstFase = false;
    bool flagSecondFase = false;

    InitWindow(screenWidth, screenHeight, "HellCIN");
    InitAudioDevice();
    
    Image tela2_background = LoadImage("./Assets/Grid.png");
    Texture2D  tela2_backgroundT = LoadTextureFromImage(tela2_background);
    UnloadImage (tela2_background);
    Vector2 position = { (float)(screenWidth/2 - tela2_background.width/2), (float)(screenHeight/2 - tela2_background.height/2 - 20)};

    Sound initialSound = LoadSound("./Assets/Sounds/soundInitial.wav");
    Texture2D firstFase = LoadTexture("./Assets/Maps/Mapa.png");
    Texture2D secondFase = LoadTexture("./Assets/Maps/Mapa2.png");
    Vector2 positionMaps = { (float)(screenWidth/2 - firstFase.width/2), (float)(screenHeight/2 - firstFase.height/2) };
    Vector2 origin = {0.0f, 0.0f};
    
    //Definição da textura de inimigos/protagonista
    Texture2D mudRun = LoadTexture("./Assets/Mud Guard/Run.png");
    Texture2D mudAttack1 = LoadTexture("./Assets/Mud Guard/attack 1.png");
    Texture2D mudAttack2 = LoadTexture("./Assets/Mud Guard/attack 2.png");
    Texture2D mudDeath = LoadTexture("./Assets/Mud Guard/damaged and death.png");

    Texture2D stormheadRun = LoadTexture("./Assets/stormhead/run3.png");
    Texture2D stormheadAttack = LoadTexture("./Assets/stormhead/attack.png");

    Texture2D wheelRun = LoadTexture("./Assets/Bot Wheel/move with FX.png");
    Texture2D wheelCharge = LoadTexture("./Assets/Bot Wheel/charge.png");
    Texture2D wheelAttack = LoadTexture("./Assets/Bot Wheel/shoot with FX.png");
    Texture2D wheelGas = LoadTexture("./Assets/Bot Wheel/GAS dash with FX.png");
    Texture2D wheelDeath = LoadTexture("./Assets/Bot Wheel/death.png");

    //Variaveis de animação para inimigos/protagonista
    int mudRun_nSprites = 6;
    int mudRun_Width = mudRun.width;
    int mudRun_Heigth = mudRun.height/mudRun_nSprites;

    int mudAttack1_nSprites = 7;
    int mudAttack1_Width = mudAttack1.width;
    int mudAttack1_Heigth = mudAttack1.height/mudAttack1_nSprites;

    int mudAttack2_nSprites = 7;
    int mudAttack2_Width = mudAttack2.width;
    int mudAttack2_Heigth = mudAttack2.height/mudAttack2_nSprites;

    int mudDeath_nSprites = 8;
    int mudDeath_Width = mudDeath.width;
    int mudDeath_Heigth = mudDeath.height/mudDeath_nSprites;



    Rectangle mudRun_sourceRect = {0.0f, 0.0f, (float)mudRun_Width, (float)mudRun_Heigth};
    Rectangle mudRun_destRect = {screenWidth/2.0f - 82, screenHeight/2.0f - 46, mudRun_Width*2.0f, mudRun_Heigth*2.0f };

    Rectangle mudAttack1_sourceRect = {0.0f, 0.0f, (float)mudAttack1_Width, (float)mudAttack1_Heigth};
    Rectangle mudAttack1_destRect = {screenWidth/2.0f - 82, screenHeight/2.0f - 46, mudAttack1_Width*2.0f, mudAttack1_Heigth*2.0f };

    Rectangle mudAttack2_sourceRect = {0.0f, 0.0f, (float)mudAttack2_Width, (float)mudAttack2_Heigth};
    Rectangle mudAttack2_destRect = {screenWidth/2.0f - 82, screenHeight/2.0f - 46, mudAttack2_Width*2.0f, mudAttack2_Heigth*2.0f };

    Rectangle mudDeath_sourceRect = {0.0f, 0.0f, (float)mudDeath_Width, (float)mudDeath_Heigth};
    Rectangle mudDeath_destRect = {screenWidth/2.0f - 82, screenHeight/2.0f - 46, mudDeath_Width*2.0f, mudDeath_Heigth*2.0f };

    int rotation = 0;
    int mudRun_framecounter = 0;
    int mudRun_framespeed = 8;
    int mudRun_currentframe = 0;

    int mudAttack1_framecounter = 0;
    int mudAttack1_framespeed = 8;
    int mudAttack1_currentframe = 0;
    bool mudAttack1_active = false;

    int mudAttack2_framecounter = 0;
    int mudAttack2_framespeed = 8;
    int mudAttack2_currentframe = 0;
    bool mudAttack2_active = false;

    int mudDeath_framecounter = 0;
    int mudDeath_framespeed = 3;
    int mudDeath_currentframe = 0;
    bool mudDeath_active = false;
    bool IsMudDead = false;


    int wheelRun_nSprites = 8;
    int wheelRun_Width = wheelRun.width;
    int wheelRun_Heigth = wheelRun.height/wheelRun_nSprites;

    int wheelCharge_nSprites = 4;
    int wheelCharge_Width = wheelCharge.width;
    int wheelCharge_Heigth = wheelCharge.height/wheelCharge_nSprites;

    int wheelAttack_nSprites = 4;
    int wheelAttack_Width = wheelAttack.width;
    int wheelAttack_Heigth = wheelAttack.height/wheelAttack_nSprites;

    int wheelGas_nSprites = 7;
    int wheelGas_Width = wheelGas.width;
    int wheelGas_Heigth = wheelGas.height/wheelGas_nSprites;

    int wheelDeath_nSprites = 6;
    int wheelDeath_Width = wheelDeath.width;
    int wheelDeath_Heigth = wheelDeath.height/wheelDeath_nSprites;


    Rectangle wheelRun_sourceRect = {0.0f, 0.0f, (float)wheelRun_Width, (float)wheelRun_Heigth};
    Rectangle wheelRun_destRect = {screenWidth/2.0f - 82, screenHeight/2.0f - 46, wheelRun_Width*2.0f, wheelRun_Heigth*2.0f };

    Rectangle wheelCharge_sourceRect = {0.0f, 0.0f, (float)wheelCharge_Width, (float)wheelCharge_Heigth};
    Rectangle wheelCharge_destRect = {screenWidth/2.0f - 82, screenHeight/2.0f - 46, wheelCharge_Width*2.0f, wheelCharge_Heigth*2.0f };

    Rectangle wheelAttack_sourceRect = {0.0f, 0.0f, (float)wheelAttack_Width, (float)wheelAttack_Heigth};
    Rectangle wheelAttack_destRect = {screenWidth/2.0f - 82, screenHeight/2.0f - 46, wheelAttack_Width*2.0f, wheelAttack_Heigth*2.0f };

    Rectangle wheelGas_sourceRect = {0.0f, 0.0f, (float)wheelGas_Width, (float)wheelGas_Heigth};
    Rectangle wheelGas_destRect = {screenWidth/2.0f - 82, screenHeight/2.0f - 46, wheelGas_Width*2.0f, wheelGas_Heigth*2.0f };

    Rectangle wheelDeath_sourceRect = {0.0f, 0.0f, (float)wheelDeath_Width, (float)wheelDeath_Heigth};
    Rectangle wheelDeath_destRect = {screenWidth/2.0f - 82, screenHeight/2.0f - 46, wheelDeath_Width*2.0f, wheelDeath_Heigth*2.0f };


    int wheelRun_framecounter = 0;
    int wheelRun_framespeed = 8;
    int wheelRun_currentframe = 0;

    int wheelCharge_framecounter = 0;
    int wheelCharge_framespeed = 8;
    int wheelCharge_currentframe = 0;
    bool wheelCharge_active = false;
    bool wheelAttack_active = false;

    int wheelAttack_framecounter = 0;
    int wheelAttack_framespeed = 10;
    int wheelAttack_currentframe = 0;

    int wheelGas_framecounter = 0;
    int wheelGas_framespeed = 15;
    int wheelGas_currentframe = 0;
    bool wheelGas_active = false;

    int wheelDeath_framecounter = 0;
    int wheelDeath_framespeed = 4;
    int wheelDeath_currentframe = 0;
    bool wheelDeath_active = false;
    bool IsWheelDead = false;


    int stormheadRun_nSprites = 10;
    int stormheadRun_Width = stormheadRun.width - 80;
    int stormheadRun_Heigth = stormheadRun.height/stormheadRun_nSprites;

    int stormheadAttack_nSprites = 21;
    int stormheadAttack_Width = stormheadAttack.width;
    int stormheadAttack_Heigth = stormheadAttack.height/stormheadAttack_nSprites;

    Rectangle stormheadRun_sourceRect = {40.0f, 0.0f, (float)stormheadRun_Width, (float)stormheadRun_Heigth};
    Rectangle stormheadRun_destRect = {screenWidth/2.0f, screenHeight/2.0f, stormheadRun_Width*1.0f, stormheadRun_Heigth*1.0f };

    Rectangle stormheadAttack_sourceRect = {0.0f, 0.0f, (float)stormheadAttack_Width, (float)stormheadAttack_Heigth};
    Rectangle stormheadAttack_destRect = {screenWidth/2.0f - 82, screenHeight/2.0f - 46, stormheadAttack_Width*2.0f, stormheadAttack_Heigth*2.0f };

    Camera2D cameraPersonagem = {0};
    cameraPersonagem.target = (Vector2){stormheadRun_destRect.x + 55.0f, stormheadRun_destRect.y + 25.0f};
    cameraPersonagem.offset = (Vector2){screenWidth/2.0f,screenHeight/2.0f};
    cameraPersonagem.rotation = 0.0f;
    cameraPersonagem.zoom = 3.5f;    

    int stormheadRun_framecounter = 0;
    int stormheadRun_framespeed = 8;
    int stormheadRun_currentframe = 0;

    int stormheadAttack_framecounter = 0;
    int stormheadAttack_framespeed = 8;
    int stormheadAttack_currentframe = 0;
    bool stormheadAttack_active = false;
    int stormheadAttack_count = 0;

    Rectangle retanguloTeste = {1394.0f, 38.0f, 38.0f, 126.0f};


    SetTargetFPS(60);

    //Inicio do jogo somente se o dispositivo de som e audio tiverem sido iniciados
    if(IsAudioDeviceReady() == true && IsWindowReady() == true){
        while(!WindowShouldClose()){

            //Teclas iniciais(as de fase serão tiradas na versão final)
            if(IsKeyDown(KEY_ENTER)){

                    beginFlag = true;

            }else if(IsKeyDown(KEY_F11)){

                    ToggleFullscreen();

            }else if(IsKeyDown(KEY_ESCAPE)){
                UnloadSound(initialSound);
                UnloadTexture(mudAttack1);
                UnloadTexture(mudAttack2);
                UnloadTexture(mudDeath);
                UnloadTexture(mudRun);
                UnloadTexture(stormheadAttack);
                UnloadTexture(stormheadRun);
                UnloadTexture(wheelAttack);
                UnloadTexture(wheelCharge);
                UnloadTexture(wheelDeath);
                UnloadTexture(wheelGas);
                UnloadTexture(wheelRun);
                UnloadTexture(firstFase);
                UnloadTexture(secondFase);
                CloseWindow();
                exit(1);
            }else if(IsKeyDown(KEY_I) && flagFirstFase == false){
                flagFirstFase = true;
                PlaySound(initialSound);
            }else if(IsKeyDown(KEY_A)){
                flagSecondFase = true;
                PlaySound(initialSound);
            }

            //Teclas de movimentação

            stormheadRun_framecounter++;
            stormheadAttack_framecounter++;

            
            if(IsKeyDown(KEY_RIGHT)){
                stormheadRun_destRect.x +=4;

                

                if(stormheadRun_sourceRect.width < 0){
                    stormheadRun_sourceRect.width = -1 * stormheadRun_sourceRect.width;
                    stormheadAttack_sourceRect.width = -1 * stormheadAttack_sourceRect.width;
                }

                stormheadRun_sourceRect.y = runningAnimations(&stormheadRun_framecounter, &stormheadRun_framespeed, &stormheadRun_currentframe, stormheadRun_sourceRect.y, stormheadRun_Heigth, stormheadRun_nSprites);
            }
            if(IsKeyDown(KEY_LEFT)){
                stormheadRun_destRect.x -=4;

                if(stormheadRun_sourceRect.width > 0){
                    stormheadRun_sourceRect.width = -1 * stormheadRun_sourceRect.width;
                    stormheadAttack_sourceRect.width = -1 * stormheadAttack_sourceRect.width;
                }

                stormheadRun_sourceRect.y = runningAnimations(&stormheadRun_framecounter, &stormheadRun_framespeed, &stormheadRun_currentframe, stormheadRun_sourceRect.y, stormheadRun_Heigth, stormheadRun_nSprites);
            }
            if(IsKeyDown(KEY_DOWN)){
                stormheadRun_destRect.y +=4;

                stormheadRun_sourceRect.y = runningAnimations(&stormheadRun_framecounter, &stormheadRun_framespeed, &stormheadRun_currentframe, stormheadRun_sourceRect.y, stormheadRun_Heigth, stormheadRun_nSprites);
            }
            if(IsKeyDown(KEY_UP)){
                stormheadRun_destRect.y -=4;

                stormheadRun_sourceRect.y = runningAnimations(&stormheadRun_framecounter, &stormheadRun_framespeed, &stormheadRun_currentframe, stormheadRun_sourceRect.y, stormheadRun_Heigth, stormheadRun_nSprites);
            }

            structureCollision(&stormheadRun_destRect,&retanguloTeste);

            //Centralização da camera
            cameraPersonagem.target = (Vector2) {stormheadRun_destRect.x + 55.0f, stormheadRun_destRect.y + 25.0f};

            if(beginFlag){

                BeginDrawing();

                    if(!flagFirstFase){
                        DrawTextureV(tela2_backgroundT, position, WHITE);
                        DrawText("Após passar pelo ENEM você, 'estudante', agora se botou numa enrascada ainda maior", 100, 300, 30, WHITE);
                        DrawText("o HELLCIN, será que você irá superar estes novos desafios? Ou ficará no caminho como", 100, 340, 30, WHITE);
                        DrawText("muitos outros antes de você, que perderam a sanidade frente aos novos desafios?", 100, 380, 30, WHITE);
                        DrawText("bem, veremos...", 100, 420, 30, WHITE);
                        DrawText("Pressione I para sofrer", 100, 500, 30, WHITE);
                    }else if(flagFirstFase == true && flagSecondFase == false){

                        //Definição de bordas do mapa
                        mapBorders(&stormheadRun_destRect.x,&stormheadRun_destRect.y,stormheadRun_destRect.width,stormheadRun_destRect.height, 38, 38, 1562, 755);

                        BeginMode2D(cameraPersonagem);
                            ClearBackground(BLACK);
                            DrawTextureV(firstFase, positionMaps, WHITE);
                            if(stormheadAttack_active){

                            }else{
                                DrawTexturePro(stormheadRun, stormheadRun_sourceRect, stormheadRun_destRect, origin, rotation, RAYWHITE);
                            }
                        EndMode2D();

                    }else if(flagFirstFase == true && flagSecondFase == true){

                        ClearBackground(BLACK);
                        DrawTextureV(secondFase, positionMaps, WHITE);
                        
                    }
                EndDrawing();
            }else{
                IniciarMenu();
            }

        }
    }
}
