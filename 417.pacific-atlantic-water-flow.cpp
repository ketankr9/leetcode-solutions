/*
 * @lc app=leetcode id=417 lang=cpp
 *
 * [417] Pacific Atlantic Water Flow
 *
 * https://leetcode.com/problems/pacific-atlantic-water-flow/description/
 *
 * algorithms
 * Medium (38.22%)
 * Total Accepted:    50.3K
 * Total Submissions: 131.5K
 * Testcase Example:  '[[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]'
 *
 * Given an m x n matrix of non-negative integers representing the height of
 * each unit cell in a continent, the "Pacific ocean" touches the left and top
 * edges of the matrix and the "Atlantic ocean" touches the right and bottom
 * edges.
 * 
 * Water can only flow in four directions (up, down, left, or right) from a
 * cell to another one with height equal or lower.
 * 
 * Find the list of grid coordinates where water can flow to both the Pacific
 * and Atlantic ocean.
 * 
 * Note:
 * 
 * 
 * The order of returned grid coordinates does not matter.
 * Both m and n are less than 150.
 * 
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Given the following 5x5 matrix:
 * 
 * ⁠ Pacific ~   ~   ~   ~   ~ 
 * ⁠      ~  1   2   2   3  (5) *
 * ⁠      ~  3   2   3  (4) (4) *
 * ⁠      ~  2   4  (5)  3   1  *
 * ⁠      ~ (6) (7)  1   4   5  *
 * ⁠      ~ (5)  1   1   2   4  *
 * ⁠         *   *   *   *   * Atlantic
 * 
 * Return:
 * 
 * [[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with
 * parentheses in above matrix).
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> res;
    void dfs(int prev, int i, int j, vector<vector<int>>& matrix, int ocean, vector<vector<int>>& visited){
        if(i < 0 || j < 0 || i >= matrix.size() || j >= matrix[0].size() || matrix[i][j] < prev || (visited[i][j]&ocean) == ocean)
            return;
        if((visited[i][j] |= ocean) == 3)
            res.push_back({i, j});
        dfs(matrix[i][j], i+1, j, matrix, ocean, visited);    dfs(matrix[i][j], i, j+1, matrix, ocean, visited);
        dfs(matrix[i][j], i-1, j, matrix, ocean, visited);    dfs(matrix[i][j], i, j-1, matrix, ocean, visited);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        res.clear();
        if(matrix.empty())  return res;
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));
        for(int i=0; i<n; i++){
            dfs(INT_MIN, i, 0, matrix, 1, visited);
            dfs(INT_MIN, i, m-1, matrix, 2, visited);
        }
        for(int j=0; j<m; j++){
            dfs(INT_MIN, 0, j, matrix, 1, visited);
            dfs(INT_MIN, n-1, j, matrix, 2, visited);
        }

        return res;
    }
};
