/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 *
 * https://leetcode.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (31.38%)
 * Total Accepted:    254.2K
 * Total Submissions: 809.9K
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * Given a string S and a string T, find the minimum window in S which will
 * contain all the characters in T in complexity O(n).
 * 
 * Example:
 * 
 * 
 * Input: S = "ADOBECODEBANC", T = "ABC"
 * Output: "BANC"
 * 
 * 
 * Note:
 * 
 * 
 * If there is no such window in S that covers all characters in T, return the
 * empty string "".
 * If there is such window, you are guaranteed that there will always be only
 * one unique minimum window in S.
 * 
 * 
 */
class Solution {
public:
    string minWindow(string s, string t) {
        int prev = 0;
        unordered_map<char, int> mm;
        int ns = s.size();
        
        for(auto e: t)
            mm[e]++;
        
        int cnt = 0;

        int ans = INT_MAX;
        int pos = -1;
        for(int i=0; i<ns; i++){
            if(mm.find(s[i])!=mm.end() && mm[s[i]]-- > 0)
                cnt++;
            
            while(prev<i){
                if(mm.find(s[prev]) == mm.end())
                    prev++;
                else if(mm[s[prev]]<0)
                    mm[s[prev++]]++;
                else
                    break;
            }
            
            if(cnt == (int)t.size() && ans > (i-prev + 1))
                pos = prev, ans = i-prev + 1;

        }
        if(pos == -1 || ans > (int)s.size())
            return "";
        return s.substr(pos, ans);
    }
};
