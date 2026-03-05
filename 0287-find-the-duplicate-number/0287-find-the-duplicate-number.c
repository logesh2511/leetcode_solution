int findDuplicate(int* nums, int numsSize) {
    int l = 0, r = numsSize - 1;
    while (l < r) {
        int mid = (l + r) >> 1;
        int cnt = 0;
        for (int i = 0; i < numsSize; ++i) {
            if (nums[i] <= mid) {
                cnt++;
            }
        }
        if (cnt > mid) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}
