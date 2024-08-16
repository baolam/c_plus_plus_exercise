#include <bits/stdc++.h>
#define maxn 100000

using namespace std;
typedef long long ll;

ll n, a[maxn];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("VAO.INP", "r", stdin);
    freopen("RA.OUT", "w", stdout);
    cin >> n;
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    sort(a+1, a+1+n);
    ll res = a[n / 2];
    if (n % 2 != 0)
        res += a[n / 2 + 1];
    cout << res;
    return 0;
}
