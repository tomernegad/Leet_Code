#include <stdio.h>
#include <string.h>
//בניתי בעזרת תכנון דינאמי מטריצה שבודקת כל תת מטריצה בגודל 1 עד גודל המערך ואז אחרי שכל החישובים האפשריים שלי 
//יהיו במטריצה אקח את זאת עם הערך הגבוה ביותר שמעידה על סדר הפיצוץ שיביא את התוצאה הגבוהה ביותר


// Function to find the maximum coins that can be obtained by bursting all balloons
int maxCoins(int* nums, int numsSize)
{
    int n = numsSize;
    
    // Create a new array with virtual balloons at the beginning and end with value 1.
    int newNums[n + 2];
    newNums[0] = newNums[n + 1] = 1;
    for (int i = 0; i < n; i++)
    {
        newNums[i + 1] = nums[i];
    }
    
    // Initialize a DP table filled with zeros
    int dp[n + 2][n + 2];
    memset(dp, 0, sizeof(dp));

    // Loop through each possible subarray length
    for (int length = 1; length <= n; length++)
    {
        // Loop through each possible starting index of the subarray
        for (int left = 1; left <= n - length + 1; left++)
        {
            int right = left + length - 1;  // Calculate the end index of the subarray
            // Loop through each possible balloon to burst within the subarray
            for (int k = left; k <= right; k++)
            {
                // Update the maximum coins for the current subarray
                dp[left][right] = fmax(dp[left][right],
                    newNums[left - 1] * newNums[k] * newNums[right + 1] + 
                    dp[left][k - 1] + dp[k + 1][right]);
            }
        }
    }

    // Find the maximum value in the entire DP table
    int maxCoins = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            maxCoins = fmax(maxCoins, dp[i][j]);
        }
    }

    return maxCoins;// we return the biggest value of bursting.
}