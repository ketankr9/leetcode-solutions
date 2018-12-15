/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (39.17%)
 * Total Accepted:    312.9K
 * Total Submissions: 798.1K
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent.
 *
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 *
 *
 *
 * Example:
 *
 *
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 *
 *
 * Note:
 *
 * Although the above answer is in lexicographical order, your answer could be
 * in any order you want.
 *
 */
class Solution {
public:
    vector<string> ans;
    void callme(int k, string temp, string digits){
      if(k == (int)digits.size()){
        ans.push_back(temp);
        return;
      }
      int adjust = 0;
      bool status = false;
      if(digits[k] == '7'){
        status = true;
      }else if(digits[k] == '8'){
        adjust = 1;
      }else if(digits[k] == '9'){
        status = true;
        adjust = 1;
      }
      callme(k+1, temp + (char)('a' + (digits[k]-'0'-2)*3+0+adjust), digits);
      callme(k+1, temp + (char)('a' + (digits[k]-'0'-2)*3+1+adjust), digits);
      callme(k+1, temp + (char)('a' + (digits[k]-'0'-2)*3+2+adjust), digits);
      if(status)
        callme(k+1, temp + (char)('a' + (digits[k]-'0'-2)*3+3+adjust), digits);
    }
    vector<string> letterCombinations(string digits) {
      ans.clear();
      if((int)digits.size() == 0)  return ans;
      callme(0, "", digits);
      return ans;
    }
};
