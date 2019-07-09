/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 *
 * https://leetcode.com/problems/spiral-matrix-ii/description/
 *
 * algorithms
 * Medium (47.14%)
 * Likes:    479
 * Dislikes: 81
 * Total Accepted:    140.3K
 * Total Submissions: 297.5K
 * Testcase Example:  '3'
 *
 * Given a positive integer n, generate a square matrix filled with elements
 * from 1 to n^2 in spiral order.
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 8, 9, 4 ],
 * ⁠[ 7, 6, 5 ]
 * ]
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
       vector<vector<int>> vec(n, vector<int>(n));
        int i = 0, j = 0;
        int k = n-1;
        int c = 1;
        while(k>=0){
            vec[i][j] = c;
            // right
            for(int p=0; p<k; p++)
                vec[i][j++] = c++;
            
            // down
            for(int p=0; p<k; p++)
                vec[i++][j] = c++;
            
            // left
            for(int p=0; p<k; p++)
                vec[i][j--] = c++;
            
            // up
            for(int p=0; p<k; p++)
                vec[i--][j] = c++;
            i++, j++;
            k -= 2;
        }
        return vec;
    }
};

