/*
 * @lc app=leetcode id=1162 lang=cpp
 *
 * [1162] As Far from Land as Possible
 *
 * https://leetcode.com/problems/as-far-from-land-as-possible/description/
 *
 * algorithms
 * Medium (28.89%)
 * Total Accepted:    1.5K
 * Total Submissions: 5.5K
 * Testcase Example:  '[[1,0,1],[0,0,0],[1,0,1]]'
 *
 * Given an N x N grid containing only values 0 and 1, where 0 represents water
 * and 1 represents land, find a water cell such that its distance to the
 * nearest land cell is maximized and return the distance.
 * 
 * The distance used in this problem is the Manhattan distance: the distance
 * between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.
 * 
 * If no land or water exists in the grid, return -1.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: [[1,0,1],[0,0,0],[1,0,1]]
 * Output: 2
 * Explanation: 
 * The cell (1, 1) is as far as possible from all the land with distance 2.
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: [[1,0,0],[0,0,0],[0,0,0]]
 * Output: 4
 * Explanation: 
 * The cell (2, 2) is as far as possible from all the land with distance
 * 4.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= grid.length == grid[0].length <= 100
 * grid[i][j] is 0 or 1
 * 
 * 
 */
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        queue<pair<int, int>> q;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(grid[i][j] == 1)
                    q.push(make_pair(i, j));
        int dist = 0;
        while(!q.empty()){
            queue<pair<int, int>> l;
            while(!q.empty()){
                pair<int, int> p = q.front(); q.pop();
                // cout<<p.first<<":"<<p.second<<" ";
                if(p.first == -1 || p.first == n || p.second == -1 || p.second == m)    continue;
                if(dp[p.first][p.second] != INT_MAX)    continue;
                if(dist != 0 && grid[p.first][p.second] == 1)    continue;
                l.push(make_pair(p.first+1, p.second));
                l.push(make_pair(p.first, p.second+1));
                l.push(make_pair(p.first, p.second-1));
                l.push(make_pair(p.first-1, p.second));
                dp[p.first][p.second] = dist;
            }
            dist++;
            q = l;
        }
        int ans = -1;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(grid[i][j] == 0)
                    ans = max(ans, dp[i][j]);
        return ans==INT_MAX?-1:ans;
        
    }
};
