/*
 * @lc app=leetcode id=967 lang=cpp
 *
 * [967] Numbers With Same Consecutive Differences
 *
 * https://leetcode.com/problems/numbers-with-same-consecutive-differences/description/
 *
 * algorithms
 * Medium (37.15%)
 * Total Accepted:    7.6K
 * Total Submissions: 20.4K
 * Testcase Example:  '3\n7'
 *
 * Return all non-negative integers of length N such that the absolute
 * difference between every two consecutive digits is K.
 * 
 * Note that every number in the answer must not have leading zeros except for
 * the number 0 itself. For example, 01 has one leading zero and is invalid,
 * but 0 is valid.
 * 
 * You may return the answer in any order.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: N = 3, K = 7
 * Output: [181,292,707,818,929]
 * Explanation: Note that 070 is not a valid number, because it has leading
 * zeroes.
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: N = 2, K = 1
 * Output: [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= N <= 9
 * 0 <= K <= 9
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> ans;
    void callme(int c, int N, int K, int cur){
        if(c == N){
            ans.push_back(cur);
            return;
        }
        int next1 = (cur%10)+K, next2 = (cur%10)-K;
        if(next1<10)
            callme(c+1, N, K, cur*10+next1);
        if(next2>=0 && next2!=next1)
            callme(c+1, N, K, cur*10+next2);
    }
    vector<int> numsSameConsecDiff(int N, int K) {
        ans.clear();
        for(int i=N==1?0:1; i<=9; i++)
            callme(1, N, K, i);
        return ans;
    }
};
