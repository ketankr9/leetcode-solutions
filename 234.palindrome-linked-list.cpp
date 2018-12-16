/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
 *
 * https://leetcode.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (34.64%)
 * Total Accepted:    211.1K
 * Total Submissions: 608.6K
 * Testcase Example:  '[1,2]'
 *
 * Given a singly linked list, determine if it is a palindrome.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->2
 * Output: false
 * 
 * Example 2:
 * 
 * 
 * Input: 1->2->2->1
 * Output: true
 * 
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
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
    ListNode* reverseMe(ListNode* root){
        if(root->next == NULL){
            return root;
        }
        ListNode* temp = root->next; //2
        ListNode* last = reverseMe(root->next);
        temp->next = root;
        root->next = NULL;
        // cout<<root->val<<endl;
        return last;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* cur1 = head;
        ListNode* cur2 = head;
        if(!head || !head->next) return true;
        while(cur1->next != NULL && cur2->next != NULL && cur2->next->next != NULL){
            cur1=cur1->next;
            cur2=cur2->next->next;
        }
        cur2 = reverseMe(cur1->next);
        cur1->next=NULL;
        cur1=head;
        while(cur2!=NULL){
            if(cur2->val != cur1->val)
                return false;
            cur1=cur1->next;
            cur2=cur2->next;
        }
        return true;
    }
};
