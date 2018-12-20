/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 *
 * https://leetcode.com/problems/count-primes/description/
 *
 * algorithms
 * Easy (27.51%)
 * Total Accepted:    196.6K
 * Total Submissions: 713.2K
 * Testcase Example:  '10'
 *
 * Count the number of prime numbers less than a non-negative number, n.
 * 
 * Example:
 * 
 * 
 * Input: 10
 * Output: 4
 * Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
 * 
 */
class Solution {
public:
    int countPrimes(int n) {
        if(n < 2)
            return 0;
        bool arr[n];
        fill_n(arr, n, true);

        for(int i=2; i<=sqrt(n);i++){
            for(int j = i*i; j < n; j += i ){
                arr[j] = false;
            }
        }
        int count = -2;
        for(auto s: arr)
            if(s)   count++;
        return count;
    }
};
