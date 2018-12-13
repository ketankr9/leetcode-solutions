/*
 * @lc app=leetcode id=784 lang=cpp
 *
 * [784] Letter Case Permutation
 *
 * https://leetcode.com/problems/letter-case-permutation/description/
 *
 * algorithms
 * Easy (53.91%)
 * Total Accepted:    31.4K
 * Total Submissions: 58.3K
 * Testcase Example:  '"a1b2"'
 *
 * Given a string S, we can transform every letter individually to be lowercase
 * or uppercase to create another string.  Return a list of all possible
 * strings we could create.
 *
 *
 * Examples:
 * Input: S = "a1b2"
 * Output: ["a1b2", "a1B2", "A1b2", "A1B2"]
 *
 * Input: S = "3z4"
 * Output: ["3z4", "3Z4"]
 *
 * Input: S = "12345"
 * Output: ["12345"]
 *
 *
 * Note:
 *
 *
 * S will be a string with length between 1 and 12.
 * S will consist only of letters or digits.
 *
 *
 */
class Solution {
public:
    bool isAlpha(char c){
      return (c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A');
    }
    char flip(char c){
      if(c <= 'z' && c >= 'a'){// small
        return 'A' + c-'a';
      }else{
        return 'a' + c-'A';
      }
    }
    void callme(int i, string temp, string s, vector<string>& ans){
      if(i==(int)s.size()){
        ans.push_back(temp);
        return;
      }
      callme(i+1, temp+s[i], s, ans);
      if(isAlpha(s[i]))
        callme(i+1, temp+flip(s[i]), s, ans);

    }

    vector<string> letterCasePermutation(string S) {
        vector<string> ans;
        callme(0,"", S, ans);
        return ans;
    }
};
