/*
 * @lc app=leetcode id=227 lang=cpp
 *
 * [227] Basic Calculator II
 *
 * https://leetcode.com/problems/basic-calculator-ii/description/
 *
 * algorithms
 * Medium (34.40%)
 * Total Accepted:    125.7K
 * Total Submissions: 365.6K
 * Testcase Example:  '"3+2*2"'
 *
 * Implement a basic calculator to evaluate a simple expression string.
 * 
 * The expression string contains only non-negative integers, +, -, *, /
 * operators and empty spaces  . The integer division should truncate toward
 * zero.
 * 
 * Example 1:
 * 
 * 
 * Input: "3+2*2"
 * Output: 7
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: " 3/2 "
 * Output: 1
 * 
 * Example 3:
 * 
 * 
 * Input: " 3+5 / 2 "
 * Output: 5
 * 
 * 
 * Note:
 * 
 * 
 * You may assume that the given expression is always valid.
 * Do not use the eval built-in library function.
 * 
 * 
 */
class Solution {
public:
	bool isnum(char c){
		return c >= '0' && c <= '9';
	}

	void removespace(int& i, string& s){
		while(i<s.size() && s[i] == ' ')
        		i++;
	}
	
	int nextnum(int& i, string& s){
		int mul = (s[i]=='-'?-1:1);
		if(!isnum(s[i])) i++;
		removespace(i, s);
		int num = 0;
		while(i<s.size() && isnum(s[i]))
			num = num*10+(s[i++]-'0');
		return num*mul;
	}

    int calculate(string s) {
    	if(s.size() == 0)	return 0;

        int i = 0;
        while(i<s.size() && s[i] == ' ')
        	i++;        
        stack<int> st;
     
        while(i<s.size()){
        	removespace(i, s);
        	if(s[i] == '*'){
        		i++;
        		int top = st.top(); st.pop();
        		st.push(top*nextnum(i, s));	
        	}else if(s[i] == '/'){
        		i++;
        		int top = st.top(); st.pop();
        		st.push(top/nextnum(i, s));
        	}else if(s[i] == '+' || s[i] == '-' || isnum(s[i])){
        		st.push(nextnum(i, s));
        	}
        }
        int ans = 0;
        while(!st.empty())
        	ans += st.top(), st.pop();
        return ans;
    }
};
