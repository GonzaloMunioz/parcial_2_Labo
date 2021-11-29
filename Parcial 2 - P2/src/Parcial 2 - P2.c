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
#define DATAFILTERED "filtrado.csv"
#define DATAMAPED "mapeado.csv"

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
		IngresarEnteroValidado("\n======================== MENU ========================"
				"\n 1) CARGAR los datos de libros"
				"\n 2) CARGAR los datos de editoriales"
				"\n 3) ORDENAR lista segun autor"
				"\n 4) IMPRIMIR por pantalla listado de libros"
				"\n 5) GENERAR archivo para lista filtrada"
				"\n 6) GENERAR archivo para lista mapeada"
				"\n 0) SALIR\n======================================================"
				"\n  Indique la opcion deseada: ", 0, 6, &option);
		switch(option)
		{
			case 1:
				if(flagBooks == 0)
				{
					if(controller_loadFromText(DATALIBRO, pArrayListBook, pArrayListEditorial, 1) == 0)
					{
						flagBooks = 1;
						printf("\nSe han cargado los datos de libros correctamente\n");
					}
					else
					{
						printf("\nOcurrio un error con la carga de los datos de libros\n");
					}
				}
				else
				{
					printf("\nYa se han cargado los datos de libros");
				}

				break;

			case 2:
				if(flagEditorials == 0)
				{
					if(controller_loadFromText(DATAEDITORIAL, pArrayListBook, pArrayListEditorial, 0) == 0)
					{
						flagEditorials = 1;
						printf("\nSe han cargado los datos de editoriales correctamente\n");
					}
					else
					{
						printf("\nOcurrio un error con la carga de los datos de editoriales\n");
					}
				}
				else
				{
					printf("\nYa se han cargado los datos de editoriales");
				}
				break;

			case 3:
				if((flagBooks == 1) && (flagEditorials == 1))
				{
					if(controller_sortBook(pArrayListBook) == 0)
					{
						printf("\nSe han ordenado los datos de libros correctamente\n");
					}
					else
					{
						printf("\nOcurrio un error con el ordenamiento de datos de libros\n");
					}
				}
				else
				{
					printf("\nPrimero debe cargar los datos de libros y/o editoriales\n");
				}
				break;

			case 4:
				if((flagBooks == 1) && (flagEditorials == 1))
				{
					if(controller_ListBook(pArrayListBook, pArrayListEditorial, "     LISTADO    ") == 0)
					{
						printf("\nSe ha mostrado por pantalla el listado\n");
					}
					else
					{
						printf("\nOcurrio un error a la hora de imprimir el listado en pantalla\n");
					}
				}
				else
				{
					printf("\nPrimero debe cargar los datos de libros y/o editoriales\n");
				}
				break;

			case 5:
				if((flagBooks == 1) && (flagEditorials == 1))
				{
					if(controller_list_by_MinotauroEditorial(DATAFILTERED , pArrayListBook, pArrayListMinotauro, pArrayListEditorial) == 0)
					{
						printf("\nSe ha creado y cargado el archivo con el listado filtrado correctamente\n");
					}
					else
					{
						printf("\nOcurrio un error a la hora de filtrar el listado\n");
					}
				}
				else
				{
					printf("\nPrimero debe cargar los datos de libros y/o editoriales\n");
				}
				break;

			case 6:
				if((flagBooks == 1) && (flagEditorials == 1))
				{
					if(controller_mapList(DATAMAPED, pArrayListBook, pArrayListEditorial) == 0)
					{
						printf("\nSe ha mapeado el listado correctamente, y se ha guardado en el archivo %c%s%c\n", 34, DATAMAPED, 34);
					}
					else
					{
						printf("\nOcurrio un error a la hora de mapear el listado\n");
					}
				}
				else
				{
					printf("\nPrimero debe cargar los datos de libros y/o editoriales\n");
				}
				break;

			case 0:
				printf("\nPROGRAMA FINALIZADO CON EXITO");
				break;
		}
	}
	while(option != 0);

	return EXIT_SUCCESS;
}
