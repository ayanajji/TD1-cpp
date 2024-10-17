#ifndef MATRIXNUMERICAL_H
#define MATRIXNUMERICAL_H

#include "MatrixBase.h"
#include <iostream>

// Hériter de la classe MatrixBase
template<typename T>
class MatrixNumerical : public MatrixBase<T> {
public:
    // Constructeurs
    MatrixNumerical() : MatrixBase<T>() {}
    MatrixNumerical(size_t rows, size_t cols) : MatrixBase<T>(rows, cols) {}

    // Question 7
    T getDeterminant() const;

    // Question 9
    MatrixNumerical<T> operator+(const MatrixNumerical<T>& other) const;
    MatrixNumerical<T> operator-(const MatrixNumerical<T>& other) const;
    MatrixNumerical<T> operator*(const MatrixNumerical<T>& other) const;
    MatrixNumerical<T> operator*(const T& scalar) const;

    // Question 10
    MatrixNumerical<T> getInverse() const;

    // Question 12   
    static MatrixNumerical<T> getIdentity(int size);

    // Méthode pour afficher la matrice
    void display() const;
};

// Implémentation de getDeterminant
template<typename T>
T MatrixNumerical<T>::getDeterminant() const {
    if (this->rows != this->cols) {
        std::cout << "Not a square matrix." << std::endl;
        return T(); 
    }
    
    T determinant = 0;
    for (size_t i = 0; i < this->rows; i++) {
        MatrixNumerical<T> submatrix(this->rows - 1, this->cols - 1);
        for (size_t j = 1; j < this->rows; j++) {
            size_t sub_col = 0;
            for (size_t k = 0; k < this->cols; k++) {
                if (k == i) continue;
                submatrix.data[j - 1][sub_col++] = this->data[j][k];
            }
        }
        T subdet = submatrix.getDeterminant();
        determinant += (i % 2 == 0 ? 1 : -1) * this->data[0][i] * subdet;
    }
    return determinant;
}

template<typename T>
void MatrixNumerical<T>::display() const {
    for (size_t i = 0; i < this->rows; i++) {
        for (size_t j = 0; j < this->cols; j++) {
            std::cout << this->data[i][j] << " ";
        }
        std::cout << std::endl; 
    }
}

template<typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator+(const MatrixNumerical<T>& other) const {
    if (this->rows != other.rows || this->cols != other.cols) {
        std::cout << "Unmatched dimensions " << std::endl;
    }

    MatrixNumerical<T> result(this->rows, this->cols);
    for (size_t i = 0; i < this->rows; i++) {
        for (size_t j = 0; j < this->cols; j++) {
            result.data[i][j] = this->data[i][j] + other.data[i][j];
        }
    }
    return result;
}

template<typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator-(const MatrixNumerical<T>& other) const {
    if (this->rows != other.rows || this->cols != other.cols) {
        std::cout << "Unmatched dimensions " << std::endl;
    }

    MatrixNumerical<T> result(this->rows, this->cols);
    for (size_t i = 0; i < this->rows; i++) {
        for (size_t j = 0; j < this->cols; j++) {
            result.data[i][j] = this->data[i][j] - other.data[i][j];
        }
    }
    return result;
}

template<typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator*(const MatrixNumerical<T>& other) const {
    if (this->cols != other.rows) {
        std::cout << "Unmatched dimensions" << std::endl;
       
    }

    MatrixNumerical<T> result(this->rows, other.cols);
    for (size_t i = 0; i < this->rows; i++) {
        for (size_t j = 0; j < other.cols; j++) {
            result.data[i][j] = 0;
            for (size_t k = 0; k < this->cols; k++) {
                result.data[i][j] += this->data[i][k] * other.data[k][j];
            }
        }
    }
    return result;
}

template<typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator*(const T& scalar) const {
    MatrixNumerical<T> result(this->rows, this->cols);
    for (size_t i = 0; i < this->rows; i++) {
        for (size_t j = 0; j < this->cols; j++) {
            result.data[i][j] = this->data[i][j] * scalar;
        }
    }
    return result;
}

template<typename T>
MatrixNumerical<T> MatrixNumerical<T>::getIdentity(int size) {
    MatrixNumerical<T> identity(size, size);
    for (int i = 0; i < size; i++) {
        identity.addElement(i, i, 1);
    }
    return identity;
}

#endif // MATRIXNUMERICAL_H
