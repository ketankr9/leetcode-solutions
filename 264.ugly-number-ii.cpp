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
        vector<long> l2(1, 2);
        vector<long> l3(1, 3);
        vector<long> l5(1, 5);
        for(int z=2; z<=n; z++){
            if(l2[i] < l3[j] && l2[i] < l5[k]){
                if(z == n)  return l2[i];
                l2.push_back(l2[i]*2);
                l3.push_back(l2[i]*3);
                l5.push_back(l2[i]*5);
                i++;
            }else if(l3[j] < l2[i] && l3[j] < l5[k]){
                if(z == n)  return l3[j];
                l3.push_back(l3[j]*3);
                l5.push_back(l3[j]*5);
                j++;
            }else if(l5[k] < l3[j] && l5[k] < l2[i]){
                if(z == n)  return l5[k];
                l5.push_back(l5[k]*5);
                k++;
            }else{
                cout<<"erroR";
            }
        }
        return -1;
    }
};
