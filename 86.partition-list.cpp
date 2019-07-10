/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
 *
 * https://leetcode.com/problems/partition-list/description/
 *
 * algorithms
 * Medium (37.67%)
 * Likes:    708
 * Dislikes: 189
 * Total Accepted:    168.9K
 * Total Submissions: 448.2K
 * Testcase Example:  '[1,4,3,2,5,2]\n3'
 *
 * Given a linked list and a value x, partition it such that all nodes less
 * than x come before nodes greater than or equal to x.
 * 
 * You should preserve the original relative order of the nodes in each of the
 * two partitions.
 * 
 * Example:
 * 
 * 
 * Input: head = 1->4->3->2->5->2, x = 3
 * Output: 1->2->2->4->3->5
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

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL)    return NULL;
        ListNode *left=NULL, *right=NULL, *headleft=NULL, *headright=NULL;

        ListNode* cur = head;
        while(cur!=NULL){
            // cout<<cur->val<<" ";
            if(cur->val<x){
                if(headleft == NULL){
                    headleft = cur;
                    left = cur;
                }else{
                    left->next = cur;
                    left = left->next;
                }
            }else{
                if(headright == NULL){
                    headright = cur;
                    right = cur;
                }else{
                    right->next = cur;
                    right = right->next;
                }
            }
            cur = cur->next;
        }
        if(right!=NULL)
            right->next = NULL;
        if(left!=NULL){
            left->next = headright;
            return headleft;
        }

        return headright;
    }
};

