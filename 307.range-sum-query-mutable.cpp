/*
 * @lc app=leetcode id=307 lang=cpp
 *
 * [307] Range Sum Query - Mutable
 *
 * https://leetcode.com/problems/range-sum-query-mutable/description/
 *
 * algorithms
 * Medium (29.21%)
 * Total Accepted:    74.7K
 * Total Submissions: 255.6K
 * Testcase Example:  '["NumArray","sumRange","update","sumRange"]\n[[[1,3,5]],[0,2],[1,2],[0,2]]'
 *
 * Given an integer array nums, find the sum of the elements between indices i
 * and j (i ≤ j), inclusive.
 * 
 * The update(i, val) function modifies nums by updating the element at index i
 * to val.
 * 
 * Example:
 * 
 * 
 * Given nums = [1, 3, 5]
 * 
 * sumRange(0, 2) -> 9
 * update(1, 2)
 * sumRange(0, 2) -> 8
 * 
 * 
 * Note:
 * 
 * 
 * The array is only modifiable by the update function.
 * You may assume the number of calls to update and sumRange function is
 * distributed evenly.
 * 
 * 
 */
class NumArray {
public:
    vector<int> tree;
    int n;
    NumArray(vector<int>& nums) {
        n = nums.size();
        if(n == 0)
            return;
        
        tree = vector<int>(2*n, 0);
        
        for(int i=n; i<2*n; i++)
            tree[i] = nums[i-n];
        
        for(int i=n-1; i>=1; i--)
            tree[i] = tree[i*2] + tree[2*i+1];
    }
    
    void update(int i, int val) {
        if(n==0)    return;
        int start = n+i;
        
        int diff = val-tree[start];
        
        while(start>=1){
            tree[start] += diff;
            start/=2;
        }
    }
    
    int sumRange(int i, int j) {
        i += n;
        j += n;
        int ans = 0;
        while(i<=j){
            if(i%2==1) ans += tree[i++];
            if(j%2==0) ans += tree[j--];
            i/=2; j/=2;
        }
        return ans;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
