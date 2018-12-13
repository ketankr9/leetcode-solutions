/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
 *
 * https://leetcode.com/problems/path-sum-ii/description/
 *
 * algorithms
 * Medium (38.38%)
 * Total Accepted:    199.4K
 * Total Submissions: 519.2K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,5,1]\n22'
 *
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's
 * sum equals the given sum.
 *
 * Note: A leaf is a node with no children.
 *
 * Example:
 *
 * Given the below binary tree and sum = 22,
 *
 *
 * ⁠     5
 * ⁠    / \
 * ⁠   4   8
 * ⁠  /   / \
 * ⁠ 11  13  4
 * ⁠/  \    / \
 * 7    2  5   1
 *
 *
 * Return:
 *
 *
 * [
 * ⁠  [5,4,11,2],
 * ⁠  [5,8,4,5]
 * ]
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

    void callme(TreeNode* root, vector<vector<int>>& vec, int sum, vector<int> temp){
      if(root == NULL)  return;
      if(root->left == NULL && root->right == NULL && sum == root->val){
        temp.push_back(root->val);
        vec.push_back(temp);
        return;
      }
      temp.push_back(root->val);
      callme(root->left, vec, sum - root->val, temp);
      callme(root->right, vec, sum - root->val, temp);
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > v;
        std::vector<int> temp;
        callme(root, v, sum, temp);
        return v;
    }
};
