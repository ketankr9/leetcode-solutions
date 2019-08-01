/*
 * @lc app=leetcode id=1027 lang=cpp
 *
 * [1027] Longest Arithmetic Sequence
 *
 * https://leetcode.com/problems/longest-arithmetic-sequence/description/
 *
 * algorithms
 * Medium (48.92%)
 * Total Accepted:    10.7K
 * Total Submissions: 21.8K
 * Testcase Example:  '[3,6,9,12]'
 *
 * Given an array A of integers, return the length of the longest arithmetic
 * subsequence in A.
 * 
 * Recall that a subsequence of A is a list A[i_1], A[i_2], ..., A[i_k] with 0
 * <= i_1 < i_2 < ... < i_k <= A.length - 1, and that a sequence B is
 * arithmetic if B[i+1] - B[i] are all the same value (for 0 <= i < B.length -
 * 1).
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [3,6,9,12]
 * Output: 4
 * Explanation: 
 * The whole array is an arithmetic sequence with steps of length = 3.
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [9,4,7,2,10]
 * Output: 3
 * Explanation: 
 * The longest arithmetic subsequence is [4,7,10].
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [20,1,15,3,10,5,8]
 * Output: 4
 * Explanation: 
 * The longest arithmetic subsequence is [20,15,10,5].
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 2 <= A.length <= 2000
 * 0 <= A[i] <= 10000
 * 
 * 
 */
class Solution {
public:
    unordered_map<int, unordered_map<int, int>> mm;
    int callme(int start, int diff, vector<int>& A){
        int i = start;
        int cnt = 0;
        int d = 0;
        if(mm.find(start)!=mm.end() && mm[start].find(diff)!=mm[start].end())
            return mm[start][diff];

        while(i<(int)A.size()){
            if(A[start]+d == A[i])
                cnt++, d += diff;
            i++;
        }
        mm[start][diff] = cnt;
        return cnt;
    }
    int longestArithSeqLength(vector<int>& A) {
        int n = A.size();
        int ans = 0;
        mm.clear();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                ans = max(ans, 1+callme(j, A[j]-A[i], A));
            }
        }
        return ans<2?0:ans;
    }
};
