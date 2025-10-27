#include <iostream>
#include <climits>
using namespace std;

// Function to find the Minimum value
int getMin(int num[], int n)
{
    // Initialize 'mini' with the maximum possible integer value
    // So any number in the array will be smaller than this initially
    int mini = INT_MAX;

    // Traverse the array and update 'mini' with the smallest value found
    for (int i = 0; i < n; i++)
    {
        mini = min(mini, num[i]);
    }
    return mini;
}

// Function to find the Maximum value
int getMax(int num[], int n)
{
    // Initialize 'maxi' with the minimum possible integer value
    // So any number in the array will be larger than this initially
    int maxi = INT_MIN;

    // Traverse the array and update 'maxi' with the smallest value found
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, num[i]);
    }
    return maxi;
}

int main()
{
    // Input elements into the array
    int size;
    cin >> size;

    int num[10];
    for (int i = 0; i < size; i++)
    {
        cin >> num[i];
    }
    // Adding a bound check
    if (size > 10)
    {
        cout << "Error: Maximum allowed size is 10." << endl;
        return 1;
    }

    // Output the maximum and minimum values using helper functions
    cout << "Maximum value is " << getMax(num, size) << endl;
    cout << "Minimum value is " << getMin(num, size) << endl;

    return 0;
}