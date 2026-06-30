#pragma once

#include "raylib/raylib.h"
#include "Bolinha.h"

typedef struct Pontuacao {
    Vector2 pos;

    int valorPorAlvo;
    int pontos;
    float multVel;
    float ganhoPorHit;

    int tamanhoText;

} Pontuacao;



void pontos( Pontuacao *p );
void desenharPontuacao( Pontuacao *p);
void atualizarMult( Pontuacao *p);