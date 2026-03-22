#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        int k;
        cin >> k;

        // Min Heap
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < n; i++) {
            pq.push(v[i]);

            if (pq.size() > k) {
                pq.pop();
            }
        }

        // k-th largest element
        cout << pq.top() << endl;
    }

    return 0;
}