/*
 * @lc app=leetcode id=659 lang=cpp
 *
 * [659] Split Array into Consecutive Subsequences
 *
 * https://leetcode.com/problems/split-array-into-consecutive-subsequences/description/
 *
 * algorithms
 * Medium (39.42%)
 * Total Accepted:    19.2K
 * Total Submissions: 47.7K
 * Testcase Example:  '[1,2,3,3,4,5]'
 *
 * You are given an integer array sorted in ascending order (may contain
 * duplicates), you need to split them into several subsequences, where each
 * subsequences consist of at least 3 consecutive integers. Return whether you
 * can make such a split.
 * 
 * Example 1:
 * 
 * Input: [1,2,3,3,4,5]
 * Output: True
 * Explanation:
 * You can split them into two consecutive subsequences : 
 * 1, 2, 3
 * 3, 4, 5
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [1,2,3,3,4,4,5,5]
 * Output: True
 * Explanation:
 * You can split them into two consecutive subsequences : 
 * 1, 2, 3, 4, 5
 * 3, 4, 5
 * 
 * 
 * 
 * Example 3:
 * 
 * Input: [1,2,3,4,4,5]
 * Output: False
 * 
 * 
 * 
 * Note:
 * 
 * The length of the input is in range of [1, 10000]
 * 
 * 
 */
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        vector<pair<int, int>> vec; // last pair(value, size)
        int i=0, n = nums.size();
        while(i<n){
            int start = i;
            while(i<n && nums[i] == nums[start])
                i++;
            //cnt = i-start
            int j = vec.size()-1;
            while(start<i && j>=0){
                if(vec[j].first+1!=nums[start]) break;
                vec[j].first++; //value increment
                vec[j].second++; //size++
                start++, j--;
            }
            while(start<i)
                vec.push_back(make_pair(nums[start++], 1));
        }
        for(i=0; i<(int)vec.size(); i++)
            if(vec[i].second < 3)    return false;
        return true;
    }
};
