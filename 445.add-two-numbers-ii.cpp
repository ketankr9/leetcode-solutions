/* @lc app=leetcode id=445 lang=cpp
 *
 *
 * [445] Add Two Numbers II
 *
 * https://leetcode.com/problems/add-two-numbers-ii/description/
 *
 * algorithms
 * Medium (50.59%)
 * Total Accepted:    97.8K
 * Total Submissions: 193.1K
 * Testcase Example:  '[7,2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The most significant digit comes first and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * Follow up:
 * What if you cannot modify the input lists? In other words, reversing the
 * lists is not allowed.
 * 
 * 
 * 
 * Example:
 * 
 * Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 8 -> 0 -> 7
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
    // ListNode* callme(ListNode* l1, ListNode* l2){
    //     if(l1 == NULL && l2 == NULL)
    //         return NULL;

    //     ListNode* root = new ListNode(l1->val + l2->val);
    //     ListNode* next = callme(l1->next, l2->next);
    //     if(next!=NULL && next->val >= 10)
    //         root->val += 1, next->val -= 10;
    //     root->next = next;
    //     return root;
    // }

    // void callme2(ListNode* root, ListNode* next){
    //     if(root->next == NULL){
    //         root->next = next;
    //         if(next->val > 9){
    //             next->val -= 10;
    //             root->val += 1;
    //         }
    //         return ;
    //     }
    //     callme(root->next, next);
    //     if(root->next->val > 9)
    //         root->next->val -= 10;
    //     root->val+=1;
    // }

    void callme(ListNode* l1, ListNode* l2){
        if(l1 == NULL && l2 == NULL)
            return;
        
        l1->val += l2->val;
        callme(l1->next, l2->next);
    }
    void normalizer(ListNode* node){
        if(node == NULL || node->next == NULL)  return;
            
        normalizer(node->next);
        if(node->next->val > 9){
            node->next->val -= 10;
            node->val += 1;
        }
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int n1 = 0, n2 = 0;

        ListNode* node;
        
        node = l1;
        while(node!=NULL)
            n1++, node = node->next;
        
        node = l2;
        while(node!=NULL)
            n2++, node = node->next;
        
        // if(n1 == n2){
        //     ListNode* next = callme(l1, l2);
        //     if(next != NULL && next->val >= 10){
        //         ListNode* root = new ListNode(1);
        //         next->val -= 10;
        //         root->next = next;
        //         return root;
        //     }else
        //         return next;
        // }else if(n1 > n2+1){
        //     Node* prev = l1;
        //     while(n1 > n2)
        //         prev = prev->next, n1--;
        //     ListNode* next = callme(prev->next, l2);
        //     prev->next = NULL;
        //     ListNode* next2 = callme2(l1, next);
        // }else{ // n1 < n2

        // }
        if(n1 > n2){
            ListNode* node = l1;
            while(n1 > n2)
                node = node->next, n1--;
            callme(node, l2);
            normalizer(l1);
            if(l1->val > 9){
                ListNode* root = new ListNode(1);
                root->next = l1;
                l1->val -= 10;
                return root;
            }else
                return l1;
        }else if(n2 > n1){
            ListNode* node = l2;
            while(n2 > n1)
                node = node->next, n2--;
            callme(node, l1);
            normalizer(l2);
            if(l2->val > 9){
                ListNode* root = new ListNode(1);
                root->next = l2;
                l2->val -= 10;
                return root;
            }else
                return l2;
        }else{
            callme(l1, l2);
            normalizer(l1);
            if(l1 != NULL && l1->val > 9){
                ListNode* root = new ListNode(1);
                root->next = l1;
                l1->val -= 10;
                return root;
            }else
                return l1;
        }

    }
};
