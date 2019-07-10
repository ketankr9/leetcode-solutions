/*
 * @lc app=leetcode id=397 lang=cpp
 *
 * [397] Integer Replacement
 *
 * https://leetcode.com/problems/integer-replacement/description/
 *
 * algorithms
 * Medium (31.61%)
 * Likes:    221
 * Dislikes: 245
 * Total Accepted:    42K
 * Total Submissions: 132.8K
 * Testcase Example:  '8'
 *
 * 
 * Given a positive integer n and you can do operations as follow:
 * 
 * 
 * 
 * 
 * If n is even, replace n with n/2.
 * If n is odd, you can replace n with either n + 1 or n - 1.
 * 
 * 
 * 
 * 
 * What is the minimum number of replacements needed for n to become 1?
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * Input:
 * 8
 * 
 * Output:
 * 3
 * 
 * Explanation:
 * 8 -> 4 -> 2 -> 1
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:
 * 7
 * 
 * Output:
 * 4
 * 
 * Explanation:
 * 7 -> 8 -> 4 -> 2 -> 1
 * or
 * 7 -> 6 -> 3 -> 2 -> 1
 * 
 * 
 */
class Solution {
public:
    unordered_map<int, int> mm;
    int callme(long n){
        if(n==0 || n == 1)
            return 0;
        int rep = INT_MAX;
        if(mm.find(n)!=mm.end())
            return mm[n];
    
        if(n%2==0)
            rep = min(rep, callme(n/2));
        else{
            rep = min(rep, callme(n-1));
            rep = min(rep, callme(n+1));
        }
        if(rep == INT_MAX){
            mm[n] = rep;
            return rep;
        }
        mm[n] = 1+rep;
        return 1+rep;
    }
    int integerReplacement(int n) {
        mm.clear();
        return callme(n);
        // int c = 0;
        // while(n!=1){
        //     if(n%2==0)
        //         n/=2;
        //     else
        //         n--;
        //     c++;
        // }
        // return c++;
    }
};

