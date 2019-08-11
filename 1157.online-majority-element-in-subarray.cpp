/*
 * @lc app=leetcode id=1157 lang=cpp
 *
 * [1157] Online Majority Element In Subarray
 *
 * https://leetcode.com/problems/online-majority-element-in-subarray/description/
 *
 * algorithms
 * Hard (17.51%)
 * Total Accepted:    408
 * Total Submissions: 2.5K
 * Testcase Example:  '["MajorityChecker","query","query","query"]\n[[[1,1,2,2,1,1]],[0,5,4],[0,3,3],[2,3,2]]'
 *
 * Implementing the class MajorityChecker, which has the following API:
 * 
 * 
 * MajorityChecker(int[] arr) constructs an instance of MajorityChecker with
 * the given array arr;
 * int query(int left, int right, int threshold) has arguments such
 * that:
 * 
 * 0 <= left <= right < arr.length representing a subarray of arr;
 * 2 * threshold > right - left + 1, ie. the threshold is always a strict
 * majority of the length of the subarray
 * 
 * 
 * 
 * 
 * Each query(...) returns the element in arr[left], arr[left+1], ...,
 * arr[right] that occurs at least threshold times, or -1 if no such element
 * exists.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * MajorityChecker majorityChecker = new MajorityChecker([1,1,2,2,1,1]);
 * majorityChecker.query(0,5,4); // returns 1
 * majorityChecker.query(0,3,3); // returns -1
 * majorityChecker.query(2,3,2); // returns 2
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= arr.length <= 20000
 * 1 <= arr[i] <= 20000
 * For each query, 0 <= left <= right < len(arr)
 * For each query, 2 * threshold > right - left + 1
 * The number of queries is at most 10000
 * 
 * 
 */
class MajorityChecker {
public:
    vector<int> vec;
    unordered_map<int, vector<int>> pos;
    MajorityChecker(vector<int>& arr) {
        vec = arr;
        for(int i=0; i<(int)arr.size(); i++)
            pos[arr[i]].push_back(i);
    }
    
    int query(int left, int right, int t) {
        // int cnt = 0;
        // int prev = -1;
        // for(int i=left; i<=right; i++){
        //     if(cnt==0)
        //         prev = vec[i];
        //     cnt += (vec[i]==prev?1:-1);
        // }
        // if(cnt>0){
        //     int count = 0;
        //     for(int i=left; i<=right; i++) count += (vec[i]==prev);
        //     return count>=t?prev:-1;
        // }
        for(int o=0; o<10; o++){
            int num = vec[left + rand()%(right-left+1)];
            if(upper_bound(pos[num].begin(), pos[num].end(), right)-lower_bound(pos[num].begin(), pos[num].end(), left)>= t)
                return num;
        }
        return -1;
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */
