#include <iostream>
using namespace std;

// Binary Search function to find the index of 'key' in sorted array
int binarySearch(int arr[], int size, int key)
{
    int start = 0;      // starting index
    int end = size - 1; // ending index

    // Calculate mid to avoid overflow
    int mid = start + (end - start) / 2;

    // Continue searching while the range is valid
    while (start <= end)
    {

        // If the mid element is the key, return its index
        if (arr[mid] == key)
        {
            return mid;
        }

        // If the key is greater than mid element, search in the right half
        if (key > arr[mid])
        {
            start = mid + 1;
        }
        else
        { // If the key is smaller, search in the left half
            end = mid - 1;
        }

        // Update mid after changing start or end
        mid = start + (end - start) / 2;
    }

    // If the key is not found, return -1
    return -1;
}

int main()
{
    int size;
    cout << "Enter the size of array: ";
    cin >> size;

    int arr[100];

    cout << "Enter " << size << " elements (sorted in ascending order): ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    int key;
    cout << "Enter the element to search: ";
    cin >> key;

    int result = binarySearch(arr, size, key);

    if (result != -1)
    {
        cout << "Element found at index: " << result << endl;
    }
    else
    {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}
