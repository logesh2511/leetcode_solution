

int singleNumber(int* nums, int numsSize) {
    int ones = 0, twos = 0, commonBits;
   
    for (int i = 0; i < numsSize; i++) {
       
        twos = twos | (ones & nums[i]);
        ones = ones ^ nums[i];
       
       
        commonBits = ones & twos;
       
       
        ones = ones & (~commonBits);
        twos = twos & (~commonBits);
    }

    return ones;
}
