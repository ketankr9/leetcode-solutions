/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 *
 * https://leetcode.com/problems/regular-expression-matching/description/
 *
 * algorithms
 * Hard (24.97%)
 * Likes:    2590
 * Dislikes: 500
 * Total Accepted:    303.6K
 * Total Submissions: 1.2M
 * Testcase Example:  '"aa"\n"a"'
 *
 * Given an input string (s) and a pattern (p), implement regular expression
 * matching with support for '.' and '*'.
 * 
 * 
 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.
 * 
 * 
 * The matching should cover the entire input string (not partial).
 * 
 * Note:
 * 
 * 
 * s could be empty and contains only lowercase letters a-z.
 * p could be empty and contains only lowercase letters a-z, and characters
 * like . or *.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * s = "aa"
 * p = "a"
 * Output: false
 * Explanation: "a" does not match the entire string "aa".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * s = "aa"
 * p = "a*"
 * Output: true
 * Explanation: '*' means zero or more of the precedeng element, 'a'.
 * Therefore, by repeating 'a' once, it becomes "aa".
 * 
 * 
 * Example 3:
 * 
 * 
 * Input:
 * s = "ab"
 * p = ".*"
 * Output: true
 * Explanation: ".*" means "zero or more (*) of any character (.)".
 * 
 * 
 * Example 4:
 * 
 * 
 * Input:
 * s = "aab"
 * p = "c*a*b"
 * Output: true
 * Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore
 * it matches "aab".
 * 
 * 
 * Example 5:
 * 
 * 
 * Input:
 * s = "mississippi"
 * p = "mis*is*p*."
 * Output: false
 * 
 * 
 */
class Solution {
public:
    bool isMatch(string s, string p) {
        s = '#'+s;
        p = '#'+p;
        int ns = s.size(), np = p.size();
        bool arr[ns][np];
        
        for(int i=1; i<ns; i++)
            arr[i][0] = false;
        for(int i=1; i<np; i++)
            arr[0][i] = false;
        arr[0][0] = true;

        for(int i=0; i<ns; i++){
            for(int j=1; j<np; j++){
                if(p[j] == '*'){
                    //i, j  =   leftmatch  ||  prevChar match 
                    arr[i][j] = (j>=2?arr[i][j-2]:false) || arr[i][j-1] ||  (i>=1?(arr[i-1][j] &&  (p[j-1] == '.' || (s[i] == p[j-1]))):false); 
                }else if(i>=1){
                    arr[i][j] = arr[i-1][j-1] && (p[j] == '.' || (s[i] == p[j]));
                }
            }
        }
        // for(int i=0; i<ns; i++){
        //     for(int j=0; j<np; j++){
        //         cout<<arr[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        return arr[ns-1][np-1];
        
    }
};

