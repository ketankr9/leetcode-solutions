/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 *
 * https://leetcode.com/problems/palindrome-partitioning/description/
 *
 * algorithms
 * Medium (41.51%)
 * Likes:    969
 * Dislikes: 39
 * Total Accepted:    169.6K
 * Total Submissions: 408.5K
 * Testcase Example:  '"aab"'
 *
 * Given a string s, partition s such that every substring of the partition is
 * a palindrome.
 * 
 * Return all possible palindrome partitioning of s.
 * 
 * Example:
 * 
 * 
 * Input: "aab"
 * Output:
 * [
 * ⁠ ["aa","b"],
 * ⁠ ["a","a","b"]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<string> local;
    vector<vector<string>> ans;
    bool ispali(const string &s){
        int n = s.size();
        for(int i=0; i<=n/2; i++)
            if(s[i]!=s[n-i-1])
                return false;
        return true;
    }
    void callme(int i, string& s){
        if(i==(int)s.size()){
            ans.push_back(local);
            return;
        }

        for(int k=1; k<=(int)s.size()-i; k++){
            if(ispali(s.substr(i, k))){
                local.push_back(s.substr(i, k));
                callme(i+k, s);
                local.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        ans.clear();
        local.clear();
        callme(0, s);
        return ans;
    }
};

