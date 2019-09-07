/*
 * @lc app=leetcode id=310 lang=cpp
 *
 * [310] Minimum Height Trees
 *
 * https://leetcode.com/problems/minimum-height-trees/description/
 *
 * algorithms
 * Medium (30.35%)
 * Total Accepted:    67K
 * Total Submissions: 220.5K
 * Testcase Example:  '4\n[[1,0],[1,2],[1,3]]'
 *
 * For an undirected graph with tree characteristics, we can choose any node as
 * the root. The result graph is then a rooted tree. Among all possible rooted
 * trees, those with minimum height are called minimum height trees (MHTs).
 * Given such a graph, write a function to find all the MHTs and return a list
 * of their root labels.
 * 
 * Format
 * The graph contains n nodes which are labeled from 0 to n - 1. You will be
 * given the number n and a list of undirected edges (each edge is a pair of
 * labels).
 * 
 * You can assume that no duplicate edges will appear in edges. Since all edges
 * are undirected, [0, 1] is the same as [1, 0] and thus will not appear
 * together in edges.
 * 
 * Example 1 :
 * 
 * 
 * Input: n = 4, edges = [[1, 0], [1, 2], [1, 3]]
 * 
 * ⁠       0
 * ⁠       |
 * ⁠       1
 * ⁠      / \
 * ⁠     2   3 
 * 
 * Output: [1]
 * 
 * 
 * Example 2 :
 * 
 * 
 * Input: n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]
 * 
 * ⁠    0  1  2
 * ⁠     \ | /
 * ⁠       3
 * ⁠       |
 * ⁠       4
 * ⁠       |
 * ⁠       5 
 * 
 * Output: [3, 4]
 * 
 * Note:
 * 
 * 
 * According to the definition of tree on Wikipedia: “a tree is an undirected
 * graph in which any two vertices are connected by exactly one path. In other
 * words, any connected graph without simple cycles is a tree.”
 * The height of a rooted tree is the number of edges on the longest downward
 * path between the root and a leaf.
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    	vector<int> ans;
    	if(n == 1){
    		ans.push_back(0);
    		return ans;
    	}    
        vector<unordered_set<int>> mm(n);    
         
        for(auto e: edges){
            mm[e[0]].insert(e[1]);
            mm[e[1]].insert(e[0]);
        }

        vector<bool> visited(n, false);
        queue<int> q;
        for(int i=0; i<n; i++)
        	if(mm[i].size() == 1)
        		q.push(i);
        	else if(mm[i].empty())
        		return ans;

        while(!q.empty()){
        	queue<int> next;
        	queue<int> qcopy = q;

        	while(!q.empty()){
        		int front = q.front(); q.pop();
        		for(auto e: mm[front]){
        			mm[e].erase(front);
        			if(mm[e].size()==1)
        				next.push(e);
        		}
        	}
        	if(next.empty()){
        		while(!qcopy.empty())
        			ans.push_back(qcopy.front()), qcopy.pop();
        		return ans;
        	}
        	q = next;
        }
        return ans;
    }
};
