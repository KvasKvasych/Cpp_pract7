#pragma once
#include <vector>
#include <iostream>
#include <stdexcept>

using namespace std;

class Matrix {
private:
    vector<vector<double>> data;
    int rows;
    int cols;

public:
    Matrix(int rows, int cols, double initial = 0.0);

    Matrix operator+(const Matrix& other) const;
    Matrix operator*(double scalar) const;
    Matrix transpose() const;

    void print() const;

    int getRows() const { return rows; }
    int getCols() const { return cols; }
    double& at(int row, int col) { return data[row][col]; }
    const double& at(int row, int col) const { return data[row][col]; }
};