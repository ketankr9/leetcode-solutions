/*
 * @lc app=leetcode id=930 lang=cpp
 *
 * [930] Binary Subarrays With Sum
 *
 * https://leetcode.com/problems/binary-subarrays-with-sum/description/
 *
 * algorithms
 * Medium (39.04%)
 * Total Accepted:    11.1K
 * Total Submissions: 28.4K
 * Testcase Example:  '[1,0,1,0,1]\n2'
 *
 * In an array A of 0s and 1s, how many non-empty subarrays have sum S?
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: A = [1,0,1,0,1], S = 2
 * Output: 4
 * Explanation: 
 * The 4 subarrays are bolded below:
 * [1,0,1,0,1]
 * [1,0,1,0,1]
 * [1,0,1,0,1]
 * [1,0,1,0,1]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * A.length <= 30000
 * 0 <= S <= A.length
 * A[i] is either 0 or 1.
 * 
 */
class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        int n = A.size();
        int ans = 0, i = 0, j = 0, sum = 0;
        if(S == 0){
            while(j<n){
                while(j < n && A[j] == 1)
                    j++;
                int z = 0;
                while(j < n && A[j] == 0)
                    j++, z++;
                ans += z*(z-1)/2 + z;
            }
            return ans;
        }
        while(j<n){
            while(j<n && sum < S)
                sum += A[j++];
            if(j == n && sum < S)  return ans; // ab nahi ho paayega
            int l = 1;
            while(i<n && A[i] == 0)
                i++, l++;
            ans += l;

            while(j<n && A[j] == 0)
                j++, ans += l;
            if(i<n)
                sum -= A[i++];
        }
        return ans;
    }
};