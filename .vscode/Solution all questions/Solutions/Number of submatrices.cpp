//#include <iostream>
//#include <vector>
//#include <unordered_map>
//
//using namespace std;
//
//class Solution {
//public:
//    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
//        int m = matrix.size();
//        int n = matrix[0].size();
//        int count = 0;
//
//        // Precompute the prefix sums for each row
//        for (int i = 0; i < m; ++i) {
//            for (int j = 1; j < n; ++j) {
//                matrix[i][j] += matrix[i][j - 1];
//            }
//        }
//
//        // Iterate through all possible pairs of columns
//        for (int left = 0; left < n; ++left) {
//            for (int right = left; right < n; ++right) {
//                unordered_map<int, int> counter;
//                counter[0] = 1;
//                int currSum = 0;
//
//                // Iterate through each row
//                for (int row = 0; row < m; ++row) {
//                    // Calculate the sum of elements in the submatrix
//                    currSum += matrix[row][right] - (left > 0 ? matrix[row][left - 1] : 0);
//
//                    // If there exists a submatrix with the sum equal to target, update the count
//                    count += counter[currSum - target];
//
//                    // Increment the counter for the current sum
//                    counter[currSum]++;
//                }
//            }
//        }
//
//        return count;
//    }
//};
//
//int main() {
//    Solution solution;
//    vector<vector<int>> matrix = { {0,1,0},{1,1,1},{0,1,0} };
//    int target = 0;
//    int result = solution.numSubmatrixSumTarget(matrix, target);
//    cout << "Result: " << result << endl;
//    return 0;
//}