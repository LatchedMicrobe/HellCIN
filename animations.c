#include "animations.h"


float runningAnimations(int *frameCounter, int *frameSpeed, int *currentFrame, float sourceValue, int measureFrame){
    if(*(frameCounter) >= (60/(*(frameSpeed)))){
        *(frameCounter) = 0;
        (*(currentFrame)) += 1;;
        if(*(currentFrame) > 6)  
            *(currentFrame) = 0;
        sourceValue = (float)(*(currentFrame)) * (float)measureFrame;
    }
    return sourceValue;
}