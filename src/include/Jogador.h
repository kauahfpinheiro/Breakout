/**
 * Definição do tipo Jogador e operações associadas.
 * 
 * Um Jogador representa, obviamente, o jogador do Breakout, que tem como
 * objetivo quebrar todos os alvos contidos na tela.
 */
#pragma once

#include "raylib/raylib.h"
#include "Bolinha.h"


typedef struct Jogador {
    Rectangle ret;
    float velocidadeBase;    // a velocidade que será usada na movimentação (não é alterada)
    float velocidadeAtual;   // a velocidade usada no momento
    int vidas;
    Color cor;
    

} Jogador;

void entradaJogador( Jogador *j );
void atualizarJogador( Jogador *j, float delta );
void desenharJogador( Jogador *j );
void impactoJogador( Jogador *j, Bolinha *b);
void resetarDesenhoJogador( Jogador *jogador, float alturaTela, float larguratela );

