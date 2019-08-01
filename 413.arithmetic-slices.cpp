/*
 * @lc app=leetcode id=413 lang=cpp
 *
 * [413] Arithmetic Slices
 *
 * https://leetcode.com/problems/arithmetic-slices/description/
 *
 * algorithms
 * Medium (56.17%)
 * Total Accepted:    66.4K
 * Total Submissions: 118.1K
 * Testcase Example:  '[1,2,3,4]'
 *
 * A sequence of number is called arithmetic if it consists of at least three
 * elements and if the difference between any two consecutive elements is the
 * same.
 * 
 * For example, these are arithmetic sequence:
 * 1, 3, 5, 7, 9
 * 7, 7, 7, 7
 * 3, -1, -5, -9
 * 
 * The following sequence is not arithmetic. 1, 1, 2, 5, 7 
 * 
 * 
 * A zero-indexed array A consisting of N numbers is given. A slice of that
 * array is any pair of integers (P, Q) such that 0 
 * 
 * A slice (P, Q) of array A is called arithmetic if the sequence:
 * ⁠   A[P], A[p + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, this
 * means that P + 1 < Q.
 * 
 * The function should return the number of arithmetic slices in the array
 * A. 
 * 
 * 
 * Example:
 * 
 * A = [1, 2, 3, 4]
 * 
 * return: 3, for 3 arithmetic slices in A: [1, 2, 3], [2, 3, 4] and [1, 2, 3,
 * 4] itself.
 * 
 */
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        if(n == 0)  return 0;
        bool dp[n][n];
        int cnt = 0;
        for(int k=2; k<n; k++){
            for(int i=0; i+k<n; i++){
                if(k == 2){
                    dp[i][i+k] = ((long)A[i] + A[i+2]) == (long)A[i+1]*2;
                    cnt += dp[i][i+k];
                    continue;
                }
                dp[i][i+k] = dp[i+1][i+k] && dp[i][i+k-1] && ((long)A[i] + A[i+2]) == (long)A[i+1]*2 && ((long)A[i+k-2] + A[i+k]) == (long)A[i+k-1]*2;                cnt += dp[i][i+k];
            }
        }
        return cnt;
    }
};
