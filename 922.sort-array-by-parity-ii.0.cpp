/*
 * @lc app=leetcode id=922 lang=cpp
 *
 * [922] Sort Array By Parity II
 *
 * https://leetcode.com/problems/sort-array-by-parity-ii/description/
 *
 * algorithms
 * Easy (66.71%)
 * Total Accepted:    29.5K
 * Total Submissions: 44.3K
 * Testcase Example:  '[4,2,5,7]'
 *
 * Given an array A of non-negative integers, half of the integers in A are
 * odd, and half of the integers are even.
 * 
 * Sort the array so that whenever A[i] is odd, i is odd; and whenever A[i] is
 * even, i is even.
 * 
 * You may return any answer array that satisfies this condition.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [4,2,5,7]
 * Output: [4,5,2,7]
 * Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been
 * accepted.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 2 <= A.length <= 20000
 * A.length % 2 == 0
 * 0 <= A[i] <= 1000
 * 
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int i=0,j=1;
        int maxx = (int)A.size();
        while(i<maxx && j<maxx){
            if(i%2==0 && A[i]%2==0){
                i+=2; continue;
            }
            if(j%2==1 && A[j]%2==1){
                j+=2; continue;
            }
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i+=2;j+=2;
        }
        return A;
    }
};
