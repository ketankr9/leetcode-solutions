/*
 * @lc app=leetcode id=1261 lang=java
 *
 * [1261] Find Elements in a Contaminated Binary Tree
 *
 * https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/description/
 *
 * algorithms
 * Medium (72.70%)
 * Likes:    104
 * Dislikes: 26
 * Total Accepted:    10.8K
 * Total Submissions: 14.9K
 * Testcase Example:  '["FindElements","find","find"]\r\n[[[-1,null,-1]],[1],[2]]\r'
 *
 * Given a binary tree with the following rules:
 * 
 * 
 * root.val == 0
 * If treeNode.val == x and treeNode.left != null, then treeNode.left.val == 2
 * * x + 1
 * If treeNode.val == x and treeNode.right != null, then treeNode.right.val ==
 * 2 * x + 2
 * 
 * 
 * Now the binary tree is contaminated, which means all treeNode.val have been
 * changed to -1.
 * 
 * You need to first recover the binary tree and then implement the
 * FindElements class:
 * 
 * 
 * FindElements(TreeNode* root) Initializes the object with a contamined binary
 * tree, you need to recover it first.
 * bool find(int target) Return if the target value exists in the recovered
 * binary tree.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input
 * ["FindElements","find","find"]
 * [[[-1,null,-1]],[1],[2]]
 * Output
 * [null,false,true]
 * Explanation
 * FindElements findElements = new FindElements([-1,null,-1]); 
 * findElements.find(1); // return False 
 * findElements.find(2); // return True 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input
 * ["FindElements","find","find","find"]
 * [[[-1,-1,-1,-1,-1]],[1],[3],[5]]
 * Output
 * [null,true,true,false]
 * Explanation
 * FindElements findElements = new FindElements([-1,-1,-1,-1,-1]);
 * findElements.find(1); // return True
 * findElements.find(3); // return True
 * findElements.find(5); // return False
 * 
 * Example 3:
 * 
 * 
 * 
 * 
 * Input
 * ["FindElements","find","find","find","find"]
 * [[[-1,null,-1,-1,null,-1]],[2],[3],[4],[5]]
 * Output
 * [null,true,false,false,true]
 * Explanation
 * FindElements findElements = new FindElements([-1,null,-1,-1,null,-1]);
 * findElements.find(2); // return True
 * findElements.find(3); // return False
 * findElements.find(4); // return False
 * findElements.find(5); // return True
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * TreeNode.val == -1
 * The height of the binary tree is less than or equal to 20
 * The total number of nodes is between [1, 10^4]
 * Total calls of find() is between [1, 10^4]
 * 0 <= target <= 10^6
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
class FindElements {
	private TreeNode head;

	private void callme(TreeNode root){
		if(root == null)	return ;
		callme(root.left);
		callme(root.right);
		if(root.left != null)
			root.left.val = root.val*2+1;
		if(root.right != null)
			root.right.val = root.val*2+2;
	}

    public FindElements(TreeNode root) {
        if(root != null)	root.val = 0;
        head = root;
    }
    
    private boolean find_(TreeNode root, List<Boolean> arr, int i){
    	if(i == -1)
    		return root != null;
    	if(root == null)
    		return false;

    	if(arr.get(i)) // true
    		return find_(root.right, arr, i-1);
    	
    	return find_(root.left, arr, i-1);
    }
    public boolean find(int target) {
        List<Boolean> arr = new ArrayList<Boolean>();
        while(target != 0){
        	arr.add((((target-1) & 1) == 1) ? true : false);
        	target = (target-1)/2;
        }
        // System.out.println(arr);
        return find_(head, arr, arr.size()-1);
    }
}

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements obj = new FindElements(root);
 * boolean param_1 = obj.find(target);
 */
// @lc code=end
