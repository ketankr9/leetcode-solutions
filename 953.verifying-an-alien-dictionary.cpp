/*
 * @lc app=leetcode id=953 lang=cpp
 *
 * [953] Verifying an Alien Dictionary
 *
 * https://leetcode.com/problems/verifying-an-alien-dictionary/description/
 *
 * algorithms
 * Easy (59.32%)
 * Total Accepted:    4.5K
 * Total Submissions: 7.6K
 * Testcase Example:  '["hello","leetcode"]\n"hlabcdefgijkmnopqrstuvwxyz"'
 *
 * In an alien language, surprisingly they also use english lowercase letters,
 * but possibly in a different order. The order of the alphabet is some
 * permutation of lowercase letters.
 *
 * Given a sequence of words written in the alien language, and the order of
 * the alphabet, return true if and only if the given words are sorted
 * lexicographicaly in this alien language.
 *
 *
 *
 *
 * Example 1:
 *
 *
 * Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
 * Output: true
 * Explanation: As 'h' comes before 'l' in this language, then the sequence is
 * sorted.
 *
 *
 *
 * Example 2:
 *
 *
 * Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
 * Output: false
 * Explanation: As 'd' comes after 'l' in this language, then words[0] >
 * words[1], hence the sequence is unsorted.
 *
 *
 *
 * Example 3:
 *
 *
 * Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
 * Output: false
 * Explanation: The first three characters "app" match, and the second string
 * is shorter (in size.) According to lexicographical rules "apple" > "app",
 * because 'l' > '∅', where '∅' is defined as the blank character which is less
 * than any other character (More info).
 *
 *
 *
 *
 * Note:
 *
 *
 * 1 <= words.length <= 100
 * 1 <= words[i].length <= 20
 * order.length == 26
 * All characters in words[i] and order are english lowercase letters.
 *
 *
 *
 *
 *
 */
class Solution {
public:
    unordered_map<char, int> mm;
    bool valid(string x, string y){
      bool status = false;
      int i = 0;
      while(i < (int)min(x.size(), y.size()) && mm[x[i]] == mm[y[i]])
        i++;
      if( i == (int)x.size() || i == (int)y.size())
        return x.size() <= y.size();
      return mm[x[i]] < mm[y[i]]; 
    }

    bool isAlienSorted(vector<string>& words, string order) {
        int N = words.size();

        for(int i=0;i<(int)order.size();i++)
          mm[order[i]] = i;

        for(int i=0;i<N-1;i++){
          if(!valid(words[i], words[i+1]))
            return false;
        }
        return true;
    }
};
