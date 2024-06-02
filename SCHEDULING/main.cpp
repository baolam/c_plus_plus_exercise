#include <bits/stdc++.h>
#define maxn 100002

using namespace std;
typedef long long ll;
typedef pair<ll,ll> II;

ll n;
II a[maxn];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("VAO.INP", "r", stdin);
    freopen("RA.OUT", "w", stdout);
    cin >> n;
    for (ll i = 1; i <= n; i++)
        cin >> a[i].first >> a[i].second;
    return 0;
}
