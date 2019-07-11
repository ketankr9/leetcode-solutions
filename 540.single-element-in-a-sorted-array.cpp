/*
 * @lc app=leetcode id=540 lang=cpp
 *
 * [540] Single Element in a Sorted Array
 *
 * https://leetcode.com/problems/single-element-in-a-sorted-array/description/
 *
 * algorithms
 * Medium (57.48%)
 * Likes:    768
 * Dislikes: 61
 * Total Accepted:    57.4K
 * Total Submissions: 99.8K
 * Testcase Example:  '[1,1,2,3,3,4,4,8,8]'
 *
 * Given a sorted array consisting of only integers where every element appears
 * exactly twice except for one element which appears exactly once. Find this
 * single element that appears only once.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [1,1,2,3,3,4,4,8,8]
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,3,7,7,10,11,11]
 * Output: 10
 * 
 * 
 * 
 * 
 * Note: Your solution should run in O(log n) time and O(1) space.
 * 
 */
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int pos = 0;
        if((int)nums.size()==1)
            return nums[0];
        if(nums[0]!=nums[1])
            return nums[0];
        int n = nums.size();
        int k = n-1;
        while(k>=2){
            while(pos+k+1<n && nums[pos+k]==nums[pos+k+1])
                pos+=k;
            k/=2;
            if(k!=1 && k%2==1)
                k++;
        }
        cout<<pos+2<<" ";
        return nums[pos+2];
    }   
};

