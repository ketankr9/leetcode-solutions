/*
 * @lc app=leetcode id=373 lang=cpp
 *
 * [373] Find K Pairs with Smallest Sums
 *
 * https://leetcode.com/problems/find-k-pairs-with-smallest-sums/description/
 *
 * algorithms
 * Medium (34.18%)
 * Total Accepted:    70.7K
 * Total Submissions: 206.6K
 * Testcase Example:  '[1,7,11]\n[2,4,6]\n3'
 *
 * You are given two integer arrays nums1 and nums2 sorted in ascending order
 * and an integer k.
 * 
 * Define a pair (u,v) which consists of one element from the first array and
 * one element from the second array.
 * 
 * Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.
 * 
 * Example 1:
 * 
 * 
 * Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
 * Output: [[1,2],[1,4],[1,6]] 
 * Explanation: The first 3 pairs are returned from the sequence: 
 * [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
 * 
 * Example 2:
 * 
 * 
 * Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
 * Output: [1,1],[1,1]
 * Explanation: The first 2 pairs are returned from the sequence: 
 * [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
 * 
 * Example 3:
 * 
 * 
 * Input: nums1 = [1,2], nums2 = [3], k = 3
 * Output: [1,3],[2,3]
 * Explanation: All possible pairs are returned from the sequence: [1,3],[2,3]
 * 
 * 
 */
class Solution {
public:
    int n, m, K;
    int p(int x, int y){
        return x*max(m, n)+y;
    }
    typedef vector<int> pp;
    typedef unordered_set<int> us;
    bool checkninsert(int i, int j, us& visited, pp& nums1, pp& nums2){
        if(i<n && j<m && visited.count(p(i, j))==0 && i<K && j<K){
            visited.insert(p(i, j));
            return true;
        }
        return false;
    }
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<std::vector<int>>    ans;
        n = nums1.size(), m = nums2.size();
        K = k;
        if(n == 0 || m == 0)    return ans;
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        unordered_set<int> visited;
        pq.push({nums1[0]+nums2[0], 0, 0});
        visited.insert(p(0, 0));
        while(k-- && !pq.empty()){
            pp top = pq.top(); pq.pop();
            int val = top[0], i = top[1], j = top[2];
            ans.push_back({nums1[i], nums2[j]});
            if(k == 0)  return ans;
            if(checkninsert(i+1, j, visited, nums1, nums2))
                pq.push({nums1[i+1]+nums2[j], i+1, j});
            if(checkninsert(i, j+1, visited, nums1, nums2))
                pq.push({nums1[i]+nums2[j+1], i, j+1});
        }
        return ans;
    }

};
