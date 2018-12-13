/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 *
 * https://leetcode.com/problems/copy-list-with-random-pointer/description/
 *
 * algorithms
 * Medium (25.56%)
 * Total Accepted:    201.5K
 * Total Submissions: 788.1K
 * Testcase Example:  '{}'
 *
 *
 * A linked list is given such that each node contains an additional random
 * pointer which could point to any node in the list or null.
 *
 *
 *
 * Return a deep copy of the list.
 *
 */
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL)
          return NULL;
        unordered_map<RandomListNode*, RandomListNode* > mm;
        RandomListNode* HEAD = head;
        while(head!=NULL){
            mm[head] = new RandomListNode(head->label);
            head = head->next;
        }
        head = HEAD;
        RandomListNode* headcopy = mm[head];
        HEAD = headcopy;
        while(head!=NULL){
          headcopy->next = mm[head->next];
          headcopy->random = mm[head->random];
          headcopy = headcopy->next;
          head = head->next;
        }
        return HEAD;
    }
};
