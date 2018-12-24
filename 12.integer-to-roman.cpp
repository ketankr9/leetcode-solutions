/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 *
 * https://leetcode.com/problems/integer-to-roman/description/
 *
 * algorithms
 * Medium (48.80%)
 * Total Accepted:    186.9K
 * Total Submissions: 382.7K
 * Testcase Example:  '3'
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
 * Given an integer, convert it to a roman numeral. Input is guaranteed to be
 * within the range from 1 to 3999.
 * 
 * Example 1:
 * 
 * 
 * Input: 3
 * Output: "III"
 * 
 * Example 2:
 * 
 * 
 * Input: 4
 * Output: "IV"
 * 
 * Example 3:
 * 
 * 
 * Input: 9
 * Output: "IX"
 * 
 * Example 4:
 * 
 * 
 * Input: 58
 * Output: "LVIII"
 * Explanation: L = 50, V = 5, III = 3.
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: 1994
 * Output: "MCMXCIV"
 * Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 * 
 */
class Solution {
public:
    string intToRoman(int num) {
        string st = "";
        // M 1000
        
        int temp = num/1000;
        while(temp--)
            st += 'M';
        num %= 1000;
        // C 100
        
        temp = num/100;
        if(temp == 9){
            st += "CM";
            num -= 900;
        }else if(temp == 4){
            st += "CD";
            num -= 400;
        }else if(temp >= 5){ // D 500
            st += 'D';
            num -= 500;
        }
        temp = num/100;
        while(temp--)
                st += 'C';
        num %= 100;
        // X 10
        // L 50
        
        
        temp = num/10;
        if(temp == 4){
            st += "XL";
            num -= 40;
        }else if(temp == 9){
            st += "XC";
            num -= 90;
        }else if(temp >= 5){
            st += 'L';
            num -= 50;
        }
        temp = num/10;
        while(temp--)
            st += 'X';
        num %= 10;
        
        // V 5
        temp = num;
        if(num == 4){
            st += "IV";
            num -= 4;
        }else if(num == 9){
            st += "IX";
            num -= 9;
        }
        if(num >= 5){
            st += 'V';
            num -= 5;
        }
        while(num--)
            st += 'I';
        // I 1
        return st;
    }
};
