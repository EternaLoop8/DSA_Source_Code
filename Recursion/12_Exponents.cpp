#include <iostream>
using namespace std;

int power(int a, int b)
{
    // Base Case: anything raised to power 0 is 1
    if (b == 0)
        return 1;

    // Base Case: power 1 returns the number itself
    if (b == 1)
        return a;

    // Recursive Call: compute power(a, b/2) once
    int ans = power(a, b / 2);

    // If b is even, result is ans * ans
    if (b % 2 == 0)
    {
        return ans * ans;
    }
    else
    {
        // If b is odd, multiply once more by a
        return a * ans * ans;
    }
}

int main()
{
    int a, b;
    cout << "Enter the base number: ";
    cin >> a;
    cout << "Enter the exponent (non-negative integer): ";
    cin >> b;
    cout << endl;

    if (b < 0)
    {
        cout << "Negative powers are not handled in this function." << endl;
        return 1;
    }

    int ans = power(a, b);

    cout << "Answer is " << ans << endl;

    return 0;
}
