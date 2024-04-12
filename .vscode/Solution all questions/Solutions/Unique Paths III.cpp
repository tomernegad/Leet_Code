//#include <vector>
//#include <iostream>
//using namespace std;
//
//class Solution {
//public:
//    int uniquePathsIII(vector<vector<int>>& grid) {
//        int count = 0;
//        int start_i = 0, start_j = 0;
//        int empty = 0;
//
//        for (int i = 0; i < grid.size(); ++i) {
//            for (int j = 0; j < grid[0].size(); ++j) {
//                if (grid[i][j] == 1) {
//                    start_i = i;
//                    start_j = j;
//                }
//                else if (grid[i][j] == 0) {
//                    ++empty;
//                }
//            }
//        }
//
//        dfs(grid, start_i, start_j, empty + 1, count); // We add 1 to empty because we count the starting cell as well
//        return count;
//    }
//
//private:
//    void dfs(vector<vector<int>>& grid, int i, int j, int empty, int& count) {
//        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == -1) // return if we out of the grid
//            //that happend while we make the recursion and we reach the corners or move to cell that have obstacle -1.
//        {
//            return;
//        }
//        if (grid[i][j] == 2) // if we go the flag
//        {
//            if (empty == 0) // And if we walked all the empty cells.
//            {
//                ++count; // increase by one the number of way of go the flag when we walked all the empty cells.
//            }
//            return;
//        }
//
//        grid[i][j] = -1; // Mark current cell as visited
//        dfs(grid, i + 1, j, empty - 1, count);
//        dfs(grid, i - 1, j, empty - 1, count);
//        dfs(grid, i, j + 1, empty - 1, count);
//        dfs(grid, i, j - 1, empty - 1, count);
//        grid[i][j] = 0; // Backtrack
//    }
//};
//
//// Example usage:
//int main() {
//    Solution sol;
//    vector<vector<int>> grid = { {1,0,0,0},{0,0,0,0},{0,0,2,-1} };
//    int result = sol.uniquePathsIII(grid);
//    cout << "Number of unique paths: " << result << endl;
//    return 0;
//}