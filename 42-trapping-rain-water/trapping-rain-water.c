#define MIN(a, b) ((a < b) ? a : b)

int trap(int* height, int heightSize) {
    int total = 0, incrWater = 0, left = 0, leftIdx = 0, countHeight = 0;
    int** stackWater = malloc(sizeof(int *) * heightSize);
    int stackWaterSize = 0, maxSize = 0;

    for(int idx = 0; idx < heightSize; idx++) {
        if(height[idx] >= left) {
            if(idx > leftIdx) {
                total += (idx - leftIdx - 1) * left - countHeight;
            }

            left = height[idx];
            leftIdx = idx;
            incrWater = 0;
            countHeight = 0;
            stackWaterSize = 0;
            continue;
        }

        if((idx > leftIdx) && (height[idx] > height[idx - 1])) {
            int newCountHeight = 0, newLeftIdx = leftIdx;
            incrWater = 0;

            for(int i = stackWaterSize - 1; i >= 0; i--) {
                if(height[stackWater[i][0]] >= height[idx]) {
                    newLeftIdx = stackWater[i][0];
                    incrWater = stackWater[i][1];
                    break;
                }
            }

            for(int i = newLeftIdx + 1; i < idx; i++) {
                newCountHeight += MIN(height[i], height[idx]);
            }

            incrWater += (idx - newLeftIdx - 1) * height[idx] - newCountHeight;
            if(maxSize > stackWaterSize) {
                stackWater[stackWaterSize][0] = idx;
                stackWater[stackWaterSize][1] = incrWater;
                stackWaterSize++;
            } else {
                *(stackWater + maxSize) = malloc(sizeof(int) * 2);
                stackWater[stackWaterSize][0] = idx;
                stackWater[stackWaterSize][1] = incrWater;
                stackWaterSize++;
                maxSize++;
            }
        }

        countHeight += height[idx];
    }

    for(int i = 0; i < maxSize; i++) {
        free(*(stackWater + i));
    }
    free(stackWater);

    return total + incrWater;
}