/*
 * @lc app=leetcode id=1092 lang=cpp
 *
 * [1092] Shortest Common Supersequence
 *
 * https://leetcode.com/problems/shortest-common-supersequence/description/
 *
 * algorithms
 * Hard (41.00%)
 * Likes:    35
 * Dislikes: 0
 * Total Accepted:    1K
 * Total Submissions: 2.5K
 * Testcase Example:  '"abac"\n"cab"'
 *
 * Given two strings str1 and str2, return the shortest string that has both
 * str1 and str2 as subsequences.  If multiple answers exist, you may return
 * any of them.
 * 
 * (A string S is a subsequence of string T if deleting some number of
 * characters from T (possibly 0, and the characters are chosen anywhere from
 * T) results in the string S.)
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: str1 = "abac", str2 = "cab"
 * Output: "cabac"
 * Explanation: 
 * str1 = "abac" is a substring of "cabac" because we can delete the first "c".
 * str2 = "cab" is a substring of "cabac" because we can delete the last "ac".
 * The answer provided is the shortest such string that satisfies these
 * properties.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= str1.length, str2.length <= 1000
 * str1 and str2 consist of lowercase English letters.
 * 
 */
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        // unordered_map<pair<int, int>, pair<int, int>> prev;
        int arr[n+1][m+1];

        for(int i=0; i<n+1; i++)
            arr[i][0] = 0;
        for(int i=0; i<m+1; i++)
            arr[0][i] = 0;
        
        for (int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(str1[i] == str2[j]){
                    arr[i+1][j+1] = arr[i][j]+1;
                    // prev[make_pair(i+1, j+1)] = make_pair(i, j);
                }else{
                    // if(arr[i][j+1] > arr[i+1][j]){
                    //     prev[make_pair(i+1, j+1)] = make_pair(i, j+1);
                    // }else{
                    //     prev[make_pair(i+1, j+1)] = make_pair(i+1, j);
                    // }
                    arr[i+1][j+1] = max(arr[i][j+1], arr[i+1][j]);
                }
            }
        }
        // cout<<arr[n][m];
        // pair<int, int> ele; ele.first = n; ele.second = m;
        // while(mm.count(ele))
        int i = n, j = m;
        string ans = "";
        while(i>=1 || j>=1){
            if(i>=1 && arr[i-1][j] == arr[i][j]){
                // if(first)   {cout<<str1[i]; first = false;}
                ans = str1[--i] + ans;
            }else if(j>=1 && arr[i][j-1] == arr[i][j]){
                // if(first)   {cout<<str2[j]; first = false;}
                ans = str2[--j] + ans;
            }else if(i>=1 && j>=1){
                ans = str1[i-1] + ans;
                i--, j--;
            }
        }
        return ans;
    }
};

