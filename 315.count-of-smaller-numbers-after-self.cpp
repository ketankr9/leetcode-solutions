/*
 * @lc app=leetcode id=315 lang=cpp
 *
 * [315] Count of Smaller Numbers After Self
 *
 * https://leetcode.com/problems/count-of-smaller-numbers-after-self/description/
 *
 * algorithms
 * Hard (38.24%)
 * Total Accepted:    77.8K
 * Total Submissions: 203.5K
 * Testcase Example:  '[5,2,6,1]'
 *
 * <p>You are given an integer array <i>nums</i> and you have to return a new
 * <i>counts</i> array. The <i>counts</i> array has the property where
 * <code>counts[i]</code> is the number of smaller elements to the right of
 * <code>nums[i]</code>.</p>
 * 
 * <p><b>Example:</b></p>
 * 
 * <pre>
 * <strong>Input:</strong> [5,2,6,1]
 * <strong>Output:</strong> <code>[2,1,1,0] 
 * <strong>Explanation:</strong></code>
 * To the right of 5 there are <b>2</b> smaller elements (2 and 1).
 * To the right of 2 there is only <b>1</b> smaller element (1).
 * To the right of 6 there is <b>1</b> smaller element (1).
 * To the right of 1 there is <b>0</b> smaller element.
 * </pre>
 */
class Solution {
public:
	#define f first
	#define s second
	#define pb push_back
	typedef pair<int, int> pr;
	void sort(int start, int end, vector<pr>& vec, vector<int>& ans){
		if(start >= end)	return;

		int mid = start+(end-start)/2;

		sort(start, mid, vec, ans);
		sort(mid+1, end, vec, ans);
		
		int i = start, j = mid+1, tmp = 0;
		vector<pr> arr;
		while(i <= mid && j <= end){
			// if(i>mid && j>end)	break;
			if(vec[i].f <= vec[j].f){
				// vec[i].s.f += tmp;
				ans[vec[i].s] += tmp;
				arr.pb(vec[i]);
				i++;
			}else if(vec[i].f > vec[j].f){
				tmp++;
				arr.pb(vec[j]);
				j++;
			}
		}
		while(i<=mid){
			// vec[i].s.f += tmp;
			ans[vec[i].s] += tmp;
				arr.pb(vec[i]);
				i++;
		}
		while(j<=end){
			tmp++;
			arr.pb(vec[j]);
			j++;
		}
		i = start;
		assert(arr.size() == end-start+1);
		while(i<=end)
			vec[i] = arr[i-start], i++;
	}
    vector<int> countSmaller(vector<int>& nums) {
    	int n = nums.size();
    	vector<int> ans(n, 0);
    	vector<pr> vec;
    	
    	for(int i=0; i<n; i++)
    		vec.push_back({nums[i], i});
		
		sort(0, n-1, vec, ans);
    	return ans;
    }
};
