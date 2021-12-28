#include <stdio.h>
#include <stdlib.h>
    #include "modul_1.h"

char data[MASS_SIZE];
int key_right[MASS_SIZE] = {-1};
int size_blok[MASS_SIZE] = {-1};


//number of keys
int key_number = -1;
int number_of_desc = 0;


//the function finds the most extreme block and returns its key number
int descriptor_of_last(){
    int max = 0;
    int index;
    for (int i = 0; i < MASS_SIZE; ++i){
        if (key_right[i] >= max){
            max = key_right[i];
            index = i;
        }
    }

    return index;
}

//block selection
int alloc (int n){
    if (key_number == -1){
        key_number++;
        number_of_desc++;
        key_right[key_number] = n - 1;
        size_blok[key_number] = n;
        return 0;
    } else {
        //we already have the keys
        key_number++;
        number_of_desc++;
        int last_byte_index = descriptor_of_last();
        size_blok[key_number] = n;
        key_right[key_number] = key_right[last_byte_index] + n;
        return key_number;
    }
}

//block deletion
int del (int descriptor){
    if (key_right[descriptor] == -1){
        printf("Error: Removal function. An attempt to address a non-existent key");
        exit(1);
    } else {

        int shift_number = size_blok[descriptor];
        int begin_point = key_right[descriptor] - size_blok[descriptor] + 1;
        for (int i = 0; i < size_blok[descriptor]; ++i) {
            for (int j = begin_point; j < MASS_SIZE - 1; ++j) {
                data[j] = data[j + 1];
            }
        }
        for (int i = 0; i < number_of_desc + 1; ++i) {
            if (key_right[i] > key_right[descriptor]) {
                key_right[i] -= size_blok[descriptor];
            }
        }

        size_blok[descriptor] = -1;
        key_right[descriptor] = -1;
    }
}

//read block byte
int read_byte(int descriptor, int delta){
    if (key_right[descriptor] == -1){
        printf("Error: Byte read function. An attempt to address a non-existent key");
        exit(1);
    } else {
        int right_index = key_right[descriptor];
        if  (data[right_index + delta - size_blok[descriptor]] == -1){
            printf("warning: Byte read function. You want to read a byte that you didn't write anything to");
        }
        if (delta > size_blok[descriptor] -1) {
            printf("Error: Byte read function. The offset has gone beyond the end of the block");
            exit(1);
        } else {
            return data[right_index + delta - size_blok[descriptor] + 1];
        }
    }
}



int write_byte(int descriptor, int delta, char data_char){
    if (key_right[descriptor] == -1){
        printf("Error: Byte write function. An attempt to address a non-existent key");
        exit(1);
    } else {
        int right_index = key_right[descriptor];
        if (delta > size_blok[descriptor] -1){
            printf("Error: Byte write function. The offset has gone beyond the end of the block");
            exit(1);
        } else {
            data[right_index + delta - size_blok[descriptor] + 1] = data_char;
        }
    }
}



int get_max_str(){
    int max = -1;
    int desc;
    for (int i = 0; i < MASS_SIZE; i++){
        if (size_blok[i] > max){
            max = size_blok[i];
            desc = i;
        }
    }
    return desc;
}

int get_max_str_size(){
    int desc = get_max_str();
    return size_blok[desc] - 1;
}