/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 *
 * https://leetcode.com/problems/first-missing-positive/description/
 *
 * algorithms
 * Hard (27.51%)
 * Total Accepted:    175K
 * Total Submissions: 635.3K
 * Testcase Example:  '[1,2,0]'
 *
 * Given an unsorted integer array, find the smallest missing positive
 * integer.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,0]
 * Output: 3
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,4,-1,1]
 * Output: 2
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [7,8,9,11,12]
 * Output: 1
 * 
 * 
 * Note:
 * 
 * Your algorithm should run in O(n) time and uses constant extra space.
 * 
 */
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i=0;
        int N=(int)nums.size();
        int j = N-1;
        while(i<=j){
            if(nums[i]>0) i++;
            else if(nums[j]<=0) j--;
            else{
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
        }
        // for(int p=0;p<N;p++)    cout<<nums[p]<<" ";
        cout<<"i:"<<i<<endl;
        // if(nums[i]<=0)
            // i--;
        for(int j=0;j<i;j++){
            int pos = abs(nums[j]);
            if(pos > N) continue;
            nums[pos-1] = -abs(nums[pos-1]);
        }
        // for(auto e:nums) cout<<e<<" ";
        for(j=0;j<i;j++)
            if(nums[j] < 0) continue;
            else    break;
        return j+1;
    }
};
