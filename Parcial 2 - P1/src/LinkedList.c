#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/**
 * @brief Crea un nuevo LinkedList en memoria de manera dinamica
 * @param void
 * @return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
                       o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
	LinkedList* this = NULL;

	this = (LinkedList*) calloc(1, sizeof(LinkedList));

    return this;
}

/**
 * @brief Retorna la cantidad de elementos de la lista
 * @param this LinkedList* Puntero a la lista
 * @return int Retorna (-1) si el puntero es NULL o
  		   la cantidad de elementos de la lista
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	returnAux = this->size;
    }

    return returnAux;
}


/**
 * @brief  Obtiene un nodo de la lista
 * @param this LinkedList* Puntero a la lista
 * @param index int Indice del nodo a obtener
 * @return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                          (pNode) Si funciono correctamente
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	int tam;
	Node* returnAux = NULL;

	if(this != NULL)
	{
		tam = ll_len(this);
		if((nodeIndex > -1) && (nodeIndex < tam))
		{
			returnAux = this->pFirstNode;
			for(int i = 0; i < nodeIndex; i++)
			{
				returnAux = returnAux->pNextNode;
			}
		}
	}

    return returnAux;
}

/**
 * @brief  Permite realizar el test de la funcion getNode la cual es privada
 * @param this LinkedList* Puntero a la lista
 * @param index int Indice del nodo a obtener
 * @return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                          (pElement) Si funciono correctamente
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/**
 * @brief Agrega y enlaza un nuevo nodo a la lista
 * @param this LinkedList* Puntero a la lista
 * @param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * @param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * @return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    int tam;
    Node* node = NULL;
    Node* auxNode = NULL;

    node = (Node*) malloc(sizeof(node));

    if((this != NULL) && (node != NULL))
    {
    	tam = ll_len(this);
    	node->pElement = pElement;
    	node->pNextNode = NULL;
    	if((nodeIndex > -1) && (nodeIndex < (tam + 1)))
    	{
    		if(nodeIndex == 0)
    		{
    			node->pNextNode = this->pFirstNode;
    			this->pFirstNode = node;
    		}
    		else
    		{
    			auxNode = getNode(this, (nodeIndex - 1));
    			node->pNextNode = auxNode->pNextNode;
    			auxNode->pNextNode = node;
    		}
    		this->size += 1;
    		returnAux = 0;
    	}
    }

    return returnAux;
}

/**
 * @brief Permite realizar el test de la funcion addNode la cual es privada
 * @param this LinkedList* Puntero a la lista
 * @param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * @param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * @return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/**
 * @brief  Agrega un elemento a la lista
 * @param pList LinkedList* Puntero a la lista
 * @param pElement void* Puntero al elemento a ser agregado
 * @return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int tam;

    if(this != NULL)
    {
    	tam = ll_len(this);
    	if(addNode(this, tam, pElement) == 0)
    	{
        	returnAux = 0;
    	}
    }

    return returnAux;
}

/** \
 * @brief Obtiene un elemento de la lista segun su indice
 * @param this LinkedList* Puntero a la lista
 * @param nodeIndex int Ubicacion del elemento a obtener
 * @return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 */
void* ll_get(LinkedList* this, int index)
{
	int tam;
	Node* auxNode = NULL;
    void* returnAux = NULL;

    if(this != NULL)
    {
    	tam = ll_len(this);
    	auxNode = getNode(this, index);
    	if((auxNode != NULL) && (index < tam) && (index > -1))
    	{
    		returnAux = auxNode->pElement;
    	}
    }

    return returnAux;
}


/**
 * @brief Modifica un elemento de la lista
 * @param this LinkedList* Puntero a la lista
 * @param nodeIndex int Ubicacion del elemento a modificar
 * @param pElement void* Puntero al nuevo elemento
 * @return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 */
int ll_set(LinkedList* this, int index, void* pElement)
{
	int tam;
    int returnAux = -1;
    Node* auxNode = NULL;

    if(this != NULL)
    {
    	tam = ll_len(this);
    	auxNode = getNode(this, index);
    	if((auxNode != NULL) && (index < tam) && (index > -1))
    	{
    		auxNode->pElement = pElement;
    		returnAux = 0;
    	}
    }

    return returnAux;
}


/**
 * @brief Elimina un elemento de la lista
 * @param this LinkedList* Puntero a la lista
 * @param nodeIndex int Ubicacion del elemento a eliminar
 * @return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 */
int ll_remove(LinkedList* this, int index)
{
	int tam;
    int returnAux = -1;
    Node* node = NULL;
    Node* prevNode = NULL;

    if(this != NULL)
    {
    	tam = ll_len(this);
    	if((index < tam) && (index > -1))
    	{
    		if(index == 0)
    		{
    			node = getNode(this, index);
    			this->pFirstNode = node->pNextNode;
    			free(node);
    		}
    		else
    		{
    			node = getNode(this, index);
    			prevNode = getNode(this, (index - 1));
    			prevNode->pNextNode = node->pNextNode;
    			free(node);
    		}
    		this->size -= 1;
    		returnAux = 0;
    	}
    }

    return returnAux;
}


/**
 * @brief Elimina todos los elementos de la lista
 * @param this LinkedList* Puntero a la lista
 * @return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 */
int ll_clear(LinkedList* this)
{
	int tam;
	int returnAux = -1;

	if(this != NULL)
	{
		tam = ll_len(this);
		for(int i = 0; i < tam; i++)
		{
			ll_remove(this, i);
		}
		returnAux = 0;
	}

    return returnAux;
}


/**
 * @brief Elimina todos los elementos de la lista y la lista
 * @param this LinkedList* Puntero a la lista
 * @return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	if(ll_clear(this) == 0)
    	{
    		free(this);
    		returnAux = 0;
    	}
    }

    return returnAux;
}

/**
 * @brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 * @param this LinkedList* Puntero a la lista
 * @param pElement void* Puntero al elemento
 * @return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
	int tam;
	int i = 0;
	int flagFound = 0;
    int returnAux = -1;
    Node* node = NULL;

    if(this != NULL)
    {
    	tam = ll_len(this);
    	node = getNode(this, i);
    	while((flagFound == 0) && (i < tam))
    	{
    		if(node->pElement == pElement)
    		{
    			flagFound = 1;
    			returnAux = i;
    		}
    		else
    		{
    			i++;
    			node = node->pNextNode;
    		}
    	}
    }

    return returnAux;
}

/**
 * @brief Indica si la lista esta o no vacia
 * @param this LinkedList* Puntero a la lista
 * @return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 */
int ll_isEmpty(LinkedList* this)
{
	int tam;
    int returnAux = -1;

    if(this != NULL)
    {
    	tam = ll_len(this);
    	if(tam == 0)
    	{
    		returnAux = 1;
    	}
    	else
    	{
    		returnAux = 0;
    	}
    }

    return returnAux;
}

/**
 * @brief Inserta un nuevo elemento en la lista en la posicion indicada
 * @param this LinkedList* Puntero a la lista
 * @param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * @param pElement void* Puntero al nuevo elemento
 * @return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	if(addNode(this, index, pElement) == 0)
    	{
    		returnAux = 0;
    	}
    }

    return returnAux;
}


/**
 * @brief Elimina el elemento de la posicion indicada y retorna su puntero
 * @param this LinkedList* Puntero a la lista
 * @param nodeIndex int Ubicacion del elemento eliminar
 * @return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 */
void* ll_pop(LinkedList* this, int index)
{
    void* returnAux = NULL;

    if(this != NULL)
    {
    	returnAux = ll_get(this, index);
    	ll_remove(this, index);
    }

    return returnAux;
}


/**
 * @brief  Determina si la lista contiene o no el elemento pasado como parametro
 * @param this LinkedList* Puntero a la lista
 * @param pElement void* Puntero del elemento a verificar
 * @return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	returnAux = 0;
    	if(ll_indexOf(this, pElement) != -1)
    	{
    		returnAux = 1;
    	}
    }

    return returnAux;
}

/**
 * @brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 * @param this LinkedList* Puntero a la lista
 * @param this2 LinkedList* Puntero a la lista
 * @return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this, LinkedList* this2)
{
	int tam;
	int i = 0;
	int flagFound = 0;
	int returnAux = -1;

	if((this != NULL) && (this2 != NULL))
	{
		returnAux = 1;
		tam = ll_len(this2);
		while((flagFound == 0) && (i < tam))
		{
			if(ll_contains(this, ll_get(this2, i)) != 1)
			{
				flagFound = 1;
				returnAux = 0;
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
 * @brief Crea y retorna una nueva lista con los elementos indicados
 * @param pList LinkedList* Puntero a la lista
 * @param from int Indice desde el cual se copian los elementos en la nueva lista
 * @param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * @return LinkedList* Retorna  (NULL) Error: si el puntero a la lista es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         	 	(puntero a la nueva lista) Si funciono correctamente
*/
LinkedList* ll_subList(LinkedList* this, int from, int to)
{
	int tam;
    LinkedList* cloneArray = NULL;

    if(this != NULL)
    {
    	tam = ll_len(this);
    	if((from > -1) && (to > from) && (to <= tam))
    	{
    		cloneArray = ll_newLinkedList();
    		if(cloneArray != NULL)
    		{
    			for(int i = from; i < to; i++)
    			{
    				ll_add(cloneArray, ll_get(this, i));
    			}
    		}
    	}
    }

    return cloneArray;
}



/**
 * @brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 * @param pList LinkedList* Puntero a la lista
 * @return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si funciono correctamente
*/
LinkedList* ll_clone(LinkedList* this)
{
	int tam;
    LinkedList* cloneArray = NULL;

    if(this != NULL)
    {
    	tam = ll_len(this);
    	cloneArray = ll_subList(this, 0, tam);
    }

    return cloneArray;
}


/**
 * @brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * @param pList LinkedList* Puntero a la lista
 * @param pFunc (*pFunc) Puntero a la funcion criterio
 * @param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * @return int Retorna  (-1) Error: si el puntero a la lista es NULL
 	 	 	 	 	 	(0) Si funciono correctamente
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
	void *auxPElement;
	void *firstParameter;
	void *secondParameter;
	int returnAux = -1;
	int comparison;
	int tam;

	if((this != NULL) && (pFunc != NULL) && ((order == 0) || (order == 1)))
	{
		tam = ll_len(this);
		for(int i = 0; i < tam - 1; i++)
		{
			for(int j = i + 1; j < tam; j++)
			{
				firstParameter = ll_get(this, i);
				secondParameter = ll_get(this, j);
				comparison = pFunc(firstParameter, secondParameter);
				if(order == 1 && comparison > 0)
				{
					auxPElement = firstParameter;
					ll_set(this, i, secondParameter);
					ll_set(this, j, auxPElement);
				}
				else
				{
					if(order == 0 && comparison < 0)
					{
						auxPElement = secondParameter;
						ll_set(this, j, firstParameter);
						ll_set(this, i, auxPElement);
					}
				}
			}
		}
		returnAux = 0;
	}

	return returnAux;
}

/**
 * @brief Crea una nueva LinkedList y copia los elementos segun el criterio de la funcion recibida como parametro
 * @param this Puntero a la lista
 * @param fn (*fn) Puntero a la funcion criterio
 * @return Retorna (NULL) en el caso de no conseguir espacio en memoria
  		   o el puntero a la nueva LinkedList si funciono correctamente
 */
LinkedList* ll_filter(LinkedList* this, int (*fn)(void* element))
{
	int tam;
	void* auxElement = NULL;
	LinkedList* cloneArray = NULL;

	if(this != NULL)
	{
		tam = ll_len(this);
		cloneArray = ll_newLinkedList();
		if(cloneArray != NULL)
		{
			for(int i = 0; i < tam; i++)
			{
				auxElement = ll_get(this, i);
				if(fn(auxElement) == 1)
				{
					ll_add(cloneArray, auxElement);
				}
			}
		}
	}

	return cloneArray;
}
















