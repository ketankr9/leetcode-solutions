/*
 * @lc app=leetcode id=826 lang=cpp
 *
 * [826] Most Profit Assigning Work
 *
 * https://leetcode.com/problems/most-profit-assigning-work/description/
 *
 * algorithms
 * Medium (35.86%)
 * Total Accepted:    11.4K
 * Total Submissions: 31.7K
 * Testcase Example:  '[2,4,6,8,10]\n[10,20,30,40,50]\n[4,5,6,7]'
 *
 * We have jobs: difficulty[i] is the difficulty of the ith job, and profit[i]
 * is the profit of the ith job. 
 * 
 * Now we have some workers. worker[i] is the ability of the ith worker, which
 * means that this worker can only complete a job with difficulty at most
 * worker[i]. 
 * 
 * Every worker can be assigned at most one job, but one job can be completed
 * multiple times.
 * 
 * For example, if 3 people attempt the same job that pays $1, then the total
 * profit will be $3.  If a worker cannot complete any job, his profit is $0.
 * 
 * What is the most profit we can make?
 * 
 * Example 1:
 * 
 * 
 * Input: difficulty = [2,4,6,8,10], profit = [10,20,30,40,50], worker =
 * [4,5,6,7]
 * Output: 100 
 * Explanation: Workers are assigned jobs of difficulty [4,4,6,6] and they get
 * profit of [20,20,30,30] seperately.
 * 
 * Notes:
 * 
 * 
 * 1 <= difficulty.length = profit.length <= 10000
 * 1 <= worker.length <= 10000
 * difficulty[i], profit[i], worker[i]  are in range [1, 10^5]
 * 
 * 
 */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool static comp(const pair<int, int> &a, const pair<int, int> &b){
        return a.second > b.second;
    }
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> mm;
        for(int i=0; i<(int)difficulty.size(); i++)
            mm.push_back(make_pair(difficulty[i], profit[i]));
        sort(mm.begin(), mm.end(), comp);
        int ans = 0;
        for(auto w: worker){
            for(int i=0; i<(int)mm.size(); i++)
                if(mm[i].first<=w){
                    ans += mm[i].second;
                    break;
                }
        }
        return ans;
    }
};
