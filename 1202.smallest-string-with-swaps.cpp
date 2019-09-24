/*
 * @lc app=leetcode id=1202 lang=cpp
 *
 * [1202] Smallest String With Swaps
 *
 * https://leetcode.com/problems/smallest-string-with-swaps/description/
 *
 * algorithms
 * Medium (36.90%)
 * Total Accepted:    2.9K
 * Total Submissions: 7.9K
 * Testcase Example:  '"dcab"\n[[0,3],[1,2]]'
 *
 * You are given a string s, and an array of pairs of indices in the string
 * pairs where pairs[i] = [a, b] indicates 2 indices(0-indexed) of the string.
 * 
 * You can swap the characters at any pair of indices in the given pairs any
 * number of times.
 * 
 * Return the lexicographically smallest string that s can be changed to after
 * using the swaps.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "dcab", pairs = [[0,3],[1,2]]
 * Output: "bacd"
 * Explaination: 
 * Swap s[0] and s[3], s = "bcad"
 * Swap s[1] and s[2], s = "bacd"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "dcab", pairs = [[0,3],[1,2],[0,2]]
 * Output: "abcd"
 * Explaination: 
 * Swap s[0] and s[3], s = "bcad"
 * Swap s[0] and s[2], s = "acbd"
 * Swap s[1] and s[2], s = "abcd"
 * 
 * Example 3:
 * 
 * 
 * Input: s = "cba", pairs = [[0,1],[1,2]]
 * Output: "abc"
 * Explaination: 
 * Swap s[0] and s[1], s = "bca"
 * Swap s[1] and s[2], s = "bac"
 * Swap s[0] and s[1], s = "abc"
 * 
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^5
 * 0 <= pairs.length <= 10^5
 * 0 <= pairs[i][0], pairs[i][1] < s.length
 * s only contains lower case English letters.
 * 
 * 
 */
class Solution {
public:
    int find(vector<int>& p, int x){
        if(p[x] != x)
            return p[x] = find(p, p[x]);
        return p[x] = x;
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        vector<int> p;

        for(int i=0; i<n; i++) p.push_back(i);        
        for(auto const& pr: pairs){
            int p1 = find(p, pr[0]), p2 = find(p, pr[1]);
            if(p1 != p2)
                p[p1] = p2;
        }

        unordered_map<int, vector<int>> mm;
        for(int i=0; i<n; i++)	mm[find(p, i)].push_back(i);

        string ans = string(n, ' ');
        for(auto const& arr: mm){
        	
        	vector<int> tmp = arr.second;
        	sort(tmp.begin(), tmp.end(), [&s](const int &i, const int &j){
        		return s[i] < s[j];
        	});

        	for(int i=0; i<tmp.size(); i++)	ans[arr.second[i]] = s[tmp[i]];
        }
        return ans;
    }
};