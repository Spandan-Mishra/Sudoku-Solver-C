# Sudoku-Solver-C
### About the project:
I made this Sudoku Solver in C. This program uses basic recursion and backtracking algorithms in order to find the solution to the sudoku.

### Working mechanism:
First the user has to input the rows of the sudoku puzzle, 0 wherever there is and empty space (currently data is stored only for 9x9 grid).
This grid is then passed to a function which iterates over every element of the grid, if it finds a cell with value 0, it checks for each value from 1 to max-length which can be placed(currently 9) in the grid. The grid and the value are passed to another function which checks if that particular value can be placed in that cell according to the other values in the row, column and box to which the cell belongs. If the check function returns that the value can be placed in that cell, then that value is placed in that particular cell, and the function is called recursively. 

The same process takes place for every cell of the grid. If at any point, no value can be placed in the cell, the function is returned and all the previously altered cells are set back to 0. On the other hand if we reach the end of the grid with no empty cells, we print the current grid and inside the printer function we set global variable success equal to true(which was initially set to false). 

When we break out of the solve function, if the success variable is still false, we can print that no solution exists for that particular input.

### Features I'd like to add:
- Maybe a web layout for this sudoku.
- Better input form (since the current one is too time taking)
- Ability to change the grid size
