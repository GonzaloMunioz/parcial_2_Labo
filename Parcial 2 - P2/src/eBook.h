/*
 * eBook.h
 *
 *  Created on: Nov 24, 2021
 *      Author: Gonza
 */

#ifndef EBOOK_H_
#define EBOOK_H_

#include "Library.h"

typedef struct
{
	int id;
	char title[55];
	char author[55];
	float price;
	int idEditorial;
}eBook;

/// Establece el ID en un eBook con el ID recibido como parametro (setter)
int eBook_setId(eBook*** newBook, int id);

/// Obtiene el ID de un eBook y lo guarda en el puntero a int recibido como parametro (getter)
int eBook_getId(eBook* newBook, int* id);

/// Establece el titulo en un eBook con el titulo recibido como parametro (setter)
int eBook_setTitle(eBook*** newBook, char* title);

/// Obtiene el titulo de un eBook y lo guarda en el puntero a char recibido como parametro (getter)
int eBook_getTitle(eBook* newBook, char* title);

/// Establece el autor en un eBook con el autor recibido como parametro (setter)
int eBook_setAuthor(eBook*** newBook, char* author);

/// Obtiene el autor de un eBook y lo guarda en el puntero a char recibido como parametro (getter)
int eBook_getAuthor(eBook* newBook, char* author);

/// Establece el precio en un eBook con el precio recibido como parametro (setter)
int eBook_setPrice(eBook*** newBook, float price);

/// Obtiene el precio de un eBook y lo guarda en el puntero a float recibido como parametro (getter)
int eBook_getPrice(eBook* newBook, float* price);

/// Establece el idEditorial en un eBook con el idEditorial recibido como parametro (setter)
int eBook_setIdEditorial(eBook*** newBook, int idEditorial);

/// Obtiene el idEditorial de un eBook y lo guarda en el puntero a int recibido como parametro (getter)
int eBook_getIdEditorial(eBook* newBook, int* idEditorial);

/// Compara dos elementos recibidos por parametros y retorna el resultado de la comparacion
int eBook_compare_by_author(void* one, void* two);

/// Compara si el elemento recibido por parametro cumple con el criterio de la funcion
int eBook_compare_editorial(void* aux);

/// Aplica un descuento a los elementos que cumplen con los criterios de la funcion
int eBook_applyDiscount(void* aux);

/// Crea un espacio en memoria para un nuevo eBook (constructor)
int eBook_new(eBook*** newBook);

/// Crea un espacio en memoria para un nuevo eBook y carga en el los datos recibidos como parametros (constructor parametrizado)
int eBook_newParametros(eBook** newBook, char* idStr, char* titleStr, char* authorStr, char* priceStr, char* idEditorialStr);

#endif /* EBOOK_H_ */
