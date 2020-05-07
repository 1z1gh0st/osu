#include "matrix.h"
#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::setw;
using std::max;
using std::cin;

/* Constructors */

Matrix::Matrix(unsigned _num_rows_, unsigned _num_cols_, double _init_val_) {
   num_rows = _num_rows_;
   num_cols = _num_cols_;
   matrix.resize(num_rows);
   for (unsigned i = 0; i < num_rows; i++) {
       matrix[i].resize(num_cols, _init_val_);
   }
}

Matrix::Matrix(unsigned _num_rows_, unsigned _num_cols_, string _s_) {
   string input = "";
   num_rows = _num_rows_;
   num_cols = _num_cols_;
   matrix.resize(num_rows);
   for (unsigned i = 0; i < num_rows; i++) {
       matrix[i].resize(num_cols, 0);
   }
    if (_s_ == "man") { // manually enter values
        for (unsigned i = 0; i < num_rows; i++) {
            for (unsigned j = 0; j < num_cols; j++) {
                cout << i << " " << j << " : ";
                getline(cin, input);
                matrix[i][j] = stod(input);
                print();
            }
        }
    } else if (_s_ == "id") { // identity matrix
        for (unsigned i = 0; i < num_rows; i++) {
            for (unsigned j = 0; j < num_cols; j++) {
                matrix[i][j] = (i == j);
            }
        }
    } else {
        throw("Matrix: invalid constructor flag");
    }
}

Matrix::Matrix(unsigned _num_rows_, unsigned _num_cols_, vector<double> _values_) {
    if ((_num_rows_ * _num_cols_) != _values_.size()) {
        cout << "ERROR: called constructor that accepts vector: vector passed was of incorrect length" << endl;
        throw("Constructor recieved vector of incorrect length (should be n by m)");
    } else {
        num_rows = _num_rows_;
        num_cols = _num_cols_;
        unsigned k = 0;
        matrix.resize(num_rows);
        for (unsigned i = 0; i < num_rows; i++) {
            matrix[i].resize(num_cols);
            for (unsigned j = 0; j < num_cols; j++) {
                matrix[i][j] = _values_[k];
                k++;
            }
        }
    }
}

Matrix::Matrix(const Matrix &_m_) {
    num_rows = _m_.num_rows;
    num_cols = _m_.num_cols;
    matrix = _m_.matrix;
}

/* Operators */

// Assignment
Matrix Matrix::operator=(const Matrix &_m_) {
    num_rows = _m_.num_rows;
    num_cols = _m_.num_cols;
    matrix = _m_.matrix;
    return *this;
}

// Scalar addition
Matrix Matrix::operator+(double _c_) {
    for (unsigned i = 0; i < num_rows; i++) {
        for (unsigned j = 0; j < num_cols; j++) {
            matrix[i][j] += _c_;
        }
    }
    return *this;
}

// Scalar subtraction
Matrix Matrix::operator-(double _c_) {
    for (unsigned i = 0; i < num_rows; i++) {
        for (unsigned j = 0; j < num_cols; j++) {
            matrix[i][j] -= _c_;
        }
    }
    return *this;
}

// Scalar multiplication
Matrix Matrix::operator*(double _c_) {
    for (unsigned i = 0; i < num_rows; i++) {
        for (unsigned j = 0; j < num_cols; j++) {
            matrix[i][j] *= _c_;
        }
    }
    return *this;
}

// Scalar division
Matrix Matrix::operator/(double _c_) {
    for (unsigned i = 0; i < num_rows; i++) {
        for (unsigned j = 0; j < num_cols; j++) {
            matrix[i][j] /= _c_;
        }
    }
    return *this;
}

// Entrywise addition
Matrix Matrix::operator+(const Matrix &_m_) {
    if (num_rows != _m_.num_rows || num_cols != _m_.num_cols) {
        cout << "ERROR: matrix subtraction of invalid dimension" << endl;
        throw("Matrix subtraction invalid dimension");
    } else {
        for (unsigned i = 0; i < num_rows; i++) {
            for (unsigned j = 0; j < num_cols; j++) {
                if (i < _m_.num_rows && j < _m_.num_cols) {
                    matrix[i][j] += _m_.matrix[i][j];
                }
            }
        }
    }
    return *this;
}

// Entrywise subtraction
Matrix Matrix::operator-(const Matrix &_m_) {
    if (num_rows != _m_.num_rows || num_cols != _m_.num_cols) {
        cout << "ERROR: matrix subtraction of invalid dimension" << endl;
        throw("Matrix subtraction invalid dimension");
    } else {
        for (unsigned i = 0; i < num_rows; i++) {
            for (unsigned j = 0; j < num_cols; j++) {
                if (i < _m_.num_rows && j < _m_.num_cols) {
                    matrix[i][j] -= _m_.matrix[i][j];
                }
            }
        }
    }
    return *this;
}

// Matrix multiplication
Matrix Matrix::operator*(const Matrix &_m_) {
    if (num_cols != _m_.num_rows) {
        cout << "ERROR: matrix multiplication of invalid dimension" << endl;
        throw("Matrix multiplication: invalid dimensions");
    } else {
        unsigned p = num_cols;
        vector<vector<double>> result (num_rows, vector<double> (_m_.num_cols, 0));
        for (unsigned i = 0; i < result.size(); i++) {
            for (unsigned j = 0; j < result[0].size(); j++) {
                for (unsigned k = 0; k < p; k++) {
                    result[i][j] += (matrix[i][k] * _m_.matrix[k][j]); 
                }
            }
        }
        num_cols = _m_.num_cols;
        matrix = result;
    }
    return *this;
}

// Determinant
float Matrix::determinant() {
    float det = 0;
    if (num_cols != num_rows) {
        cout << "ERROR: determinant invalid dimension" << endl;
        throw("Matrix determinant: invalid dimensions");
    } else {
        // Calculate the determinant
        if (num_rows == 2) {
            det = (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]); 
        } else {
            for (unsigned j = 0; j < num_cols; j++) {
                Matrix submatrix = *this;
                submatrix.remove_row_at(0);
                submatrix.remove_col_at(j);
                if (j % 2 == 0) {
                    det += matrix[0][j] * submatrix.determinant();
                } else {
                    det -= matrix[0][j] * submatrix.determinant();
                }
            }
        }
    }
    return det;
}

// Transpose
void Matrix::transpose() {
    vector<vector<double>> result (num_cols, vector<double> (num_rows, 0));
    for (unsigned i = 0; i < num_rows; i++) {
        for (unsigned j = 0; j < num_cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
    matrix = result;
    unsigned swap = num_rows;
    num_rows = num_cols;
    num_cols = swap;
}

// Entrywise multiplication
void Matrix::hadamard_mult(const Matrix &_m_) {
    if (num_rows != _m_.num_rows || num_cols != _m_.num_cols) {
        cout << "error: hadamard mult. attempted on matrix of unequal dim" << endl;
        throw("dimension error");
    } else {
        for (unsigned i = 0; i < num_rows; i++) {
            for (unsigned j = 0; j < num_cols; j++) {
                matrix[i][j] *= _m_.matrix[i][j];
            }
        }
    }
}

/* Debugging */

void Matrix::print() const {
    cout << ":" << endl;
    for (unsigned i = 0; i < num_rows; i++) {
        for (unsigned j = 0; j < num_cols; j++) {
            cout << setw(10) << matrix[i][j];
        }
        cout << endl;
    }
}

double Matrix::get_value_at(unsigned _i_, unsigned _j_) const {
    return matrix[_i_][_j_];
}

Matrix Matrix::remove_row_at(unsigned _i_) {
    if (_i_ >= num_rows) {
        cout << "error; out of range" << endl;
    } else {
        matrix.erase(matrix.begin() + _i_);
        num_rows--;
    }
    return *this;
}

Matrix Matrix::remove_col_at(unsigned _j_) {
    if (_j_ >= num_cols) {
        cout << "error; out of range" << endl;
    } else {
        for (unsigned i = 0; i < num_rows; i++) {
            matrix[i].erase(matrix[i].begin() + _j_);
        }
        num_cols--;
    }
    return *this;
}
