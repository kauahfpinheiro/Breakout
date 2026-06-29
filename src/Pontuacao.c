#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#include "raylib/raylib.h"

#include "Pontuacao.h"



void desenharPontuacao( Pontuacao *p) {
    char textoPontos[64];
    int tamanhoFonte = 20;
    int margem = 20;

    sprintf(textoPontos, "PONTOS: %d", p->pontos);

    p->tamanhoText = MeasureText(textoPontos, tamanhoFonte);

    float larguraTela = (float) GetScreenWidth();
    p->pos.x = larguraTela - p->tamanhoText - margem;

    if ( p->pos.x < margem ) {
        p->pos.x = margem;
    }

    DrawText(textoPontos, p->pos.x, p->pos.y, tamanhoFonte, WHITE);
}

void pontos( Pontuacao *p ) {
    p->pontos += p->valorPorAlvo;
}

void atualizarMult( Pontuacao *p) {
    float progresso = (float) p->pontos / 100.0f;
    p->multVel = 1.0f + (progresso * p->ganhoPorHit);
}
