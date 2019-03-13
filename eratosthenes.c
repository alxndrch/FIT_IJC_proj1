//
// Created by Alexandr Chalupnik on 2019-03-12.
//

#include "eratosthenes.h"

void Eratosthenes(bit_array_t pole){

    bit_array_setbit(pole,0,1);
    bit_array_setbit(pole,1,1);

    unsigned long num = bit_array_size(pole);
    int bit_index = 2;

    //0->prvocislo
    //2,3,5,7

    for (int i=bit_index; i<=num; i++){
        if (bit_array_getbit(pole,i) == 0)
        {
            for (int j=i; i*j<=num; j++){
                bit_array_setbit(pole,i*j,1);
            }
        }
    }

}