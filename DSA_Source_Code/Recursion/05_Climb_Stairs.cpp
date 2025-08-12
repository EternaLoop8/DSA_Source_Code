#include <iostream>
using namespace std;

long long countDistinctWayToClimbStair(int nStairs)
{
    // Rule: From any stair, you can climb either 1 step or 2 steps
    
    // Base cases
    if (nStairs < 0)
        return 0; // No way if steps go negative
    if (nStairs == 0)
        return 1; // Only 1 way (stay at ground)

    // Recursive relation: f(n) = f(n-1) + f(n-2)
    return countDistinctWayToClimbStair(nStairs - 1) +
           countDistinctWayToClimbStair(nStairs - 2);
}

int main()
{
    int n;
    cout << "Enter the number of stairs: ";
    cin >> n;

    cout << "The total distinct ways to climb " << n
         << " stairs is: " << countDistinctWayToClimbStair(n) << endl;

    return 0;
}
