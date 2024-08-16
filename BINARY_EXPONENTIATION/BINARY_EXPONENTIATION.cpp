#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll bPow(ll a, ll n)
{
    ll res = 1;
    while (n > 0)
    {
        if (n & 1) res *= a;
        n >>= 1;
        a *= a;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << bPow(2, 4);
    return 0;
}
