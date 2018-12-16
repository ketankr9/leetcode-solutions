/*
 * @lc app=leetcode id=404 lang=cpp
 *
 * [404] Sum of Left Leaves
 *
 * https://leetcode.com/problems/sum-of-left-leaves/description/
 *
 * algorithms
 * Easy (48.26%)
 * Total Accepted:    108.5K
 * Total Submissions: 224.7K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Find the sum of all left leaves in a given binary tree.
 * 
 * Example:
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * There are two left leaves in the binary tree, with values 9 and 15
 * respectively. Return 24.
 * 
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
    int summ;
    void callme(TreeNode* root, bool status){
        if(root == NULL)    return;
        if(root->left == NULL && root->right == NULL && status){
            summ += root->val;
            return;
        }
        callme(root->left, true);
        callme(root->right, false);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        summ=0;
        if(root == NULL)    return 0;
        callme(root->left, true);
        callme(root->right, false);
        return summ;
    }
};
