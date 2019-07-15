/*
 * @lc app=leetcode id=777 lang=cpp
 *
 * [777] Swap Adjacent in LR String
 *
 * https://leetcode.com/problems/swap-adjacent-in-lr-string/description/
 *
 * algorithms
 * Medium (33.48%)
 * Total Accepted:    15.8K
 * Total Submissions: 47.1K
 * Testcase Example:  '"X"\n"L"'
 *
 * In a string composed of 'L', 'R', and 'X' characters, like "RXXLRXRXL", a
 * move consists of either replacing one occurrence of "XL" with "LX", or
 * replacing one occurrence of "RX" with "XR". Given the starting string start
 * and the ending string end, return True if and only if there exists a
 * sequence of moves to transform one string to the other.
 * 
 * Example:
 * 
 * 
 * Input: start = "RXXLRXRXL", end = "XRLXXRRLX"
 * Output: True
 * Explanation:
 * We can transform start to end following these steps:
 * RXXLRXRXL ->
 * XRXLRXRXL ->
 * XRLXRXRXL ->
 * XRLXXRRXL ->
 * XRLXXRRLX
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= len(start) = len(end) <= 10000.
 * Both start and end will only consist of characters in {'L', 'R', 'X'}.
 * 
 * 
 */
class Solution {
public:
    bool canTransform(string start, string end) {
        int n = start.size();
        
        if(start.size() != end.size())
            return false;
        
        if(start == end)  return true;
        
        int i = 0;
        while(i<n){
            if(start[i] == end[i]){
                i++;
                continue;
            }
            if(start[i]=='X' && end[i] == 'L'){
                int sl = 0, el = 1;
                i++;
                while(i<n && el>sl && start[i] != 'R' && end[i] != 'R'){
                    sl += start[i] == 'L';
                    el += end[i] == 'L';
                    i++;
                }
                if(sl!=el)  return false;
            }else if(start[i] == 'R' && end[i] == 'X'){
                int sr = 1, er = 0;
                i++;
                while(i<n && sr>er && start[i] != 'L' && end[i] != 'L'){
                    sr += start[i] == 'R';
                    er += end[i] == 'R';
                    i++;
                }
                if(sr!=er)  return false;

            }else{
                return false;
            }
        }
        return true;
    }
};
