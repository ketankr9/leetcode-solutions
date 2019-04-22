/*
 * @lc app=leetcode id=357 lang=cpp
 *
 * [357] Count Numbers with Unique Digits
 *
 * https://leetcode.com/problems/count-numbers-with-unique-digits/description/
 *
 * algorithms
 * Medium (46.60%)
 * Total Accepted:    60.3K
 * Total Submissions: 128.8K
 * Testcase Example:  '2'
 *
 * Given a non-negative integer n, count all numbers with unique digits, x,
 * where 0 ≤ x < 10n.
 * 
 * 
 * Example:
 * 
 * 
 * Input: 2
 * Output: 91 
 * Explanation: The answer should be the total numbers in the range of 0 ≤ x <
 * 100, 
 * excluding 11,22,33,44,55,66,77,88,99
 * 
 * 
 */
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0)
            return 1;
        if(n>10)
            n = 10;
        int arr[max(3, n+1)];
        arr[0] = 0;
        arr[1] = 10;
        arr[2] = 9*9;
        for(int i=3;i<=n;i++){
            arr[i] = arr[i-1]*(11-i);
        }
        int ans = 0;
        for(int i=0;i<=n;i++)
            ans += arr[i];
        return ans;
    }
};
