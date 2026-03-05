int* singleNumber(int* nums, int numsSize, int* returnSize) {
    long long xs = 0;
    for (int i = 0; i < numsSize; ++i) {
        xs ^= nums[i];
    }
    int lb = xs & (-xs);
    int a = 0;
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] & lb) {
            a ^= nums[i];
        }
    }
    int b = xs ^ a;
    int* result = (int*)malloc(2 * sizeof(int));
    result[0] = a;
    result[1] = b;
    *returnSize = 2;
    return result;
}
