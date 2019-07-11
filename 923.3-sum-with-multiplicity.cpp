/*
 * @lc app=leetcode id=923 lang=cpp
 *
 * [923] 3Sum With Multiplicity
 *
 * https://leetcode.com/problems/3sum-with-multiplicity/description/
 *
 * algorithms
 * Medium (34.06%)
 * Likes:    209
 * Dislikes: 41
 * Total Accepted:    11.4K
 * Total Submissions: 33.5K
 * Testcase Example:  '[1,1,2,2,3,3,4,4,5,5]\n8'
 *
 * Given an integer array A, and an integer target, return the number of tuples
 * i, j, k  such that i < j < k and A[i] + A[j] + A[k] == target.
 * 
 * As the answer can be very large, return it modulo 10^9 + 7.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: A = [1,1,2,2,3,3,4,4,5,5], target = 8
 * Output: 20
 * Explanation: 
 * Enumerating by the values (A[i], A[j], A[k]):
 * (1, 2, 5) occurs 8 times;
 * (1, 3, 4) occurs 8 times;
 * (2, 2, 4) occurs 2 times;
 * (2, 3, 3) occurs 2 times.
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: A = [1,1,2,2,2,2], target = 5
 * Output: 12
 * Explanation: 
 * A[i] = 1, A[j] = A[k] = 2 occurs 12 times:
 * We choose one 1 from [1,1] in 2 ways,
 * and two 2s from [2,2,2,2] in 6 ways.
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 3 <= A.length <= 3000
 * 0 <= A[i] <= 100
 * 0 <= target <= 300
 * 
 */
class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
        map<int, vector<int>> mc;
        
        for(int i=0; i<(int)A.size(); i++)
            mc[A[i]].push_back(i);
        long long M = 1000000000+7;
        long long ans = 0;
        //  for(auto a: mc)
        //     for(auto b: mc){
        //         for(auto i:a.second)
        //             for(auto k:b.second){
        //                 if(i>=k)    continue;
        //                 if(a.first+b.first<=target && mc.find(target-a.first-b.first)!=mc.end())
        //                     for(auto j:mc[target-a.first-b.first]){
        //                         if(i<j && j<k)
        //                             ans = (ans+1)%M;
        //                     }
        //             }
        //     }
        // for(int i=0; i<(int)A.size(); i++)
        //     for(int j=i+1; j<(int)A.size()-1; j++){
        //         long tmp = 0;
        //         if(A[i]+A[j]<=target && mc.find(target-A[i]-A[j])!=mc.end()){
        //             for(auto k: mc[target-A[i]-A[j]])
        //                 if(k>j)
        //                     tmp++;
        //         }
        //         ans = (ans+tmp)%M;
        //     }
        for(auto a: mc)
            for(auto b: mc){
                if(!(a.first <= b.first && b.first <= (target-a.first-b.first))) continue;
                if(mc.find(target-a.first-b.first)==mc.end())   continue;
                pair<int, vector<int>> c;
                c.first = target-a.first-b.first;
                c.second = mc[c.first];
                // for(auto c: mc){
                    // if(a.first+b.first+c.first)
                    if(a.first!=b.first && b.first!=c.first)
                        ans = ans + ((long long)a.second.size()*b.second.size()*c.second.size())%M;
                    else if(a.first==b.first && b.first==c.first)
                        ans = ans + ((long long)a.second.size()*(a.second.size()-1)*(a.second.size()-2)/6)%M;
                    else if(a.first==b.first && b.first!=c.first)
                        ans += (c.second.size()*a.second.size()*(a.second.size()-1)/2)%M;
                    else if(a.first==c.first && c.first!=b.first)
                        ans += (b.second.size()*a.second.size()*(a.second.size()-1)/2)%M;
                    else if(c.first==b.first && b.first!=a.first)
                        ans += (a.second.size()*b.second.size()*(b.second.size()-1)/2)%M;
                    ans%=M;
                    // cout<<a.first<<":"<<b.first<<":"<<c.first<<" "<<ans<<" ;";
                // }
            }
        return ans;
    }
};

