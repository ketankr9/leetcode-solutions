/*
 * @lc app=leetcode id=1234 lang=cpp
 *
 * [1234] Replace the Substring for Balanced String
 *
 * https://leetcode.com/problems/replace-the-substring-for-balanced-string/description/
 *
 * algorithms
 * Medium (29.35%)
 * Total Accepted:    4.4K
 * Total Submissions: 14.8K
 * Testcase Example:  '"QWER"'
 *
 * You are given a string containing only 4 kinds of characters 'Q', 'W', 'E'
 * and 'R'.
 * 
 * A string is said to be balanced if each of its characters appears n/4 times
 * where n is the length of the string.
 * 
 * Return the minimum length of the substring that can be replaced with any
 * other string of the same length to make the original string s balanced.
 * 
 * Return 0 if the string is already balanced.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "QWER"
 * Output: 0
 * Explanation: s is already balanced.
 * 
 * Example 2:
 * 
 * 
 * Input: s = "QQWE"
 * Output: 1
 * Explanation: We need to replace a 'Q' to 'R', so that "RQWE" (or "QRWE") is
 * balanced.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "QQQW"
 * Output: 2
 * Explanation: We can replace the first "QQ" to "ER". 
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: s = "QQQQ"
 * Output: 3
 * Explanation: We can replace the last 3 'Q' to make s = "QWER".
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^5
 * s.length is a multiple of 4
 * s contains only 'Q', 'W', 'E' and 'R'.
 * 
 * 
 */
class Solution {
public:
	int g(char c){
		if(c == 'Q')
			return 0;
		else if(c == 'W')
			return 1;
		else if(c == 'E')
			return 2;
		return 3;
	}

    int balancedString(string s) {
        vector<int> req(4, 0);
        int n = (int)s.size()/4;
        
        for(auto& e: s)
        	req[g(e)]++;

        for(int i=0; i<4; i++)
        	req[i] = max(0, req[i]-n);
        
        int j = 0, ans = INT_MAX;
        vector<int> cur(4, 0);
        
        for(int i = 0; i<n*4; i++){
        	cur[g(s[i])]++;
        	
        	while(j<=i && cur[g(s[j])] > req[g(s[j])])
        		cur[g(s[j++])]--;

        	if(cur[0] >= req[0] && cur[1] >= req[1] && 
        		cur[2] >= req[2] && cur[3] >= req[3])
        		ans = min(ans, i-j+1);
        }

        return ans;
    }
};
