#include <iostream>
#include <iomanip> // optional for formatting
using namespace std;

long long power(int n)
{
    // base case
    if (n == 0)
        return 1;

    // recursive relation
    return 2LL * power(n - 1); // 2LL ensures long long multiplication
}

int main()
{
    int n;
    cout << "Enter the exponent: ";
    cin >> n;

    if (n < 0)
    {
        cout << "Negative exponents are not supported in this function.\n";
        return 0;
    }

    long long ans = power(n);

    cout << "2^" << n << " = " << ans << endl;

    return 0;
}
