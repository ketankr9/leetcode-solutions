/*
 * @lc app=leetcode id=173 lang=cpp
 *
 * [173] Binary Search Tree Iterator
 *
 * https://leetcode.com/problems/binary-search-tree-iterator/description/
 *
 * algorithms
 * Medium (50.30%)
 * Total Accepted:    225.3K
 * Total Submissions: 447.9K
 * Testcase Example:  '["BSTIterator","next","next","hasNext","next","hasNext","next","hasNext","next","hasNext"]\n[[[7,3,15,null,null,9,20]],[null],[null],[null],[null],[null],[null],[null],[null],[null]]'
 *
 * Implement an iterator over a binary search tree (BST). Your iterator will be
 * initialized with the root node of a BST.
 * 
 * Calling next() will return the next smallest number in the BST.
 * 
 * 
 * 
 * 
 * 
 * 
 * Example:
 * 
 * 
 * 
 * 
 * BSTIterator iterator = new BSTIterator(root);
 * iterator.next();    // return 3
 * iterator.next();    // return 7
 * iterator.hasNext(); // return true
 * iterator.next();    // return 9
 * iterator.hasNext(); // return true
 * iterator.next();    // return 15
 * iterator.hasNext(); // return true
 * iterator.next();    // return 20
 * iterator.hasNext(); // return false
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * next() and hasNext() should run in average O(1) time and uses O(h) memory,
 * where h is the height of the tree.
 * You may assume that next() call will always be valid, that is, there will be
 * at least a next smallest number in the BST when next() is called.
 * 
 * 
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
class BSTIterator {
public:
	int x, cur, ans, L;
	TreeNode* ROOT;
    void ll(TreeNode* root){
    	if(root == NULL)	return;
    	ll(root->left);
    	L++;
    	ll(root->right);
    }
    BSTIterator(TreeNode* root) {
        x = 0;
        ROOT = root;
        L = 0;
        ll(ROOT);
    }
    
    void dfs(TreeNode* root){
    	if(root == NULL)	return;

    	dfs(root->left);
    	if(cur++ == x)
    		ans = root->val;
    	dfs(root->right);
    }
    /** @return the next smallest number */
    int next() {
        cur = 0;
        ans = NULL;
        dfs(ROOT);

        x++;
        return ans;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
    	return L>0 && x<L; 
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
