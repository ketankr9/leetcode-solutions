/*
 * @lc app=leetcode id=812 lang=java
 *
 * [812] Largest Triangle Area
 *
 * https://leetcode.com/problems/largest-triangle-area/description/
 *
 * algorithms
 * Easy (56.71%)
 * Total Accepted:    16.6K
 * Total Submissions: 29.4K
 * Testcase Example:  '[[0,0],[0,1],[1,0],[0,2],[2,0]]'
 *
 * You have a list of points in the plane. Return the area of the largest
 * triangle that can be formed by any 3 of the points.
 * 
 * 
 * Example:
 * Input: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
 * Output: 2
 * Explanation: 
 * The five points are show in the figure below. The red triangle is the
 * largest.
 * 
 * 
 * 
 * 
 * Notes: 
 * 
 * 
 * 3 <= points.length <= 50.
 * No points will be duplicated.
 * -50 <= points[i][j] <= 50.
 * Answers within 10^-6 of the true value will be accepted as correct.
 * 
 * 
 * 
 * 
 */
class Solution {
	private double cc(int[] A, int[] B, int C[]){
		return Math.abs(A[0]*(B[1]-C[1]) + B[0]*(C[1]-A[1]) + C[0]*(A[1]-B[1]));
	}
	
    public double largestTriangleArea(int[][] p) {
        double area = 0;
        for(int i = 0; i < p.length; i++)
        	for(int j=i+1; j<p.length; j++)
        		for(int k=j+1; k<p.length; k++)
        			area = Math.max(area, cc(p[k], p[j], p[i]) );
        return area/(double)2;
    }
}
