#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, int> freq;
    int num;

    while (cin >> num) {
        freq[num]++;
    }

    bool found = false;
    for (auto& pair : freq) {
        if (pair.second >= 2) {
            cout << pair.first << " ";
            found = true;
        }
    }

    if (!found) {
        cout << "No duplicates";
    }

    return 0;
}



#include <iostream>
#include <map>
#include <sstream>
using namespace std;

int main() {
    map<int, int> freq;
    
    string input;
    getline(cin, input);
    stringstream ss(input);

    int num;
    while (ss >> num) {
        freq[num]++;
    }

    bool found = false;
    for (auto& pair : freq) {
        if (pair.second >= 2) {
            cout << pair.first << " ";
            found = true;
        }
    }

    if (!found) {
        cout << "No duplicates";
    }

    return 0;
}