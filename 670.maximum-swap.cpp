/*
 * @lc app=leetcode id=670 lang=cpp
 *
 * [670] Maximum Swap
 *
 * https://leetcode.com/problems/maximum-swap/description/
 *
 * algorithms
 * Medium (40.62%)
 * Total Accepted:    42.7K
 * Total Submissions: 105K
 * Testcase Example:  '2736'
 *
 * 
 * Given a non-negative integer, you could swap two digits at most once to get
 * the maximum valued number. Return the maximum valued number you could get.
 * 
 * 
 * Example 1:
 * 
 * Input: 2736
 * Output: 7236
 * Explanation: Swap the number 2 and the number 7.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: 9973
 * Output: 9973
 * Explanation: No swap.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * The given number is in the range [0, 108]
 * 
 * 
 */
class Solution {
public:
    int maximumSwap(int num) {
    	if(num/10 == 0)	return num;

        vector<int> vec;
        vector<int> numvec;
        int numm = num;
        numvec.push_back(num%10);
        vec.push_back(0); num/=10;
        int i = 1;
        while(num){
        	numvec.push_back(num%10);
        	if(num%10 > numvec[vec.back()])
        		vec.push_back(i);
        	else
        		vec.push_back(vec.back());
        	num/=10;
        	i++;
        }
        i = vec.size();i--;
        while(i-1>=0){
        	if(numvec[i] < numvec[vec[i-1]]){
        		swap(numvec[i], numvec[vec[i-1]]);
        		break;
        	}
        	i--;
        }
        int ans = 0;
        reverse(numvec.begin(), numvec.end());
        for(auto const& c:  numvec)
        	ans = ans*10+c;
        return ans;
    }
};
