/*
 * @lc app=leetcode id=856 lang=cpp
 *
 * [856] Score of Parentheses
 *
 * https://leetcode.com/problems/score-of-parentheses/description/
 *
 * algorithms
 * Medium (56.95%)
 * Total Accepted:    20.9K
 * Total Submissions: 36.7K
 * Testcase Example:  '"()"'
 *
 * Given a balanced parentheses string S, compute the score of the string based
 * on the following rule:
 * 
 * 
 * () has score 1
 * AB has score A + B, where A and B are balanced parentheses strings.
 * (A) has score 2 * A, where A is a balanced parentheses string.
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "()"
 * Output: 1
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "(())"
 * Output: 2
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "()()"
 * Output: 2
 * 
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "(()(()))"
 * Output: 6
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * S is a balanced parentheses string, containing only ( and ).
 * 2 <= S.length <= 50
 * 
 * 
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int> st;

        for(auto e: S){
            if(e == '(')
                st.push(-1);
            else if(e == ')' && st.top() == -1)
                st.pop(), st.push(1);
            else if(e == ')'){
                int sum = 0;
                while(st.top() != -1)
                    sum += st.top(), st.pop();
                st.pop();// remove '('
                st.push(sum*2);
            }
        }
        int ans = 0;
        while(!st.empty())
            ans += st.top(), st.pop();
        return ans;
    }
};
