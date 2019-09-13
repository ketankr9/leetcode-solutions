/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 *
 * https://leetcode.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (31.37%)
 * Total Accepted:    264.3K
 * Total Submissions: 842.7K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given a matrix of m x n elements (m rows, n columns), return all elements of
 * the matrix in spiral order.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 * Output: [1,2,3,6,9,8,7,4,5]
 * 
 * 
 * Example 2:
 * 
 * Input:
 * [
 * ⁠ [1, 2, 3, 4],
 * ⁠ [5, 6, 7, 8],
 * ⁠ [9,10,11,12]
 * ]
 * Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 * 
 */
class Solution {
public:
	#define fori(x, y)	for(int i=x; i<=y; i++)
	#define forj(x, y)	for(int j=y; j>=x; j--)
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
    	vector<int> ans;
    	if(matrix.empty())	return ans;
    	int n = matrix.size(), m = matrix[0].size();
        int starti = 0, startj = 0, endi = (int)matrix.size()-1, endj = (int)matrix[0].size()-1;
        while(starti<=endi && startj<=endj){
        	for(int i=startj; i<=endj && ans.size() < n*m; i++)
        		ans.push_back(matrix[starti][i]);
        	starti++;
        	for(int i=starti; i<=endi && ans.size() < n*m; i++)
        		ans.push_back(matrix[i][endj]);
        	endj--;
        	for(int j=endj; j>=startj && ans.size() < n*m; j--)
        		ans.push_back(matrix[endi][j]);
        	endi--;
        	for(int j=endi; j>=starti && ans.size() < n*m; j--)
        		ans.push_back(matrix[j][startj]);
        	startj++;
        }
        return ans;
    }
};
