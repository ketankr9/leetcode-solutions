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
    int offs;
    NumArray(vector<int>& nums) {
        if((int)nums.size() == 0){
            offs = -1;
            return;
        }
        int lg = ceil(log2((int)nums.size()));
        int n = 1<<(lg+1);
        offs = 1<<lg;
        tree = vector<int>(n, 0);
        for(int i=0; i<(int)nums.size(); i++)
            tree[i+offs] = nums[i];
        for(int l = lg; l>=1; l--){
            for(int i=1<<(l-1); i<1<<l; i++)
                tree[i] = tree[i*2] + tree[2*i+1];
        }
        // for(auto e: tree)
        //     cout<<e<<" ";
    }
    
    void update(int i, int val) {
        if(offs==-1)    return;
        int start = offs+i;
        int diff = val-tree[start];
        tree[start] = val;
        start/=2;
        while(start>=1){
            tree[start] += diff;
            start/=2;
        }
        // cout<<" up ";
        // for(auto e: tree)
        //     cout<<e<<" ";
    }
    
    int sumRange(int i, int j) {
        i += offs;
        j += offs;
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
