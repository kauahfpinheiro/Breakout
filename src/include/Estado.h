
#pragma once


typedef enum Estado {
    inicio,
    emJogo,
    pausado,
    dano,
    gameOver,
    vitoria,
} estado;


void atualizarEstados ( estado *e );

