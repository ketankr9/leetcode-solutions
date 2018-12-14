/*
 * @lc app=leetcode id=954 lang=cpp
 *
 * [954] Array of Doubled Pairs
 *
 * https://leetcode.com/problems/array-of-doubled-pairs/description/
 *
 * algorithms
 * Medium (30.90%)
 * Total Accepted:    3.7K
 * Total Submissions: 11.5K
 * Testcase Example:  '[3,1,3,6]'
 *
 * Given an array of integers A with even length, return true if and only if it
 * is possible to reorder it such that A[2 * i + 1] = 2 * A[2 * i] for every 0
 * <= i < len(A) / 2.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 * Example 1:
 *
 *
 * Input: [3,1,3,6]
 * Output: false
 *
 *
 *
 * Example 2:
 *
 *
 * Input: [2,1,2,6]
 * Output: false
 *
 *
 *
 * Example 3:
 *
 *
 * Input: [4,-2,2,-4]
 * Output: true
 * Explanation: We can take two groups, [-2,-4] and [2,4] to form [-2,-4,2,4]
 * or [2,4,-2,-4].
 *
 *
 *
 * Example 4:
 *
 *
 * Input: [1,2,4,16,8,4]
 * Output: false
 *
 *
 *
 *
 * Note:
 *
 *
 * 0 <= A.length <= 30000
 * A.length is even
 * -100000 <= A[i] <= 100000
 *
 *
 *
 *
 *
 *
 */
class Solution {
public:
    bool helper(vector<int> &vec){
      sort(vec.begin(), vec.end());
      int N = vec.size();
      if(N==0)  return true;
      unordered_map<int, int> count;
      for(auto e: vec){
        count[e]++;
      }
      for(auto e: vec){
        if(count[e] == 0)  continue;
        if(count[e] > count[2*e]) return false;
        count[2*e] -= count[e];
        count[e] = 0;
        }
      return true;
      }

    bool canReorderDoubled(vector<int>& A) {
      int N = A.size();
      vector<int> positive;
      vector<int> negative;
      for(auto e: A){
        if(e >=0 )
          positive.push_back(e);
        else
          negative.push_back(-e);
      }
      return  helper(positive) && helper(negative);
    }
};
