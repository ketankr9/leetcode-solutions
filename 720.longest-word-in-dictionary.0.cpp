/*
 * @lc app=leetcode id=720 lang=cpp
 *
 * [720] Longest Word in Dictionary
 *
 * https://leetcode.com/problems/longest-word-in-dictionary/description/
 *
 * algorithms
 * Easy (42.83%)
 * Total Accepted:    26.4K
 * Total Submissions: 61.6K
 * Testcase Example:  '["w","wo","wor","worl","world"]'
 *
 * Given a list of strings words representing an English Dictionary, find the
 * longest word in words that can be built one character at a time by other
 * words in words.  If there is more than one possible answer, return the
 * longest word with the smallest lexicographical order.  If there is no
 * answer, return the empty string.
 * 
 * Example 1:
 * 
 * Input: 
 * words = ["w","wo","wor","worl", "world"]
 * Output: "world"
 * Explanation: 
 * The word "world" can be built one character at a time by "w", "wo", "wor",
 * and "worl".
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: 
 * words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
 * Output: "apple"
 * Explanation: 
 * Both "apply" and "apple" can be built from other words in the dictionary.
 * However, "apple" is lexicographically smaller than "apply".
 * 
 * 
 * 
 * Note:
 * All the strings in the input will only contain lowercase letters.
 * The length of words will be in the range [1, 1000].
 * The length of words[i] will be in the range [1, 30].
 * 
 */
class Solution {
public:
    vector<string> res;
    int longest;
    void callme(int level,string carry, vector<string>& words, unordered_map<int, vector<int> >& mm){
        if(level > longest){
            longest = level;
            res.clear();
            res.push_back(carry);
        }else if(level == longest){
            res.push_back(carry);
        }

        for(auto pos: mm[level]){
            if(words[pos].compare(0, level-1, carry) == 0)
                callme(level+1, words[pos], words, mm);
        }
    }

    string longestWord(vector<string>& words) {
        // res.clear();
        longest = -1;
        unordered_map<int, vector<int> > mm;
        
        for(int i = 0; i < words.size(); i++)
            mm[words[i].size()].push_back(i);
        
        callme(1,"", words, mm);

        if(res.size() == 0)
            cout<<"ErRoR";
        string ans = res[0];
        for(auto w:res)
            ans = min(ans, w);
        return ans;
    }
};
