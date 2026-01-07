#include <bits/stdc++.h>
using namespace std;

int main() {

    // Creating an empty map
    map<int, string> m1;

    // Initializing map with list
    map<int, string> m2 = {{1, "One"}, {2, "Two"}, {3, "Three"}};

    // Inserting a key value pair
    m2.insert({4, "Four"});

    // Accessing all pairs
    for (auto &p : m2){
        cout << p.first << " " <<
        p.second << endl;
    }

    // Accessing elements
    cout << m2[1] << endl;
    cout << m2.at(2) << endl;

    // Finding element with key
    auto it = m2.find(2);

    if (it != m2.end()){
        cout << it->first << " " << it->second << endl;;
    }
    else cout << "Key not found!" << endl;

    // Traversing using oterators
    for (auto it = m2.begin(); it != m2.end(); ++it){
        cout << it->first << " " << it->second << endl;
    }

    // Update value
    m2[1] = "Zero";

    // Deleting by key
    m2.erase(2);
    
    for(auto i : m2){
        cout << i.first << " " << i.second << endl;
    }

    return 0;
}