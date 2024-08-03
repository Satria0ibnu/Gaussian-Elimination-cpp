#include <iostream>
#include <iomanip>
using namespace std;

float matrix[100][100];
float input;
int rows, cols;

void output() {
    cout << endl;
    for (int a = 0; a < rows; a++) {
        for (int b = 0; b < cols; b++) {
            cout << matrix[a][b] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void swapRows(int row1, int row2) {
    for (int i = 0; i < cols; i++) {
        swap(matrix[row1][i], matrix[row2][i]);
    }
}

// Gaussian elimination
void gaussianElimination() {
    for (int i = 0; i < rows; i++) {
        // Partial pivoting
        if (matrix[i][i] == 0) {
            for (int k = i + 1; k < rows; k++) {
                if (matrix[k][i] != 0) {
                    swapRows(i, k);
                    break;
                }
            }
        }

        // make diagonal 1
        float div = matrix[i][i];
        if (div != 0) { // avoid infinity
            for (int j = 0; j < cols; j++) {
                matrix[i][j] /= div;
            }
        }

        // make below column 0
        for (int k = i + 1; k < rows; k++) {
            float factor = matrix[k][i];
            for (int j = 0; j < cols; j++) {
                matrix[k][j] -= factor * matrix[i][j];
            }
        }
    }

    // make above column 0
    for (int i = rows - 1; i >= 0; i--) {
        for (int k = i - 1; k >= 0; k--) {
            float factor = matrix[k][i];
            for (int j = 0; j < cols; j++) {
                matrix[k][j] -= factor * matrix[i][j];
            }
        }
    }
}

int main() {
    cout << setprecision(3) << fixed;

    // USER INPUT
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "input number in cell " << i + 1 << "," << j + 1 << " = ";
            cin >> input;
            matrix[i][j] = input;
        }
    }

    output();
    gaussianElimination();
    output();

    return 0;
}
