#include <iostream>
using namespace std;

int factorial(int n)
{
    // Edge case
    if (n < 0)
    {
        cout << "Factorial not defined for negative numbers.\n";
        return 0;
    }

    // Base case
    if (n == 0)
        return 1;

    // Recursive Relation
    int smallerProblem = factorial(n - 1);
    int biggerProblem = n * smallerProblem;
    return biggerProblem;
}

int main()
{

    int n;
    cout << "Enter the number " << endl;
    cin >> n;

    int ans = factorial(n);

    if (n >= 0)
        cout << "The factorial of " << n << " is " << ans << endl;

    return 0;
}