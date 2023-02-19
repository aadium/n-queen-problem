<H1> N-queen problem </H1>
The code is an implementation of the famous "Eight Queens Puzzle," a classic problem in computer science and mathematics that requires placing eight queens on an 8x8 chessboard in such a way that no two queens can attack each other. The code is written in C++ and includes the standard library header files iostream, stack, and vector. It also uses the preprocessor macro #define to set the size of the chessboard to 8, and the namespace std is included to simplify code readability.

The code defines a class called bisat, which contains three functions: qsub, qmain, and safety. The qsub function is a recursive function that takes a 2D array (board) representing the chessboard and an integer (col) representing the current column being filled. The function attempts to place a queen in every row of the current column, and recursively calls itself with the next column until all eight queens have been placed. If a solution is found, the function returns true; otherwise, it backtracks and removes the last queen placed on the board.

The qmain function creates an empty chessboard represented as a 2D array of 8x8 elements, and calls the qsub function to solve the puzzle. If a solution is found, the function calls the printboard function to display the solution. If a solution is not found, the function prints an error message and returns false.

The safety function checks whether a queen can be safely placed in a given box on the chessboard, represented by the row and column indices passed as arguments. It does this by checking the row, column, and diagonals for any previously placed queens that would attack the current box. If no queens are found that would attack the current box, the function returns true, indicating that it is safe to place a queen in the current box.

The main function creates an instance of the bisat class and calls its qmain function to solve the Eight Queens Puzzle. If the puzzle is solved, the main function returns 0 to indicate success.
