/*
 * @lc app=leetcode id=947 lang=cpp
 *
 * [947] Most Stones Removed with Same Row or Column
 *
 * https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/
 *
 * algorithms
 * Medium (54.44%)
 * Total Accepted:    25.9K
 * Total Submissions: 47.6K
 * Testcase Example:  '[[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]'
 *
 * On a 2D plane, we place stones at some integer coordinate points.  Each
 * coordinate point may have at most one stone.
 * 
 * Now, a move consists of removing a stone that shares a column or row with
 * another stone on the grid.
 * 
 * What is the largest possible number of moves we can make?
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
 * Output: 5
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
 * Output: 3
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: stones = [[0,0]]
 * Output: 0
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= stones.length <= 1000
 * 0 <= stones[i][j] < 10000
 * 
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    int find_(int x, vector<int>& parent){
        if(parent[x]!=-1 && parent[x]!=x)
            return parent[x] = find_(parent[x], parent);
        return parent[x]=x;
    }
    void union_(int x, int y, vector<int>& parent){
        int px = find_(x, parent);
        int py = find_(y, parent);
        if(px == py)    return;
        parent[px] = py;
    }
    int removeStones(vector<vector<int>>& stones) {
         
        vector<int> parent(10000+10000+2, -1);
        for(auto e: stones)
            union_(e[0], 10001+e[1], parent);
        unordered_set<int> mm;
        for(auto e: stones){
            mm.insert(find_(e[0], parent));
            mm.insert(find_(10001+e[1], parent));
        }
        return stones.size()-mm.size();
    }
};
