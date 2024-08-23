#include <iostream>
using namespace std;

char board[3][3] = { {'1', '2', '3'},
                     {'4', '5', '6'},
                     {'7', '8', '9'} };

char currentMarker;
int currentPlayer;

void drawBoard() {
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " \n";
    cout << "---|---|---\n";
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " \n";
    cout << "---|---|---\n";
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " \n";
}

bool placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentMarker;
        return true;
    } else {
        return false;
    }
}

bool checkWin() {
    // Rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return true;
        }
    }
    // Columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return true;
        }
    }
    // Diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return true;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return true;
    }

    return false;
}

void swapPlayer() {
    if (currentMarker == 'X') {
        currentMarker = 'O';
    } else {
        currentMarker = 'X';
    }

    if (currentPlayer == 1) {
        currentPlayer = 2;
    } else {
        currentPlayer = 1;
    }
}

int main() {
    currentMarker = 'X';
    currentPlayer = 1;

    drawBoard();

    for (int i = 0; i < 9; i++) {
        cout << "Player " << currentPlayer << ", enter your slot: ";
        int slot;
        cin >> slot;

        if (slot < 1 || slot > 9) {
            cout << "Invalid slot! Please choose a slot between 1 and 9.\n";
            i--;
            continue;
        }

        if (!placeMarker(slot)) {
            cout << "Slot already occupied! Try again.\n";
            i--;
            continue;
        }

        drawBoard();

        if (checkWin()) {
            cout << "Player " << currentPlayer << " wins!\n";
            return 0;
        }

        swapPlayer();
    }

    cout << "It's a draw!\n";
    return 0;
}
