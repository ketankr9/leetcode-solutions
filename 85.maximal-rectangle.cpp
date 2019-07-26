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
        int matrix[n][m];
        
        for(int i=0; i<n; i++)
            matrix[i][0] = (mat[i][0]=='1');
        
        for(int i=0; i<n; i++)
            for(int j=1; j<m; j++)
                matrix[i][j] = matrix[i][j-1]+(mat[i][j] == '1');
        
        int maxa = 0;
        for(int r = 0; r < n; r++){
            for(int i=0; i<m; i++)
                for(int j=i; j<m; j++){
                    if(i!=0 && matrix[r][j] - matrix[r][i-1] == j-i+1) // [i, j] both inclusive
                    {   
                        int tr = r, cnt = 0;
                        while(tr>=0 && matrix[tr][j] - matrix[tr][i-1] == j-i+1)
                            tr--, cnt++;
                        maxa = max(maxa, (j-i+1)*cnt);   
                    }else if(i==0 && matrix[r][j] == j+1){
                        int tr = r, cnt = 0;
                        while(tr>=0 && matrix[tr][j] == j+1)
                            tr--, cnt++;
                        maxa = max(maxa, (j+1)*cnt);
                    }
                }
        }
        return maxa;
    }
};
