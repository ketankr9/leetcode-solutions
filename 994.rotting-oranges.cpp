/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 *
 * https://leetcode.com/problems/rotting-oranges/description/
 *
 * algorithms
 * Easy (46.18%)
 * Total Accepted:    18.1K
 * Total Submissions: 39.2K
 * Testcase Example:  '[[2,1,1],[1,1,0],[0,1,1]]'
 *
 * In a given grid, each cell can have one of three values:
 * 
 * 
 * the value 0 representing an empty cell;
 * the value 1 representing a fresh orange;
 * the value 2 representing a rotten orange.
 * 
 * 
 * Every minute, any fresh orange that is adjacent (4-directionally) to a
 * rotten orange becomes rotten.
 * 
 * Return the minimum number of minutes that must elapse until no cell has a
 * fresh orange.  If this is impossible, return -1 instead.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: [[2,1,1],[1,1,0],[0,1,1]]
 * Output: 4
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[2,1,1],[0,1,1],[1,0,1]]
 * Output: -1
 * Explanation:  The orange in the bottom left corner (row 2, column 0) is
 * never rotten, because rotting only happens 4-directionally.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [[0,2]]
 * Output: 0
 * Explanation:  Since there are already no fresh oranges at minute 0, the
 * answer is just 0.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= grid.length <= 10
 * 1 <= grid[0].length <= 10
 * grid[i][j] is only 0, 1, or 2.
 * 
 * 
 * 
 * 
 */
class Solution {
public:
	int p(int x, int y){
		return x*10+y;
	}
	void callme(int i, int j, vector<vector<int>>& grid, queue<int>& q, int& fresh){
		if(i<0 || j<0 || i == grid.size() || j == grid[0].size() || grid[i][j]!=1)
			return;
		grid[i][j] = 2;
		fresh--;
		q.push(p(i, j));
	}
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<int> q;
        int fresh = 0;
        for(int i=0; i<n; i++)
        	for(int j=0; j<m; j++){
        		fresh += (grid[i][j]==1);
        		if(grid[i][j]==2)
        		q.push(p(i, j));
        	}
        int minutes = 0;
        while(!q.empty()){
        	queue<int> tmp;
        	while(!q.empty()){
        		int i = q.front()/10, j = q.front()%10; q.pop();
        		callme(i+1, j, grid, tmp, fresh);	callme(i-1, j, grid, tmp, fresh);
        		callme(i, j+1, grid, tmp, fresh);	callme(i, j-1, grid, tmp, fresh);
        	}
        	if(tmp.empty())	break;
        	minutes++;
        	q = tmp;
        }
        return fresh==0?minutes:-1;

    }
};
