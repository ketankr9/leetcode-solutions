/*
 * @lc app=leetcode id=526 lang=cpp
 *
 * [526] Beautiful Arrangement
 *
 * https://leetcode.com/problems/beautiful-arrangement/description/
 *
 * algorithms
 * Medium (53.13%)
 * Total Accepted:    31.5K
 * Total Submissions: 59.3K
 * Testcase Example:  '2'
 *
 *
 * Suppose you have N integers from 1 to N. We define a beautiful arrangement
 * as an array that is constructed by these N numbers successfully if one of
 * the following is true for the ith position (1
 * The number at the ith position is divisible by i.
 * i is divisible by the number at the ith position.
 *
 *
 *
 *
 * Now given N, how many beautiful arrangements can you construct?
 *
 *
 * Example 1:
 *
 * Input: 2
 * Output: 2
 * Explanation:
 * The first beautiful arrangement is [1, 2]:
 * Number at the 1st position (i=1) is 1, and 1 is divisible by i (i=1).
 * Number at the 2nd position (i=2) is 2, and 2 is divisible by i (i=2).
 * The second beautiful arrangement is [2, 1]:
 * Number at the 1st position (i=1) is 2, and 2 is divisible by i (i=1).
 * Number at the 2nd position (i=2) is 1, and i (i=2) is divisible by 1.
 *
 *
 *
 * Note:
 *
 * N is a positive integer and will not exceed 15.
 *
 *
 */
class Solution {
public:
    // bool valid(vector<int> st){
    //   for(int i=0;i<(int)st.size();i++){
    //     if(st[i] >= i+1){
    //       if(st[i]%(i+1) !=0 )  return false;
    //     }else{
    //       if((i+1)%st[i] !=0 )  return false;
    //     }
    //   }
    //   return true;
    // }
    int N;
    int count;
    void callme(int k, vector<int>& v, bool* visited){
      if(k >= (int)v.size()){
        count++;
        return;
      }
      for (int i = 0; i < N; i++) {
            if(!visited[i] && (v[i]%(k+1)==0 || (k+1)%v[i]==0) ){
              visited[i] = true;
              callme(k+1, v, visited);
              visited[i] = false;
            }
      }
    }

    int countArrangement(int N) {
        count = 0;
        vector<int> v;
        this->N = N;
        for (int i = 1; i <= N; i++)
          v.push_back(i);
        bool visited[N]; fill_n(visited, N, false);
        callme(0, v, visited);
        return count;
    }
};
