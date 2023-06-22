#include <bits/stdc++.h>

using namespace std;

bool isSafe(vector<vector<char>>& board,int i,int j,char c){
    // check row
    for(int k = 0 ;k < 9;k++){
        if(board[i][k] == c){
            return false;
        }
    }

    //checking col
    for(int k = 0;k < 9;k++){
        if(board[k][j] == c){
            return false;
        }
    }

    //checking the submatrix
    int row1 = 0, row2 =  0,col1 = 0,col2 = 0;
    if(i >= 0 && i <= 2){
        row1 = 0;
        row2 = 2;
    }
    if(i >= 3 && i <= 5){
        row1 = 3;
        row2 = 5;
    }
    if(i >= 6 && i <= 8){
        row1 = 6;
        row2 = 8;
    }
    if(j >= 0 && j <= 2){
        col1 = 0;
        col2 = 2;
    }
    if(j >= 3 && j <= 5){
        col1 = 3;
        col2 = 5;
    }
    if(j >= 6 && j <= 8){
        col1 = 6;
        col2 = 8;
    }
    for(int l = row1 ; l <= row2 ;l++){
        for(int m = col1; m <= col2 ; m++){
            if(board[l][m] == c){
                return false;
            }
        }
    }
    return true;
}
bool solve(vector<vector<char>>& board){
    for(int i = 0; i < 9;i++){
        for(int j = 0; j < 9;j++){
            if(board[i][j] == '.'){
                for (char c = '1'; c <= '9'; c++) {
                    if (isSafe(board, i, j, c)){
                        board[i][j] = c;
                        bool GoingRight = solve(board);
                        if(GoingRight){
                            return true;
                        }
                        else{
                            board[i][j] = '.';
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}
void solveSudoku(vector<vector<char>>& board) {
    solve(board);
}

void print(vector<vector<char>> sudoku){
    for(int i = 0;i < 9;i++){
        for(int j = 0; j < 9;j++){
            if(sudoku[i][j] == '.'){
                cout<<'0'<<" ";
            }
            else cout<< sudoku[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    vector<vector<char>> sudoku = {{'8','.','.','.','.','.','.','.','.'},{'.','.','3','6','.','.','.','.','.'},{'.','7','.','.','9','.','2','.','.'},{'.','5','.','.','.','7','.','.','.'},{'.','.','.','.','4','5','7','.','.'},{'.','.','.','1','.','.','.','3','.'},{'.','.','1','.','.','.','.','6','8'},{'.','.','8','5','.','.','.','1','.'},{'.','9','.','.','.','.','4','.','.'}};
    solveSudoku(sudoku);
    print(sudoku);
    return 0;
}
