/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 *
 * https://leetcode.com/problems/decode-ways/description/
 *
 * algorithms
 * Medium (21.37%)
 * Total Accepted:    218.7K
 * Total Submissions: 1M
 * Testcase Example:  '"12"'
 *
 * A message containing letters from A-Z is being encoded to numbers using the
 * following mapping:
 *
 *
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 *
 *
 * Given a non-empty string containing only digits, determine the total number
 * of ways to decode it.
 *
 * Example 1:
 *
 *
 * Input: "12"
 * Output: 2
 * Explanation: It could be decoded as "AB" (1 2) or "L" (12).
 *
 *
 * Example 2:
 *
 *
 * Input: "226"
 * Output: 3
 * Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2
 * 6).
 *
 */
class Solution {
public:
    bool valid(string st, int i, int num){
      if(num == 1){ // num == 1
        int t = (int)st[i]-(int)'0';
        return i < (int)st.size() && t > 0 && t < 10;
      }else{ // num == 2
        int t = (int)st[i]*10 + (int)st[i+1]-(int)'0'*11;
        return i + 1 < (int)st.size() && t > 9 && t <= 26;
      }
    }

    int callme(int i, string s, int* memo){
      int N = (int)s.size();

      if( N-1 == i)
        return (int)valid(s, i, 1);
      else if( N-1 == i+1)
        return (int)(valid(s, i, 1) && valid(s, i+1, 1)) + (int)valid(s, i, 2);

      if(memo[i] != NULL)
        return memo[i];

      memo[i] = 0;
      if(valid(s,i,1))
        memo[i] += callme(i+1, s, memo);
      if(valid(s,i,2))
        memo[i] += callme(i+2, s, memo);

      return memo[i];
    }
    int numDecodings(string s) {
      if((int)s.size() == 0)  return 0;
      int memo[(int)s.size()];
      fill_n(memo, (int)s.size(), NULL);
      return callme(0, s, memo);
    }
};
