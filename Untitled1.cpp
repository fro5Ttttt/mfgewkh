
#include <iostream>

class Matrix {
private:
    int rows;
    int cols;
    int** data;

public:
    Matrix(int rows, int cols) {
        this->rows = rows;
        this->cols = cols;

        // Allocate memory for the matrix
        data = new int*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new int[cols];
        }
    }

    ~Matrix() {
        // Deallocate memory for the matrix
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
    }

    void inputMatrix() {
        std::cout << "Enter the elements of the matrix:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                std::cout << "Element [" << i << "][" << j << "]: ";
                std::cin >> data[i][j];
            }
        }
    }

    bool canMultiply(const Matrix& other) const {
        return cols == other.rows;
    }

    Matrix multiply(const Matrix& other) const {
        Matrix result(rows, other.cols);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                result.data[i][j] = 0;
                for (int k = 0; k < cols; k++) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }

        return result;
    }

    void displayMatrix() const {
        std::cout << "Matrix:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                std::cout << data[i][j] << "\t";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    int rows1, cols1, rows2, cols2;

    std::cout << "Enter dimensions of the first matrix:\n";
    std::cout << "Rows: ";
    std::cin >> rows1;
    std::cout << "Columns: ";
    std::cin >> cols1;

    std::cout << "Enter dimensions of the second matrix:\n";
    std::cout << "Rows: ";
    std::cin >> rows2;
    std::cout << "Columns: ";
    std::cin >> cols2;

    if (cols1 != rows2) {
        std::cout << "Matrix multiplication is not possible!\n";
        return 0;
    }

    Matrix matrix1(rows1, cols1);
    Matrix matrix2(rows2, cols2);

    matrix1.inputMatrix();
    matrix2.inputMatrix();

    Matrix result = matrix1.multiply(matrix2);

    std::cout << "Matrix multiplication result:\n";
    result.displayMatrix();

    return 0;
}
