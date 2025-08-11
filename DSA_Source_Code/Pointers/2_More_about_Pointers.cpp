#include <iostream>
using namespace std;

int main()
{
    // Initializing an integer
    int num = 5;
    int a = num;
    cout << "a before " << num << endl;
    a++;
    cout << "a after " << num << endl;

    // Initializing a pointer
    int *p = &num;
    cout << "before " << num << endl;
    (*p)++;
    cout << "after " << num << endl;

    // Copying a pointer
    int *q = p;
    cout << p << " - " << q << endl;
    cout << *p << " - " << *q << endl;

    // Adding values to a pointer
    int i = 3;
    int *t = &i;
    // cout <<  (*t)++ << endl;
    *t = *t + 1;
    cout << *t << endl;

    // Printing the address
    cout << " before t " << t << endl;
    t = t + 1;
    cout << " after t " << t << endl;

    return 0;
}