/*
 * @lc app=leetcode id=677 lang=cpp
 *
 * [677] Map Sum Pairs
 *
 * https://leetcode.com/problems/map-sum-pairs/description/
 *
 * algorithms
 * Medium (52.00%)
 * Total Accepted:    28.1K
 * Total Submissions: 54K
 * Testcase Example:  '["MapSum", "insert", "sum", "insert", "sum"]\n[[], ["apple",3], ["ap"], ["app",2], ["ap"]]'
 *
 * 
 * Implement a MapSum class with insert, and sum methods.
 * 
 * 
 * 
 * For the method insert, you'll be given a pair of (string, integer). The
 * string represents the key and the integer represents the value. If the key
 * already existed, then the original key-value pair will be overridden to the
 * new one.
 * 
 * 
 * 
 * For the method sum, you'll be given a string representing the prefix, and
 * you need to return the sum of all the pairs' value whose key starts with the
 * prefix.
 * 
 * 
 * Example 1:
 * 
 * Input: insert("apple", 3), Output: Null
 * Input: sum("ap"), Output: 3
 * Input: insert("app", 2), Output: Null
 * Input: sum("ap"), Output: 5
 * 
 * 
 * 
 */
class MapSum {
public:
    /** Initialize your data structure here. */
    struct Node{
        char ch;
        int val;
        bool last;
        unordered_map<char, Node*> child;
        Node(char c){ ch = c; child.clear(); last = false; val = 0;}
    };
    Node* head; 
    MapSum() {
        head = new Node('#');
    }
    
    void insert(string key, int val) {
        Node* root = head;

        for(int i=0; i<(int)key.size(); i++)
            root = root->child.find(key[i])==root->child.end()?root->child[key[i]] = new Node(key[i]):root->child[key[i]];

        root->val = val;
        root->last = true;
    }
    
    int dfs(Node* root){
        int sum = 0;
        
        for(auto node: root->child)
            sum += dfs(node.second);
    
        return sum + root->val;
    }
    int sum(string pre) {
        int ans = 0;
        Node* root = head;
        
        for(int i=0; i<(int)pre.size(); i++){
            if(root->child.find(pre[i])==root->child.end()) return 0;
            root = root->child[pre[i]];
        }
        
        return ans + dfs(root);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
