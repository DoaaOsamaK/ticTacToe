#include <iostream>
using namespace std;

bool equal(char x, char y, char z) {
    return (x == y && x == z && x != ' ');
}

int checkWinner(char game[3][3]) {
    // 2: X winner
    // -2: O winner
    // 0: Tie
    // -1: No winner

    // Check rows and columns for a winner
    for (int i = 0; i < 3; i++) {
        if (equal(game[i][0], game[i][1], game[i][2])) {
            return game[i][0] == 'X' ? 2 : -2;
        }
        if (equal(game[0][i], game[1][i], game[2][i])) {
            return game[0][i] == 'X' ? 2 : -2;
        }
    }

    // Check diagonals for a winner
    if (equal(game[0][0], game[1][1], game[2][2])) {
        return game[0][0] == 'X' ? 2 : -2;
    }
    if (equal(game[2][0], game[1][1], game[0][2])) {
        return game[2][0] == 'X' ? 2 : -2;
    }

    // Check for a tie
    bool tie = true;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (game[i][j] == ' ') {
                tie = false;
                break;
            }
        }
        if (!tie) break;
    }
    if (tie) return 0;

    // No winners
    return -1;
}

void drawBoard(char game[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "| " << game[i][j] << " |";
        }
        cout << "\n ___________ \n";
    }
}

int main() {
    char game[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    int x, y;
    cout << "Enter the position of the piece you want: ";
    char player = 'X';
    bool hasWinner = false;

    while (!hasWinner) {
        cin >> x >> y;
        if (x >= 0 && x < 3 && y >= 0 && y < 3) {
            if (game[x][y] == ' ') {
                game[x][y] = player;
                player = (player == 'X') ? 'O' : 'X';
                drawBoard(game);
                hasWinner = checkWinner(game) != -1;
            } else {
                cout << "This position is already taken, try again\n";
            }
        } else {
            cout << "Invalid position, try again\n";
        }
    }

    int res = checkWinner(game);
    if (res == 0) {
        cout << "Tie Game\n";
    } else {
        cout << ((res == 2) ? "X the winner" : "O the winner") << "\n";
    }
    return 0;
}
