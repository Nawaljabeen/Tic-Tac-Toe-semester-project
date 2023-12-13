MODULES: 4 Global Variables, 6 functions.
Tic tac toe game against computer.

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}}; //outer loop for rows, inner for elements in each row
char user_choice;
char winner_flag;
char computers_symbol;

int main() {
    initialMenu();
    int row, col;

    while (!isBoardFull() && !checkForWin()) {
        cout << "Enter your move (row and column): ";
        cin >> row >> col;
        cout<<endl;

        if (makeMove(row, col, user_choice)) {
            displayGrid();
            cout<<endl;
            computers_move();
            cout<<endl<<endl;
        } 
        else 
            cout << "Invalid move. Try again." << endl; 
    }

    if (checkForWin()) {
        if(winner_flag == '1')
            cout << "Player wins!" << endl;
        else
            cout<<"Computer wins!"<<endl;
    } 

    else {
        cout << "It's a draw! The game is a tie." << endl;
    }


void initialMenu() {
    cout << "Welcome to Tic-Tac-Toe. Press 1 to choose 'O' or press 2 to choose 'X': ";
    cin >> user_choice;

    switch (user_choice) {
        case '1': user_choice = 'O'; break;
        case '2': user_choice = 'X'; break;
    }

    cout << "You get the first choice." << endl;
    cout<<endl;
}

void displayGrid() {
    
    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " | ";
        }
    if (i < 2)
        cout << endl << "-------------" << endl;
    cout<<endl;
    }
}
    return 0;
}
bool makeMove(int row, int col, char symbol) {
    if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
        return false;  // Invalid move
    }

    board[row][col] = symbol;
    return true;
}

bool isBoardFull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;  // Empty space found
            }
        }
    }
    return true;  // No empty space, board is full
}


