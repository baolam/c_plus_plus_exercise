#include <bits/stdc++.h>
#define maxn 1000002

using namespace std;
typedef long long ll;

unordered_map<ll, bool> table;
ll n, p;
ll x;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll cnt = 0, s = 0;
    cin >> n >> p;
    for (int i = 1; i <= n; i++) {
        cin >> x, s += x;
        table[s] = true;
        if (table[s - p])
            cnt++;
    }
    cout << cnt;
    return 0;
}
