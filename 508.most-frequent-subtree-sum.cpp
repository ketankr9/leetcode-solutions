/*
 * @lc app=leetcode id=508 lang=cpp
 *
 * [508] Most Frequent Subtree Sum
 *
 * https://leetcode.com/problems/most-frequent-subtree-sum/description/
 *
 * algorithms
 * Medium (53.56%)
 * Total Accepted:    46.9K
 * Total Submissions: 86.5K
 * Testcase Example:  '[5,2,-3]'
 *
 * 
 * Given the root of a tree, you are asked to find the most frequent subtree
 * sum. The subtree sum of a node is defined as the sum of all the node values
 * formed by the subtree rooted at that node (including the node itself). So
 * what is the most frequent subtree sum value? If there is a tie, return all
 * the values with the highest frequency in any order.
 * 
 * 
 * Examples 1
 * Input:
 * 
 * ⁠ 5
 * ⁠/  \
 * 2   -3
 * 
 * return [2, -3, 4], since all the values happen only once, return all of them
 * in any order.
 * 
 * 
 * Examples 2
 * Input:
 * 
 * ⁠ 5
 * ⁠/  \
 * 2   -5
 * 
 * return [2], since 2 happens twice, however -5 only occur once.
 * 
 * 
 * Note:
 * You may assume the sum of values in any subtree is in the range of 32-bit
 * signed integer.
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
    unordered_map<int, int> freq;
    int subSum(TreeNode* root){
        if(root == NULL)
            return 0;
        int root_sum = root->val + subSum(root->left) + subSum(root->right);
        freq[root_sum]++;
        return root_sum;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        freq.clear();
        vector<int> ans;
        subSum(root);
        int max_freq = INT_MIN;
        for(auto it=freq.begin(); it!=freq.end(); it++){
            // cout<<it->first<<" "<<it->second<<"; ";
            if(it->second > max_freq){
                ans.clear();
                max_freq = it->second;
                ans.push_back(it->first);
            }else if(it->second == max_freq)
                ans.push_back(it->first);
        }
        return ans;
    }
};
