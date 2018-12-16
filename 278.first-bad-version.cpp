/*
 * @lc app=leetcode id=278 lang=cpp
 *
 * [278] First Bad Version
 *
 * https://leetcode.com/problems/first-bad-version/description/
 *
 * algorithms
 * Easy (27.94%)
 * Total Accepted:    187.3K
 * Total Submissions: 669.3K
 * Testcase Example:  '5\n4'
 *
 * You are a product manager and currently leading a team to develop a new
 * product. Unfortunately, the latest version of your product fails the quality
 * check. Since each version is developed based on the previous version, all
 * the versions after a bad version are also bad.
 * 
 * Suppose you have n versions [1, 2, ..., n] and you want to find out the
 * first bad one, which causes all the following ones to be bad.
 * 
 * You are given an API bool isBadVersion(version) which will return whether
 * version is bad. Implement a function to find the first bad version. You
 * should minimize the number of calls to the API.
 * 
 * Example:
 * 
 * 
 * Given n = 5, and version = 4 is the first bad version.
 * 
 * call isBadVersion(3) -> false
 * call isBadVersion(5) -> true
 * call isBadVersion(4) -> true
 * 
 * Then 4 is the first bad version. 
 * 
 */
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    unordered_map<int, bool> mm;
    int binsearch(int start, int end){
        // cout<<start<<":"<<end<<" ";
        if(start == end){
            if(start == 1)
                return 1;
        }
        // ** MOST IMPORTANT, (start+mid)2 may overflow but (start/2 + end/2) will not.
        int mid = (start/2) + (end/2);
    
        if(mm.count(mid) > 0)
            mm[mid] = mm[mid];
        else
            mm[mid] = isBadVersion(mid);
        
        if(mm.count(mid+1)>0)
            mm[mid+1]=mm[mid+1];
        else
            mm[mid+1]=isBadVersion(mid+1);
        
        if(mm[mid] == false && mm[mid+1] == true){
            return mid+1;
        }else if(mm[mid] == true){ // search in left half
            return binsearch(start, mid);
        }else if(mm[mid+1] == false){ // search in right half
            return binsearch(mid+1, end);
        } 

    }
    int firstBadVersion(int n) {
        return binsearch(1, n);
    }
};
