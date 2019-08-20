/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 *
 * https://leetcode.com/problems/sliding-window-maximum/description/
 *
 * algorithms
 * Hard (38.57%)
 * Total Accepted:    168.4K
 * Total Submissions: 436K
 * Testcase Example:  '[1,3,-1,-3,5,3,6,7]\n3'
 *
 * <p>Given an array <em>nums</em>, there is a sliding window of size
 * <em>k</em> which is moving from the very left of the array to the very
 * right. You can only see the <em>k</em> numbers in the window. Each time the
 * sliding window moves right by one position. Return the max sliding
 * window.</p>
 * 
 * <p><strong>Example:</strong></p>
 * 
 * <pre>
 * <strong>Input:</strong> <em>nums</em> = <code>[1,3,-1,-3,5,3,6,7]</code>,
 * and <em>k</em> = 3
 * <strong>Output: </strong><code>[3,3,5,5,6,7] 
 * <strong>Explanation: 
 * </strong></code>
 * Window position                Max
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       <strong>3</strong>
 * ⁠1 [3  -1  -3] 5  3  6  7       <strong>3</strong>
 * ⁠1  3 [-1  -3  5] 3  6  7      <strong> 5</strong>
 * ⁠1  3  -1 [-3  5  3] 6  7       <strong>5</strong>
 * ⁠1  3  -1  -3 [5  3  6] 7       <strong>6</strong>
 * ⁠1  3  -1  -3  5 [3  6  7]      <strong>7</strong>
 * </pre>
 * 
 * <p><strong>Note: </strong><br />
 * You may assume <em>k</em> is always valid, 1 &le; k &le; input array&#39;s
 * size for non-empty array.</p>
 * 
 * <p><strong>Follow up:</strong><br />
 * Could you solve it in linear time?</p>
 */
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        int n = nums.size();
        vector<int> ans;
        for(int i=0; i<n; i++){
        	// remove older element
        	if(!q.empty() && q.front() <= i-k)
        		q.pop_front();
        	while(!q.empty() && nums[q.back()] <= nums[i])
        		q.pop_back();
        	q.push_back(i);
        	if(i>=k-1)
        		ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};
