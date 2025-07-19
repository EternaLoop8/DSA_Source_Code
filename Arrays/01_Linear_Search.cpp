#include <iostream>
using namespace std;

// Function to search for a key in an array
bool search(int arr[], int size, int key)
{
    // Loop through each element of the array
    for (int i = 0; i < size; i++)
    {
        // If the current element matches the key, return true (1)
        if (arr[i] == key)
        {
            return 1;
        }
    }
    // If the loop completes without finding the key, return false (0)
    return 0;
}

int main()
{

    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "Enter the element to search for" << endl;
    int key;
    cin >> key;

    // Call the search function to check if key is present in the array
    bool found = search(arr, 10, key);

    // Output the result based on whether the key was found
    if (found)
    {
        cout << "Key is present" << endl;
    }
    else
    {
        cout << "Key is absent" << endl;
    }

    return 0;
}