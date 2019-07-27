/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 *
 * https://leetcode.com/problems/maximal-square/description/
 *
 * algorithms
 * Medium (33.56%)
 * Total Accepted:    139.1K
 * Total Submissions: 414.5K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * Given a 2D binary matrix filled with 0's and 1's, find the largest square
 * containing only 1's and return its area.
 * 
 * Example:
 * 
 * 
 * Input: 
 * 
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 1 0
 * 
 * Output: 4
 * 
 */
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if(n == 0)  return 0;
        int m = matrix[0].size();

        int mat[n][m+1];
        for(int j=0; j<m+1; j++)
            for(int i=0; i<n; i++)
                if(j == m)
                    mat[i][j] = 0;
                else if(matrix[i][j] == '0')
                    mat[i][j] = 0;
                else
                    mat[i][j] = (i>=1?mat[i-1][j]:0) + 1;
        
        int ans = 0;
        for(int r=0; r<n; r++){
            stack<int> st;
            for(int j=0; j<m+1; j++){
                while(!st.empty() && mat[r][j] <= mat[r][st.top()]){
                    int h = mat[r][st.top()];
                    st.pop();
                    int x = (st.empty()?-1:st.top());
                    if((j-1-x) == h)
                        ans = max(ans, (j-1-x)*h);
                }
                if(mat[r][j] == (j-(st.empty()?-1:st.top())))
                    ans = max(ans, mat[r][j]*(j-(st.empty()?-1:st.top())));
                st.push(j);
            }
        }
        return ans;
    }
};
