/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] ZigZag Conversion
 *
 * https://leetcode.com/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (29.63%)
 * Total Accepted:    264.5K
 * Total Submissions: 890.9K
 * Testcase Example:  '"PAYPALISHIRING"\n3'
 *
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
 * of rows like this: (you may want to display this pattern in a fixed font for
 * better legibility)
 * 
 * 
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * 
 * 
 * And then read line by line: "PAHNAPLSIIGYIR"
 * 
 * Write the code that will take a string and make this conversion given a
 * number of rows:
 * 
 * 
 * string convert(string s, int numRows);
 * 
 * Example 1:
 * 
 * 
 * Input: s = "PAYPALISHIRING", numRows = 3
 * Output: "PAHNAPLSIIGYIR"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "PAYPALISHIRING", numRows = 4
 * Output: "PINALSIGYAHRPI"
 * Explanation:
 * 
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
 * 
 */
class Solution {
public:
    string convert(string s, int n) {
        int N = s.size();
        string st(N,' ');
        int i = 0;
        int k = 0;
        if(n <= 1)  return s;
        while(i < N){
            st[k] = s[i];
            i += 2*n-2;
            k++;
        }
        for(int start = 1; start < n-1; start++){
            int j;
            // odd += 2*n-2;
            j = start;
            int K = k;
            int t = K;
            while( j < N){
                st[t] = s[j];
                t+=2;
                k++;
                j+=2*n-2;
            }
            // even +=  + 2*n-2, start = 
            j = 2*n-2 - start;
            t = K+1;
            while( j < N){
                st[t] = s[j];
                k++;
                t+=2;
                j+=2*n-2; 
            }
        }
        i = n-1;
        while(i < N){
            st[k] = s[i];
            k++;
            i += 2*n-2;
        }
        return st;
    }
};
