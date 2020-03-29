/*
 * @lc app=leetcode id=1367 lang=cpp
 *
 * [1367] Linked List in Binary Tree
 *
 * https://leetcode.com/problems/linked-list-in-binary-tree/description/
 *
 * algorithms
 * Medium (39.40%)
 * Likes:    181
 * Dislikes: 9
 * Total Accepted:    7.2K
 * Total Submissions: 18.2K
 * Testcase Example:  '[4,2,8]\n[1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]'
 *
 * Given a binary tree root and a linked list with head as the first node. 
 * 
 * Return True if all the elements in the linked list starting from the head
 * correspond to some downward path connected in the binary tree otherwise
 * return False.
 * 
 * In this context downward path means a path that starts at some node and goes
 * downwards.
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: head = [4,2,8], root =
 * [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
 * Output: true
 * Explanation: Nodes in blue form a subpath in the binary Tree.  
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: head = [1,4,2,6], root =
 * [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: head = [1,4,2,6,8], root =
 * [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
 * Output: false
 * Explanation: There is no path in the binary tree that contains all the
 * elements of the linked list from head.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= node.val <= 100 for each node in the linked list and binary tree.
 * The given linked list will contain between 1 and 100 nodes.
 * The given binary tree will contain between 1 and 2500 nodes.
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	bool found;
	vector<int> vec;
	int n;
	long long M, C, val;
	void callme(long long cur, TreeNode* root){
		if(root == NULL || found)
			return;
		
		if(vec.size() >= n){
			cur = (cur-C*vec[vec.size()-n])%M;
			cur  = (cur+M)%M;
		}
		cur = (cur*10ll + root->val)%M;

		vec.push_back(root->val);
		if(cur == val && vec.size() >= n)
			found = true;

		callme(cur, root->left);
		callme(cur, root->right);
		vec.pop_back();
	}

	long long poww(int k){
		if(k == 0)	return 1ll;
		long long tmp = poww(k>>1);
		tmp = (tmp*tmp)%M;
		if(k&1)
			return (tmp*10ll)%M;
		return tmp;
	}

    bool isSubPath(ListNode* head, TreeNode* root) {
        val = 0ll;
        M = 1000000007ll;
        n = 0;
        while(head != NULL){
        	n++;
        	val = (val*10ll+head->val)%M;
        	head = head->next;
        }

        C = poww(n-1);
        vec.clear();
        found = false;

        callme(0ll, root);
        return found;
    }
};
// @lc code=end
