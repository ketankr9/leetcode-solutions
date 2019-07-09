/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 *
 * https://leetcode.com/problems/unique-paths-ii/description/
 *
 * algorithms
 * Medium (33.55%)
 * Likes:    901
 * Dislikes: 132
 * Total Accepted:    208.5K
 * Total Submissions: 621.4K
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in
 * the diagram below).
 * 
 * The robot can only move either down or right at any point in time. The robot
 * is trying to reach the bottom-right corner of the grid (marked 'Finish' in
 * the diagram below).
 * 
 * Now consider if some obstacles are added to the grids. How many unique paths
 * would there be?
 * 
 * 
 * 
 * An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 * 
 * Note: m and n will be at most 100.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * [
 * [0,0,0],
 * [0,1,0],
 * [0,0,0]
 * ]
 * Output: 2
 * Explanation:
 * There is one obstacle in the middle of the 3x3 grid above.
 * There are two ways to reach the bottom-right corner:
 * 1. Right -> Right -> Down -> Down
 * 2. Down -> Down -> Right -> Right
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<int, unordered_map<int, int>> mm;
    int callme(int x, int y, int n, int m, const vector<vector<int>> &obs){
        if(x==n-1 && y==m-1 && obs[x][y]==0)
            return 1;
        if(x==n || y==m || obs[x][y] == 1)
            return 0;
        
        if(mm.count(x)!=0 && mm[x].count(y)!=0)
            return mm[x][y];
        int ans = callme(x+1, y, n, m, obs) + callme(x, y+1, n, m, obs);
        mm[x][y] = ans;
        return ans;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        mm.clear();
        return callme(0,0,n,m, obstacleGrid);        
    }
};

