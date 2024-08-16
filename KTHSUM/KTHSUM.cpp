#include <bits/stdc++.h>
#define N 100002

using namespace std;
typedef long long ll;

vector<ll> V;
ll a[N], f[N];
ll n, k;

int main()
{
    cin >> n >> k;
    f[0] = 0;

    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        f[i] = f[i - 1] + a[i];
    }

    for (ll i = 1; i <= n; i++)
    {
        for (ll j = i; j <= n; j++)
            V.push_back(f[j]-f[i - 1]);
    }

    sort(V.begin(), V.end(), greater<ll>());
    cout << V[k - 1];
    return 0;
}
