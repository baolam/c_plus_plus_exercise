#include <bits/stdc++.h>
#define maxn 200002

using namespace std;
typedef long long ll;

ll n, m;
ll sum, gtln = -1;
ll t[maxn], e[maxn];

bool Check(ll time)
{

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("VAO.INP", "r", stdin);
    freopen("RA.OUT", "w", stdout);
    ll k, cnt = 1;
    cin >> n >> m;
    for (ll i = 1; i <= n; i++)
    {
        cin >> t[i] >> k;
        for (ll j = 1; j <= k; j++)
        {
            cin >> e[cnt];
            cnt++; gtln = max(gtln, e[cnt]);
        }
    }
    cnt--;
    sort(e + 1, e + cnt);
    for (ll i = 1; i <= cnt; i++)
        cout << e[i] << ' ';
    cout << '\n';
    return 0;
}
