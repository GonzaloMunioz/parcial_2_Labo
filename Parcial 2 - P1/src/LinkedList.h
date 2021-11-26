/*
 * LinkedList.h
 *
 *  Created on: Nov 24, 2021
 *      Author: Gonza
 */

#ifndef __LINKEDLIST
#define __LINKEDLIST

struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;

//// Publicas ////


/// Crea una LinkedList nueva (constructor)
LinkedList* ll_newLinkedList(void);

/// Devuelve la cantidad de elementos en la lista
int ll_len(LinkedList* this);

/// Agrega un elemento (alta)
int ll_add(LinkedList* this, void* pElement);

/// Obtiene un elemento (getter)
void* ll_get(LinkedList* this, int index);

/// Modificar un elemento (setter)
int ll_set(LinkedList* this, int index, void* pElement);

/// Borrar un elemento (baja)
int ll_remove(LinkedList* this, int index);

/// Vacia la lista
int ll_clear(LinkedList* this);

/// Elimina la lista y la vacia
int ll_deleteLinkedList(LinkedList* this);

/// Devuelve el indice del elemento que coincida con el elemento recibido como parametro
int ll_indexOf(LinkedList* this, void* pElement);

/// Recorre la lista en busca de al menos un elemento
int ll_isEmpty(LinkedList* this);

/// Agrega un nodo en la posicion indicada, moviendo los nodos contiguos (push)
int ll_push(LinkedList* this, int index, void* pElement);

/// Obtiene un elemento, lo elimina de la lista y lo devuelve
void* ll_pop(LinkedList* this, int index);

/// Recorre la lista en busca de un elemento que coincida con el elemento recibido como parametro
int ll_contains(LinkedList* this, void* pElement);

/// Recorre una lista en busca de todos los elementos que contiene la segunda lista
int ll_containsAll(LinkedList* this, LinkedList* this2);

/// Crea una sublista desde las posiciones que recibe como parametro
LinkedList* ll_subList(LinkedList* this, int from, int to);

/// Clona una lista recibida como parametro
LinkedList* ll_clone(LinkedList* this);

/// Ordena la lista segun la funcion de ordenamiento recibida como parametro
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);

/// Recorre la lista en busqueda de todos los elementos que cumplan con el criterio de la funcion recibida como parametro y los agrega a una nueva lista
LinkedList* ll_filter(LinkedList* this, int (*fn)(void* element));

/// Funcion de testeo de la funcion addNode
int test_addNode(LinkedList* this, int nodeIndex, void* pElement);

///Funcion de testeo de la funcion getNode
Node* test_getNode(LinkedList* this, int nodeIndex);

#endif /* LINKEDLIST_H_ */
