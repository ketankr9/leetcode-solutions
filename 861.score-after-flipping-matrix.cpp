/*
 * @lc app=leetcode id=861 lang=cpp
 *
 * [861] Score After Flipping Matrix
 *
 * https://leetcode.com/problems/score-after-flipping-matrix/description/
 *
 * algorithms
 * Medium (69.80%)
 * Total Accepted:    12.7K
 * Total Submissions: 18.2K
 * Testcase Example:  '[[0,0,1,1],[1,0,1,0],[1,1,0,0]]'
 *
 * We have a two dimensional matrix A where each value is 0 or 1.
 * 
 * A move consists of choosing any row or column, and toggling each value in
 * that row or column: changing all 0s to 1s, and all 1s to 0s.
 * 
 * After making any number of moves, every row of this matrix is interpreted as
 * a binary number, and the score of the matrix is the sum of these numbers.
 * 
 * Return the highest possible score.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
 * Output: 39
 * Explanation:
 * Toggled to [[1,1,1,1],[1,0,0,1],[1,1,1,1]].
 * 0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length <= 20
 * 1 <= A[0].length <= 20
 * A[i][j] is 0 or 1.
 * 
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int nrow = A.size();
        int ncol = A[0].size();
        vector<bool> rows(nrow, false);
        vector<bool> cols(ncol, false);
        for(int i=0; i<nrow; i++){
            if(A[i][0] == 0)
                rows[i] = true;
        }
        for(int j=0; j<ncol; j++){
            int cnt = 0;
            for(int i=0; i<nrow; i++)
                cnt += A[i][j]^rows[i];
            if(cnt*2 < nrow)
                cols[j] = true;
        }
        int ans = 0;
        for(int i=0; i<nrow; i++)
            for(int j=0; j<ncol; j++){
                ans += (A[i][j]^rows[i]^cols[j])*(1<<(ncol-j-1));
            }
        return ans;
    }
};
