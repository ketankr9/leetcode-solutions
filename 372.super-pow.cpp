/*
 * @lc app=leetcode id=372 lang=cpp
 *
 * [372] Super Pow
 *
 * https://leetcode.com/problems/super-pow/description/
 *
 * algorithms
 * Medium (35.78%)
 * Total Accepted:    28.9K
 * Total Submissions: 80.6K
 * Testcase Example:  '2\n[3]'
 *
 * Your task is to calculate ab mod 1337 where a is a positive integer and b is
 * an extremely large positive integer given in the form of an array.
 * 
 * Example 1:
 * 
 * 
 * 
 * Input: a = 2, b = [3]
 * Output: 8
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: a = 2, b = [1,0]
 * Output: 1024
 * 
 * 
 * 
 */
class Solution {
public:
    int p;
    int power(int a, int b){
        if(b == 0)  return 1;
        if(b == 1)  return a%p;
        if(b%2==0){
            int x = power(a,b/2);
            return ((long long)x*(long long)x)%p;
        }else{
            int x = power(a, b-1);
            return ((long long)x*(long long)a)%p;
        }
    }
    int helper(int a, vector<int>& b, int idx){
        
        if(idx == 0)
            return power(a, b[idx]) % p;
        return ( (long long)power(helper(a, b, idx-1), 10)%p * (long long)power(a, b[idx]) %p )%p;
    }

    int superPow(int a, vector<int>& b) {
        p = 1337;
        return helper(a, b, b.size()-1);
    }
};
