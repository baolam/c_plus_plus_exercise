#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int t, n;

void solve()
{
    ll tmp;
    ll sum = 0;
    cin >> n;
    while (n)
    {
        cin >> tmp;
        sum += tmp;
        n--;
    }
    tmp = sqrt(sum);
    if (tmp * tmp == sum)
        cout << "Yes" << '\n';
    else cout << "No" << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while(t)
    {
        solve();
        t--;
    }
    return 0;
}
