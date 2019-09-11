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
	typedef pair<int, pair<int, int>> pp;
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        n = matrix.size();
  		priority_queue<pp, vector<pp>, greater<pp>> pq;
  		unordered_set<int> visited;
  		pq.push({matrix[0][0], {0, 0}});
  		visited.insert(p(0, 0));
  		while(k--){
  			pp top = pq.top(); pq.pop();
  			if(k == 0)	return top.first;
  			if(top.second.first+1<n && visited.count(p(top.second.first+1, top.second.second))==0)
  				pq.push({matrix[top.second.first+1][top.second.second], {top.second.first+1, top.second.second}}), 
  			visited.insert(p(top.second.first+1, top.second.second));

  			if(top.second.second+1<n && visited.count(p(top.second.first, top.second.second+1))==0)
  				pq.push({matrix[top.second.first][top.second.second+1], {top.second.first, top.second.second+1}}), 
  			visited.insert(p(top.second.first, top.second.second+1));
  		}
  		return -1;
    }
};
