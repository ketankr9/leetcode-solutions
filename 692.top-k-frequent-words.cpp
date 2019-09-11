/*
 * @lc app=leetcode id=692 lang=cpp
 *
 * [692] Top K Frequent Words
 *
 * https://leetcode.com/problems/top-k-frequent-words/description/
 *
 * algorithms
 * Medium (47.00%)
 * Total Accepted:    81.5K
 * Total Submissions: 173.4K
 * Testcase Example:  '["i", "love", "leetcode", "i", "love", "coding"]\n2'
 *
 * Given a non-empty list of words, return the k most frequent elements.
 * Your answer should be sorted by frequency from highest to lowest. If two
 * words have the same frequency, then the word with the lower alphabetical
 * order comes first.
 * 
 * Example 1:
 * 
 * Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
 * Output: ["i", "love"]
 * Explanation: "i" and "love" are the two most frequent words.
 * ⁠   Note that "i" comes before "love" due to a lower alphabetical order.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is",
 * "is"], k = 4
 * Output: ["the", "is", "sunny", "day"]
 * Explanation: "the", "is", "sunny" and "day" are the four most frequent
 * words,
 * ⁠   with the number of occurrence being 4, 3, 2 and 1 respectively.
 * 
 * 
 * 
 * Note:
 * 
 * You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 * Input words contain only lowercase letters.
 * 
 * 
 * 
 * Follow up:
 * 
 * Try to solve it in O(n log k) time and O(n) extra space.
 * 
 * 
 */
class Solution {
public:
	typedef pair<int, string> pr;
	#define f first
	#define s second
	struct comp{
		bool operator()(pr& a, pr& b){
			if(a.f == b.f)	return a.s < b.s;
			return a.f > b.f;
		}
	};
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mm;
        for(auto &s: words)
        	mm[s]++;

        priority_queue<pr, vector<pr>, comp> pq;
        for(auto &it: mm){
        	pq.push({it.second, it.first});
        	if(pq.size() == k+1)
        		pq.pop();
        }
        vector<string> vec(pq.size());
        int i = pq.size();
        while(!pq.empty())
        	vec[--i] = pq.top().s, pq.pop();
        
        return vec;
    }	
};
