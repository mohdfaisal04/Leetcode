bool canJump(int* nums, int numsSize) {
    // If there's only one element, we are already at the last index
    if (numsSize == 1) {
        return true;
    }
    
    // Initialize the maximum reachable index
    int maxReach = 0;
    
    // Traverse through the array
    for (int i = 0; i < numsSize; ++i) {
        // If at any point, we cannot move beyond the current maxReach, return false
        if (i > maxReach) {
            return false;
        }
        
        // Update the maximum reachable index from the current position
        maxReach = (i + nums[i] > maxReach) ? i + nums[i] : maxReach;
        
        // If we can reach or go beyond the last index, return true
        if (maxReach >= numsSize - 1) {
            return true;
        }
    }
    
    // If we exit the loop without reaching the last index, return false
    return false;
}