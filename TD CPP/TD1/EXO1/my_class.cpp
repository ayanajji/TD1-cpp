#include "my_class.h"
#include <iostream>
using namespace std;
my_class::my_class() : private_var("default") {
}

my_class::my_class( const string &s) : private_var(s) {
}

void my_class::print_my_element() const {
    cout << private_var << endl;
}
