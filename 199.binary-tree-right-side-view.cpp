/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
 *
 * https://leetcode.com/problems/binary-tree-right-side-view/description/
 *
 * algorithms
 * Medium (48.49%)
 * Likes:    1124
 * Dislikes: 51
 * Total Accepted:    176.1K
 * Total Submissions: 363.2K
 * Testcase Example:  '[1,2,3,null,5,null,4]'
 *
 * Given a binary tree, imagine yourself standing on the right side of it,
 * return the values of the nodes you can see ordered from top to bottom.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3,null,5,null,4]
 * Output: [1, 3, 4]
 * Explanation:
 * 
 * ⁠  1            <---
 * ⁠/   \
 * 2     3         <---
 * ⁠\     \
 * ⁠ 5     4       <---
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
    // vector<int> sside;
    // vector<int> ans;
    // void callme(int level, int side, TreeNode* root){
    //     if(root == NULL)    return;

    //     if(level+1>(int)ans.size()){
    //         ans.resize(level+1);
    //         sside.resize(level+1, INT_MIN);
    //     }
    //     if(sside[level] <= side){
    //         sside[level] = side;
    //         ans[level] = root->val;
    //     }
    //     callme(level+1, side-1, root->left);
    //     callme(level+1, side+1, root->right);
    // }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> q;
        if(root!=NULL)
            q.push(root);
        while(!q.empty()){
            queue<TreeNode*> tmp;
            int last;
            while(!q.empty()){
                TreeNode* ele = q.front(); q.pop();
                if(ele->left!=NULL)
                    tmp.push(ele->left);
                if(ele->right!=NULL)
                    tmp.push(ele->right);
                last = ele->val;
            }
            ans.push_back(last);
            q = tmp;
        }
        return ans;
    }
};

