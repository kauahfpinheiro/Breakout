#include <stdlib.h>
#include <math.h>

#include "raylib/raylib.h"

#include "Jogador.h"


/**
 * Processa e entrada associada ao jogador.
 */
void entradaJogador( Jogador *j ) {

    // armazena -1 caso a tecla seta para a esquerda estiver pressionada ou 0 caso contrário
    int esquerda = IsKeyDown( KEY_LEFT )  ? -1 : 0;

    // armazena 1 caso a tecla seta para a direita estiver pressionada ou 0 caso contrário
    int direita  = IsKeyDown( KEY_RIGHT ) ?  1 : 0;

    // compõe os dois movimentos (estado das teclas)
    int movimento = esquerda + direita;

    // utiliza a composição do movimento para calcular a velocidade atual
    // usada para movimentar o jogador
    j->velocidadeAtual = j->velocidadeBase * movimento;

}

/**
 * Atualiza a posição do jogador e resolve a colisão com as extremidades da tela.
 */
void atualizarJogador( Jogador *j, float delta ) {

    // integração de Euler
    j->ret.x += j->velocidadeAtual * delta;

    // verificação e resolução de colisão com as bordas horizontais da janela
    if ( j->ret.x <= 0 ) {
        j->ret.x = 0;
    } else if ( j->ret.x + j->ret.width >= GetScreenWidth() ) {
        j->ret.x = GetScreenWidth() - j->ret.width;
    }

}
void impactoJogador( Jogador *j, Bolinha *b ) {
    float relImpact;
    float velocidade;
    float velocidadeHorizontal;
    float velocidadeVertical;
    if ( !CheckCollisionCircleRec( b->centro, b->raio, j->ret ) ) {
        return;
    }

     relImpact = ( b->centro.x - ( j->ret.x + j->ret.width * 0.5f ) ) / ( j->ret.width * 0.5f );
    if ( relImpact < -1.0f ){
        relImpact = -1.0f;
    } 
    if ( relImpact >  1.0f ){
        relImpact =  1.0f;
    } 

    velocidade = sqrtf( b->vel.x * b->vel.x + b->vel.y * b->vel.y );
    if ( velocidade < 1.0f ) {
        velocidade = 1.0f;
    }

    velocidadeHorizontal = relImpact * velocidade * 0.90f;
    velocidadeVertical = -sqrtf( fmaxf( velocidade * velocidade - velocidadeHorizontal * velocidadeHorizontal, 0.0f ) );

    b->vel.x = velocidadeHorizontal;
    b->vel.y = velocidadeVertical;

    b->centro.y = j->ret.y - b->raio - 1;
}

/**
 * Desenha um jogador.
 */
void desenharJogador( Jogador *j ) {
    DrawRectangleRec( j->ret, j->cor );
}