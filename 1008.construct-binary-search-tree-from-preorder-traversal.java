/*
 * @lc app=leetcode id=1008 lang=java
 *
 * [1008] Construct Binary Search Tree from Preorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/
 *
 * algorithms
 * Medium (75.49%)
 * Likes:    628
 * Dislikes: 21
 * Total Accepted:    42.1K
 * Total Submissions: 55.7K
 * Testcase Example:  '[8,5,1,7,10,12]'
 *
 * Return the root node of a binary search tree that matches the given preorder
 * traversal.
 * 
 * (Recall that a binary search tree is a binary tree where for every node, any
 * descendant of node.left has a value < node.val, and any descendant of
 * node.right has a value > node.val.  Also recall that a preorder traversal
 * displays the value of the node first, then traverses node.left, then
 * traverses node.right.)
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [8,5,1,7,10,12]
 * Output: [8,5,10,1,7,null,12]
 * 
 * 
 * 
 * 
 * 
 * Note: 
 * 
 * 
 * 1 <= preorder.length <= 100
 * The values of preorder are distinct.
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
	TreeNode callme(int[] arr, int start, int end){ // [start, end] both inclusive
		if(start > end)
			return null;

		int mid = start+1;
		while(mid <= end && arr[mid] < arr[start])
			mid++;
		
		TreeNode root = new TreeNode(arr[start]);
		root.left = callme(arr, start+1, mid-1);
		root.right = callme(arr, mid, end);
		
		return root;
	}
    public TreeNode bstFromPreorder(int[] preorder) {
        return callme(preorder, 0, preorder.length-1);
    }
}
// @lc code=end
