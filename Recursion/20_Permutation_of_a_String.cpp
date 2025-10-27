#include <iostream>
#include <string>
using namespace std;

// Generate all permutations of s between indices left and right
void permute(string &s, int left, int right)
{
    if (left == right)
    {
        cout << s << "\n"; // print one permutation
        return;
    }

    for (int i = left; i <= right; i++)
    {
        swap(s[left], s[i]);         // choose
        permute(s, left + 1, right); // explore
        swap(s[left], s[i]);         // backtrack
    }
}

int main()
{
    string str;
    cout << "Enter a string: ";
    cin >> str;

    cout << "All permutations:\n";
    permute(str, 0, str.length() - 1);

    return 0;
}
