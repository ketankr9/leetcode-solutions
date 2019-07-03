/*
 * @lc app=leetcode id=892 lang=cpp
 *
 * [892] Surface Area of 3D Shapes
 *
 * https://leetcode.com/problems/surface-area-of-3d-shapes/description/
 *
 * algorithms
 * Easy (56.03%)
 * Likes:    153
 * Dislikes: 189
 * Total Accepted:    11.5K
 * Total Submissions: 20.5K
 * Testcase Example:  '[[2]]'
 *
 * On a N * N grid, we place some 1 * 1 * 1 cubes.
 * 
 * Each value v = grid[i][j] represents a tower of v cubes placed on top of
 * grid cell (i, j).
 * 
 * Return the total surface area of the resulting shapes.
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
 * Input: [[2]]
 * Output: 10
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[1,2],[3,4]]
 * Output: 34
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [[1,0],[0,2]]
 * Output: 16
 * 
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: [[1,1,1],[1,0,1],[1,1,1]]
 * Output: 32
 * 
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: [[2,2,2],[2,1,2],[2,2,2]]
 * Output: 46
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= N <= 50
 * 0 <= grid[i][j] <= 50
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int N = grid.size();
        int ans = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {   int v = grid[i][j];
                if(v == 0) continue;

                ans += 4*v+2;

                // up i-1
                ans -= (i-1>=0?min(grid[i-1][j], v):0);
                // down i+1
                ans -= (i+1<N?min(grid[i+1][j], v):0);
                // left j-1
                ans -= (j-1>=0?min(grid[i][j-1], v):0);
                // right j+1
                ans -= (j+1<N?min(grid[i][j+1], v):0);
            }
            
        }
        return ans;
    }
};

