/*
 * @lc app=leetcode id=988 lang=cpp
 *
 * [988] Smallest String Starting From Leaf
 *
 * https://leetcode.com/problems/smallest-string-starting-from-leaf/description/
 *
 * algorithms
 * Medium (51.94%)
 * Total Accepted:    8.7K
 * Total Submissions: 18K
 * Testcase Example:  '[0,1,2,3,4,3,4]'
 *
 * Given the root of a binary tree, each node has a value from 0 to 25
 * representing the letters 'a' to 'z': a value of 0 represents 'a', a value of
 * 1 represents 'b', and so on.
 * 
 * Find the lexicographically smallest string that starts at a leaf of this
 * tree and ends at the root.
 * 
 * (As a reminder, any shorter prefix of a string is lexicographically smaller:
 * for example, "ab" is lexicographically smaller than "aba".  A leaf of a node
 * is a node that has no children.)
 * 
 * 
 * 
 * 
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
 * 
 * 
 * Input: [0,1,2,3,4,3,4]
 * Output: "dba"
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: [25,1,3,1,3,0,2]
 * Output: "adz"
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * 
 * 
 * Input: [2,2,1,null,1,0,null,0]
 * Output: "abc"
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The number of nodes in the given tree will be between 1 and 8500.
 * Each node in the tree will have a value between 0 and 25.
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
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string smallest;
    string local;
    void traverse(TreeNode* root, TreeNode* prev){
        if(root == NULL){
            // cout<<local<<" ";
            if(prev!=NULL && (prev->left == NULL ^ prev->right == NULL))    return;
            if(smallest == "")
                smallest = local;
            else if(smallest > local)
                smallest = local;
            return ;
        }
        string tmp = local;
        local = (char)(root->val+'a') + local;
        traverse(root->left, root);
        traverse(root->right, root);
        local = tmp;
    }
    string smallestFromLeaf(TreeNode* root) {
        smallest = "";
        local = "";
        traverse(root, NULL);
        // if(root->left == NULL)
        //     return traverse(root->right) + (char)(root->val+'a');
        // else if(root->right == NULL)
        //     return traverse(root->left) + (char)(root->val+'a');
        return smallest;
    }
};
