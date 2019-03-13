// main.c
// Řešení IJC-DU1, příklad a), 7.3.2019
// Autor: Alexandr Chalupnik
// Přeloženo: gcc 4.2.1

#include <stdio.h>
#include <stdlib.h>
#include "bit_array.h"
#include "eratosthenes.h"

int main() {

    bit_array_create(q,7920);

    Eratosthenes(q);

    unsigned long size = bit_array_size(q);

    int sum = 1;
    int iter = 0;
    while(sum <= 10){
        if(bit_array_getbit(q,size-1-iter) == 0){
            printf("%lu\n",size-1-iter);
            sum++;
        }
        iter++;
    }

    return 0;
}