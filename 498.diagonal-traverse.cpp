/*
 * @lc app=leetcode id=498 lang=cpp
 *
 * [498] Diagonal Traverse
 *
 * https://leetcode.com/problems/diagonal-traverse/description/
 *
 * algorithms
 * Medium (45.59%)
 * Total Accepted:    47.1K
 * Total Submissions: 103.3K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given a matrix of M x N elements (M rows, N columns), return all elements of
 * the matrix in diagonal order as shown in the below image.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 * 
 * Output:  [1,2,4,7,5,3,6,8,9]
 * 
 * Explanation:
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * The total number of elements of the given matrix will not exceed 10,000.
 * 
 */
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> ans;
        if(n == 0)  return ans;
        int m = matrix[0].size();
        bool ulta = false;
        bool left = true;
        int x = 0, y = 0;
        int a, b;
        while((int)ans.size() < n*m){
            a = x, b = y;
            if(!ulta){
                while(a>=0 && b<m)
                    ans.push_back(matrix[a--][b++]);
            }else{
                vector<int> rev;
                while(a>=0 && b<m)
                    rev.push_back(matrix[a--][b++]);
                for(int i=rev.size()-1; i>=0; i--)
                    ans.push_back(rev[i]);
            }
            if(left) x++;
            if(x==n){
                x--;
                left = false;
            }
            if(!left)   y++;
            ulta^=true;
        }
        return ans;
    }
};
