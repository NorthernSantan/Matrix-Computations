#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_ROWS 1
#define MAX_ROWS 4
#define MIN_COLS 1
#define MAX_COLS 4
#define MIN_ENTRY 0
#define MAX_ENTRY 9

typedef struct {
    int mat [MAX_ROWS + 1] [MAX_COLS + 1];
    // ignoring row 0 and col 0 in 2D matrix
    int rows;
    int cols;
} matrixType;


void computeProducts(matrixType *A, matrixType *B, matrixType *prod);

int randBetween (int minNum, int maxNum){
    return rand () % (maxNum - minNum + 1) + minNum;
}

/*
 *
 * Printing function
 *
 * Use of nested loops with time complexity O(mn) for printing
 *
 */

void outputMatrix (matrixType *A){

    for (int i = 1; i <= (A->rows); i++) { // Nested loop printing all rows including last (based on program params include last)
        for (int j = 1; j <= (A->cols); ++j) { // Inner nested loop printing all cols including last (based on program params include last)
            printf("%4i", A->mat[i][j]); // Right spaced by 4
        }
        printf("\n"); // Print newline after each column
    }

}

int main(){
    matrixType A, B, prodAB, prodBA, sumAB;

    // randomly create matrices A and B using the given specs
    A.rows = 3;
    A.cols = 2;
    A.mat[1][1] = 3;
    A.mat[1][2] = -2;
    A.mat[2][1] = 5;
    A.mat[2][2] = 1;
    A.mat[3][1] = 0;
    A.mat[3][2] = 4;

    B.rows = 2;
    B.cols = 3;
    B.mat[1][1] = 3;
    B.mat[1][2] = -2;
    B.mat[1][3] = 3;
    B.mat[2][1] = 5;
    B.mat[2][2] = 1;
    B.mat[2][3] = 0;

    // lets output this hard-coded matrix
    printf ("Printing matrix A\n");
    outputMatrix (&A);
    printf ("Printing matrix B\n");
    outputMatrix (&B);

    // compute the products A * B if possible
    computeProducts(&A, &B, &prodAB);

    // compute the product B * A if possible
    computeProducts(&B, &A, &prodBA);

    printf ("Printing compute matrix AB\n");
    outputMatrix (&prodAB);

    printf ("Printing compute matrix BA\n");
    outputMatrix (&prodBA);

    // computer the sum
    srand((unsigned)time(NULL));   // seed the random number generator

}

/*
 *
 * Compute products function
 *
 * Use of three nested loops with time complexity O(mn^2)
 *
 */

void computeProducts(matrixType *A, matrixType *B, matrixType *prod) {

    if (A->cols != B->rows) {
        printf ("Invalid matrices\n");
        return;
    }

    prod->rows = A->rows;
    prod->cols = B->cols;

//     This code is a complicated logic puzzle, but easy if you think about it deeply
//     To simplify, here are some base cases to see what is going on
//
//     prod [1][1] = A[1][1] * B[1][1] + A[1][2] * B[2][1] + A[1][3] * B[3][1]
//     prod [1][2] = A[1][1] * B[1][2] + A[1][2] * B[2][2] + A[1][3] * B[3][2]
//
//     prod [2][1] = A[2][1] * B[1][1] + A[2][2] * B[2][1] + A[2][3] * B[3][1]
//     prod [2][2] = A[2][1] * B[1][2] + A[2][2] * B[2][2] + A[2][3] * B[3][2]

    int sum;

    // outer loop for rows of product
    for (int prodR = 1; prodR <= prod->rows; prodR++) {

        // loop for columns of product
        for (int prodC = 1; prodC <= prod->cols; prodC++) {

            // initiate sum to zero to avoid previous values
            sum = 0;

            // loop for elements in product
            for (int elemC = 1; elemC <= A->cols; elemC++)
                sum += A->mat[prodR][elemC] * B->mat[elemC][prodC];

            // printf ("Product matrix at prod->mat[%i][%i] = %i\n", prodR, prodC, sum);
            prod->mat[prodR][prodC] = sum;

        }

    }

}
