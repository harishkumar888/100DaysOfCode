/*
36. Valid SUdoku

Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.

A partially filled sudoku which is valid.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

Example 1:

Input:
[
  ["5","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
Output: true
Example 2:

Input:
[
  ["8","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being 
    modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
The given board contain only digits 1-9 and the character '.'.
The given board size is always 9x9.
*/

#include <bitset>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    int m=board.size(), n=board[0].size();
    set<string> contents;
    for(int i=0; i<m; ++i){
        for(int j=0; j<n; ++j){
            if(board[i][j] != '.'){
                string val(1, board[i][j]);
                string row  = val + " in row " + to_string(i);
                string col  = val + " in col " + to_string(j);
                string sbox = val + " in sbox " + to_string(i/3*3+j/3);
                if(contents.find(row) != contents.end())return false;
                if(contents.find(col) != contents.end())return false;
                if(contents.find(sbox) != contents.end())return false;
                contents.insert(row);
                contents.insert(col);
                contents.insert(sbox);
            }
        }
    }
    return true;
}

bool isValidSudoku_alt(vector<vector<char>>& board) {
    
    for(int i = 0; i < 9; i++) {
        
        bitset<9> col;
        bitset<9> row;
        bitset<9> rect;
        
        for(int j = 0; j < 9; j++) {
            
            //check row
            if(board[i][j] != '.' && row[board[i][j]] == true) {
                return false;
            }
            else {
                row[board[i][j]] = true;
            }
            
            //check col
            if(board[j][i] != '.' && col[board[j][i]] == true) {
                return false;
            }
            else {
                col[board[j][i]] = true;
            }
            
            //check 3x3
            int x = (3 * (i % 3)) + (j % 3);
            int y = (3 * (i / 3)) + (j / 3);
            //check rect
            if(board[y][x] != '.' && rect[board[y][x]] == true) {
                return false;
            }
            else {
                rect[board[y][x]] = true;
            }            
        }
    }
    
    return true;
}

int main(){
    vector<vector<char>> board = {{'5','3','.','.','7','.','.','.','.'},
  {'6','.','.','1','9','5','.','.','.'},
  {'.','9','8','.','.','.','.','6','.'},
  {'8','.','.','.','6','.','.','.','3'},
  {'4','.','.','8','.','3','.','.','1'},
  {'7','.','.','.','2','.','.','.','6'},
  {'.','6','.','.','.','.','2','8','.'},
  {'.','.','.','4','1','9','.','.','5'},
  {'.','.','.','.','8','.','.','7','9'}};

    cout << boolalpha << isValidSudoku(board);
    return 0;
}