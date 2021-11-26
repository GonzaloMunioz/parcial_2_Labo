/*
 * eEditorial.h
 *
 *  Created on: Nov 24, 2021
 *      Author: Gonza
 */

#ifndef EEDITORIAL_H_
#define EEDITORIAL_H_

#include "Library.h"

typedef struct
{
	int idEditorial;
	char name[50];
}eEditorial;

/// Establece el ID en un eEditorial con el ID recibido como parametro (setter)
int eEditorial_setId(eEditorial*** newEditorial, int id);

/// Obtiene el ID de un eEditorial y lo guarda en el puntero a int recibido como parametro (getter)
int eEditorial_getId(eEditorial* newEditorial, int* id);

/// Establece el nombre en un eEditorial con el nombre recibido como parametro (setter)
int eEditorial_setName(eEditorial*** newEditorial, char* name);

/// Obtiene el nombre de un eEditorial y lo guarda en el puntero a char recibido como parametro (getter)
int eEditorial_getName(eEditorial* newEditorial, char* name);

/// Crea un espacio en memoria para un nuevo eEditorial (constructor)
int eEditorial_new(eEditorial*** newEditorial);

/// Crea un espacio en memoria para un nuevo eEditorial y carga en el los datos recibidos como parametros (constructor parametrizado)
int eEditorial_newParametros(eEditorial** newEditorial, char *idStr, char* nameStr);

#endif /* EEDITORIAL_H_ */
