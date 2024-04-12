/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

int* canSeePersonsCount(int* heights, int heightsSize, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * heightsSize);
    int* stack = (int*)malloc(sizeof(int) * heightsSize);
    int top = -1;

    for (int i = heightsSize - 1; i >= 0; --i) {
        int count = 0;
        while (top >= 0 && heights[i] > heights[stack[top]]) {
            ++count;
            --top;
        }
        if (top >= 0) ++count;
        result[i] = count;
        stack[++top] = i;
    }

    *returnSize = heightsSize;
    free(stack);
    return result;
}

void main() {
    int heights[] = { 10, 6, 8, 5, 11,9};
    int heightsSize = sizeof(heights) / sizeof(heights[0]);
    int returnSize;

    int* result = canSeePersonsCount(heights, heightsSize, &returnSize);

    printf("Number of people each person can see:\n");
    for (int i = 0; i < returnSize; ++i) {
        printf("%d ", result[i]);
    }

    free(result);
}