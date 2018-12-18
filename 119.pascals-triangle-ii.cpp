/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 *
 * https://leetcode.com/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (40.79%)
 * Total Accepted:    172.3K
 * Total Submissions: 421.7K
 * Testcase Example:  '3'
 *
 * Given a non-negative index k where k ≤ 33, return the kth index row of the
 * Pascal's triangle.
 * 
 * Note that the row index starts from 0.
 * 
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output: [1,3,3,1]
 * 
 * 
 * Follow up:
 * 
 * Could you optimize your algorithm to use only O(k) extra space?
 * 
 */
class Solution {
public:

    vector<int> getRow(int rowIndex) {
        vector<int> ans(1,1);
        while(rowIndex--){
            vector<int> temp;
            temp.push_back(1);
            for(int i=0;i<(int)ans.size()-1; i++){
                temp.push_back(ans[i]+ans[i+1]);
            }
            temp.push_back(1);
            swap(ans, temp);
        }
        return ans;
    }
};
