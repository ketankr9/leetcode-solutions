/*
 * @lc app=leetcode id=661 lang=cpp
 *
 * [661] Image Smoother
 *
 * https://leetcode.com/problems/image-smoother/description/
 *
 * algorithms
 * Easy (50.37%)
 * Likes:    217
 * Dislikes: 950
 * Total Accepted:    43.4K
 * Total Submissions: 86.2K
 * Testcase Example:  '[[1,1,1],[1,0,1],[1,1,1]]'
 *
 * Given a 2D integer matrix M representing the gray scale of an image, you
 * need to design a smoother to make the gray scale of each cell becomes the
 * average gray scale (rounding down) of all the 8 surrounding cells and
 * itself.  If a cell has less than 8 surrounding cells, then use as many as
 * you can.
 * 
 * Example 1:
 * 
 * Input:
 * [[1,1,1],
 * ⁠[1,0,1],
 * ⁠[1,1,1]]
 * Output:
 * [[0, 0, 0],
 * ⁠[0, 0, 0],
 * ⁠[0, 0, 0]]
 * Explanation:
 * For the point (0,0), (0,2), (2,0), (2,2): floor(3/4) = floor(0.75) = 0
 * For the point (0,1), (1,0), (1,2), (2,1): floor(5/6) = floor(0.83333333) = 0
 * For the point (1,1): floor(8/9) = floor(0.88888889) = 0
 * 
 * 
 * 
 * Note:
 * 
 * The value in the given matrix is in the range of [0, 255].
 * The length and width of the given matrix are in the range of [1, 150].
 * 
 * 
 */

// @lc code=start
class Solution {
public:
	// int corner(vector<vector<int>>& M, int x, int y){
	// 	int ret = 0;
	// 	for(int p=0; p<2; p++)
 //        	for(int q=0; q<2; q++)
 //        		ret += M[x+p][y+q];
 //        return ret/4;
	// }

    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int n = M.size(), m = M[0].size();
        vector<vector<int>> ret(n, vector<int>(m, 0));
        for(int i=0; i<n; i++)
        	for(int j=0; j<m; j++){
        		int div = 0;
        		for(int p=-1; p<=1; p++)
        			for(int q=-1; q<=1; q++)
        				if((i+p)<n && (j+q)<m && (i+p)>=0 && (j+q)>=0){
        					ret[i][j] += M[i+p][j+q];
        					div++;
        				}
        		ret[i][j] /= div;
        	}
        return ret;
    }
};
// @lc code=end
