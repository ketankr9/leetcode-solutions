/*
 * @lc app=leetcode id=447 lang=cpp
 *
 * [447] Number of Boomerangs
 *
 * https://leetcode.com/problems/number-of-boomerangs/description/
 *
 * algorithms
 * Easy (48.38%)
 * Total Accepted:    47.3K
 * Total Submissions: 97.7K
 * Testcase Example:  '[[0,0],[1,0],[2,0]]'
 *
 * Given n points in the plane that are all pairwise distinct, a "boomerang" is
 * a tuple of points (i, j, k) such that the distance between i and j equals
 * the distance between i and k (the order of the tuple matters).
 * 
 * Find the number of boomerangs. You may assume that n will be at most 500 and
 * coordinates of points are all in the range [-10000, 10000] (inclusive).
 * 
 * Example:
 * 
 * Input:
 * [[0,0],[1,0],[2,0]]
 * 
 * Output:
 * 2
 * 
 * Explanation:
 * The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]
 * 
 * 
 */

class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        unordered_map<string, int> dist_count;
        int cnt = 0;
        for(int i=0; i<(int)points.size(); i++){
            for(int j=0; j<(int)points.size(); j++){
                if(i==j)    continue;
                int dist = pow(points[i].first-points[j].first, 2) + pow(points[i].second-points[j].second, 2);
                dist_count[to_string(i)+":"+to_string(dist)]++;
            }
        }
        for(auto it=dist_count.begin(); it!=dist_count.end(); it++){
            // cout<<it->first<<" "<<it->second<<"; ";
            cnt += (it->second)*(it->second-1);
        }
        return cnt;
    }
};
