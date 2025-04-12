// You are given a chessboard of size N×N. Your task is to write a program that uses backtracking to place N queens the chessboard such that no two queens can attack each other. The program should find all possible solutions and print the board configurations for each solution.

#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col) {
    int n = board.size();

    // check whole row
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) return false;
    }

    // upper-left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) return false;
    }

    // upper-right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1) return false;
    }

    return true;
}


void NQueenProblem (vector<vector<int>>& CurrentChessBoard, int index, vector<vector<vector<int>>>& AllChessBoard) {

    int n = CurrentChessBoard.size();
    if (index == n) {
        AllChessBoard.push_back(CurrentChessBoard);
        return;
    }

    for(int i = 0; i < n; i++) {
        if (isSafe(CurrentChessBoard, index, i)) {
            CurrentChessBoard[index][i] = 1;
            NQueenProblem(CurrentChessBoard, index + 1, AllChessBoard);
            CurrentChessBoard[index][i] = 0;
        }
    }
}



int main() {
    int n = 8;
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<vector<int>>> AllChessBoards;
    NQueenProblem(board, 0, AllChessBoards);

    for (int i = 0; i < AllChessBoards.size(); i++) {
        for (int j = 0; j < n; j ++) {
            for (int k = 0; k < n; k++) {
                cout << AllChessBoards[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl << "Chess Board : " << i + 1 << endl;
    }
}