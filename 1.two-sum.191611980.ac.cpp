/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 *
 * https://leetcode.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (39.41%)
 * Total Accepted:    1.3M
 * Total Submissions: 3.2M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an array of integers, return indices of the two numbers such that they
 * add up to a specific target.
 * 
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 * 
 * Example:
 * 
 * 
 * Given nums = [2, 7, 11, 15], target = 9,
 * 
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mmap;
        vector<int> ans;
        
        for(int i=0;i<nums.size();i++)
            mmap[nums[i]] = i;
        for(int i=0;i<nums.size();i++){
            int rem = target - nums[i];
            if( mmap.find(rem)!=mmap.end()){
                if(i==mmap[rem]) continue;
                ans.push_back(i); ans.push_back(mmap[rem]);
                return ans;
            }
        }
    }
};
