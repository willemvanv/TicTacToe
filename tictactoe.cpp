#include <iostream>
#include <cstring>
using namespace std;

//Willem van Veldhuisen
//9/22/20

//Declaring functions
void updateGrid(char x[][4]);
void turn(int *prow, int *pcolumn);
void checkWin(int *win, char grids[][4]);

//Main
int main() {
  //Variables
  char grid[4][4] = {{' ','1','2','3'}, {'a',' ',' ',' '}, {'b',' ',' ',' '}, {'c',' ',' ',' '}};
  bool running = true;
  int move = 0;
  int xWins = 0;
  int oWins = 0;
  
  int row;
  int column;
  
  //Running the game
  while (running == true) {
    updateGrid(grid);
    int wins = 0;
    turn(&row, &column);
    //Paste the players move to the board
    if (grid[row][column] == ' ') {
	if (move == 0) {
	  grid[row][column] = 'X';
        }
	if (move == 1) {
	  grid[row][column] = 'O';
        }
	if (move == 0) {
	  move = 1;
	}
	else {
	  move = 0;
	}
    }
    checkWin(&wins, grid);
    //Count points for win or tie
    if (wins != 0) {
      if (wins == 1) {
	xWins++;
	cout << "X Win!" << endl;
      }
      if (wins == 2) {
	oWins++;
	cout << "O Win!" << endl;
      }
      if (wins == 3) {
	cout << "Tie!" << endl;
      }
      cout << "X Wins: " << xWins << "  O Wins: " << oWins << endl;
      grid[1][1] = ' '; grid[1][2] = ' '; grid[1][3] = ' '; grid[2][1] = ' ';
      grid[2][2] = ' '; grid[2][3] = ' '; grid[3][1] = ' '; grid[3][2] = ' ';grid[3][3] = ' ';  
    }
  }
  
  return 0;
}
//Check for win or tie
void checkWin(int *win, char grids[][4]) {
  if (grids[1][1] == 'X' && grids[2][1] == 'X' && grids[3][1] == 'X') {
    *win = 1;
  }
  else if (grids[1][2] == 'X' && grids[2][2] == 'X' && grids[3][2] == 'X') {
    *win = 1;
  }
  else if (grids[1][3] == 'X' && grids[2][3] == 'X' && grids[3][3] == 'X') {
    *win = 1;
  }
  else if (grids[1][1] == 'X' && grids[1][2] == 'X' && grids[1][3] == 'X') {
    *win = 1;
  }
  else if (grids[2][1] == 'X' && grids[2][2] == 'X' && grids[2][3] == 'X') {
    *win = 1;
  }
  else if (grids[3][1] == 'X' && grids[3][2] == 'X' && grids[3][3] == 'X') {
    *win = 1;
  }
  else if (grids[1][1] == 'X' && grids[2][2] == 'X' && grids[3][3] == 'X') {
    *win = 1;
  }
  else if (grids[1][3] == 'X' && grids[2][2] == 'X' && grids[3][1] == 'X') {
    *win = 1;
  }
  else if (grids[1][1] == 'O' && grids[2][1] == 'O' && grids[3][1] == 'O') {
    *win = 2;
  }
  else if (grids[1][2] == 'O' && grids[2][2] == 'O' && grids[3][2] == 'O') {
    *win = 2;
  }
  else if (grids[1][3] == 'O' && grids[2][3] == 'O' && grids[3][3] == 'O') {
    *win = 2;
  }
  else if (grids[1][1] == 'O' && grids[1][2] == 'O' && grids[1][3] == 'O') {
    *win = 2;
  }
  else if (grids[2][1] == 'O' && grids[2][2] == 'O' && grids[2][3] == 'O') {
    *win = 2;
  }
  else if (grids[3][1] == 'O' && grids[3][2] == 'O' && grids[3][3] == 'O') {
    *win = 2;
  }
  else if (grids[1][1] == 'O' && grids[2][2] == 'O' && grids[3][3] == 'O') {
    *win = 2;
  }
  else if (grids[1][3] == 'O' && grids[2][2] == 'O' && grids[3][1] == 'O') {
    *win = 2;
  }
  else if (grids[1][1] != ' ' && grids[2][1] != ' ' && grids[3][1] != ' ' &&
	   grids[1][2] != ' ' && grids[2][2] != ' ' && grids[3][2] != ' ' &&
	   grids[1][3] != ' ' && grids[2][3] != ' ' && grids[3][3] != ' ') {
    *win = 3;
  }
}
//Get player input
void turn(int *prow, int *pcolumn) {
  char input[4] = {' ',' ',' '};
  int coor[2];
  cin.getline (input, 4);
  if (input[0] == 'a') {
    coor[0] = 1;
  }
  if (input[0] == 'b') {
    coor[0] = 2;
  }
  if (input[0] == 'c') {
    coor[0] = 3;
  }
  if (input[2] == '1') {
    coor[1] = 1;
  }
  if (input[2] == '2') {
    coor[1] = 2;
  }
  if (input[2] == '3') {
    coor[1] = 3;
  }
  *prow = coor[0];
  *pcolumn = coor[1];
  }
//Print out board
void updateGrid(char x[][4]) {
  for (int i = 0; i < 4; i++) {
    for (int a = 0; a < 4; a++) {
      cout << x[i][a] << ' ';
      
    }
    cout << endl;
  }
  return;
}
