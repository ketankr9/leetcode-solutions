/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
 *
 * https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
 *
 * algorithms
 * Easy (48.75%)
 * Total Accepted:    252.5K
 * Total Submissions: 503.6K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * Given an array where elements are sorted in ascending order, convert it to a
 * height balanced BST.
 * 
 * For this problem, a height-balanced binary tree is defined as a binary tree
 * in which the depth of the two subtrees of every node never differ by more
 * than 1.
 * 
 * Example:
 * 
 * 
 * Given the sorted array: [-10,-3,0,5,9],
 * 
 * One possible answer is: [0,-3,9,-10,null,5], which represents the following
 * height balanced BST:
 * 
 * ⁠     0
 * ⁠    / \
 * ⁠  -3   9
 * ⁠  /   /
 * ⁠-10  5
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
    void fillTree(TreeNode* root, vector<int>& nums,int start, int end){
        int mid = (start + end)/2;
        cout<<start<<":"<<end<<" ";
        root->val = nums[mid];
        if(start != mid){
            root->left = new TreeNode(0);
            fillTree(root->left, nums, start, mid);
        }
        if(mid+1 != end){
            root->right = new TreeNode(0);
            fillTree(root->right, nums, mid+1, end);
        }
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if((int)nums.size() == 0)
            return NULL;
        TreeNode* root = new TreeNode(0);
        fillTree(root, nums, 0, (int)nums.size());
        return root;
    }
};
