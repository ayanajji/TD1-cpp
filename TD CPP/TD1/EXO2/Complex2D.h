#ifndef COMPLEX2D_H
#define COMPLEX2D_H

class Complex2D {
private:
    double real;  
    double img;   

public:
    
    Complex2D(); 
    Complex2D(double real, double img);  
    Complex2D(double value);  
    Complex2D(const Complex2D &c);  
    double getReal() const;  
    void setReal(double real);  

    double getImg() const;  
    void setImg(double img);  

    Complex2D operator+(const Complex2D &c) const;  
    Complex2D operator-(const Complex2D &c) const; 
    Complex2D operator*(const Complex2D &c) const;  
    Complex2D operator/(const Complex2D &c) const;  
    bool operator<(const Complex2D &c) const;  
    bool operator>(const Complex2D &c) const;  
};

#endif 
