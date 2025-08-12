#include <iostream>
using namespace std;

// Recursive function to find the nth Fibonacci number
int fibonacci(int n)
{
    // Base cases
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    // Recursive call for (n-1)th and (n-2)th Fibonacci numbers
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n;
    cout << "Enter number of terms: ";
    cin >> n;

    cout << "Fibonacci series: ";
    for (int i = 0; i < n; i++)
    {
        cout << fibonacci(i) << " ";
    }
    cout << endl;

    return 0;
}
