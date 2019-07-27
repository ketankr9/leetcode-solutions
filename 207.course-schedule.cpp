/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 *
 * https://leetcode.com/problems/course-schedule/description/
 *
 * algorithms
 * Medium (38.53%)
 * Total Accepted:    234.8K
 * Total Submissions: 609.5K
 * Testcase Example:  '2\n[[1,0]]'
 *
 * There are a total of n courses you have to take, labeled from 0 to n-1.
 * 
 * Some courses may have prerequisites, for example to take course 0 you have
 * to first take course 1, which is expressed as a pair: [0,1]
 * 
 * Given the total number of courses and a list of prerequisite pairs, is it
 * possible for you to finish all courses?
 * 
 * Example 1:
 * 
 * 
 * Input: 2, [[1,0]] 
 * Output: true
 * Explanation: There are a total of 2 courses to take. 
 * To take course 1 you should have finished course 0. So it is possible.
 * 
 * Example 2:
 * 
 * 
 * Input: 2, [[1,0],[0,1]]
 * Output: false
 * Explanation: There are a total of 2 courses to take. 
 * To take course 1 you should have finished course 0, and to take course 0 you
 * should
 * also have finished course 1. So it is impossible.
 * 
 * 
 * Note:
 * 
 * 
 * The input prerequisites is a graph represented by a list of edges, not
 * adjacency matrices. Read more about how a graph is represented.
 * You may assume that there are no duplicate edges in the input
 * prerequisites.
 * 
 * 
 */
class Solution {
public:
    bool loop;
    void dfs(int root, unordered_map<int, vector<int>> &mm, vector<int> &visited){
        if(loop)    return;
        for(auto ch: mm[root]){
            if(visited[ch] == 2) continue;
            if(visited[ch] == 1){ loop = true; return; }
            visited[ch] = 1;
            dfs(ch, mm, visited);
            visited[ch] = 2;
        }
    }
    bool canFinish(int N, vector<vector<int>>& prere) {
        unordered_map<int, vector<int>> mm;
        for(auto e: prere)
            mm[e[0]].push_back(e[1]);
        loop = false;
        vector<int> visited(N, 0);
        for(int i=0; i<N; i++)
            if(visited[i]!=2){
                visited[i] = 1;
                dfs(i, mm, visited);
                visited[i] = 2;
            }
        return !loop;
    }
};
