/*
 * @lc app=leetcode id=365 lang=cpp
 *
 * [365] Water and Jug Problem
 *
 * https://leetcode.com/problems/water-and-jug-problem/description/
 *
 * algorithms
 * Medium (29.19%)
 * Total Accepted:    29.1K
 * Total Submissions: 99.7K
 * Testcase Example:  '3\n5\n4'
 *
 * You are given two jugs with capacities x and y litres. There is an infinite
 * amount of water supply available. You need to determine whether it is
 * possible to measure exactly z litres using these two jugs.
 * 
 * If z liters of water is measurable, you must have z liters of water
 * contained within one or both buckets by the end.
 * 
 * Operations allowed:
 * 
 * 
 * Fill any of the jugs completely with water.
 * Empty any of the jugs.
 * Pour water from one jug into another till the other jug is completely full
 * or the first jug itself is empty.
 * 
 * 
 * Example 1: (From the famous "Die Hard" example)
 * 
 * 
 * Input: x = 3, y = 5, z = 4
 * Output: True
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: x = 2, y = 6, z = 5
 * Output: False
 * 
 */
class Solution {
public:
    int gcd(int a, int b){
        if(a == 1 || b == 1)
            return 1;
        if(a == 0 || b == 0)
            return a+b;
        if(b<a) swap(a, b);
        return gcd(b%a, a);
    }
    bool canMeasureWater(int x, int y, int z) {
        if(z == 0)  return true;
        if(y>x) swap(x, y);
        if(z>x+y) return false;
        int g = gcd(x, y);
        return (z%g == 0?true:false);
    }
};
