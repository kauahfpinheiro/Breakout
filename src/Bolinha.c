#include "raylib/raylib.h"
#include "Bolinha.h"
#include "Estado.h"

/**
 * Atualiza a posição da bolinha na tela e resolve a colisão da mesma com as
 * extremidades da janela.
 */
void atualizarBolinha( Bolinha *bolinha, float delta, estado *e ) {

    // integração de Euler
    bolinha->centro.x += bolinha->vel.x * delta;
    bolinha->centro.y += bolinha->vel.y * delta;

    // verificação e resolução de colisão com as bordas horizontais da janela
    if ( bolinha->centro.x - bolinha->raio <= 0 ) {
        bolinha->centro.x = bolinha->raio;
        bolinha->vel.x = -bolinha->vel.x;
    } else if ( bolinha->centro.x + bolinha->raio >= GetScreenWidth() ) {
        bolinha->centro.x = GetScreenWidth() - bolinha->raio;
        bolinha->vel.x = -bolinha->vel.x;
    }

    // verificação e resolução de colisão com as bordas verticais da janela
    if ( bolinha->centro.y - bolinha->raio <= 0 ) {
        bolinha->centro.y = bolinha->raio;
        bolinha->vel.y = -bolinha->vel.y;
    } else if ( bolinha->centro.y + bolinha->raio >= GetScreenHeight() ) {
        
        *e = dano;
        
        //bolinha->centro.y = GetScreenHeight() - bolinha->raio;
       // bolinha->vel.y = -bolinha->vel.y;
    }

}

/**
 * Desenha ma bolinha.
 */
void desenharBolinha( Bolinha *bolinha ) {
    DrawCircleV( bolinha->centro, bolinha->raio, bolinha->cor );
}
void resetarDesenhoBola( Bolinha *bolinha, float tela, int jogadorY, int larguraJ ) {
    bolinha->centro.x = tela / 2;
    bolinha->centro.y = jogadorY - larguraJ;        
    bolinha->vel.x = 200;
    bolinha->vel.y = -200;
}