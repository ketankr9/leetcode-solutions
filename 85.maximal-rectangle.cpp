/*
 * @lc app=leetcode id=85 lang=cpp
 *
 * [85] Maximal Rectangle
 *
 * https://leetcode.com/problems/maximal-rectangle/description/
 *
 * algorithms
 * Hard (33.83%)
 * Total Accepted:    128.2K
 * Total Submissions: 377.3K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle
 * containing only 1's and return its area.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * ⁠ ["1","0","1","0","0"],
 * ⁠ ["1","0","1","1","1"],
 * ⁠ ["1","1","1","1","1"],
 * ⁠ ["1","0","0","1","0"]
 * ]
 * Output: 6
 * 
 * 
 */
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& mat) {
        int n = mat.size();
        if(n == 0)  return 0;
        int m = mat[0].size();
        int matrix[n][m+1];
        
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++){
                if(mat[i][j] == '0')
                    matrix[i][j] = 0;
                else
                    matrix[i][j] = (i!=0?matrix[i-1][j]:0) + 1;
            }
        
        for(int j=0; j<n; j++)
            matrix[j][m] = 0;
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<m+1; j++)
        //         cout<<matrix[i][j]<<" ";
        //     cout<<"\n";
        //     }
        int gmax = 0;
        for(int r = 0; r<n; r++){
            stack<int> st;

            int ans = 0;
            for(int i=0; i<m+1; i++){
                while(!st.empty() && matrix[r][st.top()] >= matrix[r][i]){
                    int h = matrix[r][st.top()];
                    st.pop();
                    ans = max(ans, (i-1 - (st.empty()?-1:st.top()))*h);
                }
                ans = max(ans, (i - (st.empty()?-1:st.top()))*matrix[r][i]);
                st.push(i);
            }
            gmax = max(gmax, ans);
        }
        return gmax;
    }
};
