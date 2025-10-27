#include <iostream>
using namespace std;

int main()
{
    int arr[10] = {23, 122, 41, 67};

    cout << "Value of first memory block is " << arr[0] << endl;
    cout << "Address of first memory block is " << arr << endl;
    cout << "Address of first memory block is " << &arr[0] << endl;

    cout << "First element: " << *arr << endl;
    cout << "First element + 1: " << *arr + 1 << endl;
    cout << "First element + 1: " << *(arr) + 1 << endl;
    cout << "Second element: " << *(arr + 1) << endl;
    cout << "Third element: " << arr[2] << endl;
    cout << "Third element: " << *(arr + 2) << endl;

    int i = 3;
    // Accesses arr[3] using pointer arithmetic: *(arr + 3)
    cout << "Fourth element: " << i[arr] << endl;

    int temp[10] = {1, 2};
    // size of temp = 10 elements * 4 bytes per integer = 40
    cout << "size of temp: " << sizeof(temp) << " bytes" << endl;
    cout << "size of integer: " << sizeof(*temp) << " bytes" << endl;
    cout << "size of pointer: " << sizeof(&temp) << " bytes" << endl;

    int *ptr = &temp[0];
    cout << "size of integer: " << sizeof(*ptr) << " bytes" << endl;
    cout << "size of pointer: " << sizeof(ptr) << " bytes" << endl;
    cout << "size of pointer: " << sizeof(&ptr) << " bytes" << endl;

    int a[20] = {1, 2, 3, 5};
    int *p = &a[0];
    cout << "Address of array a: " << a << endl;  // same as &a[0]
    cout << "Address of array a: " << &a << endl; // pointer to entire array
    cout << "Address of p: " << &p << endl;

    // renamed second 'arr' to arr2
    int arr2[10];
    // renamed second 'ptr' to ptr2
    int *ptr2 = &arr2[0];
    cout << "Address of ptr2: " << ptr2 << endl;
    ptr2 = ptr2 + 1;
    cout << "Address of ptr2 + 1:" << ptr2 << endl;

    return 0;
}
