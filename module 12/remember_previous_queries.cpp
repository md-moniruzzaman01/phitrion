#include <bits/stdc++.h>
using namespace std;

void printing_list(list<int> &Array) {
    cout << "L -> ";
    for (auto it = Array.begin(); it != Array.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "R -> ";
    vector<int> temp;
    for (auto it = Array.begin(); it != Array.end(); it++) {
        temp.push_back(*it);
    }
    for (int i = temp.size() - 1; i >= 0; i--) {
        cout << temp[i] << " ";
    }
    cout << endl;
}

int main() {
    int Q;
    cin >> Q;

    list<int> Array;

    while (Q--) {
        int x, v;
        cin >> x >> v;

        if (x == 0) {
            Array.push_front(v);
        } else if (x == 1) {
            Array.push_back(v);
        } else if (x == 2) {
            if (v >= 0 && v < Array.size()) {
                int i = 0;
                for (auto it = Array.begin(); it != Array.end(); it++, i++) {
                    if (i == v) {
                        Array.erase(it);
                        break;
                    }
                }
            }
        }

        printing_list(Array);
    }

    return 0;
}
