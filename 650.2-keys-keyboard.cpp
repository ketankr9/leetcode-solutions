/*
 * @lc app=leetcode id=650 lang=cpp
 *
 * [650] 2 Keys Keyboard
 *
 * https://leetcode.com/problems/2-keys-keyboard/description/
 *
 * algorithms
 * Medium (47.01%)
 * Total Accepted:    36.6K
 * Total Submissions: 77.8K
 * Testcase Example:  '3'
 *
 * Initially on a notepad only one character 'A' is present. You can perform
 * two operations on this notepad for each step:
 * 
 * 
 * Copy All: You can copy all the characters present on the notepad (partial
 * copy is not allowed).
 * Paste: You can paste the characters which are copied last time.
 * 
 * 
 * 
 * 
 * Given a number n. You have to get exactly n 'A' on the notepad by performing
 * the minimum number of steps permitted. Output the minimum number of steps to
 * get n 'A'.
 * 
 * Example 1:
 * 
 * 
 * Input: 3
 * Output: 3
 * Explanation:
 * Intitally, we have one character 'A'.
 * In step 1, we use Copy All operation.
 * In step 2, we use Paste operation to get 'AA'.
 * In step 3, we use Paste operation to get 'AAA'.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The n will be in the range [1, 1000].
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    unordered_map<int, unordered_map<int, int>> mm;
    int callme(int cur, int cop, int n){
        if(cur == n)    return 0;
        if(cur > n) return INT_MAX;

        if(mm.find(cur)!=mm.end() && mm[cur].find(cop)!=mm[cur].end())
            return mm[cur][cop];

        int tmp;
        if(cur!=cop)
            tmp = min(callme(cur+cop, cop, n), callme(cur, cur, n));
        else
            tmp = callme(cur+cop, cop, n);
        
        mm[cur][cop] = (tmp==INT_MAX?INT_MAX:tmp+1); 
        return mm[cur][cop];
    }
    int minSteps(int n) {
        if(n <= 1)  return 0;
        mm.clear();
        return 1 + callme(1, 1, n);
    }
};
