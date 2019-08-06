/*
 * @lc app=leetcode id=945 lang=cpp
 *
 * [945] Minimum Increment to Make Array Unique
 *
 * https://leetcode.com/problems/minimum-increment-to-make-array-unique/description/
 *
 * algorithms
 * Medium (43.31%)
 * Total Accepted:    12.2K
 * Total Submissions: 28.3K
 * Testcase Example:  '[1,2,2]'
 *
 * Given an array of integers A, a move consists of choosing any A[i], and
 * incrementing it by 1.
 * 
 * Return the least number of moves to make every value in A unique.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,2]
 * Output: 1
 * Explanation:  After 1 move, the array could be [1, 2, 3].
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,2,1,2,1,7]
 * Output: 6
 * Explanation:  After 6 moves, the array could be [3, 4, 1, 2, 5, 7].
 * It can be shown with 5 or less moves that it is impossible for the array to
 * have all unique values.
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 0 <= A.length <= 40000
 * 0 <= A[i] < 40000
 * 
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    int find(unordered_map<int, int>& mm, int x){
        if(mm.find(x)!=mm.end()){
            mm[x] = find(mm, mm[x]);
            return mm[x];
        }
        // mm[x] = x+1;
        return x;
    }
    int minIncrementForUnique(vector<int>& A) {
        unordered_map<int, int> next;
        int ans = 0;
        for(auto e: A){
            if(next.find(e)==next.end()){
                next[e] = find(next, e+1);
            }else{
                int x = e;
                int y = find(next, x);
                // cout<<x<<">"<<y<<" ";
                next[y] = y+1;
                ans += y - x;
            }
        }
        return ans;
    }
};
