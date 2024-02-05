#include <bits/stdc++.h>
#define maxn 1000004

using namespace std;
typedef long long ll;

vector<ll> v;
string s;
bool g[maxn];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    memset(g, true, sizeof(g));

    cin >> s;
    s.push_back('0');
    bool mem = false;
    ll n = s.length();
    ll _s = 0;
    for (ll i = 0; i < n; i++)
    {
        if (s[i] == '7') _s++, mem = true;
        else {
            if (mem) v.push_back(_s), mem = false;
            _s = 0;
        }
    }
    sort(v.begin(), v.end());
    for (ll i = 0; i < v.size(); i++)
    {
        if (g[v[i]])
        {
            _s = 0;
            for (ll j = i; j < v.size(); j++)
                if (v[j] >= v[i]) _s += v[j] - v[i] + 1;
            g[v[i]] = false;
            cout << v[i] << ' ' << _s << '\n';
        }
    }
    return 0;
}
