/*
 * @lc app=leetcode id=792 lang=cpp
 *
 * [792] Number of Matching Subsequences
 *
 * https://leetcode.com/problems/number-of-matching-subsequences/description/
 *
 * algorithms
 * Medium (43.78%)
 * Likes:    507
 * Dislikes: 40
 * Total Accepted:    22.5K
 * Total Submissions: 51.3K
 * Testcase Example:  '"abcde"\n["a","bb","acd","ace"]'
 *
 * Given string S and a dictionary of words words, find the number of words[i]
 * that is a subsequence of S.
 * 
 * 
 * Example :
 * Input: 
 * S = "abcde"
 * words = ["a", "bb", "acd", "ace"]
 * Output: 3
 * Explanation: There are three words in words that are a subsequence of S:
 * "a", "acd", "ace".
 * 
 * 
 * Note:
 * 
 * 
 * All words in words and S will only consists of lowercase letters.
 * The length of S will be in the range of [1, 50000].
 * The length of words will be in the range of [1, 5000].
 * The length of words[i] will be in the range of [1, 50].
 * 
 * 
 */
class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        int cnt = 0;
        int ns = S.size();
        unordered_set<string> ss;
        for(auto word: words){
            if(ss.count(word)!=0){
                cnt++;
                continue;
            }
            int i = 0, j = 0;
            int nw = word.size();
            while(i<ns && j<nw){
                if(word[j] == S[i])
                    i++, j++;
                else
                    i++;
            }
            if(j == nw){
                ss.insert(word);
                cnt++;
            }
        }
        return cnt;

    }
};

