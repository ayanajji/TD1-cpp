#include <iostream>
#include "MatrixNumerical.h"

using namespace std;

int main() {
    MatrixNumerical<int> matrix(3, 3);
    matrix.addElement(0, 0, 1);
    matrix.addElement(0, 1, 2);
    matrix.addElement(0, 2, 3);
    matrix.addElement(1, 0, 0);
    matrix.addElement(1, 1, 1);
    matrix.addElement(1, 2, 4);
    matrix.addElement(2, 0, 5);
    matrix.addElement(2, 1, 6);
    matrix.addElement(2, 2, 0);
    cout << "Matrix:" << endl;
    matrix.display();
    cout << "Determinant: " << matrix.getDeterminant() << endl;

    return 0;
}
