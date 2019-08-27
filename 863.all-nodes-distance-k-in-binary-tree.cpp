/*
 * @lc app=leetcode id=863 lang=cpp
 *
 * [863] All Nodes Distance K in Binary Tree
 *
 * https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/
 *
 * algorithms
 * Medium (49.43%)
 * Total Accepted:    30.4K
 * Total Submissions: 61.4K
 * Testcase Example:  '[3,5,1,6,2,0,8,null,null,7,4]\n5\n2'
 *
 * We are given a binary tree (with root node root), a target node, and an
 * integer value K.
 * 
 * Return a list of the values of all nodes that have a distance K from the
 * target node.  The answer can be returned in any order.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2
 * 
 * Output: [7,4,1]
 * 
 * Explanation: 
 * The nodes that are a distance 2 from the target node (with value 5)
 * have values 7, 4, and 1.
 * 
 * 
 * 
 * Note that the inputs "root" and "target" are actually TreeNodes.
 * The descriptions of the inputs above are just serializations of these
 * objects.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The given tree is non-empty.
 * Each node in the tree has unique values 0 <= node.val <= 500.
 * The target node is a node in the tree.
 * 0 <= K <= 1000.
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
	vector<int> ans;
	void atdis(TreeNode* root, int k){
		if(root == NULL)	return;
		// cout<<root->val<<":"<<k<<" ";
		if(k == 0){
			ans.push_back(root->val);
			return;
		}
		atdis(root->left, k-1);
		atdis(root->right, k-1);
	}
	pair<int, bool> callme(TreeNode* root, TreeNode* target, int K){
		if(root == NULL)	return {INT_MAX, false};
		if(root == target){
			atdis(root, K);
			return {1, true};
		}
		pair<int, bool> left = callme(root->left, target, K);
		pair<int, bool> right = callme(root->right, target, K);
		if(left.second){
			if(K-left.first == 0)	ans.push_back(root->val);
			atdis(root->right, K-left.first-1);
			return {left.first+1, true};
		}else if(right.second){
			if(K-right.first == 0)	ans.push_back(root->val);
			atdis(root->left, K-right.first-1);
			return {right.first+1, true};
		}
		return {INT_MAX, false};
	}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
    	ans.clear();
    	callme(root, target, K);
    	return ans;
    }
};
