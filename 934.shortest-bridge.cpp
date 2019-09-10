/*
 * @lc app=leetcode id=934 lang=cpp
 *
 * [934] Shortest Bridge
 *
 * https://leetcode.com/problems/shortest-bridge/description/
 *
 * algorithms
 * Medium (43.06%)
 * Total Accepted:    8.6K
 * Total Submissions: 19.5K
 * Testcase Example:  '[[0,1],[1,0]]'
 *
 * In a given 2D binary array A, there are two islands.  (An island is a
 * 4-directionally connected group of 1s not connected to any other 1s.)
 * 
 * Now, we may change 0s to 1s so as to connect the two islands together to
 * form 1 island.
 * 
 * Return the smallest number of 0s that must be flipped.  (It is guaranteed
 * that the answer is at least 1.)
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [[0,1],[1,0]]
 * Output: 1
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[0,1,0],[0,0,0],[0,0,1]]
 * Output: 2
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
 * Output: 1
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length = A[0].length <= 100
 * A[i][j] == 0 or A[i][j] == 1
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */
class Solution {
public:
	int g(int i, int j){
		return i*100+j;
	}
	bool isvalid(int i, int j, vector<vector<int>>& A){
		if(i < 0 || j < 0 || i == A.size() || j == A.size() || A[i][j] == 2)
			return false;
		return true;
	}
	void dfs(int i, int j, vector<vector<int>>& A, queue<int>& q){
		if(!isvalid(i, j, A) || A[i][j] == 0)
			return;
		q.push(g(i, j));
		A[i][j] = 2;
		dfs(i+1, j, A, q);	dfs(i, j-1, A, q);
		dfs(i-1, j, A, q);	dfs(i, j+1, A, q);
	}
	bool check(int i, int j, queue<int>& tmp, vector<vector<int>>& A){
		if(!isvalid(i, j, A))
			return false;
		if(A[i][j] == 1)	return true;
		A[i][j] = 2;
		tmp.push(g(i, j));
		return false;
	}
    int shortestBridge(vector<vector<int>>& A) {
        int n = A.size();
        queue<int> q;
        bool flag = true;
        for(int i=0; i<n && flag; i++)
        	for(int j=0; j<n && flag; j++){
        		if(A[i][j] == 1){
        			dfs(i, j, A, q);
        			flag = false;
        		}
        	}
        int cnt = 0;
        while(!q.empty()){
        	queue<int> tmp;
        	while(!q.empty()){
        		int x = q.front()/100, y = q.front()%100; q.pop();
        		if( check(x+1, y, tmp, A) || check(x, y+1, tmp, A) || check(x-1, y, tmp, A) || check(x, y-1, tmp, A))
        			return cnt;
        	}
        	cnt++;
        	q = tmp;
        }
        cout<<":(";
        return 1;
    }
};
