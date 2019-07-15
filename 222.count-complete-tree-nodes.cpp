/*
 * @lc app=leetcode id=222 lang=cpp
 *
 * [222] Count Complete Tree Nodes
 *
 * https://leetcode.com/problems/count-complete-tree-nodes/description/
 *
 * algorithms
 * Medium (34.75%)
 * Total Accepted:    128.4K
 * Total Submissions: 369.1K
 * Testcase Example:  '[1,2,3,4,5,6]'
 *
 * Given a complete binary tree, count the number of nodes.
 * 
 * Note: 
 * 
 * Definition of a complete binary tree from Wikipedia:
 * In a complete binary tree every level, except possibly the last, is
 * completely filled, and all nodes in the last level are as far left as
 * possible. It can have between 1 and 2h nodes inclusive at the last level h.
 * 
 * Example:
 * 
 * 
 * Input: 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   3
 * ⁠/ \  /
 * 4  5 6
 * 
 * Output: 6
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
    int leftc(TreeNode* root){
        if(root == NULL)    return 0;
        return 1 + leftc(root->left);
    }
    int rightc(TreeNode* root){
        if(root==NULL)  return 0;
        return 1 + rightc(root->right);
    }
    // int callme(TreeNode* root){
        
    // }
    int countNodes(TreeNode* root) {
        if(root == NULL)    return 0;
        int left = 1+leftc(root->left);
        int right = 1+rightc(root->right);
        if(left == right){
            return (int)pow(2, left)-1;
        }else{
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
    }
};
