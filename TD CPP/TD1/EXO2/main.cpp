#include "Complex2D.h"
#include <iostream>

int main() {
    Complex2D c1(1, 2);  
    Complex2D c2(4, 3); 

    // Effectuer des opérations
    Complex2D sum = c1 + c2;
    Complex2D difference = c1 - c2;
    Complex2D product = c1 * c2;
    Complex2D quotient = c1 / c2;

    // Afficher les résultats
    std::cout << "c1 + c2 = " << sum.getReal() << " + " << sum.getImg() << "i" << std::endl;
    std::cout << "c1 - c2 = " << difference.getReal() << " + " << difference.getImg() << "i" << std::endl;
    std::cout << "c1 * c2 = " << product.getReal() << " + " << product.getImg() << "i" << std::endl;
    std::cout << "c1 / c2 = " << quotient.getReal() << " + " << quotient.getImg() << "i" << std::endl;

    return 0;
}
