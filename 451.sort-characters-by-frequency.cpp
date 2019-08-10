/*
 * @lc app=leetcode id=451 lang=cpp
 *
 * [451] Sort Characters By Frequency
 *
 * https://leetcode.com/problems/sort-characters-by-frequency/description/
 *
 * algorithms
 * Medium (56.52%)
 * Likes:    765
 * Dislikes: 67
 * Total Accepted:    99.4K
 * Total Submissions: 175.8K
 * Testcase Example:  '"tree"'
 *
 * Given a string, sort it in decreasing order based on the frequency of
 * characters.
 * 
 * Example 1:
 * 
 * Input:
 * "tree"
 * 
 * Output:
 * "eert"
 * 
 * Explanation:
 * 'e' appears twice while 'r' and 't' both appear once.
 * So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid
 * answer.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:
 * "cccaaa"
 * 
 * Output:
 * "cccaaa"
 * 
 * Explanation:
 * Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
 * Note that "cacaca" is incorrect, as the same characters must be together.
 * 
 * 
 * 
 * Example 3:
 * 
 * Input:
 * "Aabb"
 * 
 * Output:
 * "bbAa"
 * 
 * Explanation:
 * "bbaA" is also a valid answer, but "Aabb" is incorrect.
 * Note that 'A' and 'a' are treated as two different characters.
 * 
 * 
 */
class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int, int>> cntc;
        
        for(int i=0; i<128; i++)
            cntc.push_back(make_pair(0, i));

        for(auto e: s)
            cntc[e-' '].first++;
        string ans = "";
        auto comp = [](const pair<int, int>& a, const pair<int, int>& b){return a.first>b.first;};
        sort(cntc.begin(), cntc.end(), comp);
        
        for(int i=0; i<128; i++)
            for(int c=0; c<cntc[i].first; c++)
                ans += ' '+cntc[i].second;
        return ans;
    }
};

