/*
 * @lc app=leetcode id=593 lang=cpp
 *
 * [593] Valid Square
 *
 * https://leetcode.com/problems/valid-square/description/
 *
 * algorithms
 * Medium (40.76%)
 * Total Accepted:    20.5K
 * Total Submissions: 50.2K
 * Testcase Example:  '[0,0]\n[1,1]\n[1,0]\n[0,1]'
 *
 * Given the coordinates of four points in 2D space, return whether the four
 * points could construct a square.
 * 
 * The coordinate (x,y) of a point is represented by an integer array with two
 * integers.
 * 
 * Example:
 * 
 * 
 * Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
 * Output: True
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * All the input integers are in the range [-10000, 10000].
 * A valid square has four equal sides with positive length and four equal
 * angles (90-degree angles).
 * Input points have no order.
 * 
 * 
 * 
 * 
 */

class Solution {
public:
    bool checkSame(vector<int>& p1, vector<int>& p2, vector<int>& p3){
        return pow((p1[0] - p2[0]),2)+ pow((p1[1] - p2[1]),2) == pow((p1[0] - p3[0]),2) + pow((p1[1] - p3[1]),2) && (pow((p1[0] - p3[0]),2) + pow((p1[1] - p3[1]),2))!=0;
    }
    int llen(vector<int>& p1, vector<int>& p2){
        return pow((p1[0] - p2[0]),2)+ pow((p1[1] - p2[1]),2);
    }
    bool callme(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4){
        if(llen(p1, p2)*2 == llen(p1, p4) && checkSame(p4, p2, p3) && checkSame(p2, p1, p4))
            return true;
        return false;
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        if(checkSame(p1, p2, p3)){
            return callme(p1, p2, p3, p4);
        }else if(checkSame(p1, p2, p4)){
            return callme(p1, p2, p4, p3);
        }else if(checkSame(p1, p3, p4)){
            return callme(p1, p3, p4, p2);
        }else
            return false;
    }
};
