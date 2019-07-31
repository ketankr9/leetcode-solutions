/*
 * @lc app=leetcode id=132 lang=cpp
 *
 * [132] Palindrome Partitioning II
 *
 * https://leetcode.com/problems/palindrome-partitioning-ii/description/
 *
 * algorithms
 * Hard (27.88%)
 * Total Accepted:    107.2K
 * Total Submissions: 384.2K
 * Testcase Example:  '"aab"'
 *
 * Given a string s, partition s such that every substring of the partition is
 * a palindrome.
 * 
 * Return the minimum cuts needed for a palindrome partitioning of s.
 * 
 * Example:
 * 
 * 
 * Input: "aab"
 * Output: 1
 * Explanation: The palindrome partitioning ["aa","b"] could be produced using
 * 1 cut.
 * 
 * 
 */
class Solution {
public:
    unordered_map<int, int> mm;
    int callme(int start, vector<vector<bool>>& arr){
        if(start == (int)arr.size())    return 0;
        if(mm.find(start)!=mm.end())
            return mm[start];

        int ans = INT_MAX;
        for(int i=start; i<(int)arr.size(); i++){
            if(!arr[start][i])  continue;
            ans = min(ans, 1 + callme(i+1, arr));
        }
        mm[start] = ans;
        return ans;
    }
    int minCut(string s) {
        mm.clear();
        int n = s.size();
        vector<vector<bool>> arr(n, vector<bool>(n));

        for(int i=0; i<n; i++)
            arr[i][i] = true;
        for(int i=0; i+1<n; i++)
            arr[i][i+1] = (s[i] == s[i+1]);
        for(int k=2; k<n; k++)
            for(int i=0; i+k<n; i++)
                arr[i][i+k] = (s[i] == s[i+k]) && arr[i+1][i+k-1];
        return max(0, callme(0, arr)-1);
    }
};
