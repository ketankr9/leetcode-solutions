/*
 * @lc app=leetcode id=926 lang=cpp
 *
 * [926] Flip String to Monotone Increasing
 *
 * https://leetcode.com/problems/flip-string-to-monotone-increasing/description/
 *
 * algorithms
 * Medium (50.36%)
 * Total Accepted:    14.2K
 * Total Submissions: 28.3K
 * Testcase Example:  '"00110"'
 *
 * A string of '0's and '1's is monotone increasing if it consists of some
 * number of '0's (possibly 0), followed by some number of '1's (also possibly
 * 0.)
 * 
 * We are given a string S of '0's and '1's, and we may flip any '0' to a '1'
 * or a '1' to a '0'.
 * 
 * Return the minimum number of flips to make S monotone increasing.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "00110"
 * Output: 1
 * Explanation: We flip the last digit to get 00111.
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "010110"
 * Output: 2
 * Explanation: We flip to get 011111, or alternatively 000111.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "00011000"
 * Output: 2
 * Explanation: We flip to get 00000000.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= S.length <= 20000
 * S only consists of '0' and '1' characters.
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int tones = 0, n = S.size();
        for(auto c: S)
        	tones += (c-'0');
        
        if(tones == 0 || tones == n)	return 0;

        int ones = 0, ans = (n-tones);
        for(int i=0; i<n; i++){
        	ones += (S[i]-'0');
        	ans = min(ans, ones + (n-(i+1)) - (tones-ones));
        }
        return ans == INT_MAX?0:ans;
    }
};
