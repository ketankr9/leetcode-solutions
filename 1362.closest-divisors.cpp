/*
 * @lc app=leetcode id=1362 lang=cpp
 *
 * [1362] Closest Divisors
 *
 * https://leetcode.com/problems/closest-divisors/description/
 *
 * algorithms
 * Medium (54.13%)
 * Likes:    42
 * Dislikes: 23
 * Total Accepted:    6.4K
 * Total Submissions: 11.8K
 * Testcase Example:  '8'
 *
 * Given an integer num, find the closest two integers in absolute difference
 * whose product equals num + 1 or num + 2.
 * 
 * Return the two integers in any order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: num = 8
 * Output: [3,3]
 * Explanation: For num + 1 = 9, the closest divisors are 3 & 3, for num + 2 =
 * 10, the closest divisors are 2 & 5, hence 3 & 3 is chosen.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: num = 123
 * Output: [5,25]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: num = 999
 * Output: [40,25]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= num <= 10^9
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> closestDivisors(int num) {
        vector<int> ans(2, -1);
        int n = num+1;
        int diff = INT_MAX;
        for(int i=(int)sqrt(n); i>=1; i--){
            int i2= n/i;
            if(i2*i == n){
                if(abs(i-i2) < diff){
                    diff = abs(i-i2);
                    ans[0] = i;
                    ans[1] = i2;
                }
                break;
            }
        }
        n = num+2;
        for(int i=(int)sqrt(n); i>=1; i--){
            int i2= n/i;
            if(i2*i == n){
                if(abs(i-i2) < diff){
                    diff = abs(i-i2);
                    ans[0] = i;
                    ans[1] = i2;
                }
                break;
            }
        }

        return ans;
    }
};
// @lc code=end
