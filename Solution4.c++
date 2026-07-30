#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void readMatrix(int mat[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> mat[i][j];
        }
    }
}

void printMatrix(int mat[10][10], int rows, int cols, const string& label) {
    cout << label << ":" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << mat[i][j];
        }
        cout << endl;
    }
}

void transposeMatrix(int mat[10][10], int rows, int cols, int result[10][10]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = mat[i][j];
        }
    }
}

void addMatrices(int matA[10][10], int matB[10][10], int rows, int cols, int result[10][10]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matA[i][j] + matB[i][j];
        }
    }
}

void multiplyMatrices(int matA[10][10], int matB[10][10], int m, int n, int p, int result[10][10]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n; k++) {
                result[i][j] += matA[i][k] * matB[k][j];
            }
        }
    }
}

int main() {
    int matA[10][10], matB[10][10], result[10][10];

    // ---------------- PART A: Transpose ----------------
    cout << "--- Part A: Transpose ---" << endl;
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    readMatrix(matA, rows, cols);
    printMatrix(matA, rows, cols, "Original Matrix");

    transposeMatrix(matA, rows, cols, result);
    printMatrix(result, cols, rows, "Transposed Matrix");

    // ---------------- PART B: Addition ----------------
    cout << endl << "--- Part B: Addition ---" << endl;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    cout << "Enter first matrix:" << endl;
    readMatrix(matA, rows, cols);
    cout << "Enter second matrix:" << endl;
    readMatrix(matB, rows, cols);

    addMatrices(matA, matB, rows, cols, result);
    printMatrix(result, rows, cols, "Sum Matrix");

    // ---------------- PART C: Multiplication ----------------
    cout << endl << "--- Part C: Multiplication ---" << endl;
    int m, n, p;
    cout << "Enter rows of Matrix A (M): ";
    cin >> m;
    cout << "Enter columns of Matrix A / rows of Matrix B (N): ";
    cin >> n;
    cout << "Enter columns of Matrix B (P): ";
    cin >> p;

    cout << "Enter Matrix A:" << endl;
    readMatrix(matA, m, n);
    cout << "Enter Matrix B:" << endl;
    readMatrix(matB, n, p);

    multiplyMatrices(matA, matB, m, n, p, result);
    printMatrix(result, m, p, "Product Matrix (A x B)");

    return 0;
}
