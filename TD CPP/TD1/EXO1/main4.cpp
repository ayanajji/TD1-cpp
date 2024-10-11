#include "my_class.h"
#include <string>
using namespace std;

int main() {
    my_class obj1;
    obj1.print_my_element(); 

    my_class obj2("Hello World!");
    obj2.print_my_element(); 

    return 0;
}
