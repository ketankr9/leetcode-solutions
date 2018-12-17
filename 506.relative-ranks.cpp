/*
 * @lc app=leetcode id=506 lang=cpp
 *
 * [506] Relative Ranks
 *
 * https://leetcode.com/problems/relative-ranks/description/
 *
 * algorithms
 * Easy (47.45%)
 * Total Accepted:    37.4K
 * Total Submissions: 78.8K
 * Testcase Example:  '[5,4,3,2,1]'
 *
 * 
 * Given scores of N athletes, find their relative ranks and the people with
 * the top three highest scores, who will be awarded medals: "Gold Medal",
 * "Silver Medal" and "Bronze Medal".
 * 
 * Example 1:
 * 
 * Input: [5, 4, 3, 2, 1]
 * Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
 * Explanation: The first three athletes got the top three highest scores, so
 * they got "Gold Medal", "Silver Medal" and "Bronze Medal". For the left two
 * athletes, you just need to output their relative ranks according to their
 * scores.
 * 
 * 
 * 
 * Note:
 * 
 * N is a positive integer and won't exceed 10,000.
 * All the scores of athletes are guaranteed to be unique.
 * 
 * 
 * 
 */
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<string> ans(nums.size(), "");
        map<int, int, less <int> > mm;
        int N = (int)nums.size();
        for(int i = 0; i<N; i++)
            mm[nums[i]] = i;
        int i;
        for(map<int, int>::iterator it=mm.begin();it!=mm.end();it++){
            // rank = N - i;
            // val = it_>first
            // pos = it->second
            if(N - i == 1)
                ans[it->second] = "Gold Medal";
            else if( N -i == 2)
                ans[it->second] = "Silver Medal";
            else if(N-i == 3)
                ans[it->second] = "Bronze Medal";
            else
                ans[it->second] = to_string(N - i);
            i++;
        }
        return ans;
    }
};
