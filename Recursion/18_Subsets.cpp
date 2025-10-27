#include <iostream>
#include <vector>
using namespace std;

// Recursive helper to generate all subsets of nums
void solve(const vector<int> &nums, vector<int> output, int index, vector<vector<int>> &ans)
{
    // Base case: reached end of nums, add current subset to ans
    if (index >= nums.size())
    {
        ans.push_back(output);
        return;
    }

    // Exclude current element and recurse
    solve(nums, output, index + 1, ans);

    // Include current element and recurse
    output.push_back(nums[index]);
    solve(nums, output, index + 1, ans);
}

// Function to return all subsets of the given vector
vector<vector<int>> subsets(const vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> output;
    solve(nums, output, 0, ans);
    return ans;
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int &x : nums)
        cin >> x;

    vector<vector<int>> result = subsets(nums);

    cout << "All subsets:\n";
    for (const auto &subset : result)
    {
        cout << "[ ";
        for (int num : subset)
            cout << num << " ";
        cout << "]\n";
    }

    return 0;
}