/*
 * @lc app=leetcode id=959 lang=cpp
 *
 * [959] Regions Cut By Slashes
 *
 * https://leetcode.com/problems/regions-cut-by-slashes/description/
 *
 * algorithms
 * Medium (62.35%)
 * Total Accepted:    8.8K
 * Total Submissions: 14.1K
 * Testcase Example:  '[" /","/ "]'
 *
 * In a N x N grid composed of 1 x 1 squares, each 1 x 1 square consists of a
 * /, \, or blank space.  These characters divide the square into contiguous
 * regions.
 * 
 * (Note that backslash characters are escaped, so a \ is represented as
 * "\\".)
 * 
 * Return the number of regions.
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
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * [
 * " /",
 * "/ "
 * ]
 * Output: 2
 * Explanation: The 2x2 grid is as follows:
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * [
 * " /",
 * "  "
 * ]
 * Output: 1
 * Explanation: The 2x2 grid is as follows:
 * 
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input:
 * [
 * "\\/",
 * "/\\"
 * ]
 * Output: 4
 * Explanation: (Recall that because \ characters are escaped, "\\/" refers to
 * \/, and "/\\" refers to /\.)
 * The 2x2 grid is as follows:
 * 
 * 
 * 
 * 
 * Example 4:
 * 
 * 
 * Input:
 * [
 * "/\\",
 * "\\/"
 * ]
 * Output: 5
 * Explanation: (Recall that because \ characters are escaped, "/\\" refers to
 * /\, and "\\/" refers to \/.)
 * The 2x2 grid is as follows:
 * 
 * 
 * 
 * 
 * Example 5:
 * 
 * 
 * Input:
 * [
 * "//",
 * "/ "
 * ]
 * Output: 3
 * Explanation: The 2x2 grid is as follows:
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= grid.length == grid[0].length <= 30
 * grid[i][j] is either '/', '\', or ' '.
 * 
 * 
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    int p(int x, int y){ return x*32+y; }
    
    int findp(int x, unordered_map<int, int>& parent){
        if(parent.find(x)!=parent.end() && parent[x]!=x)
            return parent[x] = findp(parent[x], parent);
        return parent[x] = x;
    }
    bool unionp(int x, int y, unordered_map<int, int>& parent){
        int p1 = findp(x, parent);
        int p2 = findp(y, parent);
        return p1==p2?true:((parent[p1] = p2)&&false);
    }
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 1;
        unordered_map<int, int> parent;
        parent[0] = 0;
        for(int i=0; i<=n; i++){
            unionp(0, p(i, m), parent);
            unionp(0, p(i, 0), parent);
        }
        for(int j=0; j<=m; j++){
            unionp(0, p(0, j), parent);
            unionp(0, p(n, j), parent);
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                // slash (i,j+1) to (i+1, j)
                // back-slash (i,j) to (i+1, j+1)
                if(grid[i][j] == '/'){
                    cnt += unionp(p(i, j+1), p(i+1, j), parent);
                }else if(grid[i][j] == '\\'){
                    cnt += unionp(p(i, j), p(i+1, j+1), parent);
                }
                
            }
        }
        return cnt;
    }
};