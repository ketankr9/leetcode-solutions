/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 *
 * https://leetcode.com/problems/insert-interval/description/
 *
 * algorithms
 * Hard (30.22%)
 * Total Accepted:    154.2K
 * Total Submissions: 509.9K
 * Testcase Example:  '[[1,3],[6,9]]\n[2,5]'
 *
 * Given a set of non-overlapping intervals, insert a new interval into the
 * intervals (merge if necessary).
 *
 * You may assume that the intervals were initially sorted according to their
 * start times.
 *
 * Example 1:
 *
 *
 * Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
 * Output: [[1,5],[6,9]]
 *
 *
 * Example 2:
 *
 *
 * Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
 * Output: [[1,2],[3,10],[12,16]]
 * Explanation: Because the new interval [4,8] overlaps with
 * [3,5],[6,7],[8,10].
 *
 */
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        int N = intervals.size();
        int i=0;
        while(i<N && intervals[i].end < newInterval.start){
          res.push_back(intervals[i]);
          i++;
        }
        res.push_back(newInterval);
        if(i == N){
          return res;
        }
        if(newInterval.end < intervals[i].start){ // non overlap
            while(i<N){
              res.push_back(intervals[i]);
              i++;
            }
            return res;
        }
        // while(i<N && intervals[i].start < newInterval.start && newInterval.start < )
        // res.push_back(Interval(min(newInterval.start, intervals[i].start),
        // max(newInterval.end, intervals[i].end)));
        // i++;

        while(i<N){
          Interval inn = res[(int)res.size()-1];
          if(intervals[i].start <= inn.end){
            res.pop_back();
            res.push_back(Interval(min(inn.start, intervals[i].start), \
            max(inn.end, intervals[i].end)));
          }else{
            res.push_back(intervals[i]);
          }
          i++;
        }
        return res;
    }
};
