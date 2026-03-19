#include <iostream>
#include "Matrix.h"
#include <stdexcept>

using namespace std;


void printDynArray(const DynArray& arr, const string& title) {
    cout << "--- " << title << " (Size: " << arr.getSize() << ") ---" << endl;
    for (size_t i = 0; i < arr.getSize(); ++i) {
        cout << arr[i] << " ";
    }
    cout << "\n\n";
}

void printMatrix(const Matrix& mat, const string& title) {
    cout << "--- " << title << " (" << mat.getRows() << "x" << mat.getCols() << ") ---" << endl;
    for (size_t i = 0; i < mat.getRows(); ++i) {
        for (size_t j = 0; j < mat.getCols(); ++j) {
            cout << mat[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    try {
        DynArray arr1;
        arr1.set(5);
        for (size_t i = 0; i < arr1.getSize(); ++i) {
            arr1[i] = (i + 1) * 10;
        }
        printDynArray(arr1, "Original arr1");


        DynArray arr2 = arr1;


        DynArray arr3;
        arr3 = arr1;


        arr1[0] = 999;
        cout << "-> Changed arr1[0] to 999 to test deep copy.\n\n";

        printDynArray(arr1, "arr1 (Modified)");
        printDynArray(arr2, "arr2 (Copy Constructor - should NOT have 999)");
        printDynArray(arr3, "arr3 (Assignment - should NOT have 999)");


        cout << "-> Resizing arr2 to 3 (Shrinking)...\n";
        arr2.resize(3);
        printDynArray(arr2, "arr2 after resize(3)");


        cout << "-> Resizing arr3 to 8 \n";
        arr3.resize(8);
        printDynArray(arr3, "arr3 after resize(8)");

        Matrix A(2, 3);
        Matrix B(2, 3);

        int counter = 1;
        for (size_t i = 0; i < A.getRows(); ++i) {
            for (size_t j = 0; j < A.getCols(); ++j) {
                A[i][j] = counter++;
                B[i][j] = 10;
            }
        }

        printMatrix(A, "Matrix A");
        printMatrix(B, "Matrix B");


        Matrix C = A + B;
        printMatrix(C, "Addition: A + B");

        Matrix D = B - A;
        printMatrix(D, "Subtraction: B - A");


        Matrix E = A * 5;
        printMatrix(E, "Scalar Multiplication: A * 5");


        Matrix F(3, 2);
        for (size_t i = 0; i < F.getRows(); ++i) {
            for (size_t j = 0; j < F.getCols(); ++j) {
                F[i][j] = i + j + 1;
            }
        }
        printMatrix(F, "Multiplication");

        Matrix G = A * F;
        printMatrix(G, "Multiplication: A * F");


        cout << "Resizing:" << endl;
        A.resize(4, 4);
        printMatrix(A, "Matrix A after resize(4, 4)");

        cout << "Resizing Matrix A to 1x2" << endl;
        A.resize(1, 2);
        printMatrix(A, "Matrix A after resize(1, 2)");

        A.at(5, 5) = 100;

    } catch (const exception& e) {
        cerr << e.what() << endl;
    }


}