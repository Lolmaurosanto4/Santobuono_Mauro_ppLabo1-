/*
 * Viaje.h
 *
 *  Created on: 6 oct. 2021
 *      Author: Mauro
 */

#ifndef VIAJE_H_
#define VIAJE_H_

    #define PED_EMPTY 0
    #define PED_USED 1

    #define HDPE 0
    #define LDPE 1
    #define PP 2

    #define ENCURSO 0
    #define PROCESADO 1

    typedef struct
    {
        int idViaje;
        char descripcion[25];
        int kms;
        int flagEstado;

    }sPedido;

#endif /* VIAJE_H_ */
