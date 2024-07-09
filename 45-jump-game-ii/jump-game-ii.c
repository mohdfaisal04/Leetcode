int jump(int* nums, int numsSize) {
    if (numsSize == 1) return 0; // If there's only one element, no jump is needed
    
    int maxReach = nums[0]; // Maximum index that can be reached
    int steps = 1; // Number of jumps taken so far
    int lastJumpEnd = nums[0]; // End of the range of the current jump
    
    for (int i = 1; i < numsSize; ++i) {
        if (i > lastJumpEnd) {
            steps++; // Need another jump
            lastJumpEnd = maxReach; // Update the end of the current jump range
        }
        maxReach = (i + nums[i] > maxReach) ? i + nums[i] : maxReach; // Update maxReach
    }
    
    return steps;
}