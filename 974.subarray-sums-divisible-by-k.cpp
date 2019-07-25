/*
 * @lc app=leetcode id=974 lang=cpp
 *
 * [974] Subarray Sums Divisible by K
 *
 * https://leetcode.com/problems/subarray-sums-divisible-by-k/description/
 *
 * algorithms
 * Medium (45.69%)
 * Total Accepted:    14.3K
 * Total Submissions: 31.1K
 * Testcase Example:  '[4,5,0,-2,-3,1]\n5'
 *
 * Given an array A of integers, return the number of (contiguous, non-empty)
 * subarrays that have a sum divisible by K.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: A = [4,5,0,-2,-3,1], K = 5
 * Output: 7
 * Explanation: There are 7 subarrays with a sum divisible by K = 5:
 * [4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2,
 * -3]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length <= 30000
 * -10000 <= A[i] <= 10000
 * 2 <= K <= 10000
 * 
 * 
 */
class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int n = A.size();

        int pprix[n+1]; fill_n(pprix, n+1, 0);
        for(int i=0; i<n; i++)
            pprix[i+1] = pprix[i] + A[i];
        
        int cnt[K]; fill_n(cnt, K, 0);
        for(int i=0; i<n+1; i++)
            cnt[(pprix[i]%K+K)%K]++;
        
        int ans = 0;
        for(int i=0; i<K; i++)
            ans += cnt[i]*(cnt[i]-1)/2;
        // ans += (cnt[0]-1)*(cnt[0]-2)/2;
        return ans;
    }
};
