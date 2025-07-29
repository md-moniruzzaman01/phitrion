#include <bits/stdc++.h>
using namespace std;

int main()
{
    list<string> List;
    string s;
    while (true)
    {
        cin >> s;
        if (s == "end")
        {
            break;
        }
        List.push_back(s);
    }

    int q;
    cin >> q;
    auto tmp = List.end();

    while (q--)
    {
        string inputs;
        cin >> inputs;

        if (inputs == "visit")
        {
            string targetAddress;
            cin >> targetAddress;

            auto it = find(List.begin(), List.end(), targetAddress);
            if (it != List.end())
            {
                tmp = it;
                cout << *tmp << endl;
            }
            else
            {
                cout << "Not Available"  << endl;
            }
        }
        else if (inputs == "next")
        {
            if (tmp == List.end() || next(tmp) == List.end())
            {
                cout << "Not Available"  << endl;
            }
            else
            {
                tmp++;
                cout << *tmp << endl;
            }
        }
        else if (inputs == "prev")
        {
            if (tmp == List.end() || tmp == List.begin())
            {
                cout << "Not Available" << endl;
            }
            else
            {
                tmp--;
                cout << *tmp << endl;
            }
        }
    }
    return 0;
}
