#include <iostream>
using namespace std;

// Function to move from source to destination step by step
void reachHome(int src, int dest)
{

    cout << "Source: " << src << "  Destination: " << dest << endl;

    // Base case: If current position is equal to destination
    if (src == dest)
    {
        cout << "Reached home!" << endl;
        return; // Stop recursion
    }

    // Processing: Move one step forward
    src++;

    // Recursive call: Try to reach home from the new position
    reachHome(src, dest);
}

int main()
{
    int dest = 10; // Target position (home)
    int src = 1;   // Starting position

    // Start the journey
    reachHome(src, dest);

    return 0;
}
