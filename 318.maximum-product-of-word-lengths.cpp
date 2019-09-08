/*
 * @lc app=leetcode id=318 lang=cpp
 *
 * [318] Maximum Product of Word Lengths
 *
 * https://leetcode.com/problems/maximum-product-of-word-lengths/description/
 *
 * algorithms
 * Medium (49.16%)
 * Total Accepted:    84.3K
 * Total Submissions: 171.4K
 * Testcase Example:  '["abcw","baz","foo","bar","xtfn","abcdef"]'
 *
 * Given a string array words, find the maximum value of length(word[i]) *
 * length(word[j]) where the two words do not share common letters. You may
 * assume that each word will contain only lower case letters. If no such two
 * words exist, return 0.
 * 
 * Example 1:
 * 
 * 
 * Input: ["abcw","baz","foo","bar","xtfn","abcdef"]
 * Output: 16 
 * Explanation: The two words can be "abcw", "xtfn".
 * 
 * Example 2:
 * 
 * 
 * Input: ["a","ab","abc","d","cd","bcd","abcd"]
 * Output: 4 
 * Explanation: The two words can be "ab", "cd".
 * 
 * Example 3:
 * 
 * 
 * Input: ["a","aa","aaa","aaaa"]
 * Output: 0 
 * Explanation: No such pair of words.
 * 
 * 
 */
class Solution {
public:
	int state(string& w){
		int v = 0;
    	for(auto const& c: w)
    		v |= (1<<(c-'a'));
    	return v;
	}
    int maxProduct(vector<string>& vec) {

    	int ans = 0;
    	for(int i=0; i<vec.size(); i++)
    		for(int j=i+1; j<vec.size(); j++){
    			if((state(vec[i])&state(vec[j]))==0)
    				ans = max(ans, (int)vec[i].size()*(int)vec[j].size());
    		}
    	return ans;   
    }
};
