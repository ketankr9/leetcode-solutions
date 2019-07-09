/*
 * @lc app=leetcode id=886 lang=cpp
 *
 * [886] Possible Bipartition
 *
 * https://leetcode.com/problems/possible-bipartition/description/
 *
 * algorithms
 * Medium (40.90%)
 * Total Accepted:    13.9K
 * Total Submissions: 34K
 * Testcase Example:  '4\n[[1,2],[1,3],[2,4]]'
 *
 * Given a set of N people (numbered 1, 2, ..., N), we would like to split
 * everyone into two groups of any size.
 * 
 * Each person may dislike some other people, and they should not go into the
 * same group. 
 * 
 * Formally, if dislikes[i] = [a, b], it means it is not allowed to put the
 * people numbered a and b into the same group.
 * 
 * Return true if and only if it is possible to split everyone into two groups
 * in this way.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: N = 4, dislikes = [[1,2],[1,3],[2,4]]
 * Output: true
 * Explanation: group1 [1,4], group2 [2,3]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: N = 3, dislikes = [[1,2],[1,3],[2,3]]
 * Output: false
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: N = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
 * Output: false
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= N <= 2000
 * 0 <= dislikes.length <= 10000
 * 1 <= dislikes[i][j] <= N
 * dislikes[i][0] < dislikes[i][1]
 * There does not exist i != j for which dislikes[i] == dislikes[j].
 * 
 * 
 * 
 * 
 * 
 */

class Solution {
public:
    vector<vector<int>> vec;
    vector<int> color;
    bool flag;
    void visit(int i, int col){
        if(!flag || color[i]!=-1){
            if(color[i]!=col)
                flag = false;
            return;
        }
        color[i] = col;
        for(auto e: vec[i])
            visit(e, col^1);

    }
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        flag = true;
        vec = vector<vector<int>>(N);
        color = vector<int>(N, -1);
        for(auto e: dislikes){
            vec[e[0]-1].push_back(e[1]-1);
            vec[e[1]-1].push_back(e[0]-1);
        }
        for(int i=0; i<N && flag; i++){
            if(color[i]==-1)
                visit(i, 0);
        }
        return flag;

    }
};
