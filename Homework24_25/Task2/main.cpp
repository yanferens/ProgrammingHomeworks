#include <iostream>
#include <utility>
#include <vector>
#include <stdexcept>
#include <concepts>

using namespace std;

template <typename T>
concept Numeric = integral<T> || floating_point<T>;

template <Numeric T>
class Matrix {
private:
    int _row = 0;
    int _column = 0;
    vector<vector<T>> _matrix;

public:
    Matrix() = default;

    Matrix(int row, int column, const vector<vector<T>>& matrix) {
        if (!set(row, column, matrix)) {
            throw invalid_argument("Invalid arguments");
        }
    }

    bool set(int row, int column, const vector<vector<T>>& matrix) {
        if (row <= 0 || column <= 0 || matrix.size() != row) {
            return false;
        }
        _row = row;
        _column = column;
        _matrix = matrix;
        return true;
    }

    const vector<vector<T>>& getMatrix() const {
        return _matrix;
    }

    pair<int, int> getPar() const {
        return {_row, _column};
    }

    void print() const {
        for (int i = 0; i < _row; ++i) {
            for (int j = 0; j < _column; ++j) {
                cout << _matrix[i][j] << "\t";
            }
            cout << endl;
        }
        cout << endl;
    }
};

template <Numeric T>
Matrix<T> matrixMultiplication(const Matrix<T>& A, const Matrix<T>& B) {
    auto [rowsA, colsA] = A.getPar();
    auto [rowsB, colsB] = B.getPar();

    if (colsA != rowsB) {
        throw logic_error("Invalid matrix dimensions");
    }

    const auto& A_vec = A.getMatrix();
    const auto& B_vec = B.getMatrix();

    vector<vector<T>> newMatrix(rowsA, vector<T>(colsB, 0));

    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            for (int k = 0; k < colsA; ++k) {
                newMatrix[i][j] += A_vec[i][k] * B_vec[k][j];
            }
        }
    }

    return Matrix<T>(rowsA, colsB, newMatrix);
}

int main() {
    try {
        vector<vector<int>> A_v = {{1, 2, 3}, {4, 5, 6}};
        vector<vector<int>> B_v = {{7, 8}, {9, 10}, {11, 12}};
        Matrix<int> A(2, 3, A_v);
        Matrix<int> B(3, 2, B_v);
        auto C = matrixMultiplication(A, B);
        C.print();

        vector<vector<double>> X_v = {{1.5, 2.0}, {3.2, 0.5}};
        vector<vector<double>> Y_v = {{2.0, 1.0}, {0.0, 4.0}};
        Matrix<double> X(2, 2, X_v);
        Matrix<double> Y(2, 2, Y_v);
        auto Z = matrixMultiplication(X, Y);
        Z.print();
        

    } catch (const exception& e) {
        cerr << e.what() << endl;
    }


}