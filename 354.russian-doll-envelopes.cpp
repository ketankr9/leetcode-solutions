/*
 * @lc app=leetcode id=354 lang=cpp
 *
 * [354] Russian Doll Envelopes
 *
 * https://leetcode.com/problems/russian-doll-envelopes/description/
 *
 * algorithms
 * Hard (34.12%)
 * Total Accepted:    46.3K
 * Total Submissions: 135.6K
 * Testcase Example:  '[[5,4],[6,4],[6,7],[2,3]]'
 *
 * You have a number of envelopes with widths and heights given as a pair of
 * integers (w, h). One envelope can fit into another if and only if both the
 * width and height of one envelope is greater than the width and height of the
 * other envelope.
 * 
 * What is the maximum number of envelopes can you Russian doll? (put one
 * inside other)
 * 
 * Note:
 * Rotation is not allowed.
 * 
 * Example:
 * 
 * 
 * 
 * Input: [[5,4],[6,4],[6,7],[2,3]]
 * Output: 3 
 * Explanation: The maximum number of envelopes you can Russian doll is 3
 * ([2,3] => [5,4] => [6,7]).
 * 
 * 
 * 
 */
class Solution {
public:
    static bool comp(const vector<int> &p1, const vector<int>& p2){
        return p1[0] == p2[0] ? p1[1] < p2[1] : p1[0] < p2[0]; 
    }
    int maxEnvelopes(vector<vector<int>>& env) {
        sort(env.begin(), env.end(), comp);
        int n = env.size();
        vector<int> dp(n, 1);
        for(int i=0; i<n; i++)
            for(int j=0; j<i; j++)
                if(env[j][0] < env[i][0] && env[j][1] < env[i][1] && dp[j]+1 > dp[i])
                    dp[i] = dp[j] + 1;
        int ans = 0;
        for(auto e: dp)
            ans = max(e, ans);
        return ans;
    }
};
