/*
 * @lc app=leetcode id=611 lang=cpp
 *
 * [611] Valid Triangle Number
 *
 * https://leetcode.com/problems/valid-triangle-number/description/
 *
 * algorithms
 * Medium (45.93%)
 * Total Accepted:    41.7K
 * Total Submissions: 90.7K
 * Testcase Example:  '[2,2,3,4]'
 *
 * Given an array consists of non-negative integers,  your task is to count the
 * number of triplets chosen from the array that can make triangles if we take
 * them as side lengths of a triangle.
 * 
 * Example 1:
 * 
 * Input: [2,2,3,4]
 * Output: 3
 * Explanation:
 * Valid combinations are: 
 * 2,3,4 (using the first 2)
 * 2,3,4 (using the second 2)
 * 2,2,3
 * 
 * 
 * 
 * Note:
 * 
 * The length of the given array won't exceed 1000.
 * The integers in the given array are in the range of [0, 1000].
 * 
 * 
 * 
 */
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;

        sort(nums.begin(), nums.end());

        for(int c = 2; c<n; c++){
            int a = 0, b = c-1;
            while(a<b){
                for( ;a<b && (nums[a]+nums[b])<=nums[c]; a++ );
                cnt += (b--)-a;
            }
        }
        return cnt;
    }
};
