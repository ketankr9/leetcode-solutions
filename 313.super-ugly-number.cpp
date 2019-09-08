/*
 * @lc app=leetcode id=313 lang=cpp
 *
 * [313] Super Ugly Number
 *
 * https://leetcode.com/problems/super-ugly-number/description/
 *
 * algorithms
 * Medium (42.06%)
 * Total Accepted:    63K
 * Total Submissions: 149.6K
 * Testcase Example:  '12\n[2,7,13,19]'
 *
 * Write a program to find the nth super ugly number.
 * 
 * Super ugly numbers are positive numbers whose all prime factors are in the
 * given prime list primes of size k.
 * 
 * Example:
 * 
 * 
 * Input: n = 12, primes = [2,7,13,19]
 * Output: 32 
 * Explanation: [1,2,4,7,8,13,14,16,19,26,28,32] is the sequence of the first
 * 12 
 * ⁠            super ugly numbers given primes = [2,7,13,19] of size 4.
 * 
 * Note:
 * 
 * 
 * 1 is a super ugly number for any given primes.
 * The given numbers in primes are in ascending order.
 * 0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.
 * The nth super ugly number is guaranteed to fit in a 32-bit signed integer.
 * 
 * 
 */
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int p = primes.size();
        vector<int> pos(p, 0);
        vector<int> ugly(1,1);

        for(int i=1; i<n; i++){
        	int idx, minn;
        	for(int j=0; j<p; j++){
        		while(primes[j]*ugly[pos[j]] == ugly.back())
        			pos[j]++;
        		if(j == 0 || primes[j]*ugly[pos[j]] < minn){
        			minn = primes[j]*ugly[pos[j]];
        			idx = j;
        		}
        	}
        	ugly.push_back(primes[idx]*ugly[pos[idx]++]);
        }
        return ugly.back();
    }
};
