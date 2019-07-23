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
        int arr[n][n];
        
        int cnt = 0;
        vector<bool> comp(N+1, false);

        for(int i = 0; i < n; i++){
            arr[i][i] = (S[i] == '1');
            // cout<<i<<":"<<i<<" "<<arr[i][i]<<endl;
            if(arr[i][i] <= N && !comp[arr[i][i]])
                    cnt++, comp[arr[i][i]] = true;
        }
        
        for(int i = 0; i+1 < n; i++){
            arr[i][i+1] = ((S[i] == '1')<<1) + (S[i+1] == '1');
            // cout<<i<<":"<<i+1<<" "<<arr[i][i+1]<<endl;
            if(arr[i][i+1] <= N && !comp[arr[i][i+1]])
                    cnt++, comp[arr[i][i+1]] = true;
        }
        
        for(int k=2; k<n; k++)
            for(int i=0; i+k<n; i++){
                if(S[i] == '1' && k >= 10)
                    arr[i][i+k] = INT_MAX;
                if( arr[i+1][i+k-1] == INT_MAX || (((long long)arr[i+1][i+k-1])<<1) >= INT_MAX )
                    arr[i][i+k] = INT_MAX;
                else if( (((long long)((long long)(S[i] == '1'))<<k) + (((long long)arr[i+1][i+k-1])<<1) + (long long)(S[i+k] == '1')) >= INT_MAX)
                    arr[i][i+k] = INT_MAX;
                else
                    arr[i][i+k] = ((long long)(S[i] == '1')<<k) + ((long long)arr[i+1][i+k-1]<<1) + (long long)(S[i+k] == '1');
                // cout<<i<<":"<<i+k<<" "<<arr[i][i+k]<<endl;
                if(arr[i][i+k] <= N && !comp[arr[i][i+k]])
                    cnt++, comp[arr[i][i+k]] = true;
            }

        return (cnt-(int)comp[0]) == N;
    }
};
