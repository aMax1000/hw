#include <iostream>


void print(char* a) {
    signed int i = 0;
    while (a[i]) {
        std::cout << a[i];
        i++;
    }
}


template<typename T>
T add(T ell1, T ell2) {
    return ell1 + ell2;
}
template<typename T>
T sup(T ell1, T ell2) {
    return ell1 - ell2;
}
template<typename T>
T mul(T ell1, T ell2) {
    return ell1 * ell2;
}
template<typename T>
T div(T ell1, T ell2) {
    T divideby0detectior = (ell2 == 0);
    char* a = new char[21] {'E', 'R','R','O','R',' ','D','I','V','I','S','I','O','N',' ','B','Y',' ','0','\n','\0'};
    a[0] = divideby0detectior*a[0];
    print(a);
    delete[] a;
    return ((1-divideby0detectior) * ell1) / (ell2+divideby0detectior);
    //returns 0 if you divide by 0
}


int main()
{
    int (*calc[4])(int, int) = { add,sup,mul,div };
    std::cout<<calc[0](1, 1)<<'\n';
    std::cout << calc[1](3, 1) << '\n';
    std::cout << calc[2](3, 3) << '\n';
    std::cout << calc[3](6, 3) << '\n';
    std::cout << calc[3](3, 0) << '\n';
}
