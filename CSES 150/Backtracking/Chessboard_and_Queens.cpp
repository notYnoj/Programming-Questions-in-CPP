#include <bits/stdc++.h>
 
using namespace std;
 
vector<vector<char>> board(8, vector<char>(8, '.'));
//check if safe
bool is_safe(int row, int col) {
    for (int i = 0; i < 8; ++i) {
      //rows and cols
        if (board[i][col] == 'Q' || board[row][i] == 'Q') {
            return false;
        }
      //diagonals
        for (int j = 0; j < 8; ++j) {
            if ((i + j == row + col || i - j == row - col) && board[i][j] == 'Q') {
                return false;
            }
        }
    }
    return true;
}
 
int count_queen_placements(int row) {
    if (row == 8) {
        return 1;
    }
 
    int count = 0;
    for (int col = 0; col < 8; ++col) {
        if (board[row][col] == '.' && is_safe(row, col)) {
            board[row][col] = 'Q';
            count += count_queen_placements(row + 1);
            board[row][col] = '.';  // Backtrack
        }
    }
 
    return count;
}
 
int main() {
    // Read the input board
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            cin >> board[i][j];
        }
    }
 
    // Start with the first row (row 0)
    int total_ways = count_queen_placements(0);
    cout << total_ways << endl;
 
    return 0;
}
