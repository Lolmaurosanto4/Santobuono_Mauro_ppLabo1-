/*
 * Avion.c
 *
 *  Created on: 6 oct. 2021
 *      Author: Mauro
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Avion.h"

static int aviones_findEmptyPlace(sAvion* pAviones, int length);
static int aviones_findNextId(sAvion* pAviones, int length);

/** \brief  Se marcan todas las posiciones del array como libres
 *          colocando en cada elmento el flag de flagEstado en TRUE
 *
 * \param sAbonado* pClientes Puntero al array de Clientes
 * \param length int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL] - (0) si Ok
 *
 */
int aviones_init(sAvion* pAviones, int length)
{
    int i;
    int retorno=-1;
    if(pAviones != NULL && length > 0)
    {
        for(i=0;i<length;i++)
        {
            (pAviones+i)->flagEstado = AVION_EMPTY;
        }
        retorno = 0;
    }
    return retorno;
}


/** \brief Agrega a la lista de Clientes un nuevo elemento, el id no lo recibe lo calcula
 * \param sAbonado* pClientes Puntero al array de Clientes
 * \param length int Longitud del array
 * \param numero int Numero del abonado
 * \param nombre[] char Nombre del abonado
 * \param direccion[] char
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL o sin espacio libre] - (0) si Ok
 *
 */
int aviones_append(sAvion* pAviones, int length,int idAvion, int matricula, int fecha, int idViaje, int idMarca,int modelo, int cantAsientos)
{
    int retorno=-1;
    int id,index;
    if(pAviones != NULL && length > 0)
    {
        index = aviones_findEmptyPlace(pAviones, length);
        if(index != -1)
        {
            id = aviones_findNextId(pAviones, length);
            (pAviones+index)->idAvion = idAvion;
            (pAviones+index)->matricula = matricula;
            (pAviones+index)->fecha = fecha;
            (pAviones+index)->idViaje = idViaje;
            (pAviones+index)->idMarca = idMarca;
            (pAviones+index)->modelo = modelo;
            (pAviones+index)->cantAsientos = cantAsientos;
            (pAviones+index)->flagEstado = AVION_USED;
            retorno=0;
        }
    }
    return retorno;

}

/** \brief Busca en la lista un abonado que coincida con el Id recibido
 *
 * \param sAbonado* pClientes Puntero al array de Clientes
 * \param length int Longitud del array
 * \param idCliente int ID del abonado
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL o sin no se encontro el abonado] - (0) si Ok
 *
 */
sAvion* aviones_find(sAvion* pAviones, int length, int idAvion)
{
    sAvion* pRetorno = NULL;
    int i;
    if(pAviones != NULL && length > 0)
    {
        for(i=0;i<length;i++)
        {
            if((pAviones+i)->idAvion == idAvion && (pAviones+i)->flagEstado == AVION_USED)
            {
                pRetorno = (pAviones+i);
                break;
            }
        }
    }
    return pRetorno;
}


/** \brief Elimina de manera logica un abonado de la lista
 *         colocando el flag de flagEstado en TRUE
 *
 * \param sAbonado* pClientes Puntero al array de Clientes
 * \param length int Longitud del array
 * \param idCliente int ID del abonado
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL]
 *                    (-2) si hay un Error [No se encontro el abonado]
 *                    ( 0) si Ok
 *
 */
int aviones_remove(sAvion* pAviones, int length, int idAvion)
{
    sAvion* pAuxCliente;
    int retorno = -1;

    pAuxCliente = clientes_find(pAviones, length, idAvion);
    if(pAuxCliente != NULL)
    {
        pAuxCliente->flagEstado = AVION_DELETE;
        retorno = 0;
    }

    return retorno;
}


/** \brief Modifica el nombre y el direccion de un abonado existente
 *
 * \param sAbonado* pClientes Puntero al array de Clientes
 * \param length int Longitud del array
 * \param idCliente int ID del abonado
 * \param nombre int Nombre del abonado
 * \param direccion int direccion del abonado
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL o si la longitud del nombre/direccion es < 1] - (0) si Ok
 *
 */
int Aviones_update(sAvion* pAviones, int length, int idAvion, int modelo, int cantAsientos)
{
    int retorno=-1;
    sAvion* pAuxAvion;

    if(pAviones != NULL && length > 0)
    {
        pAuxAvion = Aviones_find(pAviones, length,idAvion);
        if(pAuxAvion != NULL)
        {
            (pAuxAvion->modelo, modelo);
            (pAuxAvion->cantAsientos,cantAsientos);
            retorno=0;
        }
    }
    return retorno;
}

/** \brief  Busca en el array la primer posicion libre
 * \param sAbonado* pClientes Puntero al array de Clientes
 * \param length int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL] - (index del lugar libre) si Ok
 *
 */
static int aviones_findEmptyPlace(sAvion* pAviones, int length)
{
    int i;
    int retorno=-1;
    if(pAviones != NULL && length > 0)
    {
        for(i=0;i<length;i++)
        {
            if((pAviones+i)->flagEstado == AVION_EMPTY)
            {
                retorno = i;
                break;
            }
        }

    }
    return retorno;
}


/** \brief  Busca en el array el id mas alto entre los usados y los borrados
 * \param sAbonado* pClientes Puntero al array de Clientes
 * \param length int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL] - (proximo ID) si Ok
 *
 */
static int aviones_findNextId(sAvion* pAviones, int length)
{
    int i, maxId=-1;
    int retorno=-1;
    if(pAviones != NULL && length > 0)
    {
        for(i=0;i<length;i++)
        {
            if((pAviones+i)->flagEstado == AVION_USED || (pAviones+i)->flagEstado == AVION_DELETE)
            {
                if((pAviones+i)->idAvion > maxId || maxId == -1)
                    maxId = (pAviones+i)->idAvion;
            }
        }
        retorno = maxId+1;
    }
    return retorno;
}

