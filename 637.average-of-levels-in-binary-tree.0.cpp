/*
 * @lc app=leetcode id=637 lang=cpp
 *
 * [637] Average of Levels in Binary Tree
 *
 * https://leetcode.com/problems/average-of-levels-in-binary-tree/description/
 *
 * algorithms
 * Easy (57.13%)
 * Total Accepted:    64.6K
 * Total Submissions: 112.8K
 * Testcase Example:  '[3,9,20,15,7]'
 *
 * Given a non-empty binary tree, return the average value of the nodes on each
 * level in the form of an array.
 * 
 * Example 1:
 * 
 * Input:
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * Output: [3, 14.5, 11]
 * Explanation:
 * The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on
 * level 2 is 11. Hence return [3, 14.5, 11].
 * 
 * 
 * 
 * Note:
 * 
 * The range of node's value is in the range of 32-bit signed integer.
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
    vector<double> vec;
    unordered_map<int, int> count;
    int maxLevel;
    void callme(int level, TreeNode* root){
        if(!root){
            maxLevel = max(maxLevel, level);
            return;
        }
        if(level == (int)vec.size())
            vec.push_back(root->val);
        else
            vec[level]+=root->val;
        // vec[level] += root->val;
        count[level] += 1;
        callme(level+1, root->left);
        callme(level+1, root->right);
    }

    vector<double> averageOfLevels(TreeNode* root) {
        maxLevel = INT_MIN;
        callme(0, root);
        for(int i=0;i<maxLevel;i++){
            vec[i] /= (double)count[i];
        }
        return vec;

    }
};
