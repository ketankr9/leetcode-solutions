/*
 * @lc app=leetcode id=1363 lang=cpp
 *
 * [1363] Largest Multiple of Three
 *
 * https://leetcode.com/problems/largest-multiple-of-three/description/
 *
 * algorithms
 * Hard (32.33%)
 * Likes:    84
 * Dislikes: 19
 * Total Accepted:    4.9K
 * Total Submissions: 15.1K
 * Testcase Example:  '[8,1,9]'
 *
 * Given an integer array of digits, return the largest multiple of three that
 * can be formed by concatenating some of the given digits in any order.
 * 
 * Since the answer may not fit in an integer data type, return the answer as a
 * string.
 * 
 * If there is no answer return an empty string.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: digits = [8,1,9]
 * Output: "981"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: digits = [8,6,7,1,0]
 * Output: "8760"
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: digits = [1]
 * Output: ""
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: digits = [0,0,0,0,0,0]
 * Output: "0"
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= digits.length <= 10^4
 * 0 <= digits[i] <= 9
 * The returning answer must not contain unnecessary leading zeros.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        vector<int> nums;
        vector<int> ones, twos;
        for(auto e: digits){
            int r = e%3;
            if(r == 0)
                nums.push_back(e);
            else if(r == 1)
                ones.push_back(e);
            else
                twos.push_back(e);
        }
        sort(ones.begin(), ones.end(), greater<int>());
        sort(twos.begin(), twos.end(), greater<int>());
        
        int i = 0, j = 0;

        if( (!ones.empty() && ones.size()%3 == 0 && twos.size()%3 == 2)
         || (!twos.empty() && twos.size()%3 == 0 && ones.size()%3 == 2) ){
            nums.push_back(twos[j++]);
            nums.push_back(ones[i++]);
            nums.push_back(twos[j++]);
            nums.push_back(ones[i++]);           
        }
        
        int r = (ones.size()-i)/3;
        nums.insert(nums.end(), ones.begin()+i, ones.begin()+i+r*3);
        i += r*3;
        
        r = (twos.size()-j)/3;
        nums.insert(nums.end(), twos.begin()+j, twos.begin()+j+r*3);
        j += r*3;

        r = min(twos.size()-j, ones.size()-i);
        nums.insert(nums.end(), ones.begin()+i, ones.begin()+i+r);
        nums.insert(nums.end(), twos.begin()+j, twos.begin()+j+r);

        sort(nums.begin(), nums.end(), greater<int>());
        
        if(nums.size() == 0)
            return "";
        if(nums[0] == 0)
            return "0";

        string ret = "";
        for(int e: nums){
            ret += (char)('0'+e);
        }
        return ret;
    }
};
// @lc code=end
