#include "heap.h"

/**
 * TODO: Returnati un vector ce contine cele mai mari k elemente din vector.
 * HINT: Nu trebuie sa sortati tot vectorul, se poate utiliza un heap de
 * dimensiune mai mica. Pentru sortarea intregului vector se pot aplica penalizari
 * @param  *buffer: vectorul initial
 * @param  dimensiune: dimensiunea vectorului
 * @param  k: numarul de elemente returnate
 * @retval - vectorul cu cele mai mici k elemente din buffer
 */
int *kMaxElem(int *buffer, int dimensiune, int k)
{
 Heap *h=create(k);
   heapsort(h, buffer, k);
   int i=k;

   while(i!=dimensiune)
   {
      if (buffer[i] > h->vec[k-1])
      {
         h->vec[k-1] = buffer[i];
         heapsort ( h, h->vec, k);
      }
      i++;
   }

   return h->vec;
}
