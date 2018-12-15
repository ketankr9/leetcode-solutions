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
    vector<char> mapping(char digit){
      int adjust = 0;
      bool status = false;
      if(digit == '7'){
        status = true;
      }else if(digit == '8'){
        adjust = 1;
      }else if(digit == '9'){
        status = true;
        adjust = 1;
      }
      std::vector<char> res;
      res.push_back((char)('a' + (digit-'0'-2)*3+0+adjust));
      res.push_back((char)('a' + (digit-'0'-2)*3+1+adjust));
      res.push_back((char)('a' + (digit-'0'-2)*3+2+adjust));
      if(status)
        res.push_back((char)('a' + (digit-'0'-2)*3+3+adjust));
      return res;
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if((int)digits.size() == 0) return ans;
        ans.push_back("");

        for(auto d: digits){
          vector<string> temp;
          swap(temp, ans);
          for(auto t: temp){
            for(auto c: mapping(d)){
              ans.push_back(t+c);
            }
          }
        }
        return ans;
    }
};
