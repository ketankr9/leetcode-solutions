/*
 * @lc app=leetcode id=836 lang=cpp
 *
 * [836] Rectangle Overlap
 *
 * https://leetcode.com/problems/rectangle-overlap/description/
 *
 * algorithms
 * Easy (45.43%)
 * Total Accepted:    22.4K
 * Total Submissions: 48.5K
 * Testcase Example:  '[0,0,2,2]\n[1,1,3,3]'
 *
 * A rectangle is represented as a list [x1, y1, x2, y2], where (x1, y1) are
 * the coordinates of its bottom-left corner, and (x2, y2) are the coordinates
 * of its top-right corner.
 * 
 * Two rectangles overlap if the area of their intersection is positive.  To be
 * clear, two rectangles that only touch at the corner or edges do not
 * overlap.
 * 
 * Given two (axis-aligned) rectangles, return whether they overlap.
 * 
 * Example 1:
 * 
 * 
 * Input: rec1 = [0,0,2,2], rec2 = [1,1,3,3]
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: rec1 = [0,0,1,1], rec2 = [1,0,2,1]
 * Output: false
 * 
 * 
 * Notes:
 * 
 * 
 * Both rectangles rec1 and rec2 are lists of 4 integers.
 * All coordinates in rectangles will be between -10^9 and 10^9.
 * 
 * 
 */
class Solution {
public:
    // bool check(vector<int>& rec1, int x, int y){
    //     return rec1[0] < x && x < rec1[2] && rec1[1] < y && y < rec1[3];
    // }
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // return check(rec1, rec2[0], rec2[1]) || check(rec1, rec2[0], rec2[3]) || check(rec1, rec2[2], rec2[1]) || check(rec1, rec2[2], rec2[3]);
        // below
        if(rec2[1] <= rec1[1] && rec2[3] <= rec1[1])
            return false;
        //up
        if(rec2[1] >= rec1[3] && rec2[3] >= rec1[3])
            return false;
        //right
        if(rec2[0] >= rec1[2] && rec2[2] >= rec1[2])
            return false;
        //left
        if(rec2[0] <= rec1[0] && rec2[2] <= rec1[0])
            return false;

        return true;
    }
};
