/*
 * Controller.c
 *
 *  Created on: Nov 24, 2021
 *      Author: Gonza
 */

#include "Controller.h"

/**
 * @brief Carga dentro de la LinkedList (option == 1 -> eBook | option == 0 -> eEditorial) los datos que lee desde el archivo .csv
 * @param path Nombre de archivo a leer
 * @param pArrayListBook Lista de entidad eBook
 * @param pArrayListEditorial Lista de entidad eEditorial
 * @param option (option == 1 -> eBook | option == 0 -> eEditorial)
 * @return Retorna un valor logico para validar si hubo error (-1) o si salio todo ok (0)
 */
int controller_loadFromText(char* path, LinkedList* pArrayListBook, LinkedList* pArrayListEditorial, int option)
{
	FILE* pFile = NULL;
	int returnAux = -1;

	pFile = fopen(path, "r");

	if(pFile != NULL)
	{
		if(option == 1)
		{
			parser_eBookFromText(pFile, pArrayListBook);
		}
		else
		{
			if(option == 0)
			{
				parser_eEditorialFromText(pFile, pArrayListEditorial);
			}
		}
		returnAux = 0;
	}
	fclose(pFile);

	return returnAux;
}

/**
 * @brief Escribe en un archivo .csv los datos de la nueva LinkedList recibida como parametro
 * @param path Nombre de archivo a escribir
 * @param pArrayListMinotauro Lista de entidad eBook editorial Minotauro
 * @return Retorna un valor logico para validar si hubo error (-1) o si salio todo ok (0)
 */
int controller_saveFromLinkedList(char* path, LinkedList* pArrayList)
{
	FILE* pFile = NULL;
	int returnAux = -1;

	pFile = fopen(path, "w");

	if(pFile != NULL)
	{
		parser_textFromLinkedList(pFile, pArrayList);
		returnAux = 0;
	}
	fclose(pFile);

	return returnAux;
}

/**
 * @brief Busca una coincidencia dentro del array eEditorial con el ID pasado como parametro y retorna su indice
 * @param pArrayListEditorial Lista de entidad eEditorial
 * @param id ID a comparar
 * @return Retorna un valor logico para validar si hubo error (-1) o si salio todo ok (i)
 */
int controller_findIndexById(LinkedList* pArrayListEditorial, int id)
{
	int tam;
	int i = 0;
	int flagFound = 0;
	int returnAux;
	eEditorial* editorialAux = NULL;

	if(pArrayListEditorial != NULL)
	{
		tam = ll_len(pArrayListEditorial);
		while((flagFound == 0) && (i < tam))
		{
			editorialAux = (eEditorial*) ll_get(pArrayListEditorial, i);
			if(editorialAux->idEditorial == id)
			{
				flagFound = 1;
				returnAux = i;
			}
			else
			{
				i++;
			}
		}
	}

	return returnAux;
}

/**
 * @brief Imprime un eBook recibido como parametro y su editorial correspondiente
 * @param newBook eBook a imprimir
 * @param pArrayListEditorial Lista de entidad eEditorial
 * @return Retorna un valor logico para validar si hubo error (-1) o si salio todo ok (0)
 */
int controller_print(eBook* newBook, LinkedList* pArrayListEditorial)
{
	int retorno;
	int idAux;
	char titleAux[50];
	char authorAux[50];
	float priceAux;
	int idEditorialAux;
	char nameAux[50];
	int indexEditorial;
	eEditorial* editorialAux = NULL;

	retorno = -1;

	if(newBook != NULL)
	{
		eBook_getId(newBook, &idAux);
		eBook_getTitle(newBook, titleAux);
		eBook_getAuthor(newBook, authorAux);
		eBook_getPrice(newBook, &priceAux);
		eBook_getIdEditorial(newBook, &idEditorialAux);
		indexEditorial = controller_findIndexById(pArrayListEditorial, idEditorialAux);
		editorialAux = (eEditorial*) ll_get(pArrayListEditorial, indexEditorial);
		eEditorial_getName(editorialAux, nameAux);
		printf("| %6d | %-50s | %-25s | %-23s | %c%11.2f |\n", idAux, titleAux, authorAux, nameAux, 36, priceAux);
		retorno = 0;
	}

	return retorno;
}

/**
 * @brief Imprime el listado de eBooks obtenidos de la LinkedList
 * @param pArrayListBook Lista de entidad eBook
 * @param pArrayListEditorial Lista de entidad eEditorial
 * @return Retorna un valor logico para validar si hubo error (-1) o si salio todo ok (0)
 */
int controller_ListBook(LinkedList* pArrayListBook, LinkedList* pArrayListEditorial, char* keyword)
{
	eBook* auxBook;
	int tam;
	int returnAux = -1;

	if(pArrayListBook != NULL)
	{
		tam = ll_len(pArrayListBook);
		printf("\n===================================================================================================================================="
				"\n|                                                    %s                                                              |"
				"\n===================================================================================================================================="
				"\n|   ID   |                       TITULO                       |           AUTOR           |        EDITORIAL        |    PRECIO    |"
				"\n====================================================================================================================================\n", keyword);
		for(int i = 0; i < tam; i++)
		{
			auxBook = (eBook*) ll_get(pArrayListBook, i);
			controller_print(auxBook, pArrayListEditorial);
			returnAux = 0;
		}
		printf("====================================================================================================================================\n");
		returnAux = 0;
	}

	return returnAux;
}

/**
 * @brief Ordena el listado de eBook alfabeticamente, de forma ascendente, segun autor
 * @param pArrayListBook Lista de entidad eBook
 * @return Retorna un valor logico para validar si hubo error (-1) o si salio todo ok (0)
 */
int controller_sortBook(LinkedList* pArrayListBook)
{
	int returnAux = -1;

	if(pArrayListBook != NULL)
	{
		if(ll_sort(pArrayListBook, eBook_compare_by_author, 1) == 0)
		{
			returnAux = 0;
		}
	}

	return returnAux;
}

/**
 * @brief Obtiene, guarda en un archivo e imprime el listado de eBooks con editorial Minotauro obtenido del array de eBooks
 * @param path Nombre de archivo a escribir
 * @param pArrayListBook Lista de entidad eBook
 * @param pArrayListMinotauro Lista de entidad eBook en la que guardaremos solo los eBook que tengan editorial Minotauro
 * @param pArrayListEditorial Lista de entidad eEditorial
 * @return Retorna un valor logico para validar si hubo error (-1) o si salio todo ok (0)
 */
int controller_list_by_MinotauroEditorial(char* path, LinkedList* pArrayListBook, LinkedList* pArrayListMinotauro, LinkedList* pArrayListEditorial)
{
	int returnAux = -1;

	if((pArrayListBook != NULL) && (pArrayListEditorial != NULL))
	{
		pArrayListMinotauro = ll_filter(pArrayListBook, eBook_compare_editorial);
		if(controller_saveFromLinkedList(path, pArrayListMinotauro) == 0)
		{
			controller_ListBook(pArrayListMinotauro, pArrayListEditorial, "LISTADO FILTRADO");
			returnAux = 0;
		}
	}

	return returnAux;
}

/**
 * @brief Mapea el listado de eBooks, creando un nuevo listado, guardandolo en un nuevo archivo y luego lo imprime
 * @param path Nombre de archivo a escribir
 * @param pArrayListBook Lista de entidad eBook a mapear
 * @param pArrayListEditorial Lista de entidad eEditorial
 * @return Retorna un valor logico para validar si hubo error (-1) o si salio todo ok (0)
 */
int controller_mapList(char* path, LinkedList* pArrayListBook, LinkedList* pArrayListEditorial)
{
	int returnAux = -1;

	if(pArrayListBook != NULL)
	{
		if((ll_map(pArrayListBook, eBook_applyDiscount) == 0) && (controller_saveFromLinkedList(path, pArrayListBook) == 0))
		{
			controller_ListBook(pArrayListBook, pArrayListEditorial, " LISTADO MAPEADO");
			returnAux = 0;
		}
	}

	return returnAux;
}












