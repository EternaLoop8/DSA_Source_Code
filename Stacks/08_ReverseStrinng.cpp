#include <iostream>
#include <stack>
using namespace std;

int main() {
    string str = "abcde";
    stack<char> s;

    // push all characters
    for (char ch : str) {
        s.push(ch);
    }

    string ans = "";
    // pop to form reversed string
    while (!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }

    cout << "Reversed string: " << ans << endl;
    return 0;
}