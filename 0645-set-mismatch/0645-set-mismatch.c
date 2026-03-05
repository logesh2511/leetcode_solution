int* findErrorNums(int* nums, int numsSize, int* returnSize) 
{
    int n = numsSize;
    int expected_sum = n * (n + 1) / 2;
    int actual_sum = 0;
    int duplicate = -1;
    int* counts = (int*)calloc(n + 1, sizeof(int)); 
    int* result = (int*)malloc(2 * sizeof(int));
    for (int i = 0; i < n; i++) {
        actual_sum += nums[i];
        counts[nums[i]]++;
        if (counts[nums[i]] == 2) {
            duplicate = nums[i];
        }
    }
    int missing = expected_sum - actual_sum + duplicate;
    result[0] = duplicate;
    result[1] = missing;
    *returnSize = 2;
    free(counts);
    return result;
}
