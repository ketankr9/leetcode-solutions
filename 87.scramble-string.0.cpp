/*
 * @lc app=leetcode id=87 lang=cpp
 *
 * [87] Scramble String
 *
 * https://leetcode.com/problems/scramble-string/description/
 *
 * algorithms
 * Hard (31.94%)
 * Total Accepted:    93.5K
 * Total Submissions: 292.6K
 * Testcase Example:  '"great"\n"rgeat"'
 *
 * Given a string s1, we may represent it as a binary tree by partitioning it
 * to two non-empty substrings recursively.
 * 
 * Below is one possible representation of s1 = "great":
 * 
 * 
 * ⁠   great
 * ⁠  /    \
 * ⁠ gr    eat
 * ⁠/ \    /  \
 * g   r  e   at
 * ⁠          / \
 * ⁠         a   t
 * 
 * 
 * To scramble the string, we may choose any non-leaf node and swap its two
 * children.
 * 
 * For example, if we choose the node "gr" and swap its two children, it
 * produces a scrambled string "rgeat".
 * 
 * 
 * ⁠   rgeat
 * ⁠  /    \
 * ⁠ rg    eat
 * ⁠/ \    /  \
 * r   g  e   at
 * ⁠          / \
 * ⁠         a   t
 * 
 * 
 * We say that "rgeat" is a scrambled string of "great".
 * 
 * Similarly, if we continue to swap the children of nodes "eat" and "at", it
 * produces a scrambled string "rgtae".
 * 
 * 
 * ⁠   rgtae
 * ⁠  /    \
 * ⁠ rg    tae
 * ⁠/ \    /  \
 * r   g  ta  e
 * ⁠      / \
 * ⁠     t   a
 * 
 * 
 * We say that "rgtae" is a scrambled string of "great".
 * 
 * Given two strings s1 and s2 of the same length, determine if s2 is a
 * scrambled string of s1.
 * 
 * Example 1:
 * 
 * 
 * Input: s1 = "great", s2 = "rgeat"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s1 = "abcde", s2 = "caebd"
 * Output: false
 * 
 */
class Solution {
public:
    bool iszero(vector<int>& cnt){
        for(auto e: cnt)
            if(e!=0)    return false;
        return true;
    }
    bool isScramble(string s1, string s2) {
        // cout<<s1<<"."<<s2<<"\n";
       if(s1.size() != s2.size())   return false;
       if(s1 == s2) return true;
       int n = s1.size();
       if(n == 1)   return s1 == s2;
       if(n == 2)   return (s1[0] == s2[1] && s1[1]==s2[0]);
       vector<int> cnt(26, 0);
       bool ans = false;
       for(int i=0; i<n; i++){
           cnt[s1[i]-'a']++;
           cnt[s2[i]-'a']--;
           if(iszero(cnt) && i+1 != n)
            ans |= isScramble(s1.substr(0, i+1), s2.substr(0, i+1)) && isScramble(s1.substr(i+1), s2.substr(i+1));
           if(ans)  return true;
       }
       fill(cnt.begin(), cnt.end(), 0);
       reverse(s2.begin(), s2.end());
       if(s1 == s2) return true;
       for(int i=0; i<n; i++){
           cnt[s1[i]-'a']++;
           cnt[s2[i]-'a']--;
           if(iszero(cnt) && i+1 != n)
            ans |= isScramble(s1.substr(0, i+1), s2.substr(0, i+1)) && isScramble(s1.substr(i+1), s2.substr(i+1));
           if(ans)  return true;
       }
       return ans;
    }
};
