/*
 * @lc app=leetcode id=304 lang=cpp
 *
 * [304] Range Sum Query 2D - Immutable
 *
 * https://leetcode.com/problems/range-sum-query-2d-immutable/description/
 *
 * algorithms
 * Medium (31.16%)
 * Total Accepted:    63.2K
 * Total Submissions: 202.8K
 * Testcase Example:  '["NumMatrix","sumRegion","sumRegion","sumRegion"]\n[[[[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]]],[2,1,4,3],[1,1,2,2],[1,2,2,4]]'
 *
 * Given a 2D matrix matrix, find the sum of the elements inside the rectangle
 * defined by its upper left corner (row1, col1) and lower right corner (row2,
 * col2).
 * 
 * 
 * 
 * The above rectangle (with the red border) is defined by (row1, col1) = (2,
 * 1) and (row2, col2) = (4, 3), which contains sum = 8.
 * 
 * 
 * Example:
 * 
 * Given matrix = [
 * ⁠ [3, 0, 1, 4, 2],
 * ⁠ [5, 6, 3, 2, 1],
 * ⁠ [1, 2, 0, 1, 5],
 * ⁠ [4, 1, 0, 1, 7],
 * ⁠ [1, 0, 3, 0, 5]
 * ]
 * 
 * sumRegion(2, 1, 4, 3) -> 8
 * sumRegion(1, 1, 2, 2) -> 11
 * sumRegion(1, 2, 2, 4) -> 12
 * 
 * 
 * 
 * Note:
 * 
 * You may assume that the matrix does not change.
 * There are many calls to sumRegion function.
 * You may assume that row1 ≤ row2 and col1 ≤ col2.
 * 
 * 
 */
class NumMatrix {
public:
    vector<vector<int>> dp;
    NumMatrix(vector<vector<int>> matrix) {
        if((int)matrix.size() == 0){
            dp.clear();
            return;
        }
        dp.resize(matrix.size()+1, vector<int>(matrix[0].size()+1)); //= vector<int>((int)matrix.size()+1, vector<int>((int)matrix[0].size()+1, 0));
        for(int i=0; i<(int)matrix.size()+1; i++)
            for(int j=0; j<(int)matrix[0].size()+1; j++)
                dp[i][j] = (i==0||j==0?0:dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + matrix[i-1][j-1]);
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return dp.empty()?0:dp[row2+1][col2+1] + dp[row1][col1] - dp[row2+1][col1] - dp[row1][col2+1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
