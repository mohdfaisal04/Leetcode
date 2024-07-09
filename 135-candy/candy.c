int candy(int* ratings, int ratingsSize) {
    if (ratingsSize == 0) return 0;
    
    int *left2right = (int*) malloc(ratingsSize * sizeof(int));
    int *right2left = (int*) malloc(ratingsSize * sizeof(int));
    
    // Initialize each child with at least 1 candy
    for (int i = 0; i < ratingsSize; ++i) {
        left2right[i] = 1;
        right2left[i] = 1;
    }
    
    // Traverse from left to right, ensure each child with higher rating gets more candies
    for (int i = 1; i < ratingsSize; ++i) {
        if (ratings[i] > ratings[i - 1]) {
            left2right[i] = left2right[i - 1] + 1;
        }
    }
    
    // Traverse from right to left, ensure each child with higher rating gets more candies
    for (int i = ratingsSize - 2; i >= 0; --i) {
        if (ratings[i] > ratings[i + 1]) {
            right2left[i] = right2left[i + 1] + 1;
        }
    }
    
    int totalCandies = 0;
    // Sum up the maximum candies required for each child
    for (int i = 0; i < ratingsSize; ++i) {
        totalCandies += (left2right[i] > right2left[i]) ? left2right[i] : right2left[i];
    }
    
    free(left2right);
    free(right2left);
    
    return totalCandies;
}