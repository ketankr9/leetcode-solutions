/*
 * @lc app=leetcode id=235 lang=cpp
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
 *
 * https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
 *
 * algorithms
 * Easy (42.29%)
 * Total Accepted:    238.7K
 * Total Submissions: 563.9K
 * Testcase Example:  '[6,2,8,0,4,7,9,null,null,3,5]\n2\n8'
 *
 * Given a binary search tree (BST), find the lowest common ancestor (LCA) of
 * two given nodes in the BST.
 * 
 * According to the definition of LCA on Wikipedia: “The lowest common ancestor
 * is defined between two nodes p and q as the lowest node in T that has both p
 * and q as descendants (where we allow a node to be a descendant of itself).”
 * 
 * Given binary search tree:  root = [6,2,8,0,4,7,9,null,null,3,5]
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
 * Output: 6
 * Explanation: The LCA of nodes 2 and 8 is 6.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
 * Output: 2
 * Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant
 * of itself according to the LCA definition.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * All of the nodes' values will be unique.
 * p and q are different and both values will exist in the BST.
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
    bool maxLevel;
    TreeNode* ans;

    bool callme(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL || !maxLevel)   return false;
        bool temp = false;
        if(root == p || root == q)
            temp = true;

        bool foundLeft = p->val > root->val && q->val > root->val ? false:callme(root->left, p, q);
        bool foundRight = p->val < root->val && q->val < root->val ? false:callme(root->right, p, q);

        if((foundLeft && foundRight) || ((foundLeft ^ foundRight) && temp)){
            ans = root;
            maxLevel = false;
        }
        return foundLeft || foundRight || temp;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        maxLevel = true;

        callme(root, p, q);
        return ans;
    }
};

