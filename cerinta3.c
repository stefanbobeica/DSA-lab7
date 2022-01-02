#include "heap.h"

/**
 * TODO: Sortati eficient un vector k-sortat folosind un heap.
 * HINT: Se poate utiliza un heap de dimensiune mai mica decat
 * numarul de elemente din buffer
 * @param  *buffer: - vectorul k sortat
 * @param  dimensiune: numarul de elemente
 * @param  k: indicele de sortare a vectorului k-sortat
 * @retval - vectorul sortat
 */
int *kSortedArray(int *buffer, int dimensiune, int k)
{
    Heap *h = create(k);
    
    
    populateHeap(h,buffer,k);

    for (int i = k; i < dimensiune; i++)
    {
        if (buffer[i] > h->vec[0])
        {
            deleteNode(h, 0);
            insert(h, buffer[i]);
        }
    }

    heapsort(h, h->vec, h->size);
    return h->vec;
}
