/*
 * @lc app=leetcode id=528 lang=cpp
 *
 * [528] Random Pick with Weight
 *
 * https://leetcode.com/problems/random-pick-with-weight/description/
 *
 * algorithms
 * Medium (42.91%)
 * Total Accepted:    35.2K
 * Total Submissions: 82.1K
 * Testcase Example:  '["Solution", "pickIndex"]\n[[[1]], []]'
 *
 * Given an array w of positive integers, where w[i] describes the weight of
 * index i, write a function pickIndex which randomly picks an index in
 * proportion to its weight.
 * 
 * Note:
 * 
 * 
 * 1 <= w.length <= 10000
 * 1 <= w[i] <= 10^5
 * pickIndex will be called at most 10000 times.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 
 * ["Solution","pickIndex"]
 * [[[1]],[]]
 * Output: [null,0]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 
 * ["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]
 * [[[1,3]],[],[],[],[],[]]
 * Output: [null,0,1,1,1,0]
 * 
 * 
 * Explanation of Input Syntax:
 * 
 * The input is two lists: the subroutines called and their arguments.
 * Solution's constructor has one argument, the array w. pickIndex has no
 * arguments. Arguments are always wrapped with a list, even if there aren't
 * any.
 * 
 */
class Solution {
public:
	vector<int> prefix;
    Solution(vector<int>& w) {
        prefix.clear();
        prefix.push_back(w[0]);
        for(int i=1; i<w.size(); i++)
        	prefix.push_back(prefix.back()+w[i]);
        // for(auto e: prefix)
        // 	cout<<e<<" ";
    }
    
    int pickIndex() {
    	int r = rand();
    	// cout<<r<<":";
        int randi = r%prefix.back();
        // cout<<randi<<" ";
        auto it = upper_bound(prefix.begin(), prefix.end(), randi);
        return it-prefix.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
