/*
 * @lc app=leetcode id=935 lang=cpp
 *
 * [935] Knight Dialer
 *
 * https://leetcode.com/problems/knight-dialer/description/
 *
 * algorithms
 * Medium (41.09%)
 * Likes:    229
 * Dislikes: 67
 * Total Accepted:    13K
 * Total Submissions: 31.7K
 * Testcase Example:  '1'
 *
 * A chess knight can move as indicated in the chess diagram below:
 * 
 * .           
 * 
 * 
 * 
 * This time, we place our chess knight on any numbered key of a phone pad
 * (indicated above), and the knight makes N-1 hops.  Each hop must be from one
 * key to another numbered key.
 * 
 * Each time it lands on a key (including the initial placement of the knight),
 * it presses the number of that key, pressing N digits total.
 * 
 * How many distinct numbers can you dial in this manner?
 * 
 * Since the answer may be large, output the answer modulo 10^9 + 7.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 1
 * Output: 10
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 2
 * Output: 20
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 3
 * Output: 46
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= N <= 5000
 * 
 * 
 * 
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int knightDialer(int N) {
        long long M = 1000000000+7;
        long long a,b,c,d,x; 
        a=b=c=d=x=1;
        for(int k=1; k<N; k++){
            long long A,B,C,D,X;
            A = (b+c)%M;
            B = (2*a)%M;
            C = (2*a%M+d)%M;
            D = 2*c%M;
            X = 0;
            a = A, b = B, c = C, d = D, x = X;
        }
        long long ret = 4*a%M;
        ret = (ret + 2*b%M)%M;
        ret = (ret + 2*c%M)%M;
        ret = (ret+d)%M;
        ret = (ret + x)%M;

        return ret;
    }
};

