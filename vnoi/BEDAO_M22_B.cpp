#include <bits/stdc++.h>
#define maxn 200002
#define x first
#define y second

using namespace std;
typedef long ll;
typedef pair<ll,ll> ii;

ll n;
ii a[maxn];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (ll i = 1; i <= n; i++)
        cin >> a[i].x, a[i].y = i;
    sort(a+1, a+1+n);
    for (ll i = 1; i <= n; i++)
        cout << a[i].x << ' ';
    cout << '\n';
    return 0;
}
