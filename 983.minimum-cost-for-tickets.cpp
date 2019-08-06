/*
 * @lc app=leetcode id=983 lang=cpp
 *
 * [983] Minimum Cost For Tickets
 *
 * https://leetcode.com/problems/minimum-cost-for-tickets/description/
 *
 * algorithms
 * Medium (57.23%)
 * Total Accepted:    14K
 * Total Submissions: 24.5K
 * Testcase Example:  '[1,4,6,7,8,20]\n[2,7,15]'
 *
 * In a country popular for train travel, you have planned some train
 * travelling one year in advance.  The days of the year that you will travel
 * is given as an array days.  Each day is an integer from 1 to 365.
 * 
 * Train tickets are sold in 3 different ways:
 * 
 * 
 * a 1-day pass is sold for costs[0] dollars;
 * a 7-day pass is sold for costs[1] dollars;
 * a 30-day pass is sold for costs[2] dollars.
 * 
 * 
 * The passes allow that many days of consecutive travel.  For example, if we
 * get a 7-day pass on day 2, then we can travel for 7 days: day 2, 3, 4, 5, 6,
 * 7, and 8.
 * 
 * Return the minimum number of dollars you need to travel every day in the
 * given list of days.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: days = [1,4,6,7,8,20], costs = [2,7,15]
 * Output: 11
 * Explanation: 
 * For example, here is one way to buy passes that lets you travel your travel
 * plan:
 * On day 1, you bought a 1-day pass for costs[0] = $2, which covered day 1.
 * On day 3, you bought a 7-day pass for costs[1] = $7, which covered days 3,
 * 4, ..., 9.
 * On day 20, you bought a 1-day pass for costs[0] = $2, which covered day 20.
 * In total you spent $11 and covered all the days of your travel.
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: days = [1,2,3,4,5,6,7,8,9,10,30,31], costs = [2,7,15]
 * Output: 17
 * Explanation: 
 * For example, here is one way to buy passes that lets you travel your travel
 * plan:
 * On day 1, you bought a 30-day pass for costs[2] = $15 which covered days 1,
 * 2, ..., 30.
 * On day 31, you bought a 1-day pass for costs[0] = $2 which covered day 31.
 * In total you spent $17 and covered all the days of your travel.
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= days.length <= 365
 * 1 <= days[i] <= 365
 * days is in strictly increasing order.
 * costs.length == 3
 * 1 <= costs[i] <= 1000
 * 
 * 
 */
// class Solution {
// public:
//     int callme(int i, vector<int>& days, vector<int>& costs){
//         int n = days.size();

//         int ans = INT_MAX;
//         // 2 days
//             int pos = i + (i+1<n && days[i+1]==days[i]+1?2:1);
//             ans = min(ans, costs[0] + callme(pos, days, costs));
//         // 7 days
//             pos = i;
//             for(int k=6; k>=1; k/=2){
//                 while(pos+k<i+8 && days[pos+k] <= days[i]+7)
//                     pos += k;
//             }
//         // 30 days
//             pos = i;
//             for(int k=30; k>=1; k/=2){
//                 while(pos+k<30; && days[pos+k] <= days[i]+30)
//             }
//     }
//     int mincostTickets(vector<int>& days, vector<int>& costs) {
//         return callme(0, days, costs);
//     }
// };
class Solution {
public:
    unordered_set<int> ss;
    unordered_map<int, int> dp;
    int callme(int d, vector<int>& costs){
        if(d <= 0)  return 0;
        if(dp.find(d)!=dp.end())
            return dp[d];
        if(ss.count(d) == 0)
            return dp[d] = callme(d-1, costs);

        return dp[d] = min(callme(d-1, costs)+costs[0], min(callme(d-7, costs)+costs[1], callme(d-30, costs)+costs[2]));
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        ss.clear();
        dp.clear();
        int maxx = INT_MIN;
        
        for(auto e: days)
            ss.insert(e), maxx = max(maxx, e);
        
        return callme(maxx, costs);
    }
};
