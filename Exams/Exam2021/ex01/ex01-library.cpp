#include <iostream>
#include "ex01-library.h"

using namespace std;

// Task 1(a).  Implement this function
Square **createChessboard(unsigned int n) {
    Square **c = new Square*[n];
    for (unsigned int i = 0; i < n; i++) {
        c[i] = new Square[n];
        for (unsigned int j = 0; j < n; j++){
            c[i][j] = {none, nobody};
        }
    }
    return c;
}

// Task 1(b).  Implement this function
void displayChessboard(Square **c, unsigned int n) {
    for (int i = 0; i < n; i++){
        cout << endl;
        for (int j = 0; j < n; j++){
            if(c[i][j].piece == rook && c[i][j].team == black){
                cout << "R ";
            }
            if(c[i][j].piece == bishop && c[i][j].team == black){
                cout << "B ";
            }
            if(c[i][j].piece == rook && c[i][j].team == white){
                cout << "r ";
            }
            if(c[i][j].piece == bishop && c[i][j].team == white){
                cout << "b ";
            }
            if(c[i][j].piece == none){
                cout << "_ ";
            }
        }
    }
}

// Task 1(c).  Implement this function
bool move(Square **c, unsigned int n, int r1, int c1, int r2, int c2) {
   if(c[r1][c1].piece == none){
        return false;
    }
    if(c[r2][c2].team == c[r1][c1].team){
        return false;
    }
    if(c[r1][c1].piece == rook && (r1 == r2 || c1 == c2)){
        c[r2][c2] = c[r1][c1];
        c[r1][c1] = {none, nobody};
        return true;
    }
    if(c[r1][c1].piece == bishop && (r1 - c1 == r2 - c2 || r1 + c1 == r2 + c2)){
        c[r2][c2] = c[r1][c1];
        c[r1][c1] = {none, nobody};
        return true;
    }
    return false;
}



// Task 1(d).  Implement this function
bool threatened(Square **c, unsigned int n, int row, int col) {
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(c[i][j].team != c[row][col].team && c[i][j].team != nobody){
                if(move(c, n, i, j, row, col)){
                    return true;
                }
            }
        }
    }
    return false;
}

// Do not modify
void deleteChessboard(Square **c, unsigned int n) {
    for (unsigned int i = 0; i < n; i++) {
        delete[] c[i];
    }
    delete[] c;
}
