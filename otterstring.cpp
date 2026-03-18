#include <iostream>
#include "otterstring.h"

int main()
{
    char* arr = new char[5]{'1', '2', '3', '4', '5'};
    otterstring a(arr, 5);
    otterstring b(arr, 5);
    cutotterstring c(a, 2, 3);
    std::cout<<a.len()<<'\n';
    a.print();
    c.print();
    a.my_concate(arr, 5);
    a.print();
    a.my_concate(b);
    a.print();
    a.addell('a');
    a.print();
    char* d = new char[4] { '4', '5', 'a', '\0' };
    std::cout << a.findstring(d)<<'\n';
    std::cout << a.findstring(a) << '\n';
}
