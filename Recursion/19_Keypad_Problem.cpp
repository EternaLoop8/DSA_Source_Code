#include <iostream>
#include <vector>
using namespace std;

// Recursive function to generate all combinations
void solve(const string &digits, string &output, int index, vector<string> &ans, string mapping[])
{
    if (index == digits.size())
    {
        ans.push_back(output);
        return;
    }

    int number = digits[index] - '0';
    string letters = mapping[number];

    for (char ch : letters)
    {
        output.push_back(ch);
        solve(digits, output, index + 1, ans, mapping);
        output.pop_back();
    }
}

vector<string> letterCombinations(const string &digits)
{
    vector<string> ans;
    if (digits.empty())
        return ans;
    string output;
    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    solve(digits, output, 0, ans, mapping);
    return ans;
}

int main()
{
    string digits;
    cout << "Enter digits: ";
    cin >> digits;

    vector<string> combinations = letterCombinations(digits);

    cout << "Letter Combinations:\n";
    for (auto &s : combinations)
    {
        cout << s << "\n";
    }

    return 0;
}
