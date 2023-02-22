<H1> N-queen problem </H1>
The code is an implementation of the famous "Eight Queens Puzzle," a classic problem in computer science and mathematics that requires placing eight queens on an 8x8 chessboard in such a way that no two queens can attack each other. The code is written in C++ and includes the standard library header files iostream, stack, and vector. It also uses the preprocessor macro #define to set the size of the chessboard to 8, and the namespace std is included to simplify code readability.

<H3> Using Arrays (arrayqueen.cpp) </H3>
The code defines a class called bisat, which contains three functions: qsub, qmain, and safety. The qsub function is a recursive function that takes a 2D array (board) representing the chessboard and an integer (col) representing the current column being filled. The function attempts to place a queen in every row of the current column, and recursively calls itself with the next column until all eight queens have been placed. If a solution is found, the function returns true; otherwise, it backtracks and removes the last queen placed on the board.

The qmain function creates an empty chessboard represented as a 2D array of 8x8 elements, and calls the qsub function to solve the puzzle. If a solution is found, the function calls the printboard function to display the solution. If a solution is not found, the function prints an error message and returns false.

The safety function checks whether a queen can be safely placed in a given box on the chessboard, represented by the row and column indices passed as arguments. It does this by checking the row, column, and diagonals for any previously placed queens that would attack the current box. If no queens are found that would attack the current box, the function returns true, indicating that it is safe to place a queen in the current box.

The main function creates an instance of the bisat class and calls its qmain function to solve the Eight Queens Puzzle. If the puzzle is solved, the main function returns 0 to indicate success.

<H3> Using Stacks (stackqueen.cpp) </H3>
The code defines a C++ class called bisat, which contains three public member functions:

bool qsub - This function is a recursive function that uses a stack-based approach to solve the N-Queens problem. It takes four stack arguments representing the current state of the chessboard, the columns that have already been occupied, and the diagonals that have already been occupied. It returns a Boolean value indicating whether a valid solution has been found.

bool qmain - This function sets up the initial state of the chessboard and calls the qsub function to solve the N-Queens problem. If a valid solution is found, it calls the printboard function to print the solution on the console. It returns a Boolean value indicating whether a valid solution was found.

bool safety - This function takes four stack arguments representing the current state of the chessboard and diagonals, and two integer arguments representing the row and column of the queen being placed. It returns a Boolean value indicating whether it is safe to place a queen in the given row and column.

The main function creates an instance of the bisat class and calls its qmain function to solve the N-Queens problem.

The program uses a stack-based approach to simulate the placement of queens on the chessboard. The board stack contains the row numbers of the queens, while the cols, diag1, and diag2 stacks keep track of the occupied columns and diagonals.

The qsub function tries to place a queen in each row of the current column, and recursively solves for the remaining columns if a valid placement is found. If a placement cannot be found, it backtracks and removes the queen from the stack.

The safety function checks whether it is safe to place a queen in a given row and column by comparing the position of the queen with those already placed on the board. It checks if the queen is in the same row, diagonal 1, or diagonal 2 as any of the previously placed queens.

Finally, the printboard function prints the solution on the console using a 2D array arr, where 1 represents a queen and 0 represents an empty cell.
