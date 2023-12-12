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

