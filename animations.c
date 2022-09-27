#include "animations.h"

//    Definição das funções de animações do HELLCIN ~~ Rodrigo ;3

// De acordo com os parametros de contador de frames (para só tocar certas animações a cada certo intervalo), a velocidade da passagem de frames
// e o frame atual(esse precisa ser ponteiro para ter acesso a essa variavel de fora da animação), sourceValue(valor de passagem pra outros frames)
// de animação) e measureFrame(tamanho dos frames de animação) - Rodrigo

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