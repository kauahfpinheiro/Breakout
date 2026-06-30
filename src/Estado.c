#include "Estado.h"
#include "raylib/raylib.h"



void atualizarEstados ( estado *e ) {

    int pausar = IsKeyPressed( KEY_SPACE ) ? 1 : 0;
    int inciar = IsKeyPressed( KEY_UP ) ? 1 : 0;


    if ( pausar == 1 && *e == emJogo ) {

        *e = pausado;

    }
    if ( inciar == 1 && ( *e == inicio || *e == pausado ) ) {

        *e = emJogo;

    }
    


}