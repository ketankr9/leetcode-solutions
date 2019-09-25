/*
 * @lc app=leetcode id=1026 lang=cpp
 *
 * [1026] Maximum Difference Between Node and Ancestor
 *
 * https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/description/
 *
 * algorithms
 * Medium (61.36%)
 * Total Accepted:    14.6K
 * Total Submissions: 23.7K
 * Testcase Example:  '[8,3,10,1,6,null,14,null,null,4,7,13]'
 *
 * Given the root of a binary tree, find the maximum value V for which there
 * exists different nodes A and B where V = |A.val - B.val| and A is an
 * ancestor of B.
 * 
 * (A node A is an ancestor of B if either: any child of A is equal to B, or
 * any child of A is an ancestor of B.)
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: [8,3,10,1,6,null,14,null,null,4,7,13]
 * Output: 7
 * Explanation: 
 * We have various ancestor-node differences, some of which are given below :
 * |8 - 3| = 5
 * |3 - 7| = 4
 * |8 - 1| = 7
 * |10 - 13| = 3
 * Among all possible differences, the maximum value of 7 is obtained by |8 -
 * 1| = 7.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The number of nodes in the tree is between 2 and 5000.
 * Each node will have value between 0 and 100000.
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
	#define f first
	#define s second
	int ans;
	typedef pair<int, int> pr;
	pr callme(TreeNode* root){
		if(root == NULL)	return {INT_MAX, INT_MIN};
		
		pr left = callme(root->left);
		pr right = callme(root->right);
		
		if(left.f != INT_MAX)
			ans = max({ans, abs(root->val - left.f), abs(root->val - left.s)});
		if(right.f != INT_MAX)
			ans = max({ans, abs(root->val - right.f), abs(root->val - right.s)});

		return {min({root->val, left.f, right.f}), max({root->val, left.s, right.s})};
	}
    int maxAncestorDiff(TreeNode* root) {
        ans = INT_MIN;
        callme(root);
    	return ans;
    }
};
