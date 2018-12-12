/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 *
 * https://leetcode.com/problems/count-and-say/description/
 *
 * algorithms
 * Easy (38.55%)
 * Total Accepted:    238.7K
 * Total Submissions: 619K
 * Testcase Example:  '1'
 *
 * The count-and-say sequence is the sequence of integers with the first five
 * terms as following:
 *
 *
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 *
 *
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 *
 * Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the
 * count-and-say sequence.
 *
 * Note: Each term of the sequence of integers will be represented as a
 * string.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: 1
 * Output: "1"
 *
 *
 * Example 2:
 *
 *
 * Input: 4
 * Output: "1211"
 *
 */
class Solution {
public:
    string next(string inp){
      string ans ="";
      int N = inp.size();
      int i = 0;
      int count;
      while(i<N){
        count=0;
        char st = inp[i];
        while(i<N && st == inp[i])
          i++,count++;
        ans += to_string(count) + st;
        // cout<<count<<":"<<st<<" ";
      }
      // cout<<ans<<endl;
      return ans;
    }
    string countAndSay(int n) {
      string prev = "1";
      // if(n==1)  return prev;
      for(int i=2;i<=n;i++)
        prev =  next(prev);
      return prev;
    }
};
