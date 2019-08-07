/*
 * @lc app=leetcode id=452 lang=cpp
 *
 * [452] Minimum Number of Arrows to Burst Balloons
 *
 * https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/
 *
 * algorithms
 * Medium (46.90%)
 * Total Accepted:    41.6K
 * Total Submissions: 88.6K
 * Testcase Example:  '[[10,16],[2,8],[1,6],[7,12]]'
 *
 * There are a number of spherical balloons spread in two-dimensional space.
 * For each balloon, provided input is the start and end coordinates of the
 * horizontal diameter. Since it's horizontal, y-coordinates don't matter and
 * hence the x-coordinates of start and end of the diameter suffice. Start is
 * always smaller than end. There will be at most 104 balloons.
 * 
 * An arrow can be shot up exactly vertically from different points along the
 * x-axis. A balloon with xstart and xend bursts by an arrow shot at x if
 * xstart ≤ x ≤ xend. There is no limit to the number of arrows that can be
 * shot. An arrow once shot keeps travelling up infinitely. The problem is to
 * find the minimum number of arrows that must be shot to burst all balloons.
 * 
 * Example:
 * 
 * 
 * Input:
 * [[10,16], [2,8], [1,6], [7,12]]
 * 
 * Output:
 * 2
 * 
 * Explanation:
 * One way is to shoot one arrow for example at x = 6 (bursting the balloons
 * [2,8] and [1,6]) and another arrow at x = 11 (bursting the other two
 * balloons).
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    // bool operator<(const vector<int>& a, const){

    // }
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty())  return 0;
        auto comp = [](const vector<int>& a, const vector<int>& b){ return a[0] < b[0] || (a[0]==b[0]&&a[1]<b[1]); };
        sort(points.begin(), points.end(), comp);
        int cnt = 1;
        vector<int> prev = {INT_MIN, INT_MAX};
        for(auto e: points){
            if(e[0] <= prev[1]){
                prev[0] = max(e[0], prev[0]);
                prev[1] = min(e[1], prev[1]);
            }else{
                cnt++;
                prev = e;
            }
        }
        return cnt;
    }
};
