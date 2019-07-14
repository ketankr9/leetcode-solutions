/*
 * @lc app=leetcode id=993 lang=cpp
 *
 * [993] Cousins in Binary Tree
 *
 * https://leetcode.com/problems/cousins-in-binary-tree/description/
 *
 * algorithms
 * Easy (52.37%)
 * Total Accepted:    19.9K
 * Total Submissions: 38.1K
 * Testcase Example:  '[1,2,3,4]\n4\n3'
 *
 * In a binary tree, the root node is at depth 0, and children of each depth k
 * node are at depth k+1.
 * 
 * Two nodes of a binary tree are cousins if they have the same depth, but have
 * different parents.
 * 
 * We are given the root of a binary tree with unique values, and the values x
 * and y of two different nodes in the tree.
 * 
 * Return true if and only if the nodes corresponding to the values x and y are
 * cousins.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * Input: root = [1,2,3,4], x = 4, y = 3
 * Output: false
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
 * Output: true
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * 
 * 
 * Input: root = [1,2,3,null,4], x = 2, y = 3
 * Output: false
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The number of nodes in the tree will be between 2 and 100.
 * Each node has a unique integer value from 1 to 100.
 * 
 * 
 * 
 * 
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

    int depth1;
    int depth2;
    bool sameparent;
    void callme(int d, TreeNode* root, int &x, int &y){
        if(root == NULL || sameparent)    return;

        if(root->val == x){
            depth1 = d;
            return;
        }
        else if(root->val == y){
            depth2 = d;
            return;
        }

        if(root->left != NULL && root->right != NULL){
            if((root->left->val == x && root->right->val == y) 
                || (root->left->val == y && root->right->val == x)){
                sameparent = true;
                return;
            }
        }

        callme(d+1, root->left, x, y);
        callme(d+1, root->right, x, y);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        depth1 = -1;
        depth2 = -2;
        sameparent = false;
        callme(0, root, x, y);
        return depth1 == depth2 && !sameparent;
    }
};
