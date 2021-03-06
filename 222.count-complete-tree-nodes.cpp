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
    int callme(TreeNode* root, int left, int right){
        if(root == NULL)    return 0;
        
        TreeNode* tmp;

        if(left == -1){
            left = 0;
            tmp = root;
            while(tmp)  left++, tmp = tmp->left;
        }

        if(right == -1){
            right = 0;
            tmp = root;
            while(tmp)  right++, tmp = tmp->right;
        }

        return left==right?(int)pow(2, left)-1:1 + callme(root->left, left-1, -1) + callme(root->right, -1, right-1);
    }
    int countNodes(TreeNode* root) {
        return callme(root, -1, -1);
    }
};
