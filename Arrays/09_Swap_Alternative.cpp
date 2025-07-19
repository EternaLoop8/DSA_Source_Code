#include <iostream>
using namespace std;

// Function to swap alternate elements in the array
// For example: [1, 2, 3, 4] becomes [2, 1, 4, 3]
void swapAlternate(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        // Ensure we don't go out of bounds
        if (i + 1 < size)
        {
            // Swap current element with the next one
            swap(arr[i], arr[i + 1]);
            // Move to the next pair
            i++; // Skip the next element since it's already swapped
        }
    }
}

// Function to print all elements of the array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int size;
    cout << "Enter the size of the array" << endl;
    cin >> size;

    // Declare an array with a maximum size of 100
    int arr[100];

    cout << "Enter the elements of the array" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << endl;

    // Call the function to swap alternate elements
    swapAlternate(arr, size);

    // Print the updated array after swapping
    printArray(arr, size);

    return 0;
}
