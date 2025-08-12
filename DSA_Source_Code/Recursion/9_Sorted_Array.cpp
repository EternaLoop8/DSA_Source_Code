#include <iostream>
using namespace std;

bool isSorted(int arr[], int size)
{

    // Base Case:
    // If array has 0 or 1 element, it is always sorted
    if (size == 0 || size == 1)
    {
        return true;
    }

    // Check if the first pair is in correct order
    if (arr[0] > arr[1])
        return false;

    // Recursive Relation:
    bool remainingPart = isSorted(arr + 1, size - 1);
    return remainingPart;
}

int main()
{
    int arr[5] = {2, 4, 9, 9, 9};
    int size = 5;

    bool ans = isSorted(arr, size);

    if (ans)
    {
        cout << "Array is sorted " << endl;
    }
    else
    {
        cout << "Array is not sorted " << endl;
    }

    return 0;
}
