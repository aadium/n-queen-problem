#include <iostream>
#include <stack>
#define N 8
using namespace std;

class bisat {
public:

    // A helper recursive function that is used to solve the problem
    bool qsub(stack<int>& board, stack<int>& cols, stack<int>& diag1, stack<int>& diag2) {
        if (cols.size() >= N)
            return true;

        // Try placing the queen in all rows of the column
        for (int i = 0; i < N; i++) {

            // Check if the queen can be placed in the given box marked by board.size() and i
            if (safety(board, diag1, diag2, i, board.size())) {

                // Place this queen in the box
                board.push(i);
                cols.push(board.size()-1);
                diag1.push(i + board.size()-1);
                diag2.push(board.size()-1 - i);

                // Recursive function solves for all rows
                if (qsub(board, cols, diag1, diag2)) {
                    return true;
                }

                // If placing queen in board.top() and cols.size() doesn't lead to a solution, then remove queen from the box, aka backtrack and 
                board.pop();
                cols.pop();
                diag1.pop();
                diag2.pop();
            }
        }

        // If the queen cannot be placed in any row in col then return false
        return false;
    }

    // The main function that sets up the initial chessboard grid and calls out the qsub function. Also calls the printboard function.
    bool qmain() {
        stack<int> board;
        stack<int> cols;
        stack<int> diag1;
        stack<int> diag2;

        if (qsub(board, cols, diag1, diag2) == false) {
            cout << "Solution does not exist";
            return false;
        }

        printboard(board, cols);
        return true;
    }

    // A helper function to check if it is safe to place the queen
    bool safety(stack<int>& board, stack<int>& diag1, stack<int>& diag2, int row, int col) {

        // We create 3 stacks for the temporary storage of values. This is because the main stacks cannot be directly used.
        stack<int> temp_diag1 = diag1;
        stack<int> temp_diag2 = diag2;
        stack<int> temp_board = board;

        while (!temp_board.empty()) {
            if (temp_board.top() == row || temp_diag1.top() == col + row || temp_diag2.top() == col - row) {
                return false; // False is returned if the queen is directly in line of sight of another queen
            }
            temp_board.pop();
            temp_diag1.pop();
            temp_diag2.pop();
        }

        return true; // True is returned if the queen can be placed
    }

    // A helper function to print the chessboard grid
    void printboard(stack<int>& board, stack<int>& cols) {
        int arr[N][N] = {0}; // this array stores the specific locations of the queens on the chessboard grid
        while (!board.empty()) {
            arr[board.top()][cols.top()] = 1; // a specific location of the array grid gets populated if the board stack is not empty
            // the board and cols stacks are emptied as the loop iterates
            board.pop();
            cols.pop();
        }

        //the grid is printed out
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (arr[i][j]) {
                    cout << "Q ";
                }
                else {
                    cout << ". ";
                }

            }
            cout << endl;

        }

    }

};

int main(int argc, char const* argv[]) {
    bisat chessboard;

    chessboard.qmain();

    return 0;
}
