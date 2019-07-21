/*
 * @lc app=leetcode id=1130 lang=cpp
 *
 * [1130] Minimum Cost Tree From Leaf Values
 *
 * https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/description/
 *
 * algorithms
 * Medium (48.14%)
 * Total Accepted:    1K
 * Total Submissions: 2.2K
 * Testcase Example:  '[6,2,4]'
 *
 * Given an array arr of positive integers, consider all binary trees such
 * that:
 * 
 * 
 * Each node has either 0 or 2 children;
 * The values of arr correspond to the values of each leaf in an in-order
 * traversal of the tree.  (Recall that a node is a leaf if and only if it has
 * 0 children.)
 * The value of each non-leaf node is equal to the product of the largest leaf
 * value in its left and right subtree respectively.
 * 
 * 
 * Among all possible binary trees considered, return the smallest possible sum
 * of the values of each non-leaf node.  It is guaranteed this sum fits into a
 * 32-bit integer.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: arr = [6,2,4]
 * Output: 32
 * Explanation:
 * There are two possible trees.  The first has non-leaf node sum 36, and the
 * second has non-leaf node sum 32.
 * 
 * ⁠   24            24
 * ⁠  /  \          /  \
 * ⁠ 12   4        6    8
 * ⁠/  \               / \
 * 6    2             2   4
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= arr.length <= 40
 * 1 <= arr[i] <= 15
 * It is guaranteed that the answer fits into a 32-bit signed integer (ie. it
 * is less than 2^31).
 * 
 * 
 */
class Solution {
public:
    int maxme(vector<int>& arr, int start, int end){
        int ret = INT_MIN;
        for(int i=start; i<=end; i++)
            ret = max(ret, arr[i]);
        return ret;
    }
    int dp[40][40];
    int callme(int start, int end, vector<int>& arr){
        if(dp[start][end] != -1)
            return dp[start][end];

        int res = INT_MAX;
        for(int i=start; i<end; i++)
            res = min(res, callme(start, i, arr)+callme(i+1, end, arr)+maxme(arr, start, i)*maxme(arr, i+1, end));
        dp[start][end]  = (res == INT_MAX ? 0 : res);

        return dp[start][end];
    }
    int mctFromLeafValues(vector<int>& arr) {
        
        for(int i=0; i<40; i++)
            for(int j=0; j<40; j++)
                dp[i][j] = -1;
        
        return callme(0, arr.size()-1, arr);
    }
};
