/*
 * Controller.h
 *
 *  Created on: Nov 24, 2021
 *      Author: Gonza
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "Parser.h"

/// Carga dentro de la LinkedList los datos leidos desde el archivo .csv
int controller_loadFromText(char* path, LinkedList* pArrayListBook, LinkedList* pArrayListEditorial, int option);

/// Guarda en un archivo .csv los datos de la LinkedList recibida como parametro
int controller_saveFromLinkedList(char* path, LinkedList* pArrayList);

/// Recorre la lista recibida en busqueda de un elemento que tenga el mismo ID que recibe como parametro y devuelve su indice
int controller_findIndexById(LinkedList* pArrayListEditorial, int id);

/// Imprime un eBook individual y su correspondiente editorial
int controller_print(eBook* newBook, LinkedList* pArrayListEditorial);

/// Imprime un listado de los datos de todos los elementos de la LinkedList
int controller_ListBook(LinkedList* pArrayListBook, LinkedList* pArrayListEditorial, char* keyword);

/// Ordena la LinkedList alfabeticamente segun autor
int controller_sortBook(LinkedList* pArrayListBook);

/// Carga en la lista los elementos que pertenezcan a la editorial Minotauro (ID 4), los imprime y los guarda en un archivo .csv
int controller_list_by_MinotauroEditorial(char* path, LinkedList* pArrayListBook, LinkedList* pArrayListMinotauro, LinkedList* pArrayListEditorial);

/// Mapea el listado de eBooks, creando una nueva lista con los elementos mapeados y guardando los datos en un nuevo archivo .csv
int controller_mapList(char* path, LinkedList* pArrayListBook, LinkedList* pArrayListEditorial);

#endif /* CONTROLLER_H_ */
