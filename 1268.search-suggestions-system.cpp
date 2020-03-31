/*
 * @lc app=leetcode id=1268 lang=cpp
 *
 * [1268] Search Suggestions System
 *
 * https://leetcode.com/problems/search-suggestions-system/description/
 *
 * algorithms
 * Medium (58.86%)
 * Likes:    178
 * Dislikes: 62
 * Total Accepted:    15.5K
 * Total Submissions: 26.2K
 * Testcase Example:  '["mobile","mouse","moneypot","monitor","mousepad"]\r\n"mouse"\r'
 *
 * Given an array of strings products and a string searchWord. We want to
 * design a system that suggests at most three product names from products
 * after each character of searchWord is typed. Suggested products should have
 * common prefix with the searchWord. If there are more than three products
 * with a common prefix return the three lexicographically minimums products.
 * 
 * Return list of lists of the suggested products after each character of
 * searchWord is typed. 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: products = ["mobile","mouse","moneypot","monitor","mousepad"],
 * searchWord = "mouse"
 * Output: [
 * ["mobile","moneypot","monitor"],
 * ["mobile","moneypot","monitor"],
 * ["mouse","mousepad"],
 * ["mouse","mousepad"],
 * ["mouse","mousepad"]
 * ]
 * Explanation: products sorted lexicographically =
 * ["mobile","moneypot","monitor","mouse","mousepad"]
 * After typing m and mo all products match and we show user
 * ["mobile","moneypot","monitor"]
 * After typing mou, mous and mouse the system suggests ["mouse","mousepad"]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: products = ["havana"], searchWord = "havana"
 * Output:
 * [["havana"],["havana"],["havana"],["havana"],["havana"],["havana"]]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: products = ["bags","baggage","banner","box","cloths"], searchWord =
 * "bags"
 * Output:
 * [["baggage","bags","banner"],["baggage","bags","banner"],["baggage","bags"],["bags"]]
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: products = ["havana"], searchWord = "tatiana"
 * Output: [[],[],[],[],[],[],[]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= products.length <= 1000
 * There are no repeated elements in products.
 * 1 <= Σ products[i].length <= 2 * 10^4
 * All characters of products[i] are lower-case English letters.
 * 1 <= searchWord.length <= 1000
 * All characters of searchWord are lower-case English letters.
 * 
 * 
 */

// @lc code=start

class Solution {
public:
	struct Node {
		bool isLast;
		map<char, Node*> children;
		Node(){
			isLast = false;
			children.clear();
		}
	};
	void buildTree(Node* head, string& s, int i){
		if((int)s.size() == i){
			head->isLast = true;
			return;
		}
		if(head->children.find(s[i]) == head->children.end())
			head->children[s[i]] = new Node();
		buildTree(head->children[s[i]], s, i+1);
	}

	vector<vector<string>> ans;
	vector<string> tmpvec;
	string tmpst, prefix;

	void traverse(Node* head){
		if((int)tmpvec.size() >= 3)
			return;
		
		if(head->isLast)
			tmpvec.push_back(tmpst);
		
		for(auto elem: head->children){
			tmpst += elem.first;
			traverse(elem.second);
			tmpst.pop_back();
		}
	}

	void traverseHelper(Node* head){
		tmpst = "";
		tmpvec.clear();
		if(head != NULL)
			traverse(head);
		vector<string> final;
		for(auto &e: tmpvec)
			final.push_back(prefix+e);
		ans.push_back(final);
	}

	void callme(Node* head, string& s, int i){
		if((int)s.size() == i)	return;
		prefix += s[i];
		if(head == NULL || head->children.find(s[i]) == head->children.end()){
			traverseHelper(NULL);
			callme(NULL, s, i+1);
		}else{
			traverseHelper(head->children[s[i]]);
			callme(head->children[s[i]], s, i+1);
		}
		prefix.pop_back();
	}
	
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
		Node* head = new Node();
		for(string& prod: products)
			buildTree(head, prod, 0);
		prefix = "";
		callme(head, searchWord, 0);

		return ans;
    }
};
// @lc code=end
