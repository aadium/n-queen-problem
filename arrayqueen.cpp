#include <iostream>
#include <stack>
#include <vector>
#define N 8
using namespace std;

class bisat
{
    public:
    bool qsub(int board[N][N], int col)
    {
        if (col >= N)
            return true;
    
    // Try placing the queen in all rows of the column
        for (int i = 0; i < N; i++) {

    // Check if the queen can be placed in the given box marked by board[i][col]
            if (safety(board, i, col)) {

    // Place this queen in the box
                board[i][col] = 1;
    
    // Recursive function solves for all rows
                if (qsub(board, col + 1))
                    return true;
    
    // If placing queen in board[i][col] doesn't lead to a solution, then remove queen from the box, aka backtrack
                board[i][col] = 0;
            }
        }
    
    // If the queen cannot be placed in any row in col then return false
        return false;
    }

    bool qmain()
    {
        int board[N][N] = { { 0, 0, 0, 0, 0, 0, 0, 0 },
                            { 0, 0, 0, 0, 0, 0, 0, 0 },
                            { 0, 0, 0, 0, 0, 0, 0, 0 },
                            { 0, 0, 0, 0, 0, 0, 0, 0 },
                            { 0, 0, 0, 0, 0, 0, 0, 0 },
                            { 0, 0, 0, 0, 0, 0, 0, 0 },
                            { 0, 0, 0, 0, 0, 0, 0, 0 },
                            { 0, 0, 0, 0, 0, 0, 0, 0 } }; // the grid is defined
    
        if (qsub(board, 0) == false) {
            cout << "Solution does not exist";
            return false;
        }
    
        printboard(board);
        return true;
    }

    bool safety(int grid[N][N], int row, int col)
    {
        int i;
        int j;

        /* Check this row on left side */
        for (i = 0; i < col; i++)
            if (grid[row][i])
            {
                return false;
            }

        /* Check upper diagonal on left side */
        for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
            if (grid[i][j])
            {
                return false;
            }

        /* Check lower diagonal on left side */
        for (i = row, j = col; j >= 0 && i < N; i++, j--)
            if (grid[i][j])
            {
                return false;
            }

        return true;
    }

    void printboard(int grid[N][N])
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (grid[i][j])
                {
                    cout << "Q ";
                }
                else
                {
                    cout << ". ";
                }
                
            }
            cout << endl;
            
        }
        
    }

};

int main(int argc, char const *argv[])
{
    bisat chessboard;

    chessboard.qmain();
    
    return 0;
}
