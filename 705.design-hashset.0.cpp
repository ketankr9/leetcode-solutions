/*
 * @lc app=leetcode id=705 lang=cpp
 *
 * [705] Design HashSet
 *
 * https://leetcode.com/problems/design-hashset/description/
 *
 * algorithms
 * Easy (57.98%)
 * Likes:    228
 * Dislikes: 58
 * Total Accepted:    37.8K
 * Total Submissions: 65.2K
 * Testcase Example:  '["MyHashSet","add","add","contains","contains","add","contains","remove","contains"]\n' +
  '[[],[1],[2],[1],[3],[2],[2],[2],[2]]'
 *
 * Design a HashSet without using any built-in hash table libraries.
 * 
 * To be specific, your design should include these functions:
 * 
 * 
 * add(value): Insert a value into the HashSet. 
 * contains(value) : Return whether the value exists in the HashSet or not.
 * remove(value): Remove a value in the HashSet. If the value does not exist in
 * the HashSet, do nothing.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * MyHashSet hashSet = new MyHashSet();
 * hashSet.add(1);         
 * hashSet.add(2);         
 * hashSet.contains(1);    // returns true
 * hashSet.contains(3);    // returns false (not found)
 * hashSet.add(2);          
 * hashSet.contains(2);    // returns true
 * hashSet.remove(2);          
 * hashSet.contains(2);    // returns false (already removed)
 * 
 * 
 * 
 * Note:
 * 
 * 
 * All values will be in the range of [0, 1000000].
 * The number of operations will be in the range of [1, 10000].
 * Please do not use the built-in HashSet library.
 * 
 * 
 */

// @lc code=start
class MyHashSet {
private:
    struct Node{
        int val;
        Node *left, *right;
        Node(int val){
            this->val = val;
            left = NULL;
            right = NULL;
        }
        ~Node() {
            if(left  != nullptr) delete left;
            if(right != nullptr) delete right;
        }
    };

    bool findme(Node* head, int key){
        if(head == NULL)    return false;
        if(key == head->val)    return true;
        if(key < head->val)
            return findme(head->left, key);
        return findme(head->right, key);
    }

    Node* insert(Node* head, int key){
        if(head == NULL)    return new Node(key);
        if(key < head->val)
            head->left = insert(head->left, key);
        else if(key > head->val)
            head->right = insert(head->right, key);
        return head;
    }

    void removeHelper(Node* head, int key){
        if(head == NULL)    return;
        if(head->left != NULL && head->left->val == key){
            Node* tmp = head->left->left;
            head->left->left = NULL;
            head->left = head->left->right;
            while(head->left != NULL)
                head = head->left;
            head->left = tmp;
        }else if(head->right != NULL && head->right->val == key){
            Node* tmp = head->right->right;
            head->right->right = NULL;
            head->right = head->right->left;
            while(head->right != NULL)
                head = head->right;
            head->right = tmp;
        }else if(key < head->val)
            removeHelper(head->left, key);
        else if(key > head->val)
            removeHelper(head->right, key);
    }
public:
    /** Initialize your data structure here. */
    Node* root;
    MyHashSet() {
        root = new Node(-1); //dummy value just to ease the deletion of otherwise root
    }

    void add(int key) {
        root = insert(root, key);
    }

    void remove(int key) {
        removeHelper(root, key);
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return findme(root, key);
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
// @lc code=end
