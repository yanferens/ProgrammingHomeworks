#include <iostream>
#include "FlatMatrix.h"

int main() {
    try {
        FlatMatrix mat(2, 3);

        mat[0][0] = 10;
        mat[0][1] = 20;
        mat[0][2] = 30;
        mat[1][0] = 40;
        mat[1][1] = 50;
        mat[1][2] = 60;

        std::cout << "[1][2]:" << mat[1][2] << "\n\n";



        for (size_t i = 0; i < mat.getRows(); ++i) {
            for (size_t j = 0; j < mat.getCols(); ++j) {
                std::cout << mat[i][j] << "\t";
            }
            std::cout << "\n";
        }

        mat.at(5, 5) = 100;

    } catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
    }
    
}