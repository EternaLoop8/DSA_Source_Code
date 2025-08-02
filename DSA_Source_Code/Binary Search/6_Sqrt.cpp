#include<iostream>
using namespace std;

// Function to find the integer part of the square root using binary search
long long int sqrtInteger(int n) {
    int s = 0;
    int e = n;
    long long int mid = s + (e - s) / 2;

    long long int ans = -1;

    while (s <= e) {
        long long int square = mid * mid;

        if (square == n) // Perfect square found
            return mid;

        if (square < n) {
            ans = mid;     // Store possible answer
            s = mid + 1;   // Move to right half
        } else {
            e = mid - 1;   // Move to left half
        }

        mid = s + (e - s) / 2;
    }

    return ans; // Returns the floor value of square root if not a perfect square
}

// Function to add decimal precision to the square root
double morePrecision(int n, int precision, int tempSol) {
    double factor = 1;
    double ans = tempSol; // Start from the integer part

    // Run loop for the number of digits of precision required
    for (int i = 0; i < precision; i++) {
        factor = factor / 10;

        // Linearly try adding factor to ans to approach closer to actual square root
        for (double j = ans; j * j < n; j = j + factor) {
            ans = j;
        }
    }

    return ans; // Returns square root with required precision
}

int main() {
    int n;
    cout << "Enter the number: ";
    cin >> n;

    // Step 1: Find integer part of square root
    int tempSol = sqrtInteger(n);

    // Step 2: Add decimal precision (3 digits here)
    cout << "Answer is " << morePrecision(n, 3, tempSol) << endl;

    return 0;
}
