/*
 * @lc app=leetcode id=1361 lang=cpp
 *
 * [1361] Validate Binary Tree Nodes
 *
 * https://leetcode.com/problems/validate-binary-tree-nodes/description/
 *
 * algorithms
 * Medium (66.30%)
 * Likes:    101
 * Dislikes: 22
 * Total Accepted:    7.3K
 * Total Submissions: 11K
 * Testcase Example:  '4\n[1,-1,3,-1]\n[2,-1,-1,-1]'
 *
 * You have n binary tree nodes numbered from 0 to n - 1 where node i has two
 * children leftChild[i] and rightChild[i], return true if and only if all the
 * given nodes form exactly one valid binary tree.
 * 
 * If node i has no left child then leftChild[i] will equal -1, similarly for
 * the right child.
 * 
 * Note that the nodes have no values and that we only use the node numbers in
 * this problem.
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: n = 4, leftChild = [1,-1,3,-1], rightChild = [2,-1,-1,-1]
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: n = 4, leftChild = [1,-1,3,-1], rightChild = [2,3,-1,-1]
 * Output: false
 * 
 * 
 * Example 3:
 * 
 * 
 * 
 * 
 * Input: n = 2, leftChild = [1,0], rightChild = [-1,-1]
 * Output: false
 * 
 * 
 * Example 4:
 * 
 * 
 * 
 * 
 * Input: n = 6, leftChild = [1,-1,-1,4,-1,-1], rightChild = [2,-1,-1,5,-1,-1]
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 10^4
 * leftChild.length == rightChild.length == n
 * -1 <= leftChild[i], rightChild[i] <= n - 1
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int root;
    bool loop;
    void visit(int u, vector<bool>& visited, vector<int>& leftChild, vector<int>& rightChild){
        if(visited[u])
            return;
        
        visited[u] = true;

        if(leftChild[u] != -1)
            visit(leftChild[u], visited, leftChild, rightChild);
        
        if(rightChild[u] != -1)
            visit(rightChild[u], visited, leftChild, rightChild);
        
        root = u;
        // cout<<u<<" ";
    }
    
    void traverseTree(int u, vector<bool>& visited, vector<int>& leftChild, vector<int>& rightChild){
        if(u == -1) return;
        if(visited[u] || loop){
            loop = true;
            return;
        }
        visited[u] = true;
        traverseTree(leftChild[u], visited, leftChild, rightChild);
        traverseTree(rightChild[u], visited, leftChild, rightChild);
    }

    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<bool> visited(n, false);
        loop = false;
        root = -1;

        for(int i=n-1; i>=0; i--)
            visit(i, visited, leftChild, rightChild);

        fill_n(visited.begin(), n, false);

        traverseTree(root, visited, leftChild, rightChild);

        if(loop)    return false;

        for(bool e: visited)
            if(!e)  return false;

        return true;
    }
};
// @lc code=end
