/*
All memory is a data array of type char. Initial init. -1
the key_right array contains the right borders of the blocks
The block descriptor is the index in the key_right array
If the key is accessed, and the end value is -1
then this is an error, there is no such block.
Block expansion is the allocation of new memory at the end of the array
in this case, all information from the old block is copied to the new one,
old information is destroyed
*/

#include "manager.h"

char ans[MASS_SIZE];
int ans_len = 0;
int ans_des = -1;

int main(void){
    for (int i = 0 ; i <  MASS_SIZE; ++i){
        key_right[i]= -1;
        size_blok[i] = -1;
    }
    char c;
    int des, delta = 0;
    des = alloc(1);
    while ((c = getchar()) != EOF){
        if (c != '\n') {
            write_byte(des, delta, c);
            reallocc(des, delta + 2);
            delta++;
        } else{
            //a new word has begun
            if (size_blok[des] > ans_len){
                if (ans_des != -1){
                    del(ans_des);
                }
                ans_des = des;
                ans_len = size_blok[des];
            } else {
                del(des);
            }

            delta = 0;
            des = alloc(1);
        }
    }

    int len_ans = size_blok[ans_des];
    for (int i = 0; i < len_ans - 1 ; i++){
        printf("%c", read_byte(ans_des, i));
    }
    printf("\n");

    return 0;
}