#include <bits/stdc++.h>
#define maxn 100001

using namespace std;
typedef int ll;

unordered_map<ll, ll> hm;
ll n, k;
ll a[maxn];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("VAO.INP", "r", stdin);
    //freopen("RA.OUT", "w", stdout);
    cin >> n >> k;
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    ll distinct = 0;
    for (ll i = 1; i <= k; i++)
    {
        if (hm[a[i]] == 0)
            distinct++;
        hm[a[i]]++;
    }
    cout << distinct << '\n';
    for (ll i = k + 1; i <= n; i++)
    {
        if(hm[a[i - k]] == 1)
            distinct--;
        hm[a[i-k]]--;
        if (hm[a[i]] == 0)
            distinct++;
        hm[a[i]]++;
        cout << distinct << '\n';
    }
    return 0;
}
