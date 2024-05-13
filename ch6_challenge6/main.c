
#include <stdio.h> 
#include <stdint.h>

#define COLS 3 
void vectorProduct(uint16_t A[][COLS], uint16_t x[], uint16_t B[], const size_t rows);
uint16_t determinant(uint16_t A[][COLS]);

int main() { 

    uint16_t A[][COLS] = { {2, 4, 5}, {3, 6, 8}, {8, 1, 3}}; 
    uint16_t x[3] = { 1, 1, 1};   
    uint16_t B[3] = {0}; 
    size_t rows = sizeof(A)/sizeof(A[0]);

    vectorProduct(A, x, B, rows);
    //size_t cols = sizeof(A[0])/sizeof(uint16_t); 

    //printf("A has %zu rows and %zu columns", rows, cols);
    printf("[ "); 
    for ( size_t i = 0; i < COLS; i++) { 
        printf("%d ", B[i]); 
    }
    printf("]\n");

    printf("determinant of A is: %d", determinant(A));
    return 0; 
}

void vectorProduct(uint16_t A[][COLS], uint16_t x[], uint16_t B[], const size_t rows) { 

    for (size_t i = 0; i < rows; i++) { 

        uint16_t element = 0; 
        for ( size_t j = 0; j < COLS; j++)  {

            element += A[i][j]*x[j];
        }
        B[i] = element; 
    }
}

// determinant of 3x3 matrix
uint16_t determinant(uint16_t A[][COLS]) { 

    uint16_t a = A[0][0]; 
    uint16_t b = A[0][1]; 
    uint16_t c = A[0][2]; 
    uint16_t d = A[1][0];
    uint16_t e = A[1][1];
    uint16_t f = A[1][2];
    uint16_t g = A[2][0];
    uint16_t h = A[2][1];
    uint16_t i = A[2][2];

    return a*(e*i - h*f) - b*(d*i - g*f) + c*(d*h - g*e);
} 