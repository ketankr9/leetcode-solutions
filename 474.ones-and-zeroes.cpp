/*
 * @lc app=leetcode id=474 lang=cpp
 *
 * [474] Ones and Zeroes
 *
 * https://leetcode.com/problems/ones-and-zeroes/description/
 *
 * algorithms
 * Medium (38.82%)
 * Total Accepted:    26.8K
 * Total Submissions: 69K
 * Testcase Example:  '["10","0001","111001","1","0"]\n5\n3'
 *
 * In the computer world, use restricted resource you have to generate maximum
 * benefit is what we always want to pursue.
 * For now, suppose you are a dominator of m 0s and n 1s respectively. On the
 * other hand, there is an array with strings consisting of only 0s and 1s.
 * 
 * 
 * Now your task is to find the maximum number of strings that you can form
 * with given m 0s and n 1s. Each 0 and 1 can be used at most once.
 * 
 * 
 * 
 * Note:
 * 
 * The given numbers of 0s and 1s will both not exceed 100
 * The size of given string array won't exceed 600.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: Array = {"10", "0001", "111001", "1", "0"}, m = 5, n = 3
 * Output: 4
 * 
 * Explanation: This are totally 4 strings can be formed by the using of 5 0s
 * and 3 1s, which are “10,”0001”,”1”,”0”
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: Array = {"10", "0", "1"}, m = 1, n = 1
 * Output: 2
 * 
 * Explanation: You could form "10", but then you'd have nothing left. Better
 * form "0" and "1".
 * 
 * 
 */

/*
        sort(strs.begin(), strs.end(), [](auto s1, auto s2)
        {
            if(s1.size() < s2.size()){
                int c0 = 0, c1 = 0;
                for(auto e: s1){
                    if(e == '0')    c0++;
                    else if(e == '1')   c1++;
                }
                int c0_ = 0, c1_ = 0;
                for(auto e: s2){
                    if(e == '0')    c0_++;
                    else if(e == '1')   c1_++;
                }
                return abs(c0-c1) < abs(c0_ - c1_);
            }
            return s1.size() < s2.size();
        });
        int count = 0; 
        for(auto s: strs){
            int c0 = 0, c1 = 0;
            for(auto e: s){
                if(e == '0')    c0++;
                else if(e == '1')   c1++;
            }
            if(m >= c0 && n >= c1){
                m-=c0;
                n-=c1;
                count++;
            }
        }
        return count;
*/
class Solution {
public:
    int count0(const string &st){
        int zero = 0;
        for(auto const &c : st)
            zero += (c == '0');
        return zero;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        dp[0][0] = 0;
        int  ans = 0;
        for(auto const& st: strs){
            int zeros = count0(st);
            int ones = (int)st.size() - zeros;
            for(int i = m; i>=zeros; i--)
                for(int j = n; j>=ones; j--){
                    if(dp[i-zeros][j-ones] != -1){
                        dp[i][j] = max(dp[i][j], dp[i-zeros][j-ones]+1);
                        ans = max(ans, dp[i][j]);
                    }
                }
        }

        return ans;
    }
};
