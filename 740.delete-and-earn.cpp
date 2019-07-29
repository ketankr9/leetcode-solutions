/*
 * @lc app=leetcode id=740 lang=cpp
 *
 * [740] Delete and Earn
 *
 * https://leetcode.com/problems/delete-and-earn/description/
 *
 * algorithms
 * Medium (45.03%)
 * Total Accepted:    21.9K
 * Total Submissions: 47.6K
 * Testcase Example:  '[3,4,2]'
 *
 * Given an array nums of integers, you can perform operations on the array.
 * 
 * In each operation, you pick any nums[i] and delete it to earn nums[i]
 * points. After, you must delete every element equal to nums[i] - 1 or nums[i]
 * + 1.
 * 
 * You start with 0 points. Return the maximum number of points you can earn by
 * applying such operations.
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [3, 4, 2]
 * Output: 6
 * Explanation: 
 * Delete 4 to earn 4 points, consequently 3 is also deleted.
 * Then, delete 2 to earn 2 points. 6 total points are earned.
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [2, 2, 3, 3, 3, 4]
 * Output: 9
 * Explanation: 
 * Delete 3 to earn 3 points, deleting both 2's and the 4.
 * Then, delete 3 again to earn 3 points, and 3 again to earn 3 points.
 * 9 total points are earned.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The length of nums is at most 20000.
 * Each element nums[i] is an integer in the range [1, 10000].
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    // unordered_map<unordered_map<int, int>, int> dp;
    // unordered_map<int, int> mm;
    // int callme(){
    //     int ans = 0;
    //     for(auto e: mm){
    //         if(e.second == 0)   continue;
    //         mm[e.first]--;
    //         bool isx = false, isy = false;
    //         int x, y;
    //         if(mm.find(e.first-1) != mm.end()){
    //             isx = true;
    //             x = mm[e.first-1]; mm[e.first-1] = 0;
    //         }
    //         if(mm.find(e.first+1) != mm.end()){
    //             isy = true;
    //             y = mm[e.first+1]; mm[e.first+1] = 0;
    //         }
    //         ans = max(ans, e.first + callme());
    //         mm[e.first]++;
    //         if(isx) mm[e.first-1] = x;
    //         if(isy) mm[e.first+1] = y;
    //     }
    //     return ans;
    // }
    unordered_map<int, int> dp;
    int callme(int start, int end, vector<int>& mm){
        if(start >= end)    return 0;
        if(dp.find(start)!=dp.end())
            return dp[start];

        dp[start] = max(mm[start] + callme(start+2, end, mm), callme(start+1, end, mm));
        return dp[start];
    } 
    int deleteAndEarn(vector<int>& nums) {
        // // dp.clear();
        // mm.clear();
        // // unordered_map<int, int> mm;
        // for(auto e: nums)
        //     mm[e]++;
        // return callme();

        // unordered_map<int, int> mm;
        vector<int> mm(10001, 0);
        dp.clear();
        for(auto e: nums)
            mm[e]+=e;
        int start = 1;
        int ans = 0;
        while(start <= 10000){
            int i = start;
            while(mm[i])
                i++;
            if(i!=start) // at least one present
                ans += callme(start, i, mm);
            start = i+1;
        }
        return ans;
    }
};
