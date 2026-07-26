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
        //here pair is an object of type pair<int, int> where pair.first is the number and pair.second is its frequency
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

// for reverse order result
// for (auto it = freq.rbegin(); it != freq.rend(); ++it) {
//     if (it->second >= 2) {
//         cout << it->first << " ";
//         found = true;
//     }
// }


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
    for (auto it = freq.rbegin(); it != freq.rend(); ++it) {
        //now here it is an iterator pointing to a pair of (key, value) where key is the number and value is its frequency
        if (it->second >= 2) {
            cout << it->first << " ";
            found = true;
        }
    }

    if (!found) {
        cout << "No duplicates";
    }

    return 0;
}