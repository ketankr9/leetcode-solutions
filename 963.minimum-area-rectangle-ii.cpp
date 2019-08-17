/*
 * @lc app=leetcode id=963 lang=cpp
 *
 * [963] Minimum Area Rectangle II
 *
 * https://leetcode.com/problems/minimum-area-rectangle-ii/description/
 *
 * algorithms
 * Medium (46.48%)
 * Total Accepted:    5.8K
 * Total Submissions: 12.6K
 * Testcase Example:  '[[1,2],[2,1],[1,0],[0,1]]'
 *
 * Given a set of points in the xy-plane, determine the minimum area of any
 * rectangle formed from these points, with sides not necessarily parallel to
 * the x and y axes.
 * 
 * If there isn't any rectangle, return 0.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: [[1,2],[2,1],[1,0],[0,1]]
 * Output: 2.00000
 * Explanation: The minimum area rectangle occurs at [1,2],[2,1],[1,0],[0,1],
 * with an area of 2.
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: [[0,1],[2,1],[1,1],[1,0],[2,0]]
 * Output: 1.00000
 * Explanation: The minimum area rectangle occurs at [1,0],[1,1],[2,1],[2,0],
 * with an area of 1.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * 
 * 
 * Input: [[0,3],[1,2],[3,1],[1,3],[2,1]]
 * Output: 0
 * Explanation: There is no possible rectangle to form from these points.
 * 
 * 
 * 
 * Example 4:
 * 
 * 
 * 
 * 
 * Input: [[3,1],[1,1],[0,1],[2,1],[3,3],[3,2],[0,2],[2,3]]
 * Output: 2.00000
 * Explanation: The minimum area rectangle occurs at [2,1],[2,3],[3,3],[3,1],
 * with an area of 2.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= points.length <= 50
 * 0 <= points[i][0] <= 40000
 * 0 <= points[i][1] <= 40000
 * All points are distinct.
 * Answers within 10^-5 of the actual value will be accepted as correct.
 * 
 * 
 */
class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& p) {
        long m = 80001;
        unordered_map<long, vector<pair<int, int>>> mm;
        double ans = DBL_MAX;
        int n = p.size();
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++){
                if(i == j)  continue;
                mm[ (p[i][0]+p[j][0])*m + p[i][1]+p[j][1] ].push_back(make_pair(i, j));
            }
        
        for(auto e: mm){
            for(int i=0; i<(int)e.second.size(); i++)
                for(int j=0; j<(int)e.second.size(); j++){
                    if(i == j)  continue;
                    int p1 = e.second[i].first;
                    int p2 = e.second[i].second;
                    int p3 = e.second[j].first;
                    int p4 = e.second[j].second;
                    if(p1 == p2 || p2 == p3 || p3 == p1)    continue;
                    // cout<<p1<<":"<<p2<<":"<<p3<<" ";
                    if( 
                        ((p[p3][1]-p[p1][1])*(p[p2][1]-p[p3][1])) + 
                        ((p[p3][0]-p[p1][0])*(p[p2][0]-p[p3][0]))
                    != 0) continue;
                    double l = sqrt(pow((double)p[p3][1]-p[p1][1], 2) + pow((double)p[p3][0]-p[p1][0],2));
                    double r = sqrt(pow((double)p[p2][1]-p[p3][1], 2) + pow((double)p[p2][0]-p[p3][0],2));
                    // cout<<l<<":"<<r<<" ";
                    ans = min(ans, l*r);
                }
        }
        return ans==DBL_MAX?0:ans;

    }
};
