/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
 *
 * https://leetcode.com/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (44.01%)
 * Total Accepted:    196.7K
 * Total Submissions: 446.9K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * Given a binary tree, return all root-to-leaf paths.
 *
 * Note: A leaf is a node with no children.
 *
 * Example:
 *
 *
 * Input:
 *
 * ⁠  1
 * ⁠/   \
 * 2     3
 * ⁠\
 * ⁠ 5
 *
 * Output: ["1->2->5", "1->3"]
 *
 * Explanation: All root-to-leaf paths are: 1->2->5, 1->3
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
    vector<string> ans;
    void callme(TreeNode* node, string res){
        if(node->left == NULL && node->right == NULL){
          res = res+"->"+to_string(node->val);
          ans.push_back(res);
          return;
        }

        res = res+"->"+to_string(node->val);
        if(node->left != NULL)  callme(node->left,  res);
        if(node->right != NULL) callme(node->right, res);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
      ans.clear();
      if(root == NULL) return ans;
      if(root->left == NULL && root->right == NULL){
        ans.push_back(to_string(root->val));
        return ans;
      }

      if(root->left)  callme(root->left, to_string(root->val));
      if(root->right) callme(root->right, to_string(root->val));
      return ans;
    }
};
