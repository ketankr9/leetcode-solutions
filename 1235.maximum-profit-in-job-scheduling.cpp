/*
 * @lc app=leetcode id=1235 lang=cpp
 *
 * [1235] Maximum Profit in Job Scheduling
 *
 * https://leetcode.com/problems/maximum-profit-in-job-scheduling/description/
 *
 * algorithms
 * Hard (44.47%)
 * Total Accepted:    3.9K
 * Total Submissions: 8.7K
 * Testcase Example:  '[1,2,3,3]\n[3,4,5,6]\n[50,10,40,70]'
 *
 * We have n jobs, where every job is scheduled to be done from startTime[i] to
 * endTime[i], obtaining a profit of profit[i].
 * 
 * You're given the startTime , endTime and profit arrays, you need to output
 * the maximum profit you can take such that there are no 2 jobs in the subset
 * with overlapping time range.
 * 
 * If you choose a job that ends at time X you will be able to start another
 * job that starts at time X.
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
 * Output: 120
 * Explanation: The subset chosen is the first and fourth job. 
 * Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.
 * 
 * 
 * Example 2:
 * 
 * ⁠
 * 
 * 
 * 
 * Input: startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit =
 * [20,20,100,70,60]
 * Output: 150
 * Explanation: The subset chosen is the first, fourth and fifth job. 
 * Profit obtained 150 = 20 + 70 + 60.
 * 
 * 
 * Example 3:
 * 
 * 
 * 
 * 
 * Input: startTime = [1,1,1], endTime = [2,3,4], profit = [5,6,4]
 * Output: 6
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= startTime.length == endTime.length == profit.length <= 5 * 10^4
 * 1 <= startTime[i] < endTime[i] <= 10^9
 * 1 <= profit[i] <= 10^4
 * 
 * 
 */
class Solution {
public:
	typedef tuple<int, int, int> tp;
	int callme(int i, vector<tp>& vec, vector<int>& dp){
		if(i >= vec.size())	return 0;
        
        if(dp[i] != -1) return dp[i];
		
        int end = get<1>(vec[i]), ret = INT_MIN;
		
        for(int j = i; j<vec.size() && get<0>(vec[j]) < end; j++){
			auto it = lower_bound(vec.begin()+i, vec.end(), get<1>(vec[j]), [](tp& x, int y){
            	return get<0>(x) < y;
        	});
            ret = max(ret, get<2>(vec[j]) + callme( (int)(it-vec.begin()), vec, dp));
		}
		return dp[i] = (ret == INT_MIN ? 0 : ret);
	}
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<tp> vec;
        int n = startTime.size();
        for(int i=0; i<n; i++)
        	vec.push_back({startTime[i], endTime[i], profit[i]});

        sort(vec.begin(), vec.end(), [](const tp& x, const tp& y){
        	return ( get<0>(x) == get<0>(y) ? get<1>(x) < get<1>(y) : get<0>(x) < get<0>(y) );
        });
        vector<int> dp(vec.size()+1, -1);
        return callme(0, vec, dp);
    }
};
