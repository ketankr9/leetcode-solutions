/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/
 *
 * algorithms
 * Medium (33.41%)
 * Likes:    889
 * Dislikes: 75
 * Total Accepted:    188.2K
 * Total Submissions: 563.3K
 * Testcase Example:  '[1,2,3,3,4,4,5]'
 *
 * Given a sorted linked list, delete all nodes that have duplicate numbers,
 * leaving only distinct numbers from the original list.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->2->3->3->4->4->5
 * Output: 1->2->5
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 1->1->1->2->3
 * Output: 2->3
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

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head;
        ListNode* ans = new ListNode(-1);
        ListNode* newhead = ans;
        while(cur!=NULL){
            bool flag = true;
            while(cur->next!=NULL && cur->val == cur->next->val)
                cur=cur->next, flag = false;
            if(flag)
                ans->next = cur, ans = ans->next;
            cur=cur->next;
        }
        ans->next = NULL;
        return newhead->next;
    }
};

