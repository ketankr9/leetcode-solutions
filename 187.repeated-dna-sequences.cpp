/*
 * @lc app=leetcode id=187 lang=cpp
 *
 * [187] Repeated DNA Sequences
 *
 * https://leetcode.com/problems/repeated-dna-sequences/description/
 *
 * algorithms
 * Medium (36.83%)
 * Total Accepted:    135.6K
 * Total Submissions: 365.6K
 * Testcase Example:  '"AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"'
 *
 * All DNA is composed of a series of nucleotides abbreviated as A, C, G, and
 * T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to
 * identify repeated sequences within the DNA.
 * 
 * Write a function to find all the 10-letter-long sequences (substrings) that
 * occur more than once in a DNA molecule.
 * 
 * Example:
 * 
 * 
 * Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
 * 
 * Output: ["AAAAACCCCC", "CCCCCAAAAA"]
 * 
 * 
 */
class Solution {
public:
	int base;
	int p(char c){
		if(c == 'A')
			return 1;
		if(c == 'C')
			return 2;
		if(c == 'G')
			return 3;
		if(c == 'T')
			return 4;
		return -1;
	}

	string rev(int num){
		vector<char> cmap = {'A', 'C', 'G', 'T'};
		string ret = "";
		int cnt = 10;
		while(cnt--){
			ret = cmap[(num-1+5)%5] + ret;
			num/=5;
		}
		return ret;
	}
    vector<string> findRepeatedDnaSequences(string s) {
        int cur = 0;
        base = 5;
        int p5 = (int)pow(5, 9);
        unordered_map<int, int> mm;
        for(int i=0; i<s.size(); i++){
        	cur%=p5;
        	cur = cur*5 + p(s[i]);
        	if(i<9)	continue;
        	mm[cur]++;
        }
        vector<string> ans;
        for(auto const& m: mm){
        	if(m.second == 1)	continue;
        	ans.push_back(rev(m.first));
        }
        return ans;
    }
};
