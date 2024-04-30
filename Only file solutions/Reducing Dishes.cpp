//class Solution {
//public:
//    int maxSatisfaction(vector<int>& satisfaction)
//    {
//        sort(satisfaction.begin(), satisfaction.end(), greater<int>()); // Sort satisfaction levels in descending order
//        int maxSum = 0, currentSum = 0, totalSum = 0;
//
//        for (int s : satisfaction) {
//            currentSum += s; // Add current satisfaction level to the cumulative sum
//            totalSum += currentSum; // Update the total sum with the new like-time coefficient
//
//            if (totalSum > maxSum) {
//                maxSum = totalSum; // Update maxSum if the new total sum is greater
//            }
//            else if (totalSum <= 0) {
//                break; // If totalSum becomes non-positive, it won't contribute to the maximum sum, so we can stop
//            }
//        }
//
//        return maxSum;
//    }
//};