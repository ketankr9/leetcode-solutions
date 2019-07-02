/*
 * @lc app=leetcode id=830 lang=cpp
 *
 * [830] Positions of Large Groups
 *
 * https://leetcode.com/problems/positions-of-large-groups/description/
 *
 * algorithms
 * Easy (47.85%)
 * Likes:    212
 * Dislikes: 54
 * Total Accepted:    27.7K
 * Total Submissions: 57.9K
 * Testcase Example:  '"abbxxxxzzy"'
 *
 * In a string S of lowercase letters, these letters form consecutive groups of
 * the same character.
 * 
 * For example, a string like S = "abbxxxxzyy" has the groups "a", "bb",
 * "xxxx", "z" and "yy".
 * 
 * Call a group large if it has 3 or more characters.  We would like the
 * starting and ending positions of every large group.
 * 
 * The final answer should be in lexicographic order.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "abbxxxxzzy"
 * Output: [[3,6]]
 * Explanation: "xxxx" is the single large group with starting  3 and ending
 * positions 6.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "abc"
 * Output: []
 * Explanation: We have "a","b" and "c" but no large group.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "abcdddeeeeaabbbcd"
 * Output: [[3,5],[6,9],[12,14]]
 * 
 * 
 * 
 * Note:  1 <= S.length <= 1000
 * 
 */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // bool static comp(const vector<int> &a, const vector<int> &b){
    //     if(a[0] == b[0])
    //         return a[1]<b[1];
    //     return a[0] < b[0];
    // }
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> ans;
        int i=0;
        int n = S.size();
        while(i<n){
            int start = i;
            while(i<n && S[start] == S[i])
                i++;
            if(i-start >= 3){
                vector<int> tmp = {start, i-1};
                ans.push_back(tmp);
            }
            
        }
        // sort(ans.begin(), ans.end(), comp);
        return ans;
    }
};

