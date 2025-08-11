#include <iostream>
using namespace std;

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    char ch[6] = "abcde";

    // Prints address of first element (array decays to int*)
    cout << arr << endl;

    // For char arrays, cout prints as a C-string until '\0'
    cout << ch << endl;

    char *c = ch; // same as &ch[0]
    cout << c << endl; // prints the string

    char temp = 'z';
    char *p = &temp;
    cout << p << endl; // prints from 'z' until a '\0' is found (undefined behavior)

    return 0;
}
