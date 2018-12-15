/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 *
 * https://leetcode.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (36.78%)
 * Total Accepted:    254.5K
 * Total Submissions: 690.9K
 * Testcase Example:  '"11"\n"1"'
 *
 * Given two binary strings, return their sum (also a binary string).
 *
 * The input strings are both non-empty and contains only characters 1 or 0.
 *
 * Example 1:
 *
 *
 * Input: a = "11", b = "1"
 * Output: "100"
 *
 * Example 2:
 *
 *
 * Input: a = "1010", b = "1011"
 * Output: "10101"
 *
 */
class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size()-1;
        int j = b.size()-1;
        int carry = 0;
        int num;
        string res;
        while (i>=0 && j>=0) {
          int ss = carry + (int)(a[i]-'0') + (int)(b[j]-'0');
          num = ss%2;
          carry = ss/2;
          res = (char)('0'+ num) + res;
          i--; j--;
        }
        while(i>=0){
          int ss = carry + a[i]-'0';
          num = ss%2;
          carry = ss/2;
          res = (char)('0'+num) + res;
          i--;
        }
        while(j>=0){
          int ss = carry + b[j]-'0';
          num = ss%2;
          carry = ss/2;
          res = (char)('0'+num) + res;
          j--;
        }
        if(carry) res = '1' + res;
        return res;

    }
};
