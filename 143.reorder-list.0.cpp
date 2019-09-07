/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
 *
 * https://leetcode.com/problems/reorder-list/description/
 *
 * algorithms
 * Medium (32.12%)
 * Total Accepted:    169.9K
 * Total Submissions: 528.3K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 * reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
 * 
 * You may not modify the values in the list's nodes, only nodes itself may be
 * changed.
 * 
 * Example 1:
 * 
 * 
 * Given 1->2->3->4, reorder it to 1->4->2->3.
 * 
 * Example 2:
 * 
 * 
 * Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
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
    void reorderList(ListNode* head) {
    	if(head == NULL || head->next == NULL)	return;
        ListNode* cur1 = head, *cur2 = head;
        while(cur2 != NULL && cur2->next != NULL && cur2->next->next != NULL){
        	cur1 = cur1->next;
        	cur2 = cur2->next->next;
        }
        ListNode* tmp = cur1->next;
        cur1->next = NULL;
        cur1 = tmp;

        cout<<"Middle:"<<(cur1->val)<<endl;
        
        // reverse head2
        ListNode* head2 = cur1; cur2 = cur1->next; head2->next = NULL;
        while(cur2){
        	ListNode* newh = cur2;
        	cur2 = cur2->next;
        	newh->next = head2;
        	head2 = newh;
        }
        // while(head2!=NULL){
        // 	cout<<head2->val<<" ";
        // 	head2 = head2->next;
        // }
        cur1 = head;
        cur2 = head2;
        while(cur2!=NULL){
        	ListNode *tmp1 = cur1->next, *tmp2 = cur2->next;
        	cur1->next = cur2;
        	cur2->next = tmp1;
        	cur1 = tmp1;
        	cur2 = tmp2;
        }
    }
};
