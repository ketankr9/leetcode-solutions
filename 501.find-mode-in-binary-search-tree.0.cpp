/*
 * @lc app=leetcode id=501 lang=cpp
 *
 * [501] Find Mode in Binary Search Tree
 *
 * https://leetcode.com/problems/find-mode-in-binary-search-tree/description/
 *
 * algorithms
 * Easy (40.08%)
 * Total Accepted:    63K
 * Total Submissions: 157.2K
 * Testcase Example:  '[1,null,2,2]'
 *
 * Given a binary search tree (BST) with duplicates, find all the mode(s) (the
 * most frequently occurred element) in the given BST.
 * 
 * Assume a BST is defined as follows:
 * 
 * 
 * The left subtree of a node contains only nodes with keys less than or equal
 * to the node's key.
 * The right subtree of a node contains only nodes with keys greater than or
 * equal to the node's key.
 * Both the left and right subtrees must also be binary search trees.
 * 
 * 
 * 
 * 
 * For example:
 * Given BST [1,null,2,2],
 * 
 * 
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  2
 * 
 * 
 * 
 * 
 * return [2].
 * 
 * Note: If a tree has more than one mode, you can return them in any order.
 * 
 * Follow up: Could you do that without using any extra space? (Assume that the
 * implicit stack space incurred due to recursion does not count).
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
	int gmax, prev, cnt;
	vector<int> res;
	void callme(TreeNode* root){
		if(root == NULL)	return ;

		callme(root->left);
		
		if(prev != root->val)
			cnt = 0;
		prev = root->val;
		cnt++;
		if(cnt >= gmax){
			if(cnt > gmax)
				res.clear(), gmax = cnt;
			res.push_back(root->val);
		}
		callme(root->right);
	}
    vector<int> findMode(TreeNode* root) {
        res.clear();
        prev = INT_MAX;
        cnt = 0;
        gmax = INT_MIN;
        callme(root);
        return res;
    }
};
