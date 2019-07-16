/*
 * @lc app=leetcode id=837 lang=cpp
 *
 * [837] New 21 Game
 *
 * https://leetcode.com/problems/new-21-game/description/
 *
 * algorithms
 * Medium (29.88%)
 * Total Accepted:    7.4K
 * Total Submissions: 23.8K
 * Testcase Example:  '10\n1\n10'
 *
 * Alice plays the following game, loosely based on the card game "21"solve .
 * 
 * Alice starts with 0 points, and draws numbers while she has less than K
 * points.  During each draw, she gains an integer number of points randomly
 * from the range [1, W], where W is an integer.  Each draw is independent and
 * the outcomes have equal probabilities.
 * 
 * Alice stops drawing numbers when she gets K or more points.  What is the
 * probability that she has N or less points?
 * 
 * Example 1:
 * 
 * 
 * Input: N = 10, K = 1, W = 10
 * Output: 1.00000
 * Explanation:  Alice gets a single card, then stops.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: N = 6, K = 1, W = 10
 * Output: 0.60000
 * Explanation:  Alice gets a single card, then stops.
 * In 6 out of W = 10 possibilities, she is at or below N = 6 points.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: N = 21, K = 17, W = 10
 * Output: 0.73278
 * 
 * Note:
 * 
 * 
 * 0 <= K <= N <= 10000
 * 1 <= W <= 10000
 * Answers will be accepted as correct if they are within 10^-5 of the correct
 * answer.
 * The judging time limit has been reduced for this question.
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double new21Game(int N, int K, int W) {
        // max attainable point is K+W-1
        if(K+W-1<=N)    return (double)1;

        vector<double> vec(K+W, 0);
        // ANOTHER APPROACH WHICH ISN'T WORKING
        // for(int i=0; i<K+W; i++){
        //     for(int j=1; j<=W && i>=j; j++){
        //         if(i-j<K)
        //             vec[i] += vec[i-j];
        //     }
        //     if(i<=W && i>0)
        //         vec[i]++;
        // }
        // for(auto e: vec)
        //     cout<<e<<" ";
        // long long num = 0, deno = 0;
        // for(int i=K; i<K+W; i++){
        //     num += (long long)vec[i];
        //     if(i<=N)
        //         deno += (long long)vec[i];
        // }
        // return (double)deno/(double)num;
        
        for(int i=K; i<=min(K+W-1, N); i++) vec[i] = 1;
        double sum = min(K+W-1, N)-K+1-vec[K];
        for(int i=K-1; i>=0; i--){
            sum += vec[i+1];
            vec[i] = sum/W;
            sum -= vec[i+W];
        }
        return vec[0];

    }   
};
