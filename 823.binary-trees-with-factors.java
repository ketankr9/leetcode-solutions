/*
 * @lc app=leetcode id=823 lang=java
 *
 * [823] Binary Trees With Factors
 *
 * https://leetcode.com/problems/binary-trees-with-factors/description/
 *
 * algorithms
 * Medium (34.74%)
 * Likes:    243
 * Dislikes: 32
 * Total Accepted:    9.8K
 * Total Submissions: 28.3K
 * Testcase Example:  '[2,4]'
 *
 * Given an array of unique integers, each integer is strictly greater than 1.
 * 
 * We make a binary tree using these integers and each number may be used for
 * any number of times.
 * 
 * Each non-leaf node's value should be equal to the product of the values of
 * it's children.
 * 
 * How many binary trees can we make?  Return the answer modulo 10 ** 9 + 7.
 * 
 * Example 1:
 * 
 * 
 * Input: A = [2, 4]
 * Output: 3
 * Explanation: We can make these trees: [2], [4], [4, 2, 2]
 * 
 * Example 2:
 * 
 * 
 * Input: A = [2, 4, 5, 10]
 * Output: 7
 * Explanation: We can make these trees: [2], [4], [5], [10], [4, 2, 2], [10,
 * 2, 5], [10, 5, 2].
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length <= 1000.
 * 2 <= A[i] <= 10 ^ 9.
 * 
 * 
 */

// @lc code=start
class Solution {
    public int numFactoredBinaryTrees(int[] A) {
        long M = 1000000000+7;

        int n = A.length;
        Arrays.sort(A);
        
        Map<Integer, Long> ss = new HashMap<Integer, Long>();
        ss.put(A[0], 1l);
        
        for(int pos = 1; pos<n; pos++){
            long tmp = 1;
            
            for(int i=0; i<pos; i++)
                if(A[pos]%A[i] == 0 && ss.containsKey(A[pos]/A[i]))
                    tmp = ( tmp + ss.get(A[i])*ss.get(A[pos]/A[i]) )%M;

            ss.put(A[pos], tmp);
        }

        long ans = 0;
        for(int e: A)
           ans = (ans+ss.get(e))%M;
        
        return (int)ans;
    }
}
// @lc code=end
