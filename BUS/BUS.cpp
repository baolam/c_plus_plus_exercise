#include <bits/stdc++.h>
#define maxn 200002

using namespace std;
typedef long long ll;

ll n, m;
ll sum, gtln = -1;
ll t[maxn];
vector<vector<ll>> e;

bool Check(ll time)
{
    ll cnt = 0;
    for (ll i = 1; i <= n; i++)
    {
        time += t[i];
        ll tmp = lower_bound(e[i].begin(), e[i].end(), time) - e[i].begin();
        cout << tmp << ' ';
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("VAO.INP", "r", stdin);
    freopen("RA.OUT", "w", stdout);
    ll k, x;
    cin >> n >> m;
    for (ll i = 1; i <= n; i++)
    {
        cin >> t[i] >> k;
        vector<ll> tmp;
        for (ll j = 1; j <= k; j++)
        {
           cin >> x;
           sum += x;
           gtln = max(gtln, x);
           tmp.push_back(x);
        }
        sort(tmp.begin(), tmp.end());
        e.push_back(tmp);
    }
    Check(1);
    return 0;
}
