#include <bits/stdc++.h>
#define N 1000002

using namespace std;
typedef unsigned long long ll;

string a, b;
ll vl = 0;

ll c[N];
ll initalize();

int main()
{
    cin >> a >> b;
    for (ll i = 0; i < b.length(); i++)
        vl += int(b[i]) * (i + 1);
    for (ll i = 0; i < a.length(); i++)
        c[i] = int(a[i]);
    ll k = initalize();
    if (k == vl)
        cout << 1 << ' ';
    ll r = b.length() - 1;
    for (ll l = 1; l < a.length() - b.length() + 1; l++)
    {
        k -= c[l - 1] + c[r] * b.length();
        r++;
        k += c[l] + c[r] * b.length();
        if (k == vl)
            cout << l + 1 << ' ';
    }
    return 0;
}

ll initalize()
{
    ll k = 0;
    for (ll i = 0; i < b.length(); i++)
        k += a[i] * (i + 1);
    return k;
}
