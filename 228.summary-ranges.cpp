/*
 * @lc app=leetcode id=228 lang=cpp
 *
 * [228] Summary Ranges
 *
 * https://leetcode.com/problems/summary-ranges/description/
 *
 * algorithms
 * Medium (36.43%)
 * Total Accepted:    136.3K
 * Total Submissions: 374K
 * Testcase Example:  '[0,1,2,4,5,7]'
 *
 * Given a sorted integer array without duplicates, return the summary of its
 * ranges.
 * 
 * Example 1:
 * 
 * 
 * Input:  [0,1,2,4,5,7]
 * Output: ["0->2","4->5","7"]
 * Explanation: 0,1,2 form a continuous range; 4,5 form a continuous range.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:  [0,2,3,4,6,8,9]
 * Output: ["0","2->4","6","8->9"]
 * Explanation: 2,3,4 form a continuous range; 8,9 form a continuous range.
 * 
 * 
 */
class Solution {
public:
    vector<string> summaryRanges(vector<int>& A) {
        int i = 0;
        int n = A.size();
        vector<string> ans;
        while(i<n){
            int start = i;
            while(i+1<n && A[i]+1 == A[i+1])
                i++;
            ans.push_back(start==i?to_string(A[start]):to_string(A[start])+"->"+to_string(A[i]));
            i++;
        }
        return ans;
    }
};
