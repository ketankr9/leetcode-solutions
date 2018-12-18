/*
 * @lc app=leetcode id=859 lang=cpp
 *
 * [859] Buddy Strings
 *
 * https://leetcode.com/problems/buddy-strings/description/
 *
 * algorithms
 * Easy (26.88%)
 * Total Accepted:    15.8K
 * Total Submissions: 58.5K
 * Testcase Example:  '"ab"\n"ba"'
 *
 * Given two strings A and B of lowercase letters, return true if and only if
 * we can swap two letters in A so that the result equals B.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * Input: A = "ab", B = "ba"
 * Output: true
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: A = "ab", B = "ab"
 * Output: false
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: A = "aa", B = "aa"
 * Output: true
 * 
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: A = "aaaaaaabc", B = "aaaaaaacb"
 * Output: true
 * 
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: A = "", B = "aa"
 * Output: false
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 0 <= A.length <= 20000
 * 0 <= B.length <= 20000
 * A and B consist only of lowercase letters.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */
static int speedup=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    bool buddyStrings(string A, string B) {
        int n1 = A.size();
        int n2 = B.size();

        if(n1!=n2)  return false;
        int differ = 0;
        int pos[2];
        for(int i=0;i<n1;i++){
            if(A[i]!=B[i]){
                differ++;
            if(differ > 2)
                return false;
            pos[differ-1] = i;
            }
        }
        if(differ == 2){
            if(A[pos[0]] == B[pos[1]] && A[pos[1]]==B[pos[0]])
                return true;    
            return false;
        }else if(differ == 1)
            return false;
            
        // differ == 0
        unordered_set<char> ss(A.begin(), A.end());
        return ss.size() == n1 ? false : true;
    }
};