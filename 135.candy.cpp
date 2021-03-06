/*
 * @lc app=leetcode id=135 lang=cpp
 *
 * [135] Candy
 *
 * https://leetcode.com/problems/candy/description/
 *
 * algorithms
 * Hard (28.86%)
 * Total Accepted:    106.7K
 * Total Submissions: 369.4K
 * Testcase Example:  '[1,0,2]'
 *
 * There are N children standing in a line. Each child is assigned a rating
 * value.
 * 
 * You are giving candies to these children subjected to the following
 * requirements:
 * 
 * 
 * Each child must have at least one candy.
 * Children with a higher rating get more candies than their neighbors.
 * 
 * 
 * What is the minimum candies you must give?
 * 
 * Example 1:
 * 
 * 
 * Input: [1,0,2]
 * Output: 5
 * Explanation: You can allocate to the first, second and third child with 2,
 * 1, 2 candies respectively.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,2,2]
 * Output: 4
 * Explanation: You can allocate to the first, second and third child with 1,
 * 2, 1 candies respectively.
 * ⁠            The third child gets 1 candy because it satisfies the above two
 * conditions.
 * 
 * 
 */
class Solution {
public:
    int candy(vector<int>& rat) {
        int n = rat.size();
        vector<int> vec(n, 1);
        for(int i=0; i+1<n; i++){
            if(rat[i+1] > rat[i])
                vec[i+1] = max(vec[i]+1, vec[i+1]);
            if(rat[n-i-2] > rat[n-i-1])
                vec[n-i-2] = max(vec[n-i-2], 1+vec[n-i-1]);
        }
        int ans = 0;
        for(auto e: vec)    ans += e;
        return ans;
    }
};
