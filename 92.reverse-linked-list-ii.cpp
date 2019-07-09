/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
 *
 * https://leetcode.com/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (35.28%)
 * Total Accepted:    200.9K
 * Total Submissions: 569.2K
 * Testcase Example:  '[1,2,3,4,5]\n2\n4'
 *
 * Reverse a linked list from position m to n. Do it in one-pass.
 * 
 * Note: 1 ≤ m ≤ n ≤ length of list.
 * 
 * Example:
 * 
 * 
 * Input: 1->2->3->4->5->NULL, m = 2, n = 4
 * Output: 1->4->3->2->5->NULL
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
    ListNode* firstk(ListNode* head, int k){
        ListNode* cur = head;
        ListNode* prev = NULL;
        while(k--){
            ListNode* temp = cur->next;;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        head->next = cur;
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int i = 1;
        if(m == 1)
            return firstk(head, n-m+1);
        ListNode* cur = head;
        while(++i<m)
            cur = cur->next;
        cur->next = firstk(cur->next, n-m+1);
        return head;
    }
};
