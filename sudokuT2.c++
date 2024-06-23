#include <iostream>
#include <vector>
using namespace std;

    bool isSafe(int row, int col, vector<vector<char>>& board, char value) {
        int n = board.size();

        for(int i=0; i<n; i++){
            // row check
            if(board[row][i] == value)
                return false;

            // col check
            if(board[i][col] == value)
                return false;

            // 3*3 box check 
            if(board[3*(row/3)+(i/3)][3*(col/3)+(i%3)] == value)
                return false; 
        }
        return true;
    }

    bool solve(vector<vector<char>>& board) {
        int n = board.size();

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                // check for empty cell
                if(board[i][j] == '.') {
                    // try to fill with values from 1 to 9
                    for(char val = '1'; val <= '9'; val++) {
                        // check for safety
                        if(isSafe(i, j, board, val)) {
                            // insert
                            board[i][j] = val;
                            // recursion will handle rest part
                            bool remainingBoardSol = solve(board);
                            if(remainingBoardSol == true) {
                                return true;
                            }
                            // backtrack
                            board[i][j] = '.';
                        }
                    }
                    // if 1 to 9 values didn't solve the solution at current cell
                    // that means mistake somewhere behind, go back
                    return false; 
                }
            }
        }
        // all cells filled
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

int main() {
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    solveSudoku(board);

    for(int i=0; i<board.size(); i++) {
        for(int j=0; j<board[i].size(); j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    } return 0;
}