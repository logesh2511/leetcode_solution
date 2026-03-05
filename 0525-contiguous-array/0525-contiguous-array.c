

#include <stdio.h>


int findMaxLength(int* nums, int numsSize) {
    int maxLength = 0;
    int count = 0;
    int* map = (int*)malloc(sizeof(int) * (2 * numsSize + 1));
    for (int i = 0; i < 2 * numsSize + 1; i++) {
        map[i] = -2;
    }
   
    map[numsSize] = -1;
   
    for (int i = 0; i < numsSize; i++) {
        count = count + (nums[i] == 1 ? 1 : -1);
       
        if (map[count + numsSize] >= -1) {
            int subArrayLength = i - map[count + numsSize];
            maxLength = maxLength > subArrayLength ? maxLength : subArrayLength;
        } else {
            map[count + numsSize] = i;
        }
    }
   
    free(map);
    return maxLength;
}


#ifndef MAIN_FUNCTION
#define MAIN_FUNCTION




#endif
