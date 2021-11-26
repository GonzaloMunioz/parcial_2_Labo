/*
 * Parser.h
 *
 *  Created on: Nov 24, 2021
 *      Author: Gonza
 */

#ifndef PARSER_H_
#define PARSER_H_

#include "eBook.h"
#include "eEditorial.h"
#include "LinkedList.h"

/// Parsea los datos leidos desde el archivo
int parser_eBookFromText(FILE* pFile, LinkedList* pArrayListBooks);

/// Parsea los datos leidos desde el archivo
int parser_eEditorialFromText(FILE* pFile, LinkedList* pArrayListEditorial);

/// Escribe en un archivo los datos de la LinkedList
int parser_textFromMinotauro(FILE* pFile, LinkedList* pArrayListMinotauro);

#endif /* PARSER_H_ */
