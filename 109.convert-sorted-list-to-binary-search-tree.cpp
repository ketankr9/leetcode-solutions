/*
 * @lc app=leetcode id=109 lang=cpp
 *
 * [109] Convert Sorted List to Binary Search Tree
 *
 * https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/
 *
 * algorithms
 * Medium (41.04%)
 * Likes:    1063
 * Dislikes: 68
 * Total Accepted:    180.7K
 * Total Submissions: 437.3K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * Given a singly linked list where elements are sorted in ascending order,
 * convert it to a height balanced BST.
 * 
 * For this problem, a height-balanced binary tree is defined as a binary tree
 * in which the depth of the two subtrees of every node never differ by more
 * than 1.
 * 
 * Example:
 * 
 * 
 * Given the sorted linked list: [-10,-3,0,5,9],
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
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL)
            return NULL;
        if(head->next == NULL)
            return new TreeNode(head->val);
        if(head->next->next == NULL){
            TreeNode* root = new TreeNode(head->next->val);
            root->left = new TreeNode(head->val);
            return root;
        }
        ListNode* cur1 = head;
        ListNode* cur2 = head->next;
        ListNode* prev = NULL;
        while(cur2!=NULL && cur2->next!=NULL)
            prev = cur1, cur1 = cur1->next, cur2 = cur2->next->next;
        
        
        if(prev!=NULL)
            prev->next = NULL;
        TreeNode* root = new TreeNode(cur1->val);
        root->left = sortedListToBST(head);
        root->right= sortedListToBST(cur1->next);
        return root;
     }
};

