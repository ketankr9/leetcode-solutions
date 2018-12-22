/*
 * @lc app=leetcode id=788 lang=cpp
 *
 * [788] Rotated Digits
 *
 * https://leetcode.com/problems/rotated-digits/description/
 *
 * algorithms
 * Easy (51.87%)
 * Total Accepted:    19K
 * Total Submissions: 36.7K
 * Testcase Example:  '10'
 *
 * X is a good number if after rotating each digit individually by 180 degrees,
 * we get a valid number that is different from X.  Each digit must be rotated
 * - we cannot choose to leave it alone.
 * 
 * A number is valid if each digit remains a digit after rotation. 0, 1, and 8
 * rotate to themselves; 2 and 5 rotate to each other; 6 and 9 rotate to each
 * other, and the rest of the numbers do not rotate to any other number and
 * become invalid.
 * 
 * Now given a positive number N, how many numbers X from 1 to N are good?
 * 
 * 
 * Example:
 * Input: 10
 * Output: 4
 * Explanation: 
 * There are four good numbers in the range [1, 10] : 2, 5, 6, 9.
 * Note that 1 and 10 are not good numbers, since they remain unchanged after
 * rotating.
 * 
 * 
 * Note:
 * 
 * 
 * N  will be in range [1, 10000].
 * 
 * 
 */
class Solution {
public:
    bool countme(int n){
        bool c2569 = false;
        while(n>0){
            int last = n%10;
            if(last == 3 || last == 4 || last == 7)
                return false;
            if(last == 2 || last == 5 || last == 6 || last == 9)
                c2569 = true;
            n /= 10;
        }
        return c2569;
    }
    int rotatedDigits(int N) {
    int i = 1;
    int count = 0;
    while( i <= N){
        if(countme(i))
            count++;
        i++;
        }   
    return count;
    }
};
