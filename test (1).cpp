#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
char user_choice;
char winner_flag;
char computers_symbol;

// Function prototypes
void displayGrid();
void initialMenu();
bool makeMove(int row, int col, char symbol);
bool isBoardFull();
bool checkForWin();
void computers_move();

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

bool checkForWin() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == user_choice && board[i][1] == user_choice && board[i][2] == user_choice) {
            winner_flag = '1';
            return true;  // Row win
        }
        if (board[0][i] == user_choice && board[1][i] == user_choice && board[2][i] == user_choice) {
            winner_flag = '1';
            return true;  // Column win
        }
    }

    // Check diagonals
    if (board[0][0] == user_choice && board[1][1] == user_choice && board[2][2] == user_choice) {
        winner_flag = '1';
        return true;  // Diagonal win
    }
    if (board[0][2] == user_choice && board[1][1] == user_choice && board[2][0] == user_choice) {
        winner_flag = '1';
        return true;  // Diagonal win
    }

    // Check for a win for the computer
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == computers_symbol && board[i][1] == computers_symbol && board[i][2] == computers_symbol) {
            winner_flag = '2';
            return true;  // Row win for computer
        }
        if (board[0][i] == computers_symbol && board[1][i] == computers_symbol && board[2][i] == computers_symbol) {
            winner_flag = '2';
            return true;  // Column win for computer
        }
    }

    // Check diagonals for the computer
    if (board[0][0] == computers_symbol && board[1][1] == computers_symbol && board[2][2] == computers_symbol) {
        winner_flag = '2';
        return true;  // Diagonal win for computer
    }
    if (board[0][2] == computers_symbol && board[1][1] == computers_symbol && board[2][0] == computers_symbol) {
        winner_flag = '2';
        return true;  // Diagonal win for computer
    }

    return false;  // No win yet
}

void computers_move() {
    int computers_row;
    int computers_col;
    srand(time(0));

    if (user_choice == 'O')
        computers_symbol = 'X';
    else
        computers_symbol = 'O';

    bool occupied_cell = false;

    while (!occupied_cell && !isBoardFull()) {
        computers_row = rand() % 3;
        computers_col = rand() % 3;
        occupied_cell = makeMove(computers_row, computers_col, computers_symbol);
    }

    cout << "Computer's move: " << endl << endl;
    displayGrid();
    cout << endl << endl;
}

