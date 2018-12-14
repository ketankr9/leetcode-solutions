/*
 * @lc app=leetcode id=653 lang=cpp
 *
 * [653] Two Sum IV - Input is a BST
 *
 * https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/
 *
 * algorithms
 * Easy (51.33%)
 * Total Accepted:    65.8K
 * Total Submissions: 129.2K
 * Testcase Example:  '[5,3,6,2,4,null,7]\n9'
 *
 * Given a Binary Search Tree and a target number, return true if there exist
 * two elements in the BST such that their sum is equal to the given target.
 *
 * Example 1:
 *
 * Input:
 * ⁠   5
 * ⁠  / \
 * ⁠ 3   6
 * ⁠/ \   \
 * 2   4   7
 *
 * Target = 9
 *
 * Output: True
 *
 *
 *
 *
 * Example 2:
 *
 * Input:
 * ⁠   5
 * ⁠  / \
 * ⁠ 3   6
 * ⁠/ \   \
 * 2   4   7
 *
 * Target = 28
 *
 * Output: False
 *
 *
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
    std::vector<int> vec;
    void callme(TreeNode* root){
      if(root == NULL)
        return;
      callme(root->left);
      vec.push_back(root->val);
      callme(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
      vec.clear();
      callme(root);
      int i = 0;
      int j = vec.size() - 1;
      while(i<j){
        if(vec[i] + vec[j] > k)
          j--;
        else if(vec[i] + vec[j] < k)
          i++;
        else
          return true;
      }
      return false;
    }
};
