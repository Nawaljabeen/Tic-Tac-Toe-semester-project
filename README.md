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

    return 0;
}



