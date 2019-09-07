/*
 *
 
 * [220] Contains Duplicate III
 *
 * https
 ://leetcode.com/problems/contains-duplicate-iii/description/
 *
 *		} Example 1:
 * 
 * 
 * Input: nums = [1,2,3,1], k = 3, t = 0
 * Output: true
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,0,1,1], k = 1, t = 2
 * Output: true
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [1,5,9,1,5,9], k = 2, t = 3
 * Output: false
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    	if(nums.size() == 0)	return false;
    	
    	set<int> ss;
    	unordered_map<int, int> mm;
    	
    	ss.insert(nums[0]);
    	mm[nums[0]]++;
    	
    	for(int i = 1; i<nums.size(); i++){
			
			if(i>k && --mm[nums[i-k-1]]==0)
					ss.erase(nums[i-k-1]);
			
			auto it = ss.upper_bound(nums[i]);

			if(it!=ss.end()   && abs((long long)(*it)      -nums[i]) <= (long long)t)	return true;
			if(it!=ss.begin() && abs((long long)(*prev(it))-nums[i]) <= (long long)t)	return true;

			ss.insert(nums[i]);
			mm[nums[i]]++;  
		}
    	return false;
    }
};
