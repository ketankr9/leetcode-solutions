/*
 * @lc app=leetcode id=1074 lang=cpp
 *
 * [1074] Number of Submatrices That Sum to Target
 *
 * https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/description/
 *
 * algorithms
 * Hard (58.74%)
 * Total Accepted:    3K
 * Total Submissions: 5K
 * Testcase Example:  '[[0,1,0],[1,1,1],[0,1,0]]\n0'
 *
 * Given a matrix, and a target, return the number of non-empty submatrices
 * that sum to target.
 * 
 * A submatrix x1, y1, x2, y2 is the set of all cells matrix[x][y] with x1 <= x
 * <= x2 and y1 <= y <= y2.
 * 
 * Two submatrices (x1, y1, x2, y2) and (x1', y1', x2', y2') are different if
 * they have some coordinate that is different: for example, if x1 != x1'.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: matrix = [[0,1,0],[1,1,1],[0,1,0]], target = 0
 * Output: 4
 * Explanation: The four 1x1 submatrices that only contain 0.
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: matrix = [[1,-1],[-1,1]], target = 0
 * Output: 5
 * Explanation: The two 1x2 submatrices, plus the two 2x1 submatrices, plus the
 * 2x2 submatrix.
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= matrix.length <= 300
 * 1 <= matrix[0].length <= 300
 * -1000 <= matrix[i] <= 1000
 * -10^8 <= target <= 10^8
 * 
 */
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& arr, int target) {
       int n = arr.size();
       int m = arr[0].size();
       for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                arr[i][j] += (j-1>=0?arr[i][j-1]:0);

        int ans = 0;
        for(int i=0; i<m; i++)
            for(int j=i; j<m; j++){
                int cur = 0;
                unordered_map<int, int> mm;
                mm[0] = 1;
                // cout<<"\ni:"<<i<<" j:"<<j<<" "; 
                for(int k=0; k<n; k++){
                    cur += arr[k][j]-(i-1>=0?arr[k][i-1]:0);
                    // cout<<"cur:"<<cur<<" ";
                    ans += mm[cur-target];
                    mm[cur]++;
                }
                // cout<<ans<<";;";
            }
       
       return ans;
    }
};
