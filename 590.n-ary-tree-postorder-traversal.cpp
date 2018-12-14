/*
 * @lc app=leetcode id=590 lang=cpp
 *
 * [590] N-ary Tree Postorder Traversal
 *
 * https://leetcode.com/problems/n-ary-tree-postorder-traversal/description/
 *
 * algorithms
 * Easy (64.17%)
 * Total Accepted:    18.9K
 * Total Submissions: 29.4K
 * Testcase Example:  '{"$id":"1","children":[{"$id":"2","children":[{"$id":"5","children":[],"val":5},{"$id":"6","children":[],"val":6}],"val":3},{"$id":"3","children":[],"val":2},{"$id":"4","children":[],"val":4}],"val":1}'
 *
 * Given an n-ary tree, return the postorder traversal of its nodes' values.
 *
 * For example, given a 3-ary tree:
 *
 *
 *
 *
 *
 *
 *
 * Return its postorder traversal as: [5,6,3,2,4,1].
 *
 *
 * Note:
 *
 * Recursive solution is trivial, could you do it iteratively?
 *
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> postorder(Node* root) {
      stack<Node*> stk;
      vector<int> res;
      if(root == NULL)  return res;
      stk.push(root);
      while(!stk.empty()){
        Node* temp = stk.top(); stk.pop();
        res.insert(res.begin(), temp->val);
        for(auto c: temp->children)
          stk.push(c);
      }
      return res;
    }
};
