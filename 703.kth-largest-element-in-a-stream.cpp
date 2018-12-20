/*
 * @lc app=leetcode id=703 lang=cpp
 *
 * [703] Kth Largest Element in a Stream
 *
 * https://leetcode.com/problems/kth-largest-element-in-a-stream/description/
 *
 * algorithms
 * Easy (41.09%)
 * Total Accepted:    14.5K
 * Total Submissions: 34.9K
 * Testcase Example:  '["KthLargest","add","add","add","add","add"]\n[[3,[4,5,8,2]],[3],[5],[10],[9],[4]]'
 *
 * Design a class to find the kth largest element in a stream. Note that it is
 * the kth largest element in the sorted order, not the kth distinct element.
 * 
 * Your KthLargest class will have a constructor which accepts an integer k and
 * an integer array nums, which contains initial elements from the stream. For
 * each call to the method KthLargest.add, return the element representing the
 * kth largest element in the stream.
 * 
 * Example:
 * 
 * 
 * int k = 3;
 * int[] arr = [4,5,8,2];
 * KthLargest kthLargest = new KthLargest(3, arr);
 * kthLargest.add(3);   // returns 4
 * kthLargest.add(5);   // returns 5
 * kthLargest.add(10);  // returns 5
 * kthLargest.add(9);   // returns 8
 * kthLargest.add(4);   // returns 8
 * 
 * 
 * Note: 
 * You may assume that nums' length ≥ k-1 and k ≥ 1.
 * 
 */
class KthLargest {
public:
    vector<int> nums;
    int k;
    KthLargest(int k, vector<int> nums_) {
        this->k = k;
        nums = nums_;
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
    }
    
    int add(int val) {
        int i=0;
        while(i<(int)nums.size() && val < nums[i])
            i++;
        nums.insert(nums.begin()+i, val);
        return nums[k-1];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */
