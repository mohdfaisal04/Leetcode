void rotate(int* nums, int numsSize, int k) {
    k = k % numsSize; // In case k is greater than the size of the array
    int count = 0; // Number of elements rotated
    for (int start = 0; count < numsSize; start++) {
        int current = start;
        int prev = nums[start];
        do {
            int next = (current + k) % numsSize;
            int temp = nums[next];
            nums[next] = prev;
            prev = temp;
            current = next;
            count++;
        } while (start != current);
    }
}