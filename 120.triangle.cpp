/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 *
 * https://leetcode.com/problems/triangle/description/
 *
 * algorithms
 * Medium (39.84%)
 * Likes:    1185
 * Dislikes: 128
 * Total Accepted:    187.7K
 * Total Submissions: 471.1K
 * Testcase Example:  '[[2],[3,4],[6,5,7],[4,1,8,3]]'
 *
 * Given a triangle, find the minimum path sum from top to bottom. Each step
 * you may move to adjacent numbers on the row below.
 * 
 * For example, given the following triangle
 * 
 * 
 * [
 * ⁠    [2],
 * ⁠   [3,4],
 * ⁠  [6,5,7],
 * ⁠ [4,1,8,3]
 * ]
 * 
 * 
 * The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 * 
 * Note:
 * 
 * Bonus point if you are able to do this using only O(n) extra space, where n
 * is the total number of rows in the triangle.
 * 
 */
class Solution {
public:
    unordered_map<int, unordered_map<int, int>> mm;
    long long callme(int row, int i, vector<vector<int>>& triangle){
        // if(summ > INT_MAX)  return INT_MAX;
        if(row == (int)triangle.size()){
            return 0;
        }
        if(mm.find(row)!=mm.end() && mm[row].find(i)!=mm[row].end())
            return mm[row][i];
        long long a = triangle[row][i  ] + callme(row+1, i  , triangle);
        long long b = triangle[row][i+1] + callme(row+1, i+1, triangle);
        mm[row][i] = min(a, b);
        return mm[row][i];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        mm.clear();
        if(triangle.size() == 0)
            return 0;
        return triangle[0][0] + callme(1, 0, triangle);
    }
};

