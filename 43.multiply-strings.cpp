/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 *
 * https://leetcode.com/problems/multiply-strings/description/
 *
 * algorithms
 * Medium (29.26%)
 * Total Accepted:    171K
 * Total Submissions: 583.2K
 * Testcase Example:  '"2"\n"3"'
 *
 * Given two non-negative integers num1 and num2 represented as strings, return
 * the product of num1 and num2, also represented as a string.
 * 
 * Example 1:
 * 
 * 
 * Input: num1 = "2", num2 = "3"
 * Output: "6"
 * 
 * Example 2:
 * 
 * 
 * Input: num1 = "123", num2 = "456"
 * Output: "56088"
 * 
 * 
 * Note:
 * 
 * 
 * The length of both num1 and num2 is < 110.
 * Both num1 and num2 contain only digits 0-9.
 * Both num1 and num2 do not contain any leading zero, except the number 0
 * itself.
 * You must not use any built-in BigInteger library or convert the inputs to
 * integer directly.
 * 
 * 
 */
class Solution {
public:
    string multiply(string num1, string num2){
        if(num1=="0" || num2=="0")
            return "0";
        int i=num1.size()-1;
        string ans = "";
        for(int j=(int)num2.size()-1;j>=0;j--){
            string temp = "";
            int tt=1;
            while(tt<(int)num2.size()-j){
                temp += '0'; tt++;
            }
            ans = addme(ans, multiplyOne(num1, num2[j])+temp);
        }
        return ans;
    }
    string addme(string num1, string num2){
        int i=num1.size()-1;
        int j=num2.size()-1;
        int carry = 0;
        int prod;
        int val;
        string ans = "";
        while(i>=0 && j>=0){
            prod = carry + (int)(num1[i]-'0') + (int)(num2[j]-'0');
            carry = prod/10;
            val = prod%10;
            ans = (char)('0'+val) + ans;
            i--;j--;
        }
        while(i>=0){
            prod = carry + (int)(num1[i]-'0');
            carry = prod/10;
            val = prod%10;
            ans = (char)('0'+val) + ans;
            i--;
        }
        while(j>=0){
            prod = carry + (int)(num2[j]-'0');
            carry = prod/10;
            val = prod%10;
            ans = (char)('0'+val) + ans;
            j--;
        }
        if(carry)   ans = (char)(carry + '0') + ans;
        return ans;
    }
    string multiplyOne(string st, char c){
        string ans = "";
        int i = st.size()-1;
        int prod;
        int val;
        int carry = 0;
        while(i>=0){
            prod = carry + (int)(st[i]-'0')*(int)(c-'0');
            carry = prod/10;
            val = prod%10;
            ans = (char)('0'+val) + ans;
            i--;
        }
        if(carry)   ans = (char)(carry + '0') + ans;
        return ans;
    }

    string multiplySingle(string num1, string num2) {
        int i=num1.size()-1;
        int j=num2.size()-1;
        int carry = 0;
        string ans = "";
        int prod;
        int val;
        while(i>=0 && j>=0){
            prod = carry + (int)(num1[i]-'0')*(int)(num2[j]-'0');
            carry = prod/10;
            val = prod%10;
            ans = (char)('0'+val) + ans;
            i--;j--;
        }

        while(i>=0){
            prod = carry + (int)(num1[i]-'0');
            carry = prod/10;
            val = prod%10;
            ans = (char)('0'+val) + ans;
            i--;
        }
        while(j>=0){
            prod = carry + (int)(num2[j]-'0');
            carry = prod/10;
            val = prod%10;
            ans = (char)('0'+val) + ans;
            j--;
        }
        if(carry)   ans = (char)(carry + '0') + ans;
        return ans;
    }
};
