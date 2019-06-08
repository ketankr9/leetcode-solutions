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
        priority_queue<long long, vector<long long>, greater<long long> > pq;
        pq.push(1);
        long long f;
        unordered_set<int> ss;
        ss.insert(1);
        for(int i=0; i<n; i++){
            f = pq.top(); pq.pop();
            while(!pq.empty() && ss.count(f)){
                f = pq.top();
                pq.pop();
            }
            ss.insert(f);
            if(!ss.count(f*2)) pq.push(f*2);
            if(!ss.count(f*3)) pq.push(f*3);
            if(!ss.count(f*5)) pq.push(f*5);
        }
        return f;
    }
};
