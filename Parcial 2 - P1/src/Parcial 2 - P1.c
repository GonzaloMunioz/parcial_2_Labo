/*
 ============================================================================
 Name        : Parcial.c
 Author      : Gonza
 Description : Segundo parcial laboratorio I
 ============================================================================
 */

#include "Controller.h"
#define DATALIBRO "eBook.csv"
#define DATAEDITORIAL "eEditorial.csv"
#define DATAMINOTAURO "eBook_Minotauro.csv"

int main(void) {
	setbuf(stdout, NULL);
	int option;
	int flagBooks = 0;
	int flagEditorials = 0;
	LinkedList* pArrayListBook = ll_newLinkedList();
	LinkedList* pArrayListEditorial = ll_newLinkedList();
	LinkedList* pArrayListMinotauro = NULL;

	do
	{
		IngresarEnteroValidado("\n1) CARGAR los datos de libros\n2) CARGAR los datos de editoriales\n3) ORDENAR lista segun autor\n4) IMPRIMIR por pantalla listado de libros\n5) GENERAR archivo de libros de editorial Minotauro\n0) SALIR\n Indique la opcion deseada: ", 0, 6, &option);
		switch(option)
		{
			case 1:
				if(flagBooks == 0)
				{
					if(controller_loadFromText(DATALIBRO, pArrayListBook, pArrayListEditorial, 1) == 0)
					{
						flagBooks = 1;
						printf("Se han cargado los datos de libros correctamente\n");
					}
					else
					{
						printf("Ocurrio un error con la carga de los datos de libros\n");
					}
				}
				else
				{
					printf("Ya se han cargado los datos de libros");
				}

				break;

			case 2:
				if(flagEditorials == 0)
				{
					if(controller_loadFromText(DATAEDITORIAL, pArrayListBook, pArrayListEditorial, 0) == 0)
					{
						flagEditorials = 1;
						printf("Se han cargado los datos de editoriales correctamente\n");
					}
					else
					{
						printf("Ocurrio un error con la carga de los datos de editoriales\n");
					}
				}
				else
				{
					printf("Ya se han cargado los datos de editoriales");
				}
				break;

			case 3:
				if((flagBooks == 1) && (flagEditorials == 1))
				{
					if(controller_sortBook(pArrayListBook) == 0)
					{
						printf("Se han ordenado los datos de libros correctamente\n");
					}
					else
					{
						printf("Ocurrio un error con el ordenamiento de datos de libros\n");
					}
				}
				else
				{
					printf("Primero debe cargar los datos de libros y/o editoriales\n");
				}
				break;

			case 4:
				if((flagBooks == 1) && (flagEditorials == 1))
				{
					if(controller_ListBook(pArrayListBook, pArrayListEditorial) != 0)
					{
						printf("Ocurrio un error a la hora de imprimir el listado en pantalla\n");
					}
				}
				else
				{
					printf("Primero debe cargar los datos de libros y/o editoriales\n");
				}
				break;

			case 5:
				if((flagBooks == 1) && (flagEditorials == 1))
				{
					if(controller_list_by_MinotauroEditorial(DATAMINOTAURO , pArrayListBook, pArrayListMinotauro, pArrayListEditorial) == 0)
					{
						printf("Se ha creado y cargado el archivo con data de listado minotauro exitosamente\n");
					}
				}
				else
				{
					printf("Primero debe cargar los datos de libros y/o editoriales\n");
				}
				break;
		}
	}
	while(option != 0);

	return EXIT_SUCCESS;
}
