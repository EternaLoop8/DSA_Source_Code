#include <iostream>
using namespace std;

void sortArray(int *arr, int n)
{

    // Base case: If array has 0 or 1 element, it is already sorted
    if (n == 0 || n == 1)
    {
        return;
    }

    // Solve one case - push the largest element to the end
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }

    // Recursive call
    /* sortArray(arr, n) = bubble pass to put largest at end
                    + sortArray(arr, n-1)
    */
    sortArray(arr, n - 1);
}

int main()
{
    int arr[5] = {2, 5, 1, 6, 9};

    sortArray(arr, 5); // Sort the array

    // Print the sorted array
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
