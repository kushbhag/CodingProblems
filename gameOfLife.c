// Problem: https://leetcode.com/problems/game-of-life/

#include <stdbool.h>

int alive (int** board, int x, int y, int boardY, int boardX){
    int totalAlive = 0;
    bool yLow = false;
    bool yHigh = false;
    bool xLow = false;
    bool xHigh = false;

    if (y - 1 >= 0){
        yLow = true;
    }
    if (y + 1 < boardY){
        yHigh = true;
    }
    if (x - 1 >= 0){
        xLow = true;
    }
    if (x + 1 < boardX){ 
        xHigh = true;
    }
    if (yLow && xLow && board[y-1][x-1] == 1){
        totalAlive ++;
    }
    if (yLow && board[y-1][x] == 1){
        totalAlive ++;
    }
    if (yLow && xHigh && board[y-1][x+1] == 1){
        totalAlive ++;
    }
    if (xLow && board[y][x-1] == 1){
        totalAlive ++;
    }
    if (xHigh && board[y][x+1] == 1){
        totalAlive ++;
    }
    if (yHigh && xLow && board[y+1][x-1] == 1){
        totalAlive ++;
    }
    if (yHigh && board[y+1][x] == 1){
        totalAlive ++;
    }
    if (yHigh && xHigh && board[y+1][x+1] == 1){
        totalAlive ++;
    }
    return totalAlive;
}

void gameOfLife(int** board, int boardSize, int* boardColSize){
    if (boardSize == 0 || *boardColSize == 0){
        return;
    }
    int final [boardSize][*boardColSize];
    for (int y = 0; y < boardSize; y ++){
        for (int x = 0; x < *boardColSize; x ++){
            int surrAlive = alive (board, x, y, boardSize, *boardColSize);
            if (board[y][x] == 1){
                if (surrAlive < 2){
                    final[y][x] = 0;
                } else if (surrAlive < 4){
                    final[y][x] = 1;
                } else{
                    final [y][x] = 0;
                }
            } else if (surrAlive == 3){
                final[y][x] = 1;
            } else{
                final[y][x] = 0;
            }
        }
    }
    for (int y = 0; y < boardSize; y ++){
        for (int x = 0; x < *boardColSize; x ++){
            board[y][x] = final[y][x];
        }
    }
    
}