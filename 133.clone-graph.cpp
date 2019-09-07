/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 *
 * https://leetcode.com/problems/clone-graph/description/
 *
 * algorithms
 * Medium (28.18%)
 * Total Accepted:    240.1K
 * Total Submissions: 850.1K
 * Testcase Example:  '{"$id":"1","neighbors":[{"$id":"2","neighbors":[{"$ref":"1"},{"$id":"3","neighbors":[{"$ref":"2"},{"$id":"4","neighbors":[{"$ref":"3"},{"$ref":"1"}],"val":4}],"val":3}],"val":2},{"$ref":"4"}],"val":1}'
 *
 * Given a reference of a node in a connected undirected graph, return a deep
 * copy (clone) of the graph. Each node in the graph contains a val (int) and a
 * list (List[Node]) of its neighbors.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * 
 * 
 * Input:
 * 
 * {"$id":"1","neighbors":[{"$id":"2","neighbors":[{"$ref":"1"},{"$id":"3","neighbors":[{"$ref":"2"},{"$id":"4","neighbors":[{"$ref":"3"},{"$ref":"1"}],"val":4}],"val":3}],"val":2},{"$ref":"4"}],"val":1}
 * 
 * Explanation:
 * Node 1's value is 1, and it has two neighbors: Node 2 and 4.
 * Node 2's value is 2, and it has two neighbors: Node 1 and 3.
 * Node 3's value is 3, and it has two neighbors: Node 2 and 4.
 * Node 4's value is 4, and it has two neighbors: Node 1 and 3.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The number of nodes will be between 1 and 100.
 * The undirected graph is a simple graph, which means no repeated edges and no
 * self-loops in the graph.
 * Since the graph is undirected, if node p has node q as neighbor, then node q
 * must have node p as neighbor too.
 * You must return the copy of the given node as a reference to the cloned
 * graph.
 * 
 * 
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
	unordered_map<Node*, Node*> mm;

    void dfs(Node* node, unordered_set<Node*>& visited){

    	visited.insert(node);

    	if(mm.find(node)==mm.end())
    		mm[node] = new Node(node->val, vector<Node*>());

    	for(auto n: node->neighbors){
    		
    		if(mm.find(n)==mm.end())
    			mm[n] = new Node(n->val, vector<Node*>());
    		mm[node]->neighbors.push_back(mm[n]);

    		if(visited.count(n)!=0)	continue;

    		dfs(n, visited);
    	}
    }

    Node* cloneGraph(Node* node) {
    	mm.clear();
    	unordered_set<Node*> visited;
    	dfs(node, visited);
    	return mm[node];
    }
};
