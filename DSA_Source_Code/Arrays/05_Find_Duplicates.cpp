#include <iostream>
#include <vector>
using namespace std;

int findDuplicate(vector<int> &arr)
{
    int ans = 0;

    // XOR all array elements
    for (int i = 0; i < arr.size(); i++)
    {
        ans = ans ^ arr[i];
    }

    // XOR [1, n-1]
    for (int i = 1; i < arr.size(); i++)
    {
        ans = ans ^ i;
    }

    return ans;
}

int main()
{
    int size;
    cout << "Enter the size of array: ";
    cin >> size;

    vector<int> arr(size); // vector of integers with given size

    cout << "Enter the elements of array:" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    // This only works for only one duplicate element in an array
    cout << "Duplicate element is: " << findDuplicate(arr) << endl;

    return 0;
}
