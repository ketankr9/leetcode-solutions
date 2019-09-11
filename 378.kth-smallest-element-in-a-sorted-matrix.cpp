/*
 * @lc app=leetcode id=378 lang=cpp
 *
 * [378] Kth Smallest Element in a Sorted Matrix
 *
 * https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/
 *
 * algorithms
 * Medium (50.55%)
 * Total Accepted:    125.6K
 * Total Submissions: 248.4K
 * Testcase Example:  '[[1,5,9],[10,11,13],[12,13,15]]\n8'
 *
 * Given a n x n matrix where each of the rows and columns are sorted in
 * ascending order, find the kth smallest element in the matrix.
 * 
 * 
 * Note that it is the kth smallest element in the sorted order, not the kth
 * distinct element.
 * 
 * 
 * Example:
 * 
 * matrix = [
 * ⁠  [ 1,  5,  9],
 * ⁠  [10, 11, 13],
 * ⁠  [12, 13, 15]
 * ],
 * k = 8,
 * 
 * return 13.
 * 
 * 
 * 
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ n2.
 */
class Solution {
public:
	int n;
	int p(int x, int y){
		return x*n+y;
	}
	typedef vector<int> pp;
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        n = matrix.size();
  		priority_queue<pp, vector<pp>, greater<pp>> pq;
  		unordered_set<int> visited;
  		pq.push({matrix[0][0], 0, 0});
  		visited.insert(p(0, 0));
  		while(k--){
  			pp top = pq.top(); pq.pop();
  			int val = top[0], i = top[1], j = top[2];
  			if(k == 0)	return val;
  			if(i+1<n && visited.count(p(i+1, j))==0)
  				pq.push({matrix[i+1][j], i+1, j}), 
  			visited.insert(p(i+1, j));

  			if(j+1<n && visited.count(p(i, j+1))==0)
  				pq.push({matrix[i][j+1], i, j+1}), 
  			visited.insert(p(i, j+1));
  		}
  		return -1;
    }
};
