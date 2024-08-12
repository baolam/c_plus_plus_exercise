#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll b, n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> b >> n;
    ll cnt = 0;
    for (ll a = 2; a <= b; a++)
    {
        if (b * (b - a) <= n * n) cnt++;
    }
    cout << cnt;
    return 0;
}
