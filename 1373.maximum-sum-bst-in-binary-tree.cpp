/*
 * @lc app=leetcode id=1373 lang=cpp
 *
 * [1373] Maximum Sum BST in Binary Tree
 *
 * https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/description/
 *
 * algorithms
 * Hard (44.77%)
 * Likes:    101
 * Dislikes: 15
 * Total Accepted:    3.8K
 * Total Submissions: 8.6K
 * Testcase Example:  '[1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]'
 *
 * Given a binary tree root, the task is to return the maximum sum of all keys
 * of any sub-tree which is also a Binary Search Tree (BST).
 * 
 * Assume a BST is defined as follows:
 * 
 * 
 * The left subtree of a node contains only nodes with keys less than the
 * node's key.
 * The right subtree of a node contains only nodes with keys greater than the
 * node's key.
 * Both the left and right subtrees must also be binary search trees.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: root = [1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]
 * Output: 20
 * Explanation: Maximum sum in a valid Binary search tree is obtained in root
 * node with key equal to 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: root = [4,3,null,1,2]
 * Output: 2
 * Explanation: Maximum sum in a valid Binary search tree is obtained in a
 * single root node with key equal to 2.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: root = [-4,-2,-5]
 * Output: 0
 * Explanation: All values are negatives. Return an empty BST.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: root = [2,1,3]
 * Output: 6
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: root = [5,4,8,3,null,6,3]
 * Output: 7
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * Each tree has at most 40000 nodes..
 * Each node's value is between [-4 * 10^4 , 4 * 10^4].
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    #define pr pair<bool, int>
    int ans;
    pr callme(TreeNode* root){
        if(root == NULL)
            return make_pair(true, 0);
        
        pr left = callme(root->left);
        pr right = callme(root->right);

        bool isBst = left.first 
	        && right.first 
	        && (root->left == NULL || root->left->val < root->val) 
	        && (root->right == NULL || root->val < root->right->val);
        
        if(isBst)
            ans = max(ans, root->val+left.second+right.second);
        
        return make_pair(isBst, root->val+left.second+right.second);
    }
    int maxSumBST(TreeNode* root) {
        ans = 0;
        callme(root);
        return ans;
    }
};
// @lc code=end
