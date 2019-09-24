/*
 * @lc app=leetcode id=1201 lang=cpp
 *
 * [1201] Ugly Number III
 *
 * https://leetcode.com/problems/ugly-number-iii/description/
 *
 * algorithms
 * Medium (23.27%)
 * Total Accepted:    2.5K
 * Total Submissions: 10.8K
 * Testcase Example:  '3\n2\n3\n5'
 *
 * Write a program to find the n-th ugly number.
 * 
 * Ugly numbers are positive integers which are divisible by a or b or c.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 3, a = 2, b = 3, c = 5
 * Output: 4
 * Explanation: The ugly numbers are 2, 3, 4, 5, 6, 8, 9, 10... The 3rd is 4.
 * 
 * Example 2:
 * 
 * 
 * Input: n = 4, a = 2, b = 3, c = 4
 * Output: 6
 * Explanation: The ugly numbers are 2, 3, 4, 6, 8, 9, 10, 12... The 4th is
 * 6.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: n = 5, a = 2, b = 11, c = 13
 * Output: 10
 * Explanation: The ugly numbers are 2, 4, 6, 8, 10, 11, 12, 13... The 5th is
 * 10.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: n = 1000000000, a = 2, b = 217983653, c = 336916467
 * Output: 1999999984
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n, a, b, c <= 10^9
 * 1 <= a * b * c <= 10^18
 * It's guaranteed that the result will be in range [1, 2 * 10^9]
 * 
 * 
 */
class Solution {
public:
	typedef long long ll;
	ll x, y, z, w;
    ll getme(ll N, ll a, ll b, ll c){
        return  N/a - N/x + N/b - N/y + N/c - N/z + N/w;
    }
    ll lcm(ll x, ll y){
    	return (x*y/__gcd(x, y));
    }
    int nthUglyNumber(ll n, int a, int b, int c) {
        ll high = 1ll;
        x = lcm(a, b);
        y = lcm(b, c);
        z = lcm(a, c);
        w = lcm(lcm(a, b), c);
        while(getme(high, a, b, c) <= n)
            high*=2ll;
        for(ll k = high/2; k>=1ll; k/=2ll){
        	while(high-k>0 && getme(high-k, a, b, c) >= n)
        		high -= k;
        }
        return high;
    }
};