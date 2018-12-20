/*
 * @lc app=leetcode id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
 *
 * https://leetcode.com/problems/reverse-vowels-of-a-string/description/
 *
 * algorithms
 * Easy (40.28%)
 * Total Accepted:    133.6K
 * Total Submissions: 331.3K
 * Testcase Example:  '"hello"'
 *
 * Write a function that takes a string as input and reverse only the vowels of
 * a string.
 * 
 * Example 1:
 * 
 * 
 * Input: "hello"
 * Output: "holle"
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "leetcode"
 * Output: "leotcede"
 * 
 * 
 * Note:
 * The vowels does not include the letter "y".
 * 
 * 
 * 
 */
class Solution {
public:
    bool isvowel(char c){
        if(c == 'a' ||c == 'e' ||c == 'i' ||c == 'o' ||c == 'u')
            return true;
        if(c == 'A' ||c == 'E' ||c == 'I' ||c == 'O' ||c == 'U')
            return true;
        
        return false;
    }
    string reverseVowels(string S) {
     string s = S;
     int i = 0,j = s.size()-1;
        while(i<j){
            if(!isvowel(s[i])){
                i++; continue;
            }
            if(!isvowel(s[j])){
                j--; continue;
            }
            // ith and jth is vowel.
            swap(s[i], s[j]);
            i++;
            j--;
        }
        return s;
    }
};
