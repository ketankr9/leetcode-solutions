/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-preorder-traversal/description/
 *
 * algorithms
 * Medium (52.44%)
 * Total Accepted:    372.5K
 * Total Submissions: 710.1K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the preorder traversal of its nodes' values.
 * 
 * Example:
 * 
 * 
 * Input: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * Output: [1,2,3]
 * 
 * 
 * Follow up: Recursive solution is trivial, could you do it iteratively?
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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ans;
        if(root == NULL)	return ans;
        
        ans.push_back(root->val);
        st.push(root);

        while(!st.empty()){
        	if(root!=NULL && root->left!=NULL){
        		ans.push_back(root->left->val);
        		st.push(root->left);
        		root = root->left;
        		continue;
        	}
        	TreeNode* top = st.top(); st.pop();
        	root = top->right;
        	if(root!=NULL){	ans.push_back(root->val); st.push(root); };
        }
        return ans;
    }
};
