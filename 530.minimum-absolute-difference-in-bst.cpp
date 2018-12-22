/*
 * @lc app=leetcode id=530 lang=cpp
 *
 * [530] Minimum Absolute Difference in BST
 *
 * https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/
 *
 * algorithms
 * Easy (49.02%)
 * Total Accepted:    49.6K
 * Total Submissions: 101.1K
 * Testcase Example:  '[1,null,3,2]'
 *
 * Given a binary search tree with non-negative values, find the minimum
 * absolute difference between values of any two nodes.
 * 
 * Example:
 * 
 * 
 * Input:
 * 
 * ⁠  1
 * ⁠   \
 * ⁠    3
 * ⁠   /
 * ⁠  2
 * 
 * Output:
 * 1
 * 
 * Explanation:
 * The minimum absolute difference is 1, which is the difference between 2 and
 * 1 (or between 2 and 3).
 * 
 * 
 * 
 * 
 * Note: There are at least two nodes in this BST.
 * 
 */
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
    int minn;
    int findmin(TreeNode* root){

        if(root->left == NULL)
            return root->val;
        return findmin(root->left);
    }
    int findmax(TreeNode* root){
        if(root->right == NULL)
            return root->val;
        return findmax(root->right);
    }
    void callme(TreeNode* root){
        if(root == NULL)    return ;

        if(root->left != NULL){
        minn = min(minn, root->val - findmax(root->left));
        callme(root->left);
        }
        if(root->right != NULL){
        minn = min(minn, findmin(root->right) - root->val);
        callme(root->right);
        }
    }
    int getMinimumDifference(TreeNode* root) {
        minn = INT_MAX;
        callme(root);
        return minn;
    }
};
