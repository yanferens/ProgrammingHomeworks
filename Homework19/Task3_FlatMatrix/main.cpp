#include <iostream>
#include "FlatMatrix.h"
#include <stdexcept>

using namespace std;

void printFlatMatrix(const FlatMatrix& mat, const string& title) {
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
        FlatMatrix mat1(2, 3);
        FlatMatrix mat2(2, 3);

        mat1[0][0] = 1; mat1[0][1] = 2; mat1[0][2] = 3;
        mat1[1][0] = 4; mat1[1][1] = 5; mat1[1][2] = 6;

        for (size_t i = 0; i < mat2.getRows(); ++i) {
            for (size_t j = 0; j < mat2.getCols(); ++j) {
                mat2[i][j] = 5; // Fill with 5s
            }
        }

        printFlatMatrix(mat1, "FlatMatrix 1");
        printFlatMatrix(mat2, "FlatMatrix 2");


        FlatMatrix matAdd = mat1 + mat2;
        printFlatMatrix(matAdd, "Addition: mat1 + mat2");

        FlatMatrix matSub = mat1 - mat2;
        printFlatMatrix(matSub, "Subtraction: mat1 - mat2");


        FlatMatrix matScalar = mat1 * 10;
        printFlatMatrix(matScalar, "Scalar Multiplication: mat1 * 10");


        FlatMatrix mat3(3, 2);
        mat3[0][0] = 1; mat3[0][1] = 2;
        mat3[1][0] = 3; mat3[1][1] = 4;
        mat3[2][0] = 5; mat3[2][1] = 6;

        printFlatMatrix(mat3, "FlatMatrix 3: ");

        FlatMatrix matMult = mat1 * mat3;
        printFlatMatrix(matMult, "Matrix Multiplication: mat1 * mat3");


        cout << "Resizing FlatMatrix 1 to 3x5" << endl;
        mat1.resize(3, 5);
        printFlatMatrix(mat1, "FlatMatrix 1 after resize(3, 5)");

        cout << "Resizing FlatMatrix 1 to 2x2" << endl;
        mat1.resize(2, 2);
        printFlatMatrix(mat1, "FlatMatrix 1 after resize(2, 2)");


        mat1.at(10, 10) = 999;

    } catch (const exception& e) {
        cerr << e.what() << endl;
    }
}