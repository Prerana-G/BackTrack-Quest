#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int N,count=0;  // Number of queens and size of the board

bool isSafe(int **board, int row, int col) {
    int i, j;

    // Check the column for other queens
    for (i = 0; i < row; i++)
        if (board[i][col])
            return false;

    // Check the left diagonal for other queens
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check the right diagonal for other queens
    for (i = row, j = col; i >= 0 && j < N; i--, j++)
        if (board[i][j])
            return false;

    return true;
}

bool placeQueens(int **board, int row) {
    if (row >= N) {
        // Printing the board
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                printf(board[i][j] ? "Q " : ". ");
            printf("\n");
        }
        printf("\n");
        count++; // couting the possible solutions
        return true;
    }

    bool res = false;
    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1;  // Place the queen

            // Recursively place the rest of the queens
            res = placeQueens(board, row + 1) || res;        
                   
            board[row][col] = 0;  // Backtrack
            
        
        }
    }
    return res;
}

void solveNQueens() {
    int **board = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++)
        board[i] = (int *)malloc(N * sizeof(int));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = 0;

    if (!placeQueens(board, 0))
        printf("Solution does not exist\n");

    for (int i = 0; i < N; i++)
        free(board[i]);
    free(board);
}

int main() {
    printf("Enter the number of queens: ");
    scanf("%d", &N);
    solveNQueens();
    printf("No. of possible solutions: %d",count);
    return 0;
}
