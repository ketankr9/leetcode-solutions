/*
 * @lc app=leetcode id=796 lang=cpp
 *
 * [796] Rotate String
 *
 * https://leetcode.com/problems/rotate-string/description/
 *
 * algorithms
 * Easy (49.06%)
 * Likes:    411
 * Dislikes: 38
 * Total Accepted:    42.4K
 * Total Submissions: 86.5K
 * Testcase Example:  '"abcde"\n"cdeab"'
 *
 * We are given two strings, A and B.
 * 
 * A shift on A consists of taking string A and moving the leftmost character
 * to the rightmost position. For example, if A = 'abcde', then it will be
 * 'bcdea' after one shift on A. Return True if and only if A can become B
 * after some number of shifts on A.
 * 
 * 
 * Example 1:
 * Input: A = 'abcde', B = 'cdeab'
 * Output: true
 * 
 * Example 2:
 * Input: A = 'abcde', B = 'abced'
 * Output: false
 * 
 * 
 * Note:
 * 
 * 
 * A and B will have length at most 100.
 * 
 * 
 */
class Solution {
public:
    bool rotateString(string A, string B) {
        if(A.size()!=B.size())
            return false;
        int n = A.size();
        if(n == 0)  return true;
        for(int shift=0; shift<n; shift++){
            bool flag = true;
            for(int i=0; i<n; i++)
                if(A[i]!=B[(i+shift)%n]){
                    flag = false;
                    break;
                }
            if(flag)
                return true;
        }
        return false;
    }
};

