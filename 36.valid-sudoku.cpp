/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 *
 * https://leetcode.com/problems/valid-sudoku/description/
 *
 * algorithms
 * Medium (43.63%)
 * Total Accepted:    246.3K
 * Total Submissions: 564.6K
 * Testcase Example:  '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * <p>Determine if a&nbsp;9x9 Sudoku board&nbsp;is valid.&nbsp;Only the filled
 * cells need to be validated&nbsp;<strong>according to the following
 * rules</strong>:</p>
 * 
 * <ol>
 * <li>Each row&nbsp;must contain the&nbsp;digits&nbsp;<code>1-9</code> without
 * repetition.</li>
 * <li>Each column must contain the digits&nbsp;<code>1-9</code>&nbsp;without
 * repetition.</li>
 * <li>Each of the 9 <code>3x3</code> sub-boxes of the grid must contain the
 * digits&nbsp;<code>1-9</code>&nbsp;without repetition.</li>
 * </ol>
 * 
 * <p><img
 * src="https://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Sudoku-by-L2G-20050714.svg/250px-Sudoku-by-L2G-20050714.svg.png"
 * style="height:250px; width:250px" /><br />
 * <small>A partially filled sudoku which is valid.</small></p>
 * 
 * <p>The Sudoku board could be partially filled, where empty cells are filled
 * with the character <code>&#39;.&#39;</code>.</p>
 * 
 * <p><strong>Example 1:</strong></p>
 * 
 * <pre>
 * <strong>Input:</strong>
 * [
 * ⁠
 * [&quot;5&quot;,&quot;3&quot;,&quot;.&quot;,&quot;.&quot;,&quot;7&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;],
 * ⁠
 * [&quot;6&quot;,&quot;.&quot;,&quot;.&quot;,&quot;1&quot;,&quot;9&quot;,&quot;5&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;],
 * ⁠
 * [&quot;.&quot;,&quot;9&quot;,&quot;8&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;6&quot;,&quot;.&quot;],
 * ⁠
 * [&quot;8&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;6&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;3&quot;],
 * ⁠
 * [&quot;4&quot;,&quot;.&quot;,&quot;.&quot;,&quot;8&quot;,&quot;.&quot;,&quot;3&quot;,&quot;.&quot;,&quot;.&quot;,&quot;1&quot;],
 * ⁠
 * [&quot;7&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;2&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;6&quot;],
 * ⁠
 * [&quot;.&quot;,&quot;6&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;2&quot;,&quot;8&quot;,&quot;.&quot;],
 * ⁠
 * [&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;4&quot;,&quot;1&quot;,&quot;9&quot;,&quot;.&quot;,&quot;.&quot;,&quot;5&quot;],
 * ⁠
 * [&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;8&quot;,&quot;.&quot;,&quot;.&quot;,&quot;7&quot;,&quot;9&quot;]
 * ]
 * <strong>Output:</strong> true
 * </pre>
 * 
 * <p><strong>Example 2:</strong></p>
 * 
 * <pre>
 * <strong>Input:</strong>
 * [
 * &nbsp;
 * [&quot;8&quot;,&quot;3&quot;,&quot;.&quot;,&quot;.&quot;,&quot;7&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;],
 * &nbsp;
 * [&quot;6&quot;,&quot;.&quot;,&quot;.&quot;,&quot;1&quot;,&quot;9&quot;,&quot;5&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;],
 * &nbsp;
 * [&quot;.&quot;,&quot;9&quot;,&quot;8&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;6&quot;,&quot;.&quot;],
 * &nbsp;
 * [&quot;8&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;6&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;3&quot;],
 * &nbsp;
 * [&quot;4&quot;,&quot;.&quot;,&quot;.&quot;,&quot;8&quot;,&quot;.&quot;,&quot;3&quot;,&quot;.&quot;,&quot;.&quot;,&quot;1&quot;],
 * &nbsp;
 * [&quot;7&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;2&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;6&quot;],
 * &nbsp;
 * [&quot;.&quot;,&quot;6&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;2&quot;,&quot;8&quot;,&quot;.&quot;],
 * &nbsp;
 * [&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;4&quot;,&quot;1&quot;,&quot;9&quot;,&quot;.&quot;,&quot;.&quot;,&quot;5&quot;],
 * &nbsp;
 * [&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;8&quot;,&quot;.&quot;,&quot;.&quot;,&quot;7&quot;,&quot;9&quot;]
 * ]
 * <strong>Output:</strong> false
 * <strong>Explanation:</strong> Same as Example 1, except with the
 * <strong>5</strong> in the top left corner being 
 * ⁠   modified to <strong>8</strong>. Since there are two 8&#39;s in the top
 * left 3x3 sub-box, it is invalid.
 * </pre>
 * 
 * <p><strong>Note:</strong></p>
 * 
 * <ul>
 * <li>A Sudoku board (partially filled) could be valid but is not necessarily
 * solvable.</li>
 * <li>Only the filled cells need to be validated according to the
 * mentioned&nbsp;rules.</li>
 * <li>The given board&nbsp;contain only digits <code>1-9</code> and the
 * character <code>&#39;.&#39;</code>.</li>
 * <li>The given board size is always <code>9x9</code>.</li>
 * </ul>
 * 
 */
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<bool> vec;

        // row wise
        for(int r=0; r<9;r++){
            vec = vector<bool>(10, false);
            for(int c=0; c<9; c++){
                if(board[r][c] == '.')  continue;
                if(vec[board[r][c]-'0'])   return false;
                vec[board[r][c]-'0'] = true;
            }
        }
        cout<<"passed row; ";
        for(int r=0; r<9;r++){
            vec = vector<bool>(10, false);
            for(int c=0; c<9; c++){
                if(board[c][r] == '.')  continue;
                if(vec[board[c][r]-'0'])   return false;
                vec[board[c][r]-'0'] = true;
            }
        }
        cout<<"passed col; ";
        for(int r=0; r<9;r+=3){
            for(int c=0; c<9; c+=3){
                vec = vector<bool>(10, false);
                for(int i=r; i<r+3;i++)
                    for(int j=c;j<c+3;j++){
                        if(board[i][j] == '.')  continue;
                        if(vec[board[i][j]-'0'])   return false;
                            vec[board[i][j]-'0'] = true;
                    }
            }
        }
        cout<<"passed sub; ";
        return true;
    }
};
