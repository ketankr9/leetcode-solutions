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
    bool callme(TreeNode* root, long minn, long maxx){
        if(root == NULL)
            return false;
        if(root->val >= maxx || root->val <= minn)
          return true;
        return callme(root->left, minn, root->val) || callme(root->right, root->val, maxx);
    }

    bool isValidBST(TreeNode* root) {
        return !callme(root, LONG_MIN, LONG_MAX);
    }
};
