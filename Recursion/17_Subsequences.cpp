#include <iostream>
#include <vector>
using namespace std;

// Recursive function to generate all subsequences of 'str'
void solve(vector<string> &ans, string str, string output, int i)
{
    // Base case: reached end of string
    if (i >= str.length())
    {
        if (output.length() > 0) // Ignore empty subsequence
            ans.push_back(output);
        return;
    }

    // Exclude current character and move forward
    solve(ans, str, output, i + 1);

    // Include current character and move forward
    output.push_back(str[i]);
    solve(ans, str, output, i + 1);
}

// Function to return all non-empty subsequences of a string
vector<string> subsequences(string str)
{
    vector<string> ans;
    solve(ans, str, "", 0);
    return ans;
}

int main()
{
    string str;
    cout << "Enter a string: ";
    cin >> str;

    vector<string> result = subsequences(str);

    cout << "Subsequences are:\n";
    for (auto &subseq : result)
    {
        cout << subseq << "\n";
    }

    return 0;
}