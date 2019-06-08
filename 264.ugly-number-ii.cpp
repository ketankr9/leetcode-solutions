/*
 * @lc app=leetcode id=264 lang=cpp
 *
 * [264] Ugly Number II
 *
 * https://leetcode.com/problems/ugly-number-ii/description/
 *
 * algorithms
 * Medium (35.55%)
 * Total Accepted:    104.9K
 * Total Submissions: 288K
 * Testcase Example:  '10'
 *
 * Write a program to find the n-th ugly number.
 * 
 * Ugly numbers are positive numbers whose prime factors only include 2, 3,
 * 5. 
 * 
 * Example:
 * 
 * 
 * Input: n = 10
 * Output: 12
 * Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10
 * ugly numbers.
 * 
 * Note:  
 * 
 * 
 * 1 is typically treated as an ugly number.
 * n does not exceed 1690.
 * 
 */
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        int i=0, j=0, k=0;
        if(n == 1)  return 1;
        vector<long> vec(1, 1);

        for(int z=2; z<=n; z++){
            int m = min(vec[i]*2, min(vec[j]*3, vec[k]*5) );
            if(z == n)  return m;
            vec.push_back(m);
            if(m == vec[i]*2)   i++;
            if(m == vec[j]*3)   j++;
            if(m == vec[k]*5)   k++;
        }
        return -1;
    }
};
