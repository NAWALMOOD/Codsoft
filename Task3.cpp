//3rd task of Codsoft internship
//tic-tac-toe Game

//Build a simple console-based Tic-Tac-Toe game that
//allows two players to play against each other

#include <iostream>
#include <vector>

using namespace std;

const int board_size = 3;

// 2-D vector
vector<vector<char>> board(board_size, vector<char>(board_size, ' '));
char currentPlayer = 'X';

void displayBoard() {
    cout << "-------------" << endl;
    for (int i = 0; i < board_size; ++i) {
        cout << "| ";
        for (int j = 0; j < board_size; ++j) {
            cout << board[i][j] << " | ";
        }
        cout << endl << "-------------" << endl;
    }
}

bool makeMove(int row, int col) {
    if (row < 0 || row >= board_size || col < 0 || col >= board_size || board[row][col] != ' ') {
        return false;
    }

    board[row][col] = currentPlayer;
    return true;
}

bool checkWin() {
    for (int i = 0; i < board_size; ++i) {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) {
            return true; // Check rows
        }
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer) {
            return true; // Check columns
        }
    }
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) {
        return true; // Check main diagonal
    }
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) {
        return true; // Check secondary diagonal
    }
    return false;
}

bool checkDraw() {
    for (int i = 0; i < board_size; ++i) {
        for (int j = 0; j < board_size; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    cout << "TIC-TAC-TOE GAME" << endl;
    displayBoard();

    int row, col;
    while (true) {
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        if (row < 0 || row >= board_size || col < 0 || col >= board_size) {
            cout << "Invalid move. Row and column must be between 0 and " << board_size - 1 << ". Try again." << endl;
        } else if (makeMove(row, col)) {
            displayBoard();

            if (checkWin()) {
                cout << "Player " << currentPlayer << " wins!" << endl;
                break;
            } else  if (checkDraw()) 
            {
                cout << "It's a draw!" << endl;
                break;
            }

            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
            cout << "Invalid move. That cell is already occupied. Try again." << endl;
        }
    }

    return 0;
}
