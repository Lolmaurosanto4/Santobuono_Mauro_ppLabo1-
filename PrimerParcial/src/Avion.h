/*
 * Avion.h
 *
 *  Created on: 6 oct. 2021
 *      Author: Mauro
 */

#ifndef AVION_H_
#define AVION_H_

    #define AVION_EMPTY 0
    #define AVION_USED 1
    #define AVION_DELETE 2

    typedef struct
    {
        int idAvion;
        int matricula;
        int fecha;
        int idViaje;
        int idMarca;
        int modelo;
        int cantAsientos;
        int flagEstado;

    }sAvion;


#endif /* AVION_H_ */


/** \brief  Se marcan todas las posiciones del array como libres
 *          colocando en cada elmento el flag de flagEstado en TRUE
 *
 * \param sCliente* pCliente Puntero al array de cliente
 * \param length int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL] - (0) si Ok
 *
 */
int aviones_init(sAvion* pAvion, int length);

/** \brief Agrega a la lista de abonados un nuevo elemento, el id no lo recibe lo calcula
 * \param sAbonado* pAbonados Puntero al array de abonados
 * \param length int Longitud del array
 * \param fecha int
 * \param idViaje int
 * \param idMcarca int
 * \param cantAsientnos int
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL o sin espacio libre] - (0) si Ok
 *
 */
int aviones_append(sAvion* pAviones, int length,int idAvion, int matricula, int fecha, int idViaje, int idMarca,int modelo, int cantAsientos);


/** \brief Busca en la lista un abonado que coincida con el Id recibido
 *
 * \param sAbonado* pAbonados Puntero al array de abonados
 * \param length int Longitud del array
 * \param idAbonado int ID del abonado
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL o sin no se encontro el abonado] - (0) si Ok
 *
 */
sAvion* avioens_find(sAvion* pAviones, int length, int idAvion);


/** \brief Elimina de manera logica un abonado de la lista
 *         colocando el flag de flagEstado en TRUE
 *
 * \param sAbonado* pAbonados Puntero al array de abonados
 * \param length int Longitud del array
 * \param idAbonado int ID del abonado
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL o sin no se encontro el abonado] - (0) si Ok
 *
 */
int aviones_remove(sAvion* pAviones, int length, int idAvion);


/** \brief Modifica el nombre y el apellido de un abonado existente
 *
 * \param sAbonado* pAbonados Puntero al array de abonados
 * \param length int Longitud del array
 * \param idAbonado int ID del abonado
 * \param nombre int Nombre del abonado
 * \param apellido int Apellido del abonado
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL o si la longitud del nombre/apellido es < 1] - (0) si Ok
 *
 */
int aviones_update(sAvion* pAviones, int length, int idAvion, int modelo, int cantAsientos);
