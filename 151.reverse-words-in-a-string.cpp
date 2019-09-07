/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 *
 * https://leetcode.com/problems/reverse-words-in-a-string/description/
 *
 * algorithms
 * Medium (17.67%)
 * Total Accepted:    307K
 * Total Submissions: 1.7M
 * Testcase Example:  '"the sky is blue"'
 *
 * Given an input string, reverse the string word by word.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "the sky is blue"
 * Output: "blue is sky the"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "  hello world!  "
 * Output: "world! hello"
 * Explanation: Your reversed string should not contain leading or trailing
 * spaces.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "a good   example"
 * Output: "example good a"
 * Explanation: You need to reduce multiple spaces between two words to a
 * single space in the reversed string.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * A word is defined as a sequence of non-space characters.
 * Input string may contain leading or trailing spaces. However, your reversed
 * string should not contain leading or trailing spaces.
 * You need to reduce multiple spaces between two words to a single space in
 * the reversed string.
 * 
 * 
 * 
 * 
 * Follow up:
 * 
 * For C programmers, try to solve it in-place in O(1) extra space.
 */
class Solution {
public:
	void reverseij(int start, int end, string& st){
		while(start<end)
			swap(st[start++], st[--end]);
	}

    string reverseWords(string s) {
    	int n = s.size();
    	reverseij(0, n, s);
    	int i = 0;
    	while(i<n){
    		while(i<n && s[i] == ' ')
    			i++;
    		int start = i;
    		while(i<n && s[i] != ' ')
    			i++;
    		reverseij(start, i, s);
    	}
    	int j = 0;
    	i = 0;

    	// starting spaces
	    while(j<n && s[j] == ' ')
	    	j++;
	    
	    while(j<n){
	    	if(s[j] != ' '){
	    		s[i++] = s[j++];
	    		continue;
	    	}
	    	s[i++] = s[j++]; //add one space

	    	while(j<n && s[j]==' ')	j++; //remove extra spaces
	    }

	    return s.substr(0, (i-1<n&&i>=1&&s[i-1]==' ')?i-1:i);
    }

};
