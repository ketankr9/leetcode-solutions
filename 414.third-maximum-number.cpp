/*
 * @lc app=leetcode id=414 lang=cpp
 *
 * [414] Third Maximum Number
 *
 * https://leetcode.com/problems/third-maximum-number/description/
 *
 * algorithms
 * Easy (28.30%)
 * Total Accepted:    77.9K
 * Total Submissions: 274.7K
 * Testcase Example:  '[3,2,1]'
 *
 * Given a non-empty array of integers, return the third maximum number in this
 * array. If it does not exist, return the maximum number. The time complexity
 * must be in O(n).
 * 
 * Example 1:
 * 
 * Input: [3, 2, 1]
 * 
 * Output: 1
 * 
 * Explanation: The third maximum is 1.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [1, 2]
 * 
 * Output: 2
 * 
 * Explanation: The third maximum does not exist, so the maximum (2) is
 * returned instead.
 * 
 * 
 * 
 * Example 3:
 * 
 * Input: [2, 2, 3, 1]
 * 
 * Output: 1
 * 
 * Explanation: Note that the third maximum here means the third maximum
 * distinct number.
 * Both numbers with value 2 are both considered as second maximum.
 * 
 * 
 */
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long first, second, third;
        first = second = third = LONG_MIN;
        for(auto e: nums){
            if(e > first){
                third = second;
                second = first;
                first = e;
            }else if(e>second){
                if(e == first)  continue;
                third = second;
                second = e;
            }else if(e>third){
                if(e == second) continue;
                third = e;
            }
        }
        if(third == LONG_MIN){
            return first;
        }
        return third;
    }
};
