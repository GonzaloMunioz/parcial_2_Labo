/*
 * Parser.c
 *
 *  Created on: Nov 24, 2021
 *      Author: Gonza
 */

#include "Parser.h"

/**
 * @brief Parsea los datos de los libros desde el archivo .csv recibido como parametro y los agrega a la LinkedList
 * @param pFile Puntero a archivo a leer
 * @param pArrayListBooks Lista de entidad eBook
 * @return Retorna un valor logico para validar si hubo error (-1) o si salio todo ok (0)
 */
int parser_eBookFromText(FILE* pFile, LinkedList* pArrayListBooks)
{
	int returnAux;
	char id[128];
	char title[128];
	char author[128];
	char price[128];
	char idEditorial[128];
	eBook* auxBook;

	fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n ", id, title, author, price, idEditorial);

	while(!feof(pFile))
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n ", id, title, author, price, idEditorial);
		if(eBook_newParametros(&auxBook, id, title, author, price, idEditorial) == 0)
		{
			if(ll_add(pArrayListBooks, auxBook) == 0)
			{
				returnAux = 0;
			}
		}
	}

	return returnAux;
}

/**
 * @brief Parsea los datos de las editoriales desde el archivo .csv recibido como parametro y los agrega a la LinkedList
 * @param pFile Puntero a archivo a leer
 * @param pArrayListEditorial Lista de entidad eEditorial
 * @return Retorna un valor logico para validar si hubo error (-1) o si salio todo ok (0)
 */
int parser_eEditorialFromText(FILE* pFile, LinkedList* pArrayListEditorial)
{
	int returnAux;
	char idEditorial[128];
	char name[128];
	eEditorial* auxEditorial;

	fscanf(pFile, "%[^,],%[^\n]\n ", idEditorial, name);

	while(!feof(pFile))
	{
		fscanf(pFile, "%[^,],%[^\n]\n ", idEditorial, name);
		if(eEditorial_newParametros(&auxEditorial, idEditorial, name) == 0)
		{
			if(ll_add(pArrayListEditorial, auxEditorial) == 0)
			{
				returnAux = 0;
			}
		}
	}

	return returnAux;
}

/**
 * @brief Escribe en un archivo los datos de la LinkedList de entidad eBook, editorial Minotauro
 * @param pFile Puntero a archivo a escribir
 * @param pArrayListMinotauro Lista de entidad eBook
 * @return Retorna un valor logico para validar si hubo error (-1) o si salio todo ok (0)
 */
int parser_textFromMinotauro(FILE* pFile, LinkedList* pArrayListMinotauro)
{
	int tam;
	int returnAux = -1;
	int idAux;
	char titleAux[50];
	char authorAux[50];
	float priceAux;
	int idEditorialAux;
	eBook* bookAux = NULL;

	if(pFile != NULL)
	{
		tam = ll_len(pArrayListMinotauro);
		fprintf(pFile, "id,title,author,price,idEditorial\n");
		for(int i = 0; i < tam; i++)
		{
			bookAux = (eBook*) ll_get(pArrayListMinotauro, i);
			eBook_getId(bookAux, &idAux);
			eBook_getTitle(bookAux, titleAux);
			eBook_getAuthor(bookAux, authorAux);
			eBook_getPrice(bookAux, &priceAux);
			eBook_getIdEditorial(bookAux, &idEditorialAux);
			fprintf(pFile, "%d,%s,%s,%.2f,%d\n", idAux, titleAux, authorAux, priceAux, idEditorialAux);
		}
		returnAux = 0;
	}

	return returnAux;
}





