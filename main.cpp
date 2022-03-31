#include <iostream>
#include "sudoku.h"

using namespace std;


int main()
{
    int board[9][9] = { {0, 3, 0, 1, 8, 0, 0, 0, 9},
         {0, 1, 4, 0, 0, 9, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0, 3},
         {7, 0, 0, 8, 0, 0, 5, 2, 0},
         {0, 0, 0, 0, 1, 0, 0, 0, 0},
         {0, 5, 6, 0, 0, 4, 0, 0, 8},
         {2, 0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 2, 0, 0, 7, 4, 0},
         {4, 0, 0, 0, 9, 1, 0, 6, 0} };

    SudokuSolver sudoku(board);

    if(sudoku.gridSolver()){
        cout << "Solved successfully!" << endl;
    }else{
        cout << "Unsolvable Grid (:" << endl;
    }

    sudoku.printGrid();

    return 0;
}
