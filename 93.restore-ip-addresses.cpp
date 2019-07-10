/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 *
 * https://leetcode.com/problems/restore-ip-addresses/description/
 *
 * algorithms
 * Medium (31.83%)
 * Likes:    695
 * Dislikes: 289
 * Total Accepted:    144.1K
 * Total Submissions: 452.7K
 * Testcase Example:  '"25525511135"'
 *
 * Given a string containing only digits, restore it by returning all possible
 * valid IP address combinations.
 * 
 * Example:
 * 
 * 
 * Input: "25525511135"
 * Output: ["255.255.11.135", "255.255.111.35"]
 * 
 * 
 */
class Solution {
public:
    vector<string> ans;
    void callme(string st, int i, int dot, const string &s){
        if(i == (int)s.size() && dot == 4){
            ans.push_back(st.substr(1));
            return;
        }
        if(i == (int)s.size() || dot == 4){
            return;
        }

        if(i+1<=(int)s.size())
        callme(st+"."+s.substr(i, 1), i+1, dot+1, s);
        if(i+2<=(int)s.size() && s[i]!='0')
        callme(st+"."+s.substr(i, 2), i+2, dot+1, s);
        if(i+3<=(int)s.size() && s[i]!='0' && stoi(s.substr(i, 3))<256)
        callme(st+"."+s.substr(i, 3), i+3, dot+1, s);
    }
    vector<string> restoreIpAddresses(string s) {
        ans.clear();
        callme("",0, 0, s);
        return ans;
    }
};

