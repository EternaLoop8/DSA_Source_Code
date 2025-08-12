#include <iostream>
using namespace std;

int partition(int arr[], int s, int e)
{
    int pivot = arr[s];

    // Count elements smaller or equal to pivot
    int cnt = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= pivot)
        {
            cnt++;
        }
    }

    // Place pivot at correct position
    int pivotIndex = s + cnt;
    swap(arr[pivotIndex], arr[s]);

    // Partition elements around pivot
    int i = s, j = e;

    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] <= pivot)
            i++;
        while (arr[j] > pivot)
            j--;

        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void quickSort(int arr[], int s, int e)
{
    if (s >= e)
        return; // Base case: 1 or no element

    int p = partition(arr, s, e); // Partition array

    quickSort(arr, s, p - 1); // Sort left part
    quickSort(arr, p + 1, e); // Sort right part
}

int main()
{
    int arr[5] = {2, 1, 3, 5, 4};
    int n = 5;

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
