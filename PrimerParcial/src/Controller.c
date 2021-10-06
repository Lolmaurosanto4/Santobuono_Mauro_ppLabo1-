/*
 * Controller.c
 *
 *  Created on: 6 oct. 2021
 *      Author: Mauro
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Avion.h"
#include "Viaje.h"





/** \brief Carga datos de prueba tanto en el array de Clientes como en el de Pedidos
 * \param void
 * \return void
 */
void controller_mock(sAvion* pAviones, int lengthavion)
{
	aviones_append(pAviones,lengthaviones ,1,1001, 10, 100,1003,2010, 102);
	aviones_append(pAviones,lengthaviones ,1,1002, 13, 101,1000,2015, 104);
	aviones_append(pAviones,lengthaviones ,1,1003, 15, 102,1002,2013, 101);


}


/** \brief Pide al usuario los datos de un nuevo Cliente y luego lo agrega al array
 * \param sCliente* pClientes Puntero al array de Clientes
 * \param length int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL o sin espacio libre] - (0) si Ok
 *
 */
int controller_altaAviones(sAvion* pAviones, int length)
{
    int matricula;
    int fecha;
    int idViaje;
    int idMarca;
    int modelo;
    int cantAsientos;
    int retorno=-1;

    system("clear");
    retorno = getValidInt("\nMatricula: ","\nMatricula valido 1000 - 10000", &matricula,1000,10000,3);
    if(retorno == 0)
    {
        retorno = getValidInt("\nFecha: ","\nFecha valido 1 - 31", &fecha,1,31,3);
        if(retorno == 0)
        {
            retorno = getValidInt("\nidViajes: ","\nidViajes valido 100 - 104", &idViaje,100,104,3);
            if(retorno == 0)
            {
            	retorno = getValidInt("\nidMarca: ","\nidMarca valido 1000 - 1003", &idMarca,1000,1003,3);
            	if(retorno == 0)
            	{
            		retorno = getValidInt("\nModelo: ","\nModelo valido 2000 - 2021", &modelo,2000,2021,3);
            		if(retorno == 0)
            			{
            			retorno = getValidInt("\nCantidad de asientos: ","\nCantidad de asientos valido 100 - 200", &cantAsientos,100,200,3);
            			if(retorno ==0)
            				{
            				 retorno = aviones_append(pAviones, length, matricula, fecha, idViaje, idMarca, modelo, cantAsientos);
            				}
            			}
            	}
            }
        }
    }
    return retorno;
}

/** \brief Pide al usuario el ID, Nombre, direccion y localidad  de un cliente a ser modificadolos luego los modifica
 * \param sCliente* pClientes Puntero al array de Clientes
 * \param length int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL]
 *                    (-2) si hay un Error [No se encontro el cliente]
 *                    ( 0) si Ok
 */
int controller_modificarAviones(sAvion* pAviones, int length)
{
    int modelo;
    char cantAsientos;
    int id;

    int retorno=-1;

    clearScreen();
    retorno = getValidInt("\nID a Modificar: ","\nRango valido 0-9999", &id,0,9999,3);

    if(retorno == 0)
    {
        if(aviones_find(pAviones, length, id) == NULL)
        {
            printf("El avion elegido no existe\n");
            pause();

        }
        else
        {
        	retorno = getValidInt("\nModelo: ","\nModelo valido 2000 - 2021", &modelo,2000,2021,3);
            if(retorno == 0)
            {
                retorno = getValidInt("\nCantidad de asientos: ","\nCantidad de asientos  valido 100 - 150", &cantAsientos,100,150,3);
                if(retorno == 0)
                {
                    retorno = aviones_update(pAviones, length, id, modelo, cantAsientos);
                }
            }
        }
    }
    return retorno;
}


/** \brief Pide al usuario el ID de un clietne a ser dado de baja
 * \param sCliente* pClientes Puntero al array de Clientes
 * \param length int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL]
 *                    (-2) si hay un Error [No se encontro el Cliente]
 *                    ( 0) si Ok
 */
int controller_bajaAviones(sAvion* pAviones, int length)
{
    int id;

    int retorno=-1;

    clearScreen();
    retorno = getValidInt("\nID a dar de Baja: ","\nRango valido 0-9999", &id,0,9999,3);

    if(retorno == 0)
    {
        if(aviones_find(pAviones, length, id) == NULL)
        {
            printf("El avion elegido no existe\n");
            pause();
        }
        else
        {
            retorno = aviones_remove(pAviones, length, id);
        }
    }
    return retorno;
}


/** \brief Recorre el array de Clientes y los muestra por pantalla
 * \param sCliente* pClientes Puntero al array de Clientes
 * \param length int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL] - (0) si Ok
 *
 */
int controller_listarAviones(sAvion* pAviones, int length)
{
    int retorno=-1,i;
    if(pAviones != NULL && length > 0)
    {
        clearScreen();
        printf("\n\n%4s - %-20s - %-20s - %-20s - %-20s - %-20s - %-8s\n"," ID AVION","    MATRICULA","    FECHA","   ID VIAJE","   ID MARCA","   MODELO","   CANTIDAD DE ASIENTOS");
        for(i=0;i<length;i++)
        {
            if((pAviones+i)->flagEstado == AVION_USED)
                printf("\n\n%4d - %-20d - %-20d - %-20d - %-20d - %-20d - %-8d\n",(pAviones+i)->idAvion,(pAviones+i)->matricula,(pAviones+i)->fecha,(pAviones+i)->idViaje,(pAviones+i)->idMarca),(pAviones+i)->modelo,(pAviones+i)->cantAsientos);
        }
        retorno = 0;
    }
    return retorno;
}


/** \brief Recorre el array de Pedidos y las muestra por pantalla
 * \param sCliente* pClientes Puntero al array de Clientes
 * \param length int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL] - (0) si Ok
 *
 */


