#include <stdio.h>
    #include "modul_1.h"

int reallocc (int descriptor, int new_size){

    if (key_right[descriptor] == -1) {
        printf("Error: Reallocation function. An attempt to address a non-existent key");
        return 1;
    } else {
        int last_desc = descriptor_of_last();
        int right_index = key_right[descriptor];
        if (descriptor != last_desc) {
            for (int i = 0; i < size_blok[descriptor]; ++i) {
                data[key_right[last_desc] + i + 1] = data[right_index + i - size_blok[descriptor] + 1];
            }

            del(descriptor);
            key_right[descriptor] = key_right[last_desc] + new_size;
            size_blok[descriptor] = new_size;
        } else{
            key_right[descriptor] += 1;
            size_blok[descriptor] += 1;
        }
        return 0;
    }
}