/*
 * @lc app=leetcode id=671 lang=cpp
 *
 * [671] Second Minimum Node In a Binary Tree
 *
 * https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/description/
 *
 * algorithms
 * Easy (42.77%)
 * Total Accepted:    37.8K
 * Total Submissions: 88.4K
 * Testcase Example:  '[2,2,5,null,null,5,7]'
 *
 * 
 * Given a non-empty special binary tree consisting of nodes with the
 * non-negative value, where each node in this tree has exactly two or zero
 * sub-node. If the node has two sub-nodes, then this node's value is the
 * smaller value among its two sub-nodes. 
 * 
 * 
 * 
 * Given such a binary tree, you need to output the second minimum value in the
 * set made of all the nodes' value in the whole tree. 
 * 
 * 
 * 
 * If no such second minimum value exists, output -1 instead.
 * 
 * 
 * Example 1:
 * 
 * Input: 
 * ⁠   2
 * ⁠  / \
 * ⁠ 2   5
 * ⁠    / \
 * ⁠   5   7
 * 
 * Output: 5
 * Explanation: The smallest value is 2, the second smallest value is 5.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: 
 * ⁠   2
 * ⁠  / \
 * ⁠ 2   2
 * 
 * Output: -1
 * Explanation: The smallest value is 2, but there isn't any second smallest
 * value.
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
    // long firstMin, secondMin;
    int count;
    int callme(TreeNode* root){
        count++;
        if(!root)  return INT_MAX;
        if(root->left == NULL && root->right == NULL)
            return INT_MAX;
        int secondMin;
        if(root->val == root->left->val && root->val == root->right->val)
            secondMin = min(callme(root->left), callme(root->right));
        else if(root->val == root->left->val){
            secondMin = min(root->right->val, callme(root->left));
        }else if(root->val == root->right->val){
            secondMin = min(root->left->val, callme(root->right));
        }
        // else{
            // secondMin = min(callme(root->left), callme(root->right));
        // }
        // callme(root->left);
        // callme(root->right);
        return secondMin;
    }

    int findSecondMinimumValue(TreeNode* root) {
        count = 0;
        // firstMin = LONG_MAX;
        // secondMin = LONG_MAX;
        int ans = callme(root);
        if(ans == INT_MAX)
            return -1;
        return ans;
        // cout<<count<<endl;
        // return secondMin;
    }
};
