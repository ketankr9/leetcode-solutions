/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 *
 * https://leetcode.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (40.51%)
 * Total Accepted:    177.1K
 * Total Submissions: 436.9K
 * Testcase Example:  '[1,2,2]'
 *
 * Given a collection of integers that might contain duplicates, nums, return
 * all possible subsets (the power set).
 *
 * Note: The solution set must not contain duplicate subsets.
 *
 * Example:
 *
 *
 * Input: [1,2,2]
 * Output:
 * [
 * ⁠ [2],
 * ⁠ [1],
 * ⁠ [1,2,2],
 * ⁠ [2,2],
 * ⁠ [1,2],
 * ⁠ []
 * ]
 *
 *
 */
class Solution {
public:
    vector<vector<int>> vec;
    void callme(int k, vector<int>& nums, vector<int> temp){
      if(k>=(int)nums.size()){
        vec.push_back(temp);
        return;
      }
      int j=k;
      while(j<(int)nums.size() && nums[k] == nums[j])
        j++;
      for(int count = 0; count <= j-k; count++){
        for(int i=0;i<count;i++)
          temp.push_back(nums[k]);
        callme(j, nums, temp);
        for(int i=0;i<count;i++)
          temp.pop_back();
      }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vec.clear();
        if(nums.size() == 0)
          return vec;
        sort(nums.begin(), nums.end());
        vector<int> v;
        callme(0, nums, v);
        return vec;
    }
};
