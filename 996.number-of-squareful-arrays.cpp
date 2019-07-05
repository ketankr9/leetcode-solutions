/*
 * @lc app=leetcode id=996 lang=cpp
 *
 * [996] Number of Squareful Arrays
 *
 * https://leetcode.com/problems/number-of-squareful-arrays/description/
 *
 * algorithms
 * Hard (47.64%)
 * Likes:    140
 * Dislikes: 12
 * Total Accepted:    5.9K
 * Total Submissions: 12.3K
 * Testcase Example:  '[1,17,8]'
 *
 * Given an array A of non-negative integers, the array is squareful if for
 * every pair of adjacent elements, their sum is a perfect square.
 * 
 * Return the number of permutations of A that are squareful.  Two permutations
 * A1 and A2 differ if and only if there is some index i such that A1[i] !=
 * A2[i].
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [1,17,8]
 * Output: 2
 * Explanation: 
 * [1,8,17] and [17,8,1] are the valid permutations.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [2,2,2]
 * Output: 1
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length <= 12
 * 0 <= A[i] <= 1e9
 * 
 */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> used;
    int ans;
    bool check(int n){
        int k = sqrt(n);
        return k*k == n;
    }
    void callme(int k, int n, int last, vector<int>& A){
        if(k == n){
            ans ++;
            return;
        }
        int i = 0;
        while(i<n){
            if(!used[i] && (k==0 || check(last+A[i]))){
                used[i] = true;
                callme(k+1, n, A[i], A);
                used[i] = false;
                while(i+1<n && A[i]==A[i+1])
                    i++;
            }
            i++;
        }
    }
    int numSquarefulPerms(vector<int>& A) {
        int n = A.size();
        ans = 0;
        used = vector<bool>(n, false);
        sort(A.begin(), A.end());
        callme(0, n, -1, A);
        return ans;
    }
};

