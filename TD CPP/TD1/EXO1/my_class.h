#ifndef MY_CLASS_H
#define MY_CLASS_H
#include <string>

class my_class {
private:
    std::string private_var; 
public:
    my_class(); 
    my_class(const std::string &s);  

    void print_my_element() const;   
};

#endif
