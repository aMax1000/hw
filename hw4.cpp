
#include <iostream>
using namespace std;
int main()
{
    double a;
    double b=0;
    int sum=0;
    cin>>a;
    for (int i=0; i < a; i++) {
        cin >> b;
        sum += b;
    }
    cout <<sum<<endl;
    cout << sum/a << endl;

    int c;
    int d;
    cin >> c;
    cin >> d;
    for (int i = 0; i < c; i++) {
        cout<<(i+1)*d << endl;
    }
}
