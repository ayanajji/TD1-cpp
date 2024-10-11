#include "Complex2D.h"

Complex2D::Complex2D() : real(0), img(0) {}

Complex2D::Complex2D(double real, double img) : real(real), img(img) {}

Complex2D::Complex2D(double value) : real(value), img(value) {}

Complex2D::Complex2D(const Complex2D &c) : real(c.real), img(c.img) {}

double Complex2D::getReal() const {
    return real;
}

double Complex2D::getImg() const {
    return img;
}

void Complex2D::setReal(double real) {
    this->real = real;
}

void Complex2D::setImg(double img) {
    this->img = img;
}

Complex2D Complex2D::operator+(const Complex2D &c) const {
    return Complex2D(real + c.real, img + c.img);
}
Complex2D Complex2D::operator-(const Complex2D &c) const {
    return Complex2D(real - c.real, img - c.img);
}

Complex2D Complex2D::operator*(const Complex2D &c) const {
    return Complex2D(real * c.real - img * c.img, real * c.img + img * c.real);
}
Complex2D Complex2D::operator/(const Complex2D &c) const {
    
    return Complex2D((real * c.real + img * c.img) ,(img * c.real - real * c.img) );
}

bool Complex2D::operator<(const Complex2D &c) const {
    return (real < c.real) || (real == c.real && img < c.img);
}

bool Complex2D::operator>(const Complex2D &c) const {
    return (real > c.real) || (real == c.real && img > c.img);
}
