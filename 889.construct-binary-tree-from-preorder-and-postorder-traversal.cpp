/*
 * @lc app=leetcode id=889 lang=cpp
 *
 * [889] Construct Binary Tree from Preorder and Postorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (61.67%)
 * Total Accepted:    19.9K
 * Total Submissions: 32.3K
 * Testcase Example:  '[1,2,4,5,3,6,7]\n[4,5,2,6,7,3,1]'
 *
 * Return any binary tree that matches the given preorder and postorder
 * traversals.
 * 
 * Values in the traversals pre and post are distinct positive integers.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: pre = [1,2,4,5,3,6,7], post = [4,5,2,6,7,3,1]
 * Output: [1,2,3,4,5,6,7]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= pre.length == post.length <= 30
 * pre[] and post[] are both permutations of 1, 2, ..., pre.length.
 * It is guaranteed an answer exists. If there exists multiple answers, you can
 * return any of them.
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
	TreeNode* callme(int a, int b, int x, int y, vector<int>& pre, vector<int>& post){
		if(a > b)	return NULL;
		
		TreeNode* root = new TreeNode(pre[a]);
		if(a == b)	return root;

		int l = 0;
		while(x+l<y && post[x+l] != pre[a+1])
			l++;
		
		root->left = callme(a+1, a+1+l, x, x+l, pre, post);
		root->right = callme(a+1+l+1, b, x+l+1, y-1, pre, post);
		return root;
	}
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        return callme(0, pre.size()-1, 0, post.size()-1, pre, post);
    }
};
