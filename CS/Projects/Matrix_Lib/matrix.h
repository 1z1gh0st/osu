/* --------------------------------------
 *           MATRIX LIBRARY
 *
 *    Author: felipe-finesse
 *    Purpose: Matrix library for building
 *        custom neural nets
 *    Date: 05/04/2020
 *
 * -------------------------------------*/

#ifndef MATRIX_H
#define MATRIX_H

#include<vector>
#include<string>

using std::vector;
using std::string;

class Matrix {
    private:
        unsigned num_rows;
        unsigned num_cols;
        vector<vector<double>> matrix;
    public:
        /* --- CONSTRUCTORS --- */
        Matrix(unsigned, unsigned, double); // Constructor
        Matrix(unsigned, unsigned, string);
        Matrix(unsigned, unsigned, vector<double>);
        Matrix(const Matrix &); // Copy constructor

        /* --- OPERATORS --- */
        Matrix operator=(const Matrix &); // Assignment operator overload

        // Scalar Algebra
        Matrix operator+(double);
        Matrix operator-(double);
        Matrix operator*(double);
        Matrix operator/(double);

        // Matrix Algebra
        Matrix operator+(const Matrix &);
        Matrix operator-(const Matrix &);
        Matrix operator*(const Matrix &);

        void transpose();
        float determinant();
        void hadamard_mult(const Matrix &); // TODO
        void kroenecker_mult(const Matrix &); // TODO

        /* --- DEBUGGING --- */
        void print() const;
        double get_value_at(unsigned i, unsigned j) const;

        /* --- OTHER --- */
        Matrix remove_row_at(unsigned);
        Matrix remove_col_at(unsigned);
};

#endif
