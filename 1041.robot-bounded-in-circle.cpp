/*
 * @lc app=leetcode id=1041 lang=cpp
 *
 * [1041] Robot Bounded In Circle
 *
 * https://leetcode.com/problems/robot-bounded-in-circle/description/
 *
 * algorithms
 * Medium (44.60%)
 * Total Accepted:    7.5K
 * Total Submissions: 16.7K
 * Testcase Example:  '"GGLLGG"'
 *
 * On an infinite plane, a robot initially stands at (0, 0) and faces north.
 * The robot can receive one of three instructions:
 * 
 * 
 * "G": go straight 1 unit;
 * "L": turn 90 degrees to the left;
 * "R": turn 90 degress to the right.
 * 
 * 
 * The robot performs the instructions given in order, and repeats them
 * forever.
 * 
 * Return true if and only if there exists a circle in the plane such that the
 * robot never leaves the circle.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "GGLLGG"
 * Output: true
 * Explanation: 
 * The robot moves from (0,0) to (0,2), turns 180 degrees, and then returns to
 * (0,0).
 * When repeating these instructions, the robot remains in the circle of radius
 * 2 centered at the origin.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "GG"
 * Output: false
 * Explanation: 
 * The robot moves north indefinitely.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "GL"
 * Output: true
 * Explanation: 
 * The robot moves from (0, 0) -> (0, 1) -> (-1, 1) -> (-1, 0) -> (0, 0) ->
 * ...
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= instructions.length <= 100
 * instructions[i] is in {'G', 'L', 'R'}
 * 
 * 
 */
class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0;
        int prev = 0;
        for(int p=0; p<4; p++)
        for(auto e: instructions){
            if(e == 'G'){
                switch(prev){
                    case 0:
                        y++;
                        break;
                    case 1:
                        x++;
                        break;
                    case 2:
                        y--;
                        break;
                    case 3:
                        x--;
                        break;
                };
            }else{
                if(e == 'L')
                    prev = (prev-1+4)%4;
                else
                    prev = (prev+1)%4; //prev++%=4;
            }
        }
        return x*x + y*y == 0;
    }
};
