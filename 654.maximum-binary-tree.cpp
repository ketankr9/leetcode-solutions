/*
 * @lc app=leetcode id=654 lang=cpp
 *
 * [654] Maximum Binary Tree
 *
 * https://leetcode.com/problems/maximum-binary-tree/description/
 *
 * algorithms
 * Medium (76.98%)
 * Total Accepted:    97.1K
 * Total Submissions: 126.1K
 * Testcase Example:  '[3,2,1,6,0,5]'
 *
 * 
 * Given an integer array with no duplicates. A maximum tree building on this
 * array is defined as follow:
 * 
 * The root is the maximum number in the array. 
 * The left subtree is the maximum tree constructed from left part subarray
 * divided by the maximum number.
 * The right subtree is the maximum tree constructed from right part subarray
 * divided by the maximum number. 
 * 
 * 
 * 
 * 
 * Construct the maximum tree by the given array and output the root node of
 * this tree.
 * 
 * 
 * Example 1:
 * 
 * Input: [3,2,1,6,0,5]
 * Output: return the tree root node representing the following tree:
 * 
 * ⁠     6
 * ⁠   /   \
 * ⁠  3     5
 * ⁠   \    / 
 * ⁠    2  0   
 * ⁠      \
 * ⁠       1
 * 
 * 
 * 
 * Note:
 * 
 * The size of the given array will be in the range [1,1000].
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
	TreeNode* callme(vector<int>& nums, int start, int end){
		if(start == end)	return NULL;
		if(start+1 == end)	return new TreeNode(nums[start]);

		int idx = start;
		int maxx = nums[start];
		for(int i=start+1; i<end; i++)
			if(nums[i] > maxx)
				maxx = nums[i], idx = i;
		TreeNode* root = new TreeNode(maxx);
		root->left = callme(nums, start, idx);
		root->right = callme(nums, idx+1, end);
		return root;
	}

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return callme(nums, 0, nums.size());
    }
};
