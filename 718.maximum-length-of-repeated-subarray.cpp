/*
 * @lc app=leetcode id=718 lang=cpp
 *
 * [718] Maximum Length of Repeated Subarray
 *
 * https://leetcode.com/problems/maximum-length-of-repeated-subarray/description/
 *
 * algorithms
 * Medium (46.61%)
 * Total Accepted:    36.8K
 * Total Submissions: 78.9K
 * Testcase Example:  '[1,2,3,2,1]\n[3,2,1,4,7]'
 *
 * Given two integer arrays A and B, return the maximum length of an subarray
 * that appears in both arrays.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * A: [1,2,3,2,1]
 * B: [3,2,1,4,7]
 * Output: 3
 * Explanation: 
 * The repeated subarray with maximum length is [3, 2, 1].
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= len(A), len(B) <= 1000
 * 0 <= A[i], B[i] < 100
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    int callme(int i, int j, vector<int>& A, vector<int>& B){
        int cnt = 0;
        while(i<(int)A.size() && j<(int)B.size() && A[i++] == B[j++])
            cnt++;
        return cnt;
    }
    int findLength(vector<int>& A, vector<int>& B) {
        int na = A.size(), nb = B.size();
        int ans = 0;
        int dp[na][nb];
        for(int i=0; i<na; i++)
            for(int j=0; j<nb; j++){
                if(i ==0 || j == 0)
                    dp[i][j] = (A[i] == B[j]);
                else
                    dp[i][j] = A[i]==B[j]?dp[i-1][j-1]+1:0;
                ans = max(ans, dp[i][j]);
            }
        return ans;
    }
};
