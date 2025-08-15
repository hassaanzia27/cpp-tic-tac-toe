#include <iostream>
using namespace std;

class TicTacToe {
private:
    char board[3][3];
    char currentPlayer;

public:
    TicTacToe() {
        char start = '1';
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = start;						/*[0][0] [0][1] [0][2]    1  2  3
															[1][0] [1][1] [1][2]      4  5  6
															[2][0] [2][1] [2][2]      7  8  9
															*/
                start++;						
            }
        }
        currentPlayer = 'X';
    }

    void displayBoard() {
        cout << "\n";
        for (int i = 0; i < 3; i++) {
            cout << " ";
            for (int j = 0; j < 3; j++) {
                cout << board[i][j];
                if (j < 2) cout << " | ";
            }
            if (i < 2) cout << "\n-----------\n";
        }
        cout << "\n\n";
    }

    void makeMove() {
        int move;
        cout << "Player " << currentPlayer << ", enter a number (1-9): ";
        cin >> move;

        while (move < 1 || move > 9) {
            cout << "Invalid input! Enter a number from 1 to 9: ";
            cin >> move;
        }

        int row = (move - 1) / 3;
        int col = (move - 1) % 3;

        if (board[row][col] == 'X' || board[row][col] == 'O') {
            cout << "Cell already taken! Try again.\n";
            makeMove();
        } else {
            board[row][col] = currentPlayer;
        }
    }

    void switchPlayer() {
        if (currentPlayer == 'X') {
            currentPlayer = 'O';
        } else {
            currentPlayer = 'X';
        }
    }

    int checkWin() {
        // Check rows
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
                return 1;
        }

        // Check columns
        for (int i = 0; i < 3; i++) {
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
                return 1;
        }

        // Check diagonals
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
            return 1;
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
            return 1;

        // Check for draw
        int filledCells = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == 'X' || board[i][j] == 'O')
                    filledCells++;
            }
        }

        if (filledCells == 9)
            return -1; // Draw

        return 0; // Game continues
    }

    void playGame() {
        int result = 0;
        while (result == 0) {
            displayBoard();
            makeMove();
            result = checkWin();
            if (result == 0) switchPlayer();
        }

        displayBoard();
        if (result == 1)
            cout << "Player " << currentPlayer << " wins the game!\n";
        else
            cout << "It's a draw!\n";
    }
};

int main() {
    TicTacToe game;
    game.playGame();
    return 0;
}

