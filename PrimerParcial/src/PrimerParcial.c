/*
 ============================================================================
 Name        : PrimerParcial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "controller.h"

#define CLIENTES_CANTIDAD 100
#define PEDIDOS_CANTIDAD 1000


int main(void) {
	setbuf(stdout, NULL);


	int main()
	{
	    int menuOpcionElegida;
	    char menuPrinsipalMensaje[] =
	                "\n1-Alta del avion\
	                 \n2-Modificar datos del avion\
	                 \n3-Baja del avion\
	                 \n4-Listar aviones\
	                 \n5-Listar viajes\
	                 \n6-Listar marcas\
	                 \n7-Salir\n\
	                 \nIngrese opcion: ";
	    char menuPrinsipalMensajeError[] = "\nSe debe elegir una opcion del 1 al 7";

	    //Se crea el array de clientes y se inicializa
	    sAvion arrayAviones[CLIENTES_CANTIDAD];
	    aviones_init(arrayAviones,CLIENTES_CANTIDAD);

	    //Se crea el array de pedidos y se inicializa
	    sPedido arrayLlamadas[PEDIDOS_CANTIDAD];
	    pedidos_init(arrayLlamadas,PEDIDOS_CANTIDAD);

	    // Carga datos de test
	    controller_mock(arrayLlamadas, PEDIDOS_CANTIDAD,arrayClientes,CLIENTES_CANTIDAD);

	    do
	    {
	        clearScreen();
	        menuOpcionElegida = 0;
	        getValidInt(menuPrinsipalMensaje,menuPrinsipalMensajeError, &menuOpcionElegida , 0 , 7 , 2 );

	        switch(menuOpcionElegida)
	        {
	        case 1: // ALTA CLIENTE
	            controller_altaCliente(arrayClientes,CLIENTES_CANTIDAD);
	            break;
	        case 2: // MODIFICAR CLIENTE
	            controller_modificarCliente(arrayClientes,CLIENTES_CANTIDAD);
	            break;
	        case 3: // BAJA CLIENTE
	            controller_bajaCliente(arrayClientes,CLIENTES_CANTIDAD);
	            break;
	        case 4: // INFORMES
	        	 controller_listarClientes(arrayClientes,CLIENTES_CANTIDAD);
	        	 pause();

	            break;
	        case 5: // LISTAR PEDIDOS

	            pause();
	            break;
	        case 6: // LISTAR CLIENTES

	            pause();
	            break;
	        case 7:
	            //SALIR
	            break;
	        default:
	            printf("\nNO ES UNA OPCION VALIDA!!!\n\n");
	            pause();
	            break;
	        }

	    }while(menuOpcionElegida != 9);

	    return 0;

	}
}
