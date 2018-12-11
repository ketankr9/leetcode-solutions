/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 *
 * https://leetcode.com/problems/daily-temperatures/description/
 *
 * algorithms
 * Medium (56.93%)
 * Total Accepted:    39.8K
 * Total Submissions: 69.9K
 * Testcase Example:  '[73,74,75,71,69,72,76,73]'
 *
 *
 * Given a list of daily temperatures T, return a list such that, for each day
 * in the input, tells you how many days you would have to wait until a warmer
 * temperature.  If there is no future day for which this is possible, put 0
 * instead.
 *
 * For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76,
 * 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].
 *
 *
 * Note:
 * The length of temperatures will be in the range [1, 30000].
 * Each temperature will be an integer in the range [30, 100].
 *
 */
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> stk;
        unordered_map<int, int> m;
        vector<int> ans;
        int N = (int)T.size();
        for(int i=N-1;i>=0;i--){
          if(stk.empty())
            m[T[i]] = 0, stk.push(T[i]), ans.insert(ans.begin(), 0);

          else if(T[i] < stk.top())
            m[T[i]] = 1, stk.push(T[i]), ans.insert(ans.begin(), 1);
          else{
            int count = 1;
            while(!stk.empty() && stk.top() <= T[i])
              count += m[stk.top()], stk.pop();
            if(stk.empty())
              ans.insert(ans.begin(), 0), m[T[i]] = 0;
            else
              ans.insert(ans.begin(), count), m[T[i]] = count;
            stk.push(T[i]);
          }
        }
        return ans;
    }
};
