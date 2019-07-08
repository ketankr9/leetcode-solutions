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
    long long M;
    bool check(int x, int y){
        if(x == 3 && y != 1)
            return false;
        if(x >=0 && x<4 && y>=0 && y<3)
            return true;
        return false;
    }
    long long addme(int x, int y, vector<vector<long long> > ans){
        vector<int> two = {2, -2};
        vector<int> one = {1, -1};
        long long summ = 0;
        for(auto t: two)
            for(auto o: one){
                if(check(x+t, y+o))
                    summ = (summ + ans[x+t][y+o]%M)%M;
                if(check(x+o, y+t))
                    summ = (summ + ans[x+o][y+t]%M)%M;
            }
        return summ;
    }
    int knightDialer(int N) {
        vector<vector<long long> > ans(4, vector<long long>(3, 1));
        M = 1000000000+7;
        for(int k=1; k<N; k++){
            vector<vector<long long> > tp(4, vector<long long>(3, 0));
            tp[0][0] = tp[0][2] = tp[2][0] = tp[2][2] = (ans[2][1] + ans[1][2])%M;
            tp[0][1] = tp[2][1] = (ans[2][0]*2)%M;
            tp[1][0] = tp[1][2] = (ans[0][0]*2 + ans[3][1])%M;
            tp[3][1] = (ans[1][0] + ans[1][2])%M;
            tp[1][1] = 0;
            ans = tp;
        }
        long long ret = 0;
        for(int i=0; i<4; i++)
                for(int j=0; j<3; j++){
                    if(i == 3 && j != 1)    continue;
                    ret = (ret + ans[i][j])%M;
                }
        return ret;
    }
};

