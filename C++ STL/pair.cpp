#include <bits/stdc++.h>
using namespace std;

int main() {

// Creating an empty pair
pair<int, string> p1;

// Insert values using curly braces {}
pair<int, string> p2 = {1, "Geeks"};

// Insert values using make_pair method
pair<int, string> p3 = make_pair(2, "ForGeeks");

cout << p2.first << " " << p2.second << endl;
cout << p3.first << " " << p3.second;
return 0;
}