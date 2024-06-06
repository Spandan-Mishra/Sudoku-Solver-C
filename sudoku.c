//including headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <windows.h>

#include "sudoku.h"

int grid[length][length];
bool success = false;
bool *successfull = &success;
// sudoku grid for checking
// 5 3 0 0 7 0 0 0 0
// 6 0 0 1 9 5 0 0 0
// 0 9 8 0 0 0 0 6 0
// 8 0 0 0 6 0 0 0 3
// 4 0 0 8 0 3 0 0 1
// 7 0 0 0 2 0 0 0 6
// 0 6 0 0 0 0 2 8 0
// 0 0 0 4 1 9 0 0 5
// 0 0 0 0 8 0 0 0 9


int main(void) {
    //beginning the game
    printf("\n\tWelcome to the Sudoku Solver!\n\n");
    system("pause");
    printf("Enter the numbers in the grid row-wise (enter '0' for empty space) for a %dX%d grid\n\n", length, length);


    //taking inputs
    for(int i=0; i<length; i++) {
        int counter=0;
        printf("Enter values for row-%d: ", i+1);
        for(int j=0; j<length; j++) {
            scanf("%d", &grid[i][j]);
            counter++;
            if(grid[i][j] < 0 || grid[i][j] > length) {
                printf("Enter a value between 0 and %d", length);
                return 0;
            }
        }
        if(counter != length) {
            printf("Enter %d values for each row", length);
            return 0;
        }
    }
    printf("\n");
    //calling the solver function
    solve();
    if(*successfull == false) 
        printf("No solution exists for the given sudoku\n\n");
    else 
        printf("\n");
    

}

bool checker(int x, int y, int n) {
     for(int i=0; i<length; i++) {
        if(grid[i][y] == n) {
            return false;
        }
     }
     for(int j=0; j<length; j++) {
        if(grid[x][j] == n) {
            return false;
        }
     }

     int x_corner = floor(x/3) * 3;
     int y_corner = floor(y/3) * 3;

     for(int i=0; i<length/3; i++) {
        for(int j=0; j<length/3; j++) {
            if(grid[x_corner+i][y_corner+j] == n) {
                return false;
            }
        }
     }

     return true;
}

void solve() {
    for(int i=0; i<length; i++) {
        for(int j=0; j<length; j++) {
            if(grid[i][j] == 0) {
                for(int n = 1; n<10; n++) {
                    if(checker(i, j, n)) {
                        grid[i][j] = n;
                        solve();
                        grid[i][j] = 0;
                    }
                }
                return ;
            }
        }
    }
    //printing the solved sudoku
    printer();
    return ;
}

void printer() {
    for(int i=0; i<length; i++) {
        if(i%3 == 0 && i!= 0) {
            printf("------------------------\n");
        }
        for(int j=0; j<length; j++) {
            if(j%3 == 0 && j!= 0) {
                printf("| ");
            }
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    *successfull = true;
} 
