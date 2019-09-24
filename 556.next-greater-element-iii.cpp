/*
 * @lc app=leetcode id=556 lang=cpp
 *
 * [556] Next Greater Element III
 *
 * https://leetcode.com/problems/next-greater-element-iii/description/
 *
 * algorithms
 * Medium (30.43%)
 * Total Accepted:    29.4K
 * Total Submissions: 96.6K
 * Testcase Example:  '12'
 *
 * Given a positive 32-bit integer n, you need to find the smallest 32-bit
 * integer which has exactly the same digits existing in the integer n and is
 * greater in value than n. If no such positive 32-bit integer exists, you need
 * to return -1.
 * 
 * Example 1:
 * 
 * 
 * Input: 12
 * Output: 21
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 21
 * Output: -1
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> vec;
        while(n){
        	vec.push_back(n%10);
        	n/=10;
        }
        int i = 0;
        long ans = 0l;
        while(i+1<vec.size() && vec[i] <= vec[i+1])
        	i++;
        if(i+1 >= vec.size())
        	return -1;
        
        int j = 0;
 		while(j<i+1 && vec[j] <= vec[i+1])
 			j++;
 		swap(vec[j], vec[i+1]);
        sort(vec.begin(), vec.begin()+i+1);
        reverse(vec.begin(), vec.begin()+i+1);
        
        for(int i = (int)vec.size()-1; i>=0; i--)
        	ans = ans*10l + (long)vec[i];
        return ans<=INT_MAX?ans:-1;
    }
};
