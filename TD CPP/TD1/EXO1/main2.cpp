#include "hello.h"
#include<iostream>
#include <string>
using namespace std;
void print_funtion( string sentense) {
    cout << sentense << endl;  
}
int main(){
    string sentence = "Hello World !";
    print_function(sentence);
    return 0;
}