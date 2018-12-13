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
    bool valid(char a, char b){
      return a=='1' || (a=='2' && b <= '6');
    }
    bool valid(char a){
      return a != '0';
    }

    int callme(int i, string s, int* memo){
      int N = (int)s.size();

      if( N-1 == i)
        return valid(s[i]);
      else if( N-1 == i+1)
        return (valid(s[i]) && valid(s[i+1])) + valid(s[i], s[i+1]);

      if(memo[i] != NULL)
        return memo[i];

      memo[i] = 0;
      if(valid(s[i], s[i+1]))
        memo[i] += callme(i+2, s, memo);
      if(valid(s[i]))
          memo[i] += callme(i+1, s, memo);

      return memo[i];
    }
    int numDecodings(string s) {
      if((int)s.size() == 0)  return 0;
      int memo[(int)s.size()];
      fill_n(memo, (int)s.size(), NULL);
      return callme(0, s, memo);
    }
};
