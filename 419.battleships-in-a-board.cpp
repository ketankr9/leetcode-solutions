/*
 * @lc app=leetcode id=419 lang=cpp
 *
 * [419] Battleships in a Board
 *
 * https://leetcode.com/problems/battleships-in-a-board/description/
 *
 * algorithms
 * Medium (66.56%)
 * Total Accepted:    68.2K
 * Total Submissions: 102.4K
 * Testcase Example:  '[["X",".",".","X"],[".",".",".","X"],[".",".",".","X"]]'
 *
 * Given an 2D board, count how many battleships are in it. The battleships are
 * represented with 'X's, empty slots are represented with '.'s. You may assume
 * the following rules:
 * 
 * 
 * You receive a valid board, made of only battleships or empty slots.
 * Battleships can only be placed horizontally or vertically. In other words,
 * they can only be made of the shape 1xN (1 row, N columns) or Nx1 (N rows, 1
 * column), where N can be of any size.
 * At least one horizontal or vertical cell separates between two battleships -
 * there are no adjacent battleships.
 * 
 * 
 * Example:
 * X..X
 * ...X
 * ...X
 * 
 * In the above board there are 2 battleships.
 * 
 * Invalid Example:
 * ...X
 * XXXX
 * ...X
 * 
 * This is an invalid board that you will not receive - as battleships will
 * always have a cell separating between them.
 * 
 * Follow up:Could you do it in one-pass, using only O(1) extra memory and
 * without modifying the value of the board?
 */
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
   		int cnt = 0;
   		if(board.empty())	return cnt;
   		int n = board.size(), m = board[0].size();
        for(int i=1; i<=n; i++){
        	int j = 0;
        	while(j<m){
	        	if(board[i-1][j] == 'X' && (i==n?true:board[i][j] == '.') ){
		        	while(j<m && (i==n?true:board[i][j] == '.') && board[i-1][j] == 'X')
		        		j++;
		        	cnt++;
	        	}else
		    		while(j<m && !((i==n?true:board[i][j] == '.') && board[i-1][j] == 'X'))
		    			j++;
        	}
        }
    	return cnt;
    }
};
