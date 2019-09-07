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
        stack<ListNode*> st;
        ListNode* cur = head;
        while(cur!=NULL)
        	st.push(cur), cur = cur->next;
        
        cur = head;

        ListNode* tmp;
        while(!st.empty()){
        	tmp = cur->next;
        	if(cur == st.top()){
        		cur->next = NULL;
        		return;
        	}
        	cur->next = st.top(); st.pop();
        	if(cur->next == tmp){
        		cur->next->next = NULL;
        		return;
        	}
        	cur->next->next = tmp;
        	cur = tmp;
        }
    }
};
