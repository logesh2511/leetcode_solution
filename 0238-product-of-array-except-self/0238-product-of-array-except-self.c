int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int* ans = (int*)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;
    for (int i = 0, left = 1; i < numsSize; ++i) {
        ans[i] = left;
        left *= nums[i];
    }
    for (int i = numsSize - 1, right = 1; i >= 0; --i) {
        ans[i] *= right;
        right *= nums[i];
    }
    return ans;
}
