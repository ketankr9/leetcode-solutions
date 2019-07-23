/*
 * @lc app=leetcode id=1016 lang=cpp
 *
 * [1016] Binary String With Substrings Representing 1 To N
 *
 * https://leetcode.com/problems/binary-string-with-substrings-representing-1-to-n/description/
 *
 * algorithms
 * Medium (60.14%)
 * Total Accepted:    7.6K
 * Total Submissions: 12.6K
 * Testcase Example:  '"0110"\n3'
 *
 * Given a binary string S (a string consisting only of '0' and '1's) and a
 * positive integer N, return true if and only if for every integer X from 1 to
 * N, the binary representation of X is a substring of S.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: S = "0110", N = 3
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: S = "0110", N = 4
 * Output: false
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= S.length <= 1000
 * 1 <= N <= 10^9
 * 
 * 
 */
class Solution {
public:
    bool queryString(string S, int N) {
        int n = S.size();

        int cnt = 0;
        int i = 0;
        
        vector<bool> ans(N+1, false);

        while(i<n){
            if(S[i] == '0'){ i++; continue; }

            int tmp = 0;
            for(int k=i; k<min(i+31, n); k++){
                tmp = (tmp<<1) + (S[k] == '1');
                if(tmp<=N && !ans[tmp])
                    ans[tmp] = true, cnt++;
                if(tmp > N)
                    break;
            }
            i++;
        }

        return (cnt - (ans[0] == true)) == N;
    }
};
