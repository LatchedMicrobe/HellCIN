#include "collision.h"


//    Definição das funções de colisões do HELLCIN ~~ Rodrigo ;3

// Com base nos da posição x e y do retangulo do personagem, do comprimento e largura do retangulo do personagem, e do mapa, define as bordas
// do mapas(Pode precisar ser mudada na adição de inimigos) - Rodrigo
void mapBorders(float *rectanglePosX, float *rectanglePosY, float rectangleWidth, float rectangleHeight, int mapWidth, int mapHeight){

    if(*(rectanglePosX) + rectangleWidth >= mapWidth){
        (*(rectanglePosX)) = mapWidth - rectangleWidth;
    }else if(*(rectanglePosX) <= 0){
        (*(rectanglePosX)) = 0;
    }

    if(*(rectanglePosY) + rectangleHeight >= mapHeight){
        (*(rectanglePosY)) = mapHeight - rectangleHeight;
    }else if(*(rectanglePosY) <= 0){
        (*(rectanglePosY)) = 0;
    }
}