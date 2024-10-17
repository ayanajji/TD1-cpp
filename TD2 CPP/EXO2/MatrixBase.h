#ifndef MATRIXBASE_H
#define MATRIXBASE_H

#include <vector>
#include <iostream>
using namespace std;

//Question 1.

template<typename T>
class MatrixBase {
protected:
    vector<vector<T>> data;    
    size_t rows;               
    size_t cols;               

//Question 2
public:
    
    MatrixBase();                          
    MatrixBase(size_t rows, size_t cols);   

//Question 3
    void addElement(size_t row, size_t col, T element);
    T getElement(size_t row, size_t col) const;

// Question 4
    size_t getRows() const { return rows; }
    size_t getCols() const { return cols; }

//Question 5  
  void Display() const;
};

// Implementation

template<typename T>
MatrixBase<T>::MatrixBase() : rows(1), cols(1) {
    data.resize(rows, vector<T>(cols));
}

template<typename T>
MatrixBase<T>::MatrixBase(size_t rows_, size_t cols_) : rows(rows_), cols(cols_) {
    data.resize(rows, vector<T>(cols));
}

template<typename T>
void MatrixBase<T>::addElement(size_t row_, size_t col_, T element) {
    data[row_][col_] = element;
}

template<typename T>
T MatrixBase<T>::getElement(size_t row_, size_t col_) const {
    return data[row_][col_];
}

template<typename T>
void MatrixBase<T>::Display() const {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
}

#endif // MATRIXBASE_H
