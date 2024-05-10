
int trap(int* height, int heightSize)
{
    if (heightSize <= 2) return 0; // Not enough elements to trap water

    int left = 0, right = heightSize - 1; // Initialize left and right pointers
    int left_max = 0, right_max = 0; // Initialize variables to keep track of maximum heights from left and right sides
    int water_trapped = 0; // Initialize variable to keep track of water trapped

    while (left < right)
    {
        if (height[left] < height[right])//When left height is higher than right.
        {
            // Update left_max if the current height is greater
            if (height[left] >= left_max)
                left_max = height[left];
            else
                water_trapped += left_max - height[left]; // Add trapped water with the gap between current left and max left.
            left++; // Move the left pointer to the right
        }
        else // Same like lines 12 - 19 but for right instead left.
        {
            // Update right_max if the current height is greater
            if (height[right] >= right_max)
                right_max = height[right];
            else
                water_trapped += right_max - height[right]; // Add trapped water
            right--; // Move the right pointer to the left
        }
    }
    return water_trapped;
}