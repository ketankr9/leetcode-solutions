/*
 * @lc app=leetcode id=520 lang=cpp
 *
 * [520] Detect Capital
 *
 * https://leetcode.com/problems/detect-capital/description/
 *
 * algorithms
 * Easy (51.97%)
 * Total Accepted:    73.6K
 * Total Submissions: 141.6K
 * Testcase Example:  '"USA"'
 *
 * 
 * Given a word, you need to judge whether the usage of capitals in it is right
 * or not.
 * 
 * 
 * 
 * We define the usage of capitals in a word to be right when one of the
 * following cases holds:
 * 
 * All letters in this word are capitals, like "USA".
 * All letters in this word are not capitals, like "leetcode".
 * Only the first letter in this word is capital if it has more than one
 * letter, like "Google".
 * 
 * Otherwise, we define that this word doesn't use capitals in a right way.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: "USA"
 * Output: True
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: "FlaG"
 * Output: False
 * 
 * 
 * 
 * Note:
 * The input will be a non-empty word consisting of uppercase and lowercase
 * latin letters.
 * 
 */
class Solution {
public:
    bool isupper(char c){
        if(c>='A' && c<='Z')
            return true;
        return false;
    }

    bool detectCapitalUse(string word) {
        int N = word.size();
        if(N==1)
            return true;
        
        if(isupper(word[0]) && isupper(word[1])){
            for(auto e: word)
                if(!isupper(e)) return false;
            return true;
        }else if(isupper(word[0])){
            for(int i=1;i<N;i++)
                if(isupper(word[i]))    return false;
            return true;
        }
            //all should be lower
        for(auto w:word)
            if(isupper(w))  return false;
        return true;
    }
};
