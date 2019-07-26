/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 *
 * https://leetcode.com/problems/largest-rectangle-in-histogram/description/
 *
 * algorithms
 * Hard (31.65%)
 * Likes:    2083
 * Dislikes: 56
 * Total Accepted:    184.9K
 * Total Submissions: 583K
 * Testcase Example:  '[2,1,5,6,2,3]'
 *
 * Given n non-negative integers representing the histogram's bar height where
 * the width of each bar is 1, find the area of largest rectangle in the
 * histogram.
 * 
 * 
 * 
 * 
 * Above is a histogram where width of each bar is 1, given height =
 * [2,1,5,6,2,3].
 * 
 * 
 * 
 * 
 * The largest rectangle is shown in the shaded area, which has area = 10
 * unit.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: [2,1,5,6,2,3]
 * Output: 10
 * 
 * 
 */
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        if(n == 0)  return 0;
        int right[n];
        int left[n];
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && heights[i] <= heights[st.top()])
                st.pop();
            right[i] = (st.empty() ? (n-1)-i : (st.top()-1)-i);
            st.push(i);
        }
        stack<int> empty;   swap(empty, st);
        for(int i=0; i<n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            left[i] = (st.empty() ? i-0 : i-(st.top()+1));
            st.push(i);
        }

        int ans = 0;
        for(int i=0; i<n; i++)
            ans = max(ans, (left[i] + right[i] + 1)*heights[i]);

        return ans;
    }
};
