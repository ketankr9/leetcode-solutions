/*
 * @lc app=leetcode id=415 lang=cpp
 *
 * [415] Add Strings
 *
 * https://leetcode.com/problems/add-strings/description/
 *
 * algorithms
 * Easy (42.37%)
 * Total Accepted:    77.2K
 * Total Submissions: 181.8K
 * Testcase Example:  '"0"\n"0"'
 *
 * Given two non-negative integers num1 and num2 represented as string, return
 * the sum of num1 and num2.
 * 
 * Note:
 * 
 * The length of both num1 and num2 is < 5100.
 * Both num1 and num2 contains only digits 0-9.
 * Both num1 and num2 does not contain any leading zero.
 * You must not use any built-in BigInteger library or convert the inputs to
 * integer directly.
 * 
 * 
 */
class Solution {
public:
    string addStrings(string num1, string num2) {
        int N1 = num1.size();
        int N2 = num2.size();
        string ans = "";
        int carry = 0, i = N1-1, j = N2-1;;
        while(i>=0 || j>=0 || carry){
            int summ = carry;
            if(i>=0){
                summ += num1[i] - '0';
                i--;
            }
            if(j>=0){
                summ += num2[j]-'0';
                j--;
            }
            carry = summ/10;
            ans = (char)('0' + summ%10) + ans;
        }
        return ans;
    }
};
