/*
 * @lc app=leetcode id=203 lang=java
 *
 * [203] Remove Linked List Elements
 *
 * https://leetcode.com/problems/remove-linked-list-elements/description/
 *
 * algorithms
 * Easy (36.14%)
 * Total Accepted:    238.9K
 * Total Submissions: 660.8K
 * Testcase Example:  '[1,2,6,3,4,5,6]\n6'
 *
 * Remove all elements from a linked list of integers that have value val.
 * 
 * Example:
 * 
 * 
 * Input:  1->2->6->3->4->5->6, val = 6
 * Output: 1->2->3->4->5
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode removeElements(ListNode head, int val) {
        ListNode root = new ListNode(Integer.MIN_VALUE);
        ListNode tmp = root;
        root.next = head;
    	while(root.next != null){
    		if(root.next.val == val)
    			root.next = root.next.next;
    		else
    			root = root.next;
    	}
    	return tmp.next;
    }
}
