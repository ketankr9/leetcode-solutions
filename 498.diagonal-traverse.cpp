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
        bool up = true;
        int x = 0, y = 0;
        int a = 0, b = 1;//(m >= 2?1:);
        while((int)ans.size() < n*m){
            if(!ulta){
                // cout<<"L"<<x<<y<<"\n";
                if(x>=n){
                    left = false;
                    y = x-(n-1);
                    x = n-1;
                }
                int p = x, q = y;
                while(p>=0 && q<m)
                    ans.push_back(matrix[p--][q++]);
                if(left) x+=2;
                else   y+=2;
                
            }else{
                // cout<<"U"<<a<<b<<"\n";
                if(b>=m){
                    up = false;
                    a = b-(m-1);
                    b = m-1;
                }
                int p = a, q = b;
                while(p<n && q>=0)
                    ans.push_back(matrix[p++][q--]);
                if(up) b+=2;
                else   a+=2;
                
            }
            ulta^=true;
        }
        return ans;
    }
};
