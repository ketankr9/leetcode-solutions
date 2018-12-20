/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 *
 * https://leetcode.com/problems/roman-to-integer/description/
 *
 * algorithms
 * Easy (50.45%)
 * Total Accepted:    322.8K
 * Total Submissions: 639.1K
 * Testcase Example:  '"III"'
 *
 * Roman numerals are represented by seven different symbols: I, V, X, L, C, D
 * and M.
 * 
 * 
 * Symbol       Value
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 * 
 * For example, two is written as II in Roman numeral, just two one's added
 * together. Twelve is written as, XII, which is simply X + II. The number
 * twenty seven is written as XXVII, which is XX + V + II.
 * 
 * Roman numerals are usually written largest to smallest from left to right.
 * However, the numeral for four is not IIII. Instead, the number four is
 * written as IV. Because the one is before the five we subtract it making
 * four. The same principle applies to the number nine, which is written as IX.
 * There are six instances where subtraction is used:
 * 
 * 
 * I can be placed before V (5) and X (10) to make 4 and 9. 
 * X can be placed before L (50) and C (100) to make 40 and 90. 
 * C can be placed before D (500) and M (1000) to make 400 and 900.
 * 
 * 
 * Given a roman numeral, convert it to an integer. Input is guaranteed to be
 * within the range from 1 to 3999.
 * 
 * Example 1:
 * 
 * 
 * Input: "III"
 * Output: 3
 * 
 * Example 2:
 * 
 * 
 * Input: "IV"
 * Output: 4
 * 
 * Example 3:
 * 
 * 
 * Input: "IX"
 * Output: 9
 * 
 * Example 4:
 * 
 * 
 * Input: "LVIII"
 * Output: 58
 * Explanation: L = 50, V= 5, III = 3.
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: "MCMXCIV"
 * Output: 1994
 * Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 * 
 */
static int speedup=[](){ ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
    int val(char c){
        int v = 0;
        switch (c)
        {
            case 'I':
                v = 1;
                break;
            case 'V':
                v = 5;
                break;
            case 'X':
                v = 10;
                break;
            case 'L':
                v = 50;
                break;
            case 'C':
                v = 100;
                break;
            case 'D':
                v = 500;
                break;
            case 'M':
                v = 1000;
                break;       
            default:
                break;
        }
        return v;
    }

    int romanToInt(string s) {
        int ans = 0;
        int i=0;
        int N = s.size();
        while(i<N-1){
            if(val(s[i]) < val(s[i+1])){ //check I, X, C;
                ans += val(s[i+1]) - val(s[i]), i++;
            }else{
                ans += val(s[i]);
            }
            i++;
        }
        if(i == N-1)
            ans += val(s[N-1]);
        return ans;
    }
};
