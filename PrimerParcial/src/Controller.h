/*
 * Controller.h
 *
 *  Created on: 6 oct. 2021
 *      Author: Mauro
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_



#endif /* CONTROLLER_H_ */

/** \brief Carga datos de prueba tanto en el array de Clientes como en el de llamadas
 * \param void
 * \return void
 */
void controller_mock(sAvion* pAviones, int lengthaviones);


/** \brief Pide al usuario los datos de un nuevo abonado y luego lo agrega al array
 * \param sAbonado* pClientes Puntero al array de Clientes
 * \param length int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL o sin espacio libre] - (0) si Ok
 *
 */
int controller_altaAviones(sAvion* pAviones, int length);


/** \brief Pide al usuario el ID, Nombre y Apellido  de un abonado a ser modificadolos luego los modifica
 * \param sAbonado* pClientes Puntero al array de Clientes
 * \param length int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL]
 *                    (-2) si hay un Error [No se encontro el abonado]
 *                    ( 0) si Ok
 */
int controller_modificarAviones(sAvion* pAviones, int length);


/** \brief Pide al usuario el ID de un abonado a ser dado de baja
 * \param sAbonado* pClientes Puntero al array de Clientes
 * \param length int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL]
 *                    (-2) si hay un Error [No se encontro el abonado]
 *                    ( 0) si Ok
 */
int controller_bajaAviones(sAvion* pAviones, int length);


/** \brief Recorre el array de Clientes y los muestra por pantalla
 * \param sAbonado* pClientes Puntero al array de Clientes
 * \param length int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL] - (0) si Ok
 *
 */
int controller_listarAviones(sAvion* pAviones, int length);

