#include <iostream>
using namespace std;

// Function to find unique elements in an array
int findUnique(int *arr, int size)
{
    int ans = 0;
    for (int i = 0; i < size; i++) {
        ans = ans ^ arr[i];
    }
    return ans;
}

int main() {
    int arr[] = {1, 3, 2, 2, 3};  
    int size = sizeof(arr) / sizeof(arr[0]);  
    cout << "Unique element is: " << findUnique(arr, size) << endl;
    return 0;
}
