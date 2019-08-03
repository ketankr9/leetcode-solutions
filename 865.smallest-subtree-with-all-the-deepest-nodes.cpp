/*
 * @lc app=leetcode id=865 lang=cpp
 *
 * [865] Smallest Subtree with all the Deepest Nodes
 *
 * https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/description/
 *
 * algorithms
 * Medium (56.65%)
 * Total Accepted:    20.7K
 * Total Submissions: 36.6K
 * Testcase Example:  '[3,5,1,6,2,0,8,null,null,7,4]'
 *
 * Given a binary tree rooted at root, the depth of each node is the shortest
 * distance to the root.
 * 
 * A node is deepest if it has the largest depth possible among any node in the
 * entire tree.
 * 
 * The subtree of a node is that node, plus the set of all descendants of that
 * node.
 * 
 * Return the node with the largest depth such that it contains all the deepest
 * nodes in its subtree.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [3,5,1,6,2,0,8,null,null,7,4]
 * Output: [2,7,4]
 * Explanation:
 * 
 * 
 * 
 * We return the node with value 2, colored in yellow in the diagram.
 * The nodes colored in blue are the deepest nodes of the tree.
 * The input "[3, 5, 1, 6, 2, 0, 8, null, null, 7, 4]" is a serialization of
 * the given tree.
 * The output "[2, 7, 4]" is a serialization of the subtree rooted at the node
 * with value 2.
 * Both the input and output have TreeNode type.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The number of nodes in the tree will be between 1 and 500.
 * The values of each node are unique.
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
class Solution {
public:
    TreeNode* ans;
    int maxd;
    int callme(int d, TreeNode* root){
        if(root == NULL)    return d;
        int x = callme(d+1, root->left);
        int y = callme(d+1, root->right);
        if(x == y && x >= maxd){
            maxd = x;
            ans = root;
        }
        // else if( x < y){
        //     // if(root->right!=NULL)
        //         // cout<<root->right->val<<" ";
        // }else{
        //     // if(root->left!=NULL)
        //         // cout<<root->left->val<<" ";
        // }
        return max(x, y);
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        ans = NULL;
        maxd = -1;
        callme(0, root);
        return ans;
    }
};
