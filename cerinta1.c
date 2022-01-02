#include "heap.h"

/**
 * TODO: Alocati memorie si cititi datele din fisier
 * @param  **v: vectorul cu datele citite
 * @param  dimensiune: dimensiunea vectorului
 * @param  input: fisierul de intrare
 * @retval None
 */
void readVector(int **v, int dimensiune, FILE *input)
{
    *v = (int *)malloc(sizeof(int) * dimensiune);
    int aux, i;
    for (int i = 0; i < dimensiune; i++)
    {
        fscanf(input, "%d", (*v) + i);
    }
}

/** 
 * TODO:   Stergeti elementul de pe pozitia i din heap
 * @param  *h: heap binar 
 * @param  i: index-ul elementului ce trebuie sters din heap
 * @retval None
 */
void deleteNode(Heap *h, int i)
{
    int aux;
    h->vec[i] = h->vec[h->size - 1];
    h->size--;
    while (parent(h, i) != 1)
    {
        if (h->vec[parent(h, i)] <= h->vec[i])
            break;
        aux = h->vec[i];
        h->vec[i] = h->vec[parent(h, i)];
        h->vec[parent(h, i)] = aux;
        i = parent(h, i);
    }
    if (parent(h, i) == -1)
        heapify(h, 0);
    else
        heapify(h, i);
}
/**
 * TODO: Implementati algoritmul heapsort
 * @param  *h: heap-ul binar ce contine datele vectorului sortat
 * @param  *buf: vectorul ce trebuie sortat
 * @param  dimensiune: dimensiunea vectorului ce trebuie sortat
 * @retval None
 */
void heapsort(Heap *h, int *buf, int dimensiune)
{
    if (h == NULL || buf == NULL || dimensiune == 0)
        return;
    while (dimensiune > h->capacity)
        resize(h);

    for (int i = 0; i < dimensiune; i++)
        h->vec[i] = buf[i];
    h->size = dimensiune;
    for (int i = (dimensiune - 1) / 2 - 1; i >= 0; i--)
        heapify(h, i);
    for (int i = dimensiune - 1; i >= 0; i--)
    {
        int aux = h->vec[0];
        h->vec[0] = h->vec[i];
        h->vec[i] = aux;
        h->size = i;
        heapify(h, 0);
    }

    h->size = dimensiune;
    printHeap(h);
}
