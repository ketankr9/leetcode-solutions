/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 *
 * https://leetcode.com/problems/decode-string/description/
 *
 * algorithms
 * Medium (45.35%)
 * Likes:    1574
 * Dislikes: 90
 * Total Accepted:    110.9K
 * Total Submissions: 244.4K
 * Testcase Example:  '"3[a]2[bc]"'
 *
 * Given an encoded string, return its decoded string.
 * 
 * The encoding rule is: k[encoded_string], where the encoded_string inside the
 * square brackets is being repeated exactly k times. Note that k is guaranteed
 * to be a positive integer.
 * 
 * You may assume that the input string is always valid; No extra white spaces,
 * square brackets are well-formed, etc.
 * 
 * Furthermore, you may assume that the original data does not contain any
 * digits and that digits are only for those repeat numbers, k. For example,
 * there won't be input like 3a or 2[4].
 * 
 * Examples:
 * 
 * 
 * s = "3[a]2[bc]", return "aaabcbc".
 * s = "3[a2[c]]", return "accaccacc".
 * s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    bool isnum(char c){
        return c<='9' && c>='0';
    }
    string decodeString(string s) {
        stack<char> st;
        int i=0;
        int n = s.size();
        while(i<n){
            if(s[i] == ']'){
                string tmp = "";

                while(st.top()!='[')
                    tmp = st.top()+tmp, st.pop(); // remove alpha
                
                st.pop(); // remove '['
                
                string p = "";
                while(!st.empty() && isnum(st.top()))
                    p = st.top()+p, st.pop(); // remove num
                for(int k = stoi(p); k>0;k--)
                    for(auto c: tmp)
                        st.push(c);
            }else{
                st.push(s[i]);
            }
            i++;
        }
        string ans="";
        while(!st.empty()){
            ans = st.top()+ans;
            st.pop();
        }
        return ans;
    }
};

