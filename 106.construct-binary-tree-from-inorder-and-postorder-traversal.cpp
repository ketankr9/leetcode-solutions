/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (40.96%)
 * Total Accepted:    168.9K
 * Total Submissions: 412.3K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * Given inorder and postorder traversal of a tree, construct the binary tree.
 * 
 * Note:
 * You may assume that duplicates do not exist in the tree.
 * 
 * For example, given
 * 
 * 
 * inorder = [9,3,15,20,7]
 * postorder = [9,15,7,20,3]
 * 
 * Return the following binary tree:
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
	TreeNode* callme(vector<int>& post, int startp, int endp, vector<int>& inord, int starti, int endi){
		if(startp > endp)	return NULL;

		TreeNode* root = new TreeNode(post[endp]);
		int k = starti, len = 0;
		while(post[endp] != inord[k])
			k++, len++;
		root->left = callme(post, startp, startp+len-1, inord, starti, k-1);
		root->right = callme(post, startp+len, endp-1, inord, k+1, endi);
		return root;
	}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return callme(postorder, 0, (int)postorder.size()-1, inorder, 0, (int)inorder.size()-1);
    }
};
