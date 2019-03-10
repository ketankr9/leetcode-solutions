/*
 * @lc app=leetcode id=858 lang=cpp
 *
 * [858] Mirror Reflection
 *
 * https://leetcode.com/problems/mirror-reflection/description/
 *
 * algorithms
 * Medium (51.37%)
 * Total Accepted:    5.9K
 * Total Submissions: 11.4K
 * Testcase Example:  '2\n1'
 *
 * There is a special square room with mirrors on each of the four walls.
 * Except for the southwest corner, there are receptors on each of the
 * remaining corners, numbered 0, 1, and 2.
 * 
 * The square room has walls of length p, and a laser ray from the southwest
 * corner first meets the east wall at a distance q from the 0th receptor.
 * 
 * Return the number of the receptor that the ray meets first.  (It is
 * guaranteed that the ray will meet a receptor eventually.)
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: p = 2, q = 1
 * Output: 2
 * Explanation: The ray meets receptor 2 the first time it gets reflected back
 * to the left wall.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= p <= 1000
 * 0 <= q <= p
 * 
 * 
 * 
 */
class Solution {
public:
    int hcf(int x, int y){
        if(x==0 || y==0)
            return x+y;
        if(x==y)
            return x;
        if(x<y)
            return hcf(x, y-x);
        
        return hcf(x-y, y);
    } 
    int mirrorReflection(int p, int q) {
        if(p*q == 0)
            return 0;
        int h = hcf(p, q);
        int a = p/h;
        int b = q/h;
        cout<<h<<endl;
        if(a%2==0){ // right
            if(b%2==0){
                return -1;
            }else{
                return 2;
            }
        }else{ // left
            if(b%2==0){
                return 0;
            }else{
                return 1;
            }
        }

    }
};
