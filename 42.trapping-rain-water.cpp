/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 *
 * https://leetcode.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (43.73%)
 * Likes:    3874
 * Dislikes: 71
 * Total Accepted:    311.7K
 * Total Submissions: 711.9K
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * Given n non-negative integers representing an elevation map where the width
 * of each bar is 1, compute how much water it is able to trap after raining.
 * 
 * 
 * The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
 * In this case, 6 units of rain water (blue section) are being trapped. Thanks
 * Marcos for contributing this image!
 * 
 * Example:
 * 
 * 
 * Input: [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 * 
 */
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n == 0)  return 0;
        
        stack<int> st;

        vector<int> nm(n, -1);
        for(int i=n-1; i>=0; i--){
            int last = -1;
            while(!st.empty() && height[i] > height[st.top()])
                last = st.top(), st.pop();
            nm[i] = (st.empty() ? last : st.top());
            st.push(i);
        }
        int start = 0;
        int ans = 0;
        while(nm[start]!=-1){
            int end = nm[start];
            ans += (end - start -1)*min(height[start], height[end]);
            for(int i=start+1; i<end; i++)
                ans -= height[i];
            start = end;
        }
        return ans;

    }
};

