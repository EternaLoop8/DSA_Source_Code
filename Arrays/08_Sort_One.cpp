#include <iostream>
using namespace std;

// Function to print the array elements
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " "; 
    }
    cout << endl; 
}

// Function to sort a binary array containing only 0s and 1s
void sortOne(int arr[], int n)
{
    int left = 0, right = n - 1;
   
    while (left < right)
    {
        // Move 'left' forward if it's already pointing to 0
        while (arr[left] == 0 && left < right)
        {
            left++;
        }

        // Move 'right' backward if it's already pointing to 1
        while (arr[right] == 1 && left < right)
        {
            right--;
        }

        // If left < right, swap the elements to move 0 to the left and 1 to the right
        if (left < right)
        {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
}

int main()
{
    int size;
    cout << "Enter the size of array: ";
    cin >> size; // Read the number of elements in the array

    int arr[100]; // Declare a fixed-size array (max 100 elements)

    // Input array elements
    cout << "Enter the elements of array:" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    // Sort the array containing only 0s and 1s
    sortOne(arr, size);

    // Print the sorted array
    printArray(arr, size);

    return 0;
}
