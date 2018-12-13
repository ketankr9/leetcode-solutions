/*
 * @lc app=leetcode id=515 lang=cpp
 *
 * [515] Find Largest Value in Each Tree Row
 *
 * https://leetcode.com/problems/find-largest-value-in-each-tree-row/description/
 *
 * algorithms
 * Medium (56.61%)
 * Total Accepted:    53.5K
 * Total Submissions: 94.4K
 * Testcase Example:  '[1,3,2,5,3,null,9]'
 *
 * You need to find the largest value in each row of a binary tree.
 *
 * Example:
 *
 * Input:
 *
 * ⁠         1
 * ⁠        / \
 * ⁠       3   2
 * ⁠      / \   \
 * ⁠     5   3   9
 *
 * Output: [1, 3, 9]
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
    // std::vector<int> res;
    void callme(int level, TreeNode* root, std::vector<int>& res){
      if(root == NULL)
        return;
      if((int)res.size() == level)
        res.push_back(INT_MIN);
      res[level] = max(res[level], root->val);
      callme(level+1, root->left, res);
      callme(level+1, root->right, res);
    }

    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        res.clear();
        callme(0,root, res);
        return res;
    }
};
