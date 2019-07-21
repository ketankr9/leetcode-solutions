/*
 * @lc app=leetcode id=537 lang=cpp
 *
 * [537] Complex Number Multiplication
 *
 * https://leetcode.com/problems/complex-number-multiplication/description/
 *
 * algorithms
 * Medium (65.80%)
 * Total Accepted:    37.8K
 * Total Submissions: 57.4K
 * Testcase Example:  '"1+1i"\n"1+1i"'
 *
 * 
 * Given two strings representing two complex numbers.
 * 
 * 
 * You need to return a string representing their multiplication. Note i2 = -1
 * according to the definition.
 * 
 * 
 * Example 1:
 * 
 * Input: "1+1i", "1+1i"
 * Output: "0+2i"
 * Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert
 * it to the form of 0+2i.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: "1+-1i", "1+-1i"
 * Output: "0+-2i"
 * Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you need convert
 * it to the form of 0+-2i.
 * 
 * 
 * 
 * Note:
 * 
 * The input strings will not have extra blank.
 * The input strings will be given in the form of a+bi, where the integer a and
 * b will both belong to the range of [-100, 100]. And the output should be
 * also in this form.
 * 
 * 
 */
class Solution {
public:
    pair<int, int> cleanme(string s){
        int a = 0, b = 0;
        bool aneg=false, bneg=false;
        aneg = s[0] == '-';
        int i = aneg;
        // cout<<s[i];
        while(s[i]!='+')
            a = a*10 + (int)s[i++]-'0';
        i++; // remove +
        bneg = s[i] == '-';
        i += bneg;

        // cout<<s[i];
        while(s[i]!='i')
            b = b*10 + ((int)s[i++]-'0');
        
        return make_pair(a*(aneg?-1:1), b*(bneg?-1:1));
    }
    string complexNumberMultiply(string a, string b) {
        pair<int, int> x = cleanme(a);
        pair<int, int> y = cleanme(b);

        // cout<<x.first<<" "<<x.second<<" ";
        // cout<<y.first<<" "<<y.second<<" ";
        
        int p = x.first*y.first - x.second*y.second;
        int q = x.first*y.second + x.second*y.first;
        
        string ans = "";

        ans += to_string(p)+"+"+to_string(q)+"i";
        return ans;
    }
};
