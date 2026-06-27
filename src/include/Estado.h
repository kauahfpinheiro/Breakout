
#pragma once


typedef enum Estado {
    inicio,
    emJogo,
    pausado,
    dano,
} estado;


void atualizarEstados ( estado *e );

