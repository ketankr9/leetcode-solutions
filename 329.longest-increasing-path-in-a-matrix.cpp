/*
 * @lc app=leetcode id=329 lang=cpp
 *
 * [329] Longest Increasing Path in a Matrix
 *
 * https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/
 *
 * algorithms
 * Hard (39.23%)
 * Total Accepted:    78.3K
 * Total Submissions: 199.4K
 * Testcase Example:  '[[9,9,4],[6,6,8],[2,1,1]]'
 *
 * Given an integer matrix, find the length of the longest increasing path.
 * 
 * From each cell, you can either move to four directions: left, right, up or
 * down. You may NOT move diagonally or move outside of the boundary (i.e.
 * wrap-around is not allowed).
 * 
 * Example 1:
 * 
 * 
 * Input: nums = 
 * [
 * ⁠ [9,9,4],
 * ⁠ [6,6,8],
 * ⁠ [2,1,1]
 * ] 
 * Output: 4 
 * Explanation: The longest increasing path is [1, 2, 6, 9].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = 
 * [
 * ⁠ [3,4,5],
 * ⁠ [3,2,6],
 * ⁠ [2,2,1]
 * ] 
 * Output: 4 
 * Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally
 * is not allowed.
 * 
 */
class Solution {
public:
	typedef pair<int, int> pr;
	#define f first
	#define s second
	#define mk make_pair
	#define pb push_back
	unordered_map<int, unordered_map<int, int>> mm;
	int ans;
	bool check(int i, int j, vector<vector<int>>& matrix){
		if(i<0 || j<0 || i>=matrix.size() || j>=matrix[0].size())	return false;
		return true;
	}
	bool check(int i, int j, int x, int y, vector<vector<int>>& matrix){
		if(i+x<0 || j+y<0 || i+x>=matrix.size() || j+y>=matrix[0].size())	return false;
		return matrix[i+x][j+y] < matrix[i][j];
	}
	int dfs(int i, int j, vector<vector<int>>& matrix){
		if(!check(i, j, matrix))	return 0;

		if(mm.find(i)!=mm.end() && mm[i].find(j)!=mm[i].end())	return mm[i][j];

		int ret = 0;
		if(check(i, j, 1, 0, matrix))
			ret = max(ret, dfs(i+1, j, matrix));
		if(check(i, j, -1, 0, matrix))
			ret = max(ret, dfs(i-1, j, matrix));
		if(check(i, j, 0, 1, matrix))
			ret = max(ret, dfs(i, j+1, matrix));
		if(check(i, j, 0, -1, matrix))
			ret = max(ret, dfs(i, j-1, matrix));
		return mm[i][j] = ret+1;
	}
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty())	return 0;
        mm.clear();
        ans = 1;
    	int n = matrix.size(), m = matrix[0].size();
    	for(int i=0; i<n; i++)
    		for(int j=0; j<m; j++)
    			ans = max(ans, dfs(i, j, matrix));
    	return ans;
    }
};
