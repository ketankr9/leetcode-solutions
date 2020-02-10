/*
 * @lc app=leetcode id=844 lang=cpp
 *
 * [844] Backspace String Compare
 *
 * https://leetcode.com/problems/backspace-string-compare/description/
 *
 * algorithms
 * Easy (47.14%)
 * Likes:    1009
 * Dislikes: 60
 * Total Accepted:    98K
 * Total Submissions: 207.9K
 * Testcase Example:  '"ab#c"\n"ad#c"'
 *
 * Given two strings S and T, return if they are equal when both are typed into
 * empty text editors. # means a backspace character.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: S = "ab#c", T = "ad#c"
 * Output: true
 * Explanation: Both S and T become "ac".
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: S = "ab##", T = "c#d#"
 * Output: true
 * Explanation: Both S and T become "".
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: S = "a##c", T = "#a#c"
 * Output: true
 * Explanation: Both S and T become "c".
 * 
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: S = "a#c", T = "b"
 * Output: false
 * Explanation: S becomes "c" while T becomes "b".
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= S.length <= 200
 * 1 <= T.length <= 200
 * S and T only contain lowercase letters and '#' characters.
 * 
 * 
 * Follow up:
 * 
 * 
 * Can you solve it in O(N) time and O(1) space?
 * 
 * 
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
	stack<char> kyon(string& s){
        stack<char> qs;
        for(auto &e: s){
        	if(e == '#'){
        		if(!qs.empty())
        			qs.pop();
        	}else
        		qs.push(e);
        }
        return qs;
	}

    bool backspaceCompare(string S, string T) {
        stack<char> qs = kyon(S), qt = kyon(T);
        
        while(!qs.empty() && !qt.empty() && qs.top() == qt.top())
        	qs.pop(), qt.pop();

        return qs.empty() && qt.empty();

    }
};
// @lc code=end
