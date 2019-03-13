// bit_array.h
// Řešení IJC-DU1, příklad a), 7.3.2019
// Autor: Alexandr Chalupnik
// Přeloženo: gcc 4.2.1

#ifndef PROJ1_BIT_ARRAY_H
#define PROJ1_BIT_ARRAY_H

#include<limits.h>
#include<string.h>

#include "error.h"

typedef unsigned long* bit_array_t;

/*
 * @brief velikost unsigned long v bitech
 */
#define ul_bit sizeof(unsigned long)*CHAR_BIT

#define bit_array_create(jmeno_pole,velikost) \
    /*static_assert(bit_array_mem_size(velikost)+1<sizeof(unsigned long)*CHAR_BIT,"prekrocena maximalni velikost pole");*/ \
    unsigned long (jmeno_pole)[bit_array_mem_size(velikost) +1] = {velikost,}; \

#define bit_array_alloc(jmeno_pole,velikost) \
    /*static_assert(bit_array_mem_size(velikost)+1<sizeof(unsigned long)*CHAR_BIT,"prekrocena maximalni velikost pole");*/\
    bit_array_t jmeno_pole = (bit_array_t) malloc(sizeof(unsigned long) + bit_array_mem_size(velikost)*sizeof(unsigned long)); \
    *(jmeno_pole) = velikost; \
    memset(jmeno_pole,0,velikost);\

#ifndef USE_INLINE
    /*
     *@brief velikost pole
     */
    #define bit_array_mem_size(velikost) \
        ((velikost)/(ul_bit) + (((velikost)%(ul_bit) !=0)? 1 : 0))

    #define bit_array_free(jmeno_pole) \
        free(jmeno_pole)

    #define bit_array_size(jmeno_pole) \
        jmeno_pole[0]

    #define bit_array_setbit(jmeno_pole,index,vyraz) \
    do{ \
        if(vyraz == 1){ \
            *(jmeno_pole + (index/(ul_bit)+1)) |= ((unsigned long)1 << (index%(ul_bit)));\
        }else{\
            *(jmeno_pole + (index/(ul_bit)+1)) &= ~(((unsigned long)1) << (index%(ul_bit)));\
        }\
        \
    }while(0)

    #define bit_array_getbit(jmeno_pole,index) \
            (( *(jmeno_pole +((index)/(ul_bit)+1)) & ((unsigned long)1 << ((index)%(ul_bit))))? 1 : 0)


#else

    unsigned long bit_array_mem_size(unsigned long velikost){
        return ((velikost)/(ul_bit) + (((velikost)%(ul_bit) !=0)? 1 : 0));
    }

    inline void bit_array_free(bit_array_t arr){
        free(arr);
    }

    inline unsigned long bit_array_size(bit_array_t arr){
        return *(arr+0);
    }

    inline void bit_array_setbit(bit_array_t arr, int index, int vyraz){
        if(index > (bit_arra_mem_size(bit_array_size(arr))+1) || index < 0){ \
        }else if(vyraz == 1){ \
            *arr(index/(ul_bit)+1) |= ((unsigned long)1 << (index%(ul_bit)))\
        }else{\
            *arr[index/(ul_bit)+1] &= ~(((unsigned long)1) << (index%(ul_bit)))\
        }
    }

    inline unsigned long bit_array_getbit(bit_array_t arr, int index){
        if((index > (bit_arra_mem_size(bit_array_size(arr))+1) || index < 0)){

        }
            (jmeno_pole[index/(ul_bit)+1] & ((unsigned long)1 << (index%(ul_bit))))? 1 : 0)
    }

#endif

#endif
