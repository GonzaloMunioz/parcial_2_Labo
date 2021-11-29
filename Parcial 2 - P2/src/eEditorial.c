/*
 * eEditorial.c
 *
 *  Created on: Nov 24, 2021
 *      Author: Gonza
 */

#include "eEditorial.h"

/**
 * @brief Establece dentro del eEditorial el ID que recibe como parametro
 * @param newEditorial Puntero a puntero a puntero a la ubicacion de nuestro eEditorial
 * @param id ID a establecer
 * @return Retorna un valor logico para validar si hubo error (-1) o si salio todo ok (0)
 */
int eEditorial_setId(eEditorial*** newEditorial, int id)
{
	int returnAux = -1;

	if(newEditorial != NULL)
	{
		(**newEditorial)->idEditorial = id;
		returnAux = 0;
	}

	return returnAux;
}

/**
 * @brief Obtiene de nuestro eEditorial el ID y lo asigna al puntero a int recibido como parametro
 * @param newEditorial Puntero a la ubicacion de nuestro eEditorial
 * @param id Puntero a la variable que se le asignara el ID obtenido
 * @return Retorna un valor logico para validar si hubo error (-1) o si salio todo ok (0)
 */
int eEditorial_getId(eEditorial* newEditorial, int* id)
{
	int returnAux = -1;

	if (newEditorial != NULL) {
		*id = newEditorial->idEditorial;
		returnAux = 0;
	}

	return returnAux;
}

/**
 * @brief Establece dentro del eEditorial el nombre que recibe como parametro
 * @param newEditorial Puntero a puntero a puntero a la ubicacion de nuestro eEditorial
 * @param name Nombre a establecer
 * @return Retorna un valor logico para validar si hubo error (-1) o si salio todo ok (0)
 */
int eEditorial_setName(eEditorial*** newEditorial, char* name)
{
	int returnAux = -1;

	if(newEditorial != NULL)
	{
		strcpy((**newEditorial)->name, name);
		returnAux = 0;
	}

	return returnAux;
}

/**
 * @brief Obtiene de nuestro eEditorial el nombre y lo asigna al puntero a char recibido como parametro
 * @param newEditorial Puntero a la ubicacion de nuestro eEditorial
 * @param name Puntero a la variable que se le asignara el nombre obtenido
 * @return Retorna un valor logico para validar si hubo error (-1) o si salio todo ok (0)
 */
int eEditorial_getName(eEditorial* newEditorial, char* name)
{
	int returnAux = -1;

	if(newEditorial != NULL)
	{
		strcpy(name, newEditorial->name);
		returnAux = 0;
	}

	return returnAux;
}

/**
 * @brief Crea un espacio en memoria dinamica para un eEditorial y lo asigna al puntero a puntero a puntero recibido como parametro
 * @param newEditorial Puntero a puntero a puntero a la ubicacion de nuestro eEditorial
 * @return Retorna un valor logico para validar si hubo error (-1) o si salio todo ok (0)
 */
int eEditorial_new(eEditorial*** newEditorial)
{
	int returnAux = -1;

	**newEditorial = (eEditorial*) calloc(1, sizeof(eEditorial));

	if(newEditorial != NULL)
	{
		returnAux = 0;
	}

	return returnAux;
}

/**
 * @brief Crea un espacio en memoria dinamica para un eEditorial, carga en el los datos recibidos por parametros y lo asigna al puntero a puntero recibido como parametro
 * @param newEditorial Puntero a puntero a la ubicacion de nuestro eEditorial
 * @param idStr ID leido desde el archivo .csv
 * @param nameStr Nombre leido desde el archivo .csv
 * @return Retorna un valor logico para validar si hubo error (-1) o si salio todo ok (0)
 */
int eEditorial_newParametros(eEditorial** newEditorial, char* idStr, char* nameStr)
{
	int returnAux = -1;

	if(eEditorial_new(&newEditorial) == 0)
	{
		eEditorial_setId(&newEditorial, atoi(idStr));
		eEditorial_setName(&newEditorial, nameStr);
		returnAux = 0;
	}

	return returnAux;
}




