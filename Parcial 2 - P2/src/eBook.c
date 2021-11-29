/*
 * eBook.c
 *
 *  Created on: Nov 24, 2021
 *      Author: Gonza
 */

#include "eBook.h"

/**
 * @brief Establece dentro del eBook el ID que recibe como parametro
 * @param newBook Puntero a puntero a puntero a la ubicacion de nuestro eBook
 * @param id ID a establecer
 * @return Retorna un valor logico para validar si hubo error (-1) o si salio todo ok (0)
 */
int eBook_setId(eBook*** newBook, int id)
{
	int returnAux = -1;

	if(newBook != NULL)
	{
		(**newBook)->id = id;
		returnAux = 0;
	}

	return returnAux;
}

/**
 * @brief Obtiene de nuestro eBook el ID y lo asigna al puntero a int recibido como parametro
 * @param newBook Puntero a la ubicacion de nuestro eBook
 * @param id Puntero a la variable que se le asignara el ID obtenido
 * @return Retorna un valor logico para validar si hubo error (-1) o si salio todo ok (0)
 */
int eBook_getId(eBook* newBook, int* id)
{
	int returnAux = -1;

	if (newBook != NULL) {
		*id = newBook->id;
		returnAux = 0;
	}

	return returnAux;
}

/**
 * @brief Establece dentro del eBook el titulo que recibe como parametro
 * @param newBook Puntero a puntero a puntero a la ubicacion de nuestro eBook
 * @param title Titulo a establecer
 * @return Retorna un valor logico para validar si hubo error (-1) o si salio todo ok (0)
 */
int eBook_setTitle(eBook*** newBook, char* title)
{
	int returnAux = -1;

	if(newBook != NULL)
	{
		strcpy((**newBook)->title, title);
		returnAux = 0;
	}

	return returnAux;
}

/**
 * @brief Obtiene de nuestro eBook el titulo y lo asigna al puntero a char recibido como parametro
 * @param newBook Puntero a la ubicacion de nuestro eBook
 * @param title Puntero a la variable que se le asignara el titulo obtenido
 * @return Retorna un valor logico para validar si hubo error (-1) o si salio todo ok (0)
 */
int eBook_getTitle(eBook* newBook, char* title)
{
	int returnAux = -1;

	if(newBook != NULL)
	{
		strcpy(title, newBook->title);
		returnAux = 0;
	}

	return returnAux;
}

/**
 * @brief Establece dentro del eBook el autor que recibe como parametro
 * @param newBook Puntero a puntero a puntero a la ubicacion de nuestro eBook
 * @param author Autor a establecer
 * @return Retorna un valor logico para validar si hubo error (-1) o si salio todo ok (0)
 */
int eBook_setAuthor(eBook*** newBook, char* author)
{
	int returnAux = -1;

	if(newBook != NULL)
	{
		strcpy((**newBook)->author, author);
		returnAux = 0;
	}

	return returnAux;
}

/**
 * @brief Obtiene de nuestro eBook el autor y lo asigna al puntero a char recibido como parametro
 * @param newBook Puntero a la ubicacion de nuestro eBook
 * @param author Puntero a la variable que se le asignara el autor obtenido
 * @return Retorna un valor logico para validar si hubo error (-1) o si salio todo ok (0)
 */
int eBook_getAuthor(eBook* newBook, char* author)
{
	int returnAux = -1;

	if(newBook != NULL)
	{
		strcpy(author, newBook->author);
		returnAux = 0;
	}

	return returnAux;
}

/**
 * @brief Establece dentro del eBook el precio que recibe como parametro
 * @param newBook Puntero a puntero a puntero a la ubicacion de nuestro eBook
 * @param price Precio a establecer
 * @return Retorna un valor logico para validar si hubo error (-1) o si salio todo ok (0)
 */
int eBook_setPrice(eBook*** newBook, float price)
{
	int returnAux = -1;

	if(newBook != NULL)
	{
		(**newBook)->price = price;
		returnAux = 0;
	}

	return returnAux;
}

/**
 * @brief Obtiene de nuestro eBook el precio y lo asigna al puntero a float recibido como parametro
 * @param newBook Puntero a la ubicacion de nuestro eBook
 * @param price Puntero a la variable que se le asignara el precio obtenido
 * @return Retorna un valor logico para validar si hubo error (-1) o si salio todo ok (0)
 */
int eBook_getPrice(eBook* newBook, float* price)
{
	int returnAux = -1;

	if (newBook != NULL) {
		*price = newBook->price;
		returnAux = 0;
	}

	return returnAux;
}

/**
 * @brief Establece dentro del eBook el idEditorial que recibe como parametro
 * @param newBook Puntero a puntero a puntero a la ubicacion de nuestro eBook
 * @param idEditorial idEditorial a establecer
 * @return Retorna un valor logico para validar si hubo error (-1) o si salio todo ok (0)
 */
int eBook_setIdEditorial(eBook*** newBook, int idEditorial)
{
	int returnAux = -1;

	if(newBook != NULL)
	{
		(**newBook)->idEditorial = idEditorial;
		returnAux = 0;
	}

	return returnAux;
}

/**
 * @brief Obtiene de nuestro eBook el idEditorial y lo asigna al puntero a int recibido como parametro
 * @param newBook Puntero a la ubicacion de nuestro eBook
 * @param idEditorial Puntero a la variable que se le asignara el idEditorial obtenido
 * @return Retorna un valor logico para validar si hubo error (-1) o si salio todo ok (0)
 */
int eBook_getIdEditorial(eBook* newBook, int* idEditorial)
{
	int returnAux = -1;

	if (newBook != NULL) {
		*idEditorial = newBook->idEditorial;
		returnAux = 0;
	}

	return returnAux;
}

/**
 * @brief Compara los dos elementos segun el campo autor
 * @param one Primer elemento a comparar
 * @param two Segundo elemento a comparar
 * @return Retorna un valor logico para validar si hubo error (-1) o si salio todo ok (resultado de la comparacion)
 */
int eBook_compare_by_author(void* one, void* two)
{
	int returnAux = -1;
	char nameOne[128];
	char nameTwo[128];

	if((eBook_getAuthor((eBook*) one, nameOne) == 0) && (eBook_getAuthor((eBook*) two, nameTwo) == 0))
	{
		returnAux = stricmp(nameOne, nameTwo);
	}

	return returnAux;
}

/**
 * @brief Compara el elemento recibido como parametro para validar que su ID sea 4 (Minotauro)
 * @param aux Elemento a comparar
 * @return Retorna un valor logico para validar si hubo error (-1) o si el elemento no tenia ID == 4 (0) y si el elemento tenia ID == 4 (1)
 */
int eBook_compare_editorial(void* aux)
{
	int returnAux = -1;
	int idAux;

	if(eBook_getIdEditorial((eBook*) aux, &idAux) == 0)
	{
		returnAux = 0;
		if(idAux == 4)
		{
			returnAux = 1;
		}
	}

	return returnAux;
}

/**
 * @brief Aplica un descuento a todos los elementos de la editorial Planeta (20%) que tengan un precio mayor o igual a $300
 * 		  o a todos los elementos de la editorial Siglo XXI Editores (10%) que tengan un precio mayor o igual a $200
 * @param aux Elemento a aplicar el descuento
 * @return Puntero a elemento con el descuento aplicado, si corresponde
 */
int eBook_applyDiscount(void* aux)
{
	int idAux;
	int returnAux = -1;
	float priceAux;

	if((eBook_getIdEditorial((eBook*) aux, &idAux) == 0) && (eBook_getPrice((eBook*) aux, &priceAux) == 0))
	{
		if((idAux == 1) && (priceAux > 299))
		{
			priceAux = priceAux - (priceAux * 20 / 100);
		}
		else
		{
			if((idAux == 2) && (priceAux > 199))
			{
				priceAux = priceAux - (priceAux * 10 / 100);
			}
		}
		((eBook*)aux)->price = priceAux;
		returnAux = 0;
	}

	return returnAux;
}

/**
 * @brief Crea un espacio en memoria dinamica para un eBook y lo asigna al puntero a puntero a puntero recibido como parametro
 * @param newBook Puntero a puntero a puntero a la ubicacion de nuestro eBook
 * @return Retorna un valor logico para validar si hubo error (-1) o si salio todo ok (0)
 */
int eBook_new(eBook*** newBook)
{
	int returnAux = -1;

	**newBook = (eBook*) malloc(sizeof(eBook));

	if(newBook != NULL)
	{
		returnAux = 0;
	}

	return returnAux;
}

/**
 * @brief Crea un espacio en memoria dinamica para un eBook, carga en el los datos recibidos por parametros y lo asigna al puntero a puntero recibido como parametro
 * @param newBook Puntero a puntero a la ubicacion de nuestro eBook
 * @param idStr ID leido desde el archivo .csv
 * @param titleStr Titulo leido desde el archivo .csv
 * @param authorStr Autor leido desde el archivo .csv
 * @param priceStr Precio leido desde el archivo .csv
 * @param idEditorialStr idEditorial leido desde el archivo .csv
 * @return Retorna un valor logico para validar si hubo error (-1) o si salio todo ok (0)
 */
int eBook_newParametros(eBook** newBook, char* idStr, char* titleStr, char* authorStr, char* priceStr, char* idEditorialStr)
{
	int returnAux = -1;

	if(eBook_new(&newBook) == 0)
	{
		eBook_setId(&newBook, atoi(idStr));
		eBook_setTitle(&newBook, titleStr);
		eBook_setAuthor(&newBook, authorStr);
		eBook_setPrice(&newBook, atof(priceStr));
		eBook_setIdEditorial(&newBook, atoi(idEditorialStr));
		returnAux = 0;
	}

	return returnAux;
}




