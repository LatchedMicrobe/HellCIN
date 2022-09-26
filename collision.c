#include "collision.h"

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