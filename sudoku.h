#include <iostream>

using namespace std;

class SudokuSolver{
private:
     int grid[9][9];
     const int grid_size = 9;
    // check if numner exist in Row
    bool isNumberExistInRow(int number, int row){
        for(int column = 0; column < grid_size;column++){
            if(grid[row][column] == number){
                return true;
            }
        }
        return false;
    }
    // check if numner exist in Column
    bool isNumberExistInColumn(int number, int column){
        for(int row = 0; row < grid_size;row++){
            if(grid[row][column] == number){
                return true;
            }
        }
        return false;
    }
    // check if numner exist in Box
    bool isNumberExistInBox(int number,int row, int column){
        int localBoxRow = row - row % 3;
        int localBoxColumn = column - column % 3;
        for(int i = localBoxRow; i < localBoxRow + 3; i++){
            for(int j = localBoxColumn; j < localBoxColumn + 3; j++){
                if(grid[i][j] == number){
                    return true;
                }
            }
        }
        return false;
    }
    // check if the place is valid
    bool isValidPlacement(int number, int row, int column){
        return !isNumberExistInRow(number,row) && !isNumberExistInColumn(number,column) && !isNumberExistInBox(number,row,column);
    }

public:
    SudokuSolver(int board[9][9]){
        for(int i = 0; i < grid_size; i++){
            for(int j = 0; j < grid_size; j++){
                grid[i][j] = board[i][j];
            }
        }
    }

    bool gridSolver(){
        for(int row = 0; row < grid_size; row++){
            for(int column = 0; column < grid_size; column++){
                if(grid[row][column] == 0){
                    for(int numberToTry = 1; numberToTry <= grid_size; numberToTry++){
                        if(isValidPlacement(numberToTry,row,column)){
                            grid[row][column] = numberToTry;
                            if(gridSolver()){
                                return true;
                            }else{
                                grid[row][column] = 0;
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool printGrid(){
        for(int row = 0; row < grid_size; row++){
                if(row % 3 == 0 && row != 0){
                    cout << "---------------" << endl;
                }
            for(int column = 0; column < grid_size; column++){
                if(column % 3 == 0 && column != 0){
                    cout << " | ";
                }
                cout << grid[row][column];
            }
            cout << endl;
        }
    }
};


