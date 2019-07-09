/*
 * @lc app=leetcode id=60 lang=cpp
 *
 * [60] Permutation Sequence
 *
 * https://leetcode.com/problems/permutation-sequence/description/
 *
 * algorithms
 * Medium (33.44%)
 * Likes:    880
 * Dislikes: 230
 * Total Accepted:    142K
 * Total Submissions: 424.7K
 * Testcase Example:  '3\n3'
 *
 * The set [1,2,3,...,n] contains a total of n! unique permutations.
 * 
 * By listing and labeling all of the permutations in order, we get the
 * following sequence for n = 3:
 * 
 * 
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 * 
 * 
 * Given n and k, return the k^th permutation sequence.
 * 
 * Note:
 * 
 * 
 * Given n will be between 1 and 9 inclusive.
 * Given k will be between 1 and n! inclusive.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 3, k = 3
 * Output: "213"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 4, k = 9
 * Output: "2314"
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fact(int a){
        if(a<=1)    return 1;
        return a*fact(a-1);
    }

    string getPermutation(int n, int k) {
        vector<int> used;
        for(int p=1;p<=n;p++)
            used.push_back(p);
        string ans = "";
        int i=n-1;
        while(k>0){
            int ff = fact(i--);
            int x = k/ff;
            k -= x*ff;
            if(k == 0){
                ans = ans + to_string(used[x-1]);
                used.erase(used.begin()+x-1);
                reverse(used.begin(), used.end());
            }else{
                ans = ans + to_string(used[x]);//to_string(kth(x, used));
                used.erase(used.begin()+x);
            }
        }
        for(auto e: used)
            ans = ans + to_string(e);
        return ans;
    }
};

