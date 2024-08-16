#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string a, b;

bool checked(ll l);

int main()
{
    cin >> a >> b;

    for (ll l = 0; l < a.length(); l++)
    {
        if (checked(l))
            cout << l + 1 << ' ';
    }

    return 0;
}

bool checked(ll l)
{
    if (l + b.length() - 1 > a.length())
        return false;
    string x = "";
    for (ll i = l; i < l + b.length(); i++)
        x += a[i];
    //cout << x << endl;
    return x == b;
}
