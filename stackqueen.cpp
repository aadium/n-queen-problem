#include <iostream>
#include <stack>
#define N 8
using namespace std;

class bisat {
public:
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

    bool safety(stack<int>& board, stack<int>& diag1, stack<int>& diag2, int row, int col) {
        // Check if the queen at (row, col) is in conflict with any of the previous queens on the same row, diagonal1, or diagonal2
        stack<int> temp_diag1 = diag1;
        stack<int> temp_diag2 = diag2;
        stack<int> temp_board = board;

        while (!temp_board.empty()) {
            if (temp_board.top() == row || temp_diag1.top() == col + row || temp_diag2.top() == col - row) {
                return false;
            }
            temp_board.pop();
            temp_diag1.pop();
            temp_diag2.pop();
        }

        return true;
    }

    void printboard(stack<int>& board, stack<int>& cols) {
        int arr[N][N] = {0};
        while (!board.empty()) {
            arr[board.top()][cols.top()] = 1;
            board.pop();
            cols.pop();
        }

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
