/*
 * @lc app=leetcode id=914 lang=cpp
 *
 * [914] X of a Kind in a Deck of Cards
 *
 * https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/description/
 *
 * algorithms
 * Easy (34.09%)
 * Total Accepted:    20.1K
 * Total Submissions: 58.9K
 * Testcase Example:  '[1,2,3,4,4,3,2,1]'
 *
 * In a deck of cards, each card has an integer written on it.
 * 
 * Return true if and only if you can choose X >= 2 such that it is possible to
 * split the entire deck into 1 or more groups of cards, where:
 * 
 * 
 * Each group has exactly X cards.
 * All the cards in each group have the same integer.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3,4,4,3,2,1]
 * Output: true
 * Explanation: Possible partition [1,1],[2,2],[3,3],[4,4]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,1,1,2,2,2,3,3]
 * Output: false
 * Explanation: No possible partition.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [1]
 * Output: false
 * Explanation: No possible partition.
 * 
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: [1,1]
 * Output: true
 * Explanation: Possible partition [1,1]
 * 
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: [1,1,2,2,2,2]
 * Output: true
 * Explanation: Possible partition [1,1],[2,2],[2,2]
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= deck.length <= 10000
 * 0 <= deck[i] < 10000
 * 
 * 
 * 
 * 
 * 
 * 
 * 
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
    int gcd(int a, int b){
        if(a == 0 || b == 0)
            return a+b;
        if(a == 1 || b == 1)
            return 1;
        if(a>b)
            swap(a, b);
        return gcd(b%a, a);
    }
    bool hasGroupsSizeX(vector<int>& deck) {
        vector<int> vec(10000, 0);
        
        for(auto e: deck)
            vec[e]++;
        int hcf = -1;
        for(int i=0; i<10000; i++){
            if(vec[i]==0)   continue;
            // cout<<vec[i]<<" ";
            if(hcf == -1){
                hcf = vec[i];
                continue;
            }
            hcf = gcd(hcf, vec[i]);
            if(hcf < 2)
                return false;
        }
        // cout<<"::"<<hcf<<" ";
        return hcf>=2;
    }
};
